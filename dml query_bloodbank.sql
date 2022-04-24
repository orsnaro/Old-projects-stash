---------------------------------------------------------------------------------------------------------------------------------
                                             --INSERT CLIENTS--

insert into client (ssn,blood_type,cname,age,phone_num)
values     ('2018010151327410','A-','Ali Fahmy',38,'147258'),
           ('2017010050063750','A+','Ahmed Maher',41,'369753'),
		   ('2090306080202050','A+','Ramdan Ahmed',35,'658741'),
		   ('2010300937198320','AB+','Maha Ahmed',25,'748596'),
		   ('3010130253002810','AB-','Maher Abdou',42,'152463'),
		   ('3011010009516780','B-','Yousif ElShahat',42,'159753'),
		   ('3017010020191230','B+','Shrief Mohamed',34,'154236'),
		   ('3005010141165400','B+','Samier Mohamed',38,'984278'),
		   ('3017010606693330','O+','Ahmed ElSaied',24,'754286'),
		   ('3180102204847450','O+','Ahmed Rady',20,'102834'), --10
		   ('2008010097989820','A+','Amr Nabiel',32,'871625'),
		   ('2019010083373870','O-','Walied Mohamed',42,'298346'),
		   ('2017010103003740','B-','Haytham Amr ',32,'182730'),
		   ('2018101092100030','O-','Magdy Mohamed',30,'951623'),
		   ('2002010697691220','B+','Karim Abdallah',34,'102938'),
		   ('2019010116343710','A+','Faried Abdelmoiem',23,'109876'),
		   ('3021010662929121','O-','Ebrahim Gad',44,'195371'),
		   ('3018010925968671','AB+','Ahmed Ramy',32,'098375'),
		   ('3019010202538141','AB-','Mohamed Eleps',23,'912435'),
		   ('3008010159856451','B+','samy Elsaied',34,'092837');
	

                                      --INSERT DONER

Insert into Donor (ssn,last_donation)
values ('2018010151327410','2021-12-27'),
       ('2017010050063750','2018-07-15'),
       ('2090306080202050','2017-08-13'),
       ('2010300937198320','2019-12-25'),
       ('3010130253002810','2011-03-29'),
       ('3011010009516780','2018-02-14'),
       ('3017010020191230','2021-03-29'),
       ('3005010141165400','2020-02-12'),
       ('3017010606693330','2019-08-07'),
       ('3180102204847450','2018-01-14'), --10
       ('2008010097989820','2016-04-15'),
       ('2019010083373870','2018-02-08'),
       ('2017010103003740','2021-01-01'),
       ('2018101092100030','2018-11-27'),
       ('2002010697691220','2019-03-06'),
       ('2019010116343710','2020-12-11'); --16

                                          --INSERT Recepient

INSERT INTO Recepient(ssn) SELECT ssn From client 
where ssn like '%1';

UPDATE Recepient
Set bld_particles_needed = 'plasma', bags_need= 1
WHERE ssn = '3021010662929121';

UPDATE Recepient
Set bld_particles_needed = 'O-', bags_need= 6
WHERE ssn = '3018010925968671';

UPDATE Recepient
Set bld_particles_needed = 'A+', bags_need= 2
WHERE ssn = '3019010202538141';

UPDATE Recepient
Set bld_particles_needed = 'AB-', bags_need= 10
WHERE ssn = '3008010159856451';



 

insert into central_inventory ( sec_id , capacity , available , staff_type , worker_id , shft_id , tot_status )
values  ('bank_A' , 500 , 320 , 'worker', 'WK_1' ,1,0.64 ),
        ('bank_B' , 500 , 362 , 'worker' ,'WK_2' ,2, 0.72 ),
        ('bank_AB', 500 , 289 , 'worker' ,'WK_3' ,3 , 0.57 ),
        ('bank_O' , 500 , 416 , 'worker' ,'WK_4' ,4, 0.83 ),
        ('bank_plasma', 750 , 520 , 'worker' ,'WK_5' ,5, 0.69 ),
        ('lab', 300 , 63 , 'doctor' ,'DR_1' ,7, 0.72 );


                                           
										   -- insert hospital
insert into hospital ( unit_id , process_date , city , st_no , tot_need_quantity , need_type )
values ( 1 , '2019-07-23' , ' alhamoul ' , 15 , 370 , 'bank_A' ) ,
      ( 2 , '2020-1-15' , ' dsouq ', 8 , 480 , 'bank_plasma' );



		                                 --insert request_log






