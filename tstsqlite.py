import sqlite3
from sqlite3 import Error


# TODO : error handling (expired license .. etc)
# TODO : tickting and park cost system ( calc diff between time stamps and ticket is the event id no)
# TODO :
# (not very imp) make sure that copying , reassigning the connection and cursor objects
# doesnt make big problems or memory leaks
###########################################################################
def connect_db():
	def_db = r"./temp.db"
	connect_obj = None

	try:
		# connect_obj = sqlite3.connect(def_db, autocommit=True) # autocommite doesnt work in this version
		connect_obj = sqlite3.connect(def_db)
		connect_obj.execute("PRAGMA foreign_keys = ON")
		return connect_obj

	except Error as e:
		print(e)
###########################################################################
def create_db(conn):
    cursor = conn.cursor()

    # table 1
    cursor.execute("""
	CREATE TABLE IF NOT EXISTS people_info (
	id text PRIMARY KEY,
	name text NOT NULL,
	car_model text,
	license_exp_date DATE
	);
	""")

    # table 2 event type : 0 == occupy a cell , 1 == free a cell
    cursor.execute("""
	CREATE TABLE IF NOT EXISTS event_log(
	event_id integer PRIMARY KEY autoincrement,
	person_id text NOT NULL,
	event_type integer NOt NULL,
	Timestamp DATETIME DEFAULT CURRENT_TIMESTAMP NOT  NULL,
	FOREIGN KEY (person_id) REFERENCES people_info(id)
	);
	""")

    # table 3 status : 0 = available , 1 = full , 2 = maintainance
    cursor.execute("""
	CREATE TABLE IF NOT EXISTS parking_status(
	unit_id integer NOT NULL default 1,
	cell_id integer NOT NULL,
	taken_by text default NULL,
	status integer default 0 ,
	FOREIGN KEY (taken_by) REFERENCES people_info(id)
	);
	""")


    # test sample of non real people info
    cursor.execute("""
	INSERT INTO people_info (id, name, car_model, license_exp_date)
	VALUES
	(1234567890123, 'John Doe', 'Toyota Camry 2015', '2022-05-31'),
	(2345678901234, 'Jane Smith', 'Honda Accord 2016', '2023-01-15'),
	(3456789012345, 'Ahmed Ali', 'Nissan Altima 2017', '2022-11-30'),
	(4567890123456, 'Fatima Hassan', 'Ford Mustang 2018', '2024-03-20'),
	(5678901234567, 'Mohammed Khalid', 'Chevrolet Impala 2019', '2023-09-10'),
	(6789012345678, 'Sara Ahmed', 'Hyundai Sonata 2020', '2025-02-28'),
	(7890123456789, 'Abdullah Saleh', 'Kia Optima 2016', '2022-08-05'),
	(8901234567890, 'Aisha Mohammed', 'Mazda CX5 2017', '2023-06-15'),
	(2345610987654,'Youssef Salah','Jeep Cherokee 2019','2024-07-01'),
	(3456721098765,'Nada Khalid','Ford Escape 2017','2022-12-31'),
	(4567832109876,'Omar Ali','Honda Civic 2018','2023-08-15'),
	(5678943210987,'Rania Ahmed','Toyota RAV4 2016','2022-04-30'),
	(6789054321098,'Khaled Hassan','Nissan Maxima 2015','2021-11-15'),
	(7890165432109,'Laila Saleh','Chevrolet Malibu 2014','2021-05-31'),
	(8901276543210,'Mona Mohammed','Hyundai Elantra 2013','2020-12-15'),
	(9012387654321,'Hassan Ali','Kia Sportage2009','2024-12-15');
	""")
    conn.commit()  # some statements need commit / but we enabled auto commit

    # insert initial data for parking status table
    cursor.execute("""
	insert into parking_status (unit_id , cell_id)
	values
	(1 ,  0),
	(1 ,  1),
	(1 ,  2),
	(1 ,  3),
	(1 ,  4),
	(1 ,  5);
	""")
    conn.commit()  # some statements need commit / but we enabled auto commit
