import sqlite3
from sqlite3 import Error

def connect_db() :
	def_db = r"./temp.db"
	connect_obj = None
	
	try:
		connect_obj =  sqlite3.connect(def_db)
		return  connect_obj
	
	except Error as e :
		print (e)
	

def create_db(conn) :
	cursor = conn.cursor()

	cursor.execute( """
	CREATE TABLE IF NOT EXISTS people_info (
	id integer PRIMARY KEY,
	name text NOT NULL,
	car_model text,
	license_exp_date DATE 
	);
	""")
	
	cursor.execute("""
	CREATE TABLE IF NOT EXISTS event_log(
	event_id integer PRIMARY KEY,
	person_id integer NOT NULL,
	event_type integer NOt NULL,
	Timestamp DATETIME DEFAULT CURRENT_TIMESTAMP NOT  NULL
	);
	
	""")

	cursor.execute("""
	CREATE TABLE IF NOT EXISTS parking_status(
	unit_id integer NOT NULL,
	cell_id integer NOT NULL,
	taken_by integer ,
	status integer 
	);
	""")

	cursor.execute("""
	CREATE TABLE IF NOT EXISTS total_available(
	available_counter integer default 6
	);
	
	""")

	 #test sample of non real data 
	cursor.execute( """
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
	conn.commit() # for insert delete or update



def build_db() : # only once
	conn = connect_db()
	create_db(conn) #inside will make the 4 main tables : data , park status , event log , total available
	cur = conn.cursor()

# def db_cmd( cmd : int , id : str) : 
# 	if cmd is 0 : # park car command
# 		cursor  , conn = connect_db()
# 		#check if parking is full return parking full err (from available table)
# 		#else :
# 		#take id  and get all data fro personal data table 
# 		# take all persons data and add new event in events log table ( event type : occupy parking cell)
# 		# update parking status table ( take the nearist available parking) and update total available table
# 		# increase available counter in tot_availabel table
# 		# ( this is done by select old value fetch it +1 then update the table)
# 		# return NOThing important END

# 	elif cmd is 1 : ...  # get car from park command
# 		# query the parking status table  by id
# 		# if car isnt there return no matching id found err
# 		# els:
# 		# get all personal data from personal data table by id
# 		# register new event in event log table with data you got (event type = free parking cell )
# 		# update parking status table 
# 		#decrease available counter in tot_availabel table 
# 		# ( this is done by select old value fetch it -1 then update the table)
# 		# return parking cell number
		
if __name__ == "__main__" :
	build_db()