insert into request_log ( destination_unit , ssn , req_date , is_donor , is_recp , is_completed , cname , age , blood_type , wieght , bags_quantity , blood_particles )
values    (1,'2018010151327410','2019-07-23',1,0,1,'Ali Fahmy',38,'A-',85,null,null), 
         (1,'2017010050063750','2019-07-23',2,0,1,'Ahmed Maher',41,'A+',75,null,null), 
         (1,'2090306080202050','2019-07-23',3,0,0,'Ramdan Ahmed',35,'A+',71,null,null),
         (1,'2010300937198320','2019-07-23',4,0,1,'Maha Ahmed',25,'AB+',74,null,null),
         (1,'3010130253002810','2019-07-23',5,0,0,'Maher Abdou',42,'AB-',72,null,null) ,
         (1,'3011010009516780','2020-01-15',6,0,0,'Yousif ElShahat',42,'B-',68,null,null) ,
         (1,'3017010020191230','2020-01-15',7,0,0,'Shrief Mohamed',34,'B+',84,null,null) ,
         (1,'3005010141165400','2020-01-15',8,0,1,'Samier Mohamed',38,'B+',89,null,null),
         (2,'3017010606693330','2020-01-15',9,0,1,'Ahmed ElSaied', 24,'O+',83,null,null) ,
         (2,'3180102204847450','2020-01-15',10,0,0,'Ahmed Rady',20,  'O+', 81,null,null) ,
         (1,'2008010097989820','2019-07-23',11,0,1,'Amr Nabiel',20,'A+',84,null,null),
         (2,'2019010083373870','2019-07-23',12,0,0,'Walied Mohamed',32,'O-',65,null,null),
         (2,'2017010103003740','2019-07-23',13,0,1,'Haytham Amr ',42,'B-',59,null,null),
         (1,'2018101092100030','2020-01-15',14,0,0,'Magdy Mohamed',32,'O-',59,null,null),
         (1,'2002010697691220','2020-01-15',15,0,1,'Karim Abdallah',30,'B+',59,null,null),
         (1,'2019010116343710','2020-01-15',16,0,1,'Faried Abdelmoiem',34,'A+',100,null,null),
         (2,'3021010662929121','2020-01-15',17,1,1,'Ebrahim Gad',23,'O-',47,1,'plasma'),
         (1,'3018010925968671','2019-07-23',18,1,0,'Ahmed Ramy',44,'AB+',51,6,'O-'),
         (1,'3019010202538141','2019-07-23',19,1,1,'Mohamed Eleps',23,'AB-',75,2,'A+'),
         (2,'3008010159856451','2019-07-23',20,1,0,'samy Elsaied',34,'B+',78,10, 'AB-');


insert into supply_line (shft_id ,destination_sec ,lap_tst_rslt )
values 
(1,'bank_A',0),
(1,'bank_A',0),
(1,'bank_A',1),
(1,'bank_A',1),
(2,'bank_O',1),
(2,'bank_O',1),
(1,'bank_plasma',1),
(2,'bank_plasma',1),
(1,'bank_plasma',1),
(2,'bank_B',1),
(2,'bank_B',1),
(1,'bank_B',1),
(1,'bank_O',1),
(2,'bank_O',1),
(1,'bank_AB',1),
(2,'bank_AB',1)

-- insert staff_status
insert into staff_status ( worker_id , assigned_bag , shft_id )
values 
( 'WK_1' , 2001, 2 ),
( 'WK_2' , 2002 , 2 ),
( 'WK_1' , 2003, 1 ),
( 'WK_1' , 2004 , 2 ),
( 'WK_1' , 2005, 1 ),
( 'WK_2' , 2006 , 1 ),
( 'WK_1' , 2007, 1 ),
( 'WK_2' , 2008 , 1 ),
( 'WK_2' , 2009, 2 ),
( 'WK_2' , 2010 , 1 ),
( 'WK_1' , 2011, 2 ),
( 'WK_2' , 2012 , 2 ),
( 'WK_1' , 2013, 1 ),
( 'WK_2' , 2014 , 1 ),
( 'WK_1' , 2015, 1 ),
( 'WK_1' , 2016 , 2 );





insert into blood_bag (bld_bag_date,blood_type,client_id)
values
('2019-07-23','A+','2018010151327410'),
('2019-07-23','A+','2017010050063750'),
('2019-07-23','A-','2090306080202050'),
('2019-07-23','AB+','2010300937198320'),
('2019-07-23','AB-','3010130253002810'),
('2019-07-23','B-','3011010009516780'),
('2019-07-23','B+','3017010020191230'),
('2020-1-15','B+','3005010141165400'),
('2019-07-23','O+','3017010606693330'),
('2019-07-23','O+','3180102204847450'),
('2020-1-15','A+','2008010097989820'),
('2019-07-23','O-','2019010083373870'),
('2020-1-15','B-','2017010103003740'),
('2020-1-15','AB+','2018101092100030'),
('2020-1-15','O+','2002010697691220'),
('2020-1-15','O-','2019010116343710');



--insert sec
/*  INSERT INTO table_name (column1, column2, column3, ...)
VALUES (value1, value2, value3, ...);  */
--update sec 
/* UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition; */
--delete sec (danger)
/* DELETE FROM table_name WHERE condition; */