###########################################################################
def build_db():  # only once to create database
	conn = connect_db()
	# inside create_db() will make the 4 main tables 
	# -> people_info , parking_status , event_log , total_available
	create_db(conn)
###########################################################################
def park_car_db(conn , cmd ,id) : # park car command to update database
	cursor = conn.cursor()
# check if parking is full return parking full err (from available table)
	car_counter_query = ( """ select sum(status) from parking_status where status = 1; """ )
	cursor.execute(car_counter_query)
	mx_sz = 6
	available_cells = mx_sz - (cursor.fetchall())[0] 

	if available_cells == 0:
		conn.close()
		print (" debug message : Fail parking is full! ")
		return 0  # 0 == fail park is full
	else:
		# take id  and get all data from people_info table ( NO NEED FOR NOW)
		query_personal_data = '''select * from people_info where id = ?; '''
		cursor.execute(query_personal_data, (id,))
		person_info = cursor.fetchall()

		# take all persons data and add new event in events log table ( event type : occupy parking cell)
		event_type = cmd
		person_id = id
		cursor.execute("""
	insert into event_log (person_id , event_type ) values
	(? , ?);
	""", (person_id , event_type))
		conn.commit()

		# update parking status table ( take the nearist available parking) and update total available table
		cursor.execute(
				'''SELECT cell_id FROM parking_status WHERE status = 0 order by cell_id asc;''')
		nearest_empty_cell_id = cursor.fetchone() #returns tuple with only 1 element

		# you got the id now change status to 1 (occupied)
		cursor.execute(
				""" update parking_status set status = 1 where cell_id = ? ;""", (nearest_empty_cell_id[0],)) # or just pass nearest_empty_cell_id
		conn.commit()

		# (NO NEED) another way to  get the nearist empty cell id using select and first_value()
		# cursor.execute(""" select * , first_value(taken_by)
		# over (order by taken_by)
		# as nearst_empty_cel
		# from parking_status
		# where status = 0 ;
		# """) # no need also check if empty before

		conn.close()
		# return NOThing important END
		print ("debug message : SUCCESS Database has been updated ! ")
		return 1  # success
###########################################################################
def get_car_db(conn , cmd , id) : # get car from parking command ( free a cell in db )
	cursor = conn.cursor()
# query the parking status table  by id
	cursor.execute(
		"""select cell_id , status from parking_status where taken_by = ?; """, (id,))
	cell_data = cursor.fetchall()
	status = cell_data[1]
	
	# if car isn't there return no matching id found err
	if status != 1:
		conn.close()
		print("debug message : FAIL car not found!")
		return 0  # fail car not found err
	else:
	# get all personal data from personal data table by id ( NO NEED FOR NOW)
		cursor.execute(""" select * from people_info where id = ?""", (id,))
		person_data = cursor.fetchall()  # id, name, car_model, license_exp_date

	# register new event in event log table with data you got (event type = free parking cell )
		cursor.execute(""" insert into event_log (person_id , event_type)
		values(? , ?);
		""", (id , cmd))
		conn.commit()

	# update parking status table
		cursor.execute("""" update parking_status set status  = 0
				where taken_by = ? ;""", (id,))
		conn.commit()
		
		conn.close()
	# return parking cell number
		print ( "debug message : SUCCESS Database has been updated!")
		return cell_data[0]
###########################################################################
def calc_cost() : ...
###########################################################################
def db_cmd(cmd : int, id : str):
	conn = connect_db()
	if cmd == 0:  # park car command
		return park_car_db(conn , cmd , id)
	elif cmd == 1: # get car from park command ( free a cell )
		return get_car_db(conn , cmd , id)
###########################################################################
if __name__ == "__main__":
	# test your code
	# build_db() #build the sqlite3 db for fist time
	db_cmd(0 , str(9012387654321) ) # Example: park new car with driver id = 9012387654321
