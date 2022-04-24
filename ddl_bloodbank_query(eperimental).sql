
-- physical version 0.1  (11/26/21)
--v 0.2 (25/12/21)
--v 0.3 (30/12/21)
--v 1.0 (1-1-2022)
--*this is a (reduced) version no extra cnostraints and features + no excessive commenting*--
--intialization

CREATE DATABASE BLOOD_BANK ;
GO
USE BLOOD_BANK;
GO



                                           -- main entities --

create table  central_inventory
(

--sec
sec_id      varchar(255) primary key , --lap 'l' and storages 'bank1_plasma,bank2_blood.., bank4_plasma_o' ,other
capacity    int,
available   int, 
staff_type  varchar(255) not null,
--end composite 

worker_id  varchar(255) unique,
shft_id    int unique ,
tot_status decimal,

constraint valid_secid check (sec_id like'b%' or sec_id like 'l%'),

);



create table  hospital
(
unit_id       int primary key,
process_date  date not null unique ,  --real use: default getdate(),  

--hospital_address 
 city varchar(255) not null ,st_no varchar(255) ,
--composite end

--need  
 tot_need_quantity int ,need_type varchar(255), --blood/plasma other 
--end  composite

  constraint Fk_ndtypRefInvntrySecID  foreign key  (need_type) references central_inventory(sec_id), 
  constraint is_storage_chk           check( need_type != 'l%'),


);

create table  supply_line
(
--trigger to update with each req_donor update (maybe usin cascadin ref integ constraint)

tot_unchkd_quantity int   identity(2001,1) ,--could use sum or count instead
shft_id             int not null,
destination_sec     varchar(255) not null ,
lap_tst_rslt        binary not null,-- if zero not accepted

constraint Pk_supply                   primary key (tot_unchkd_quantity), 
constraint Fk_DestinSecRefInvntrySecId foreign key (destination_sec) references central_inventory(sec_id),

);





create table  client
(
ssn        varchar(255),
blood_type varchar(255) not null,
cname      varchar(255),
age        int not null,
phone_num  varchar(255) null,

constraint Pk_client primary key (ssn),
constraint Clntage_Chk check (age>=18)
);



--############################################################################################
                             -- weak/associative/sub entities --
create table  Donor
(

ssn           varchar(255)  not null primary key ,
last_donation date DEFAULT '1900-01-01',
--donation_date datetime default getdate() ,

 constraint Fk_SsnRefClntSsn foreign key (ssn) references client(ssn) 
 on delete cascade on update cascade,
 constraint is_donated_recently 
 check
 (
 DATEDIFF (month, last_donation ,cast(getdate() as date)) >= 3
 )
);

create table  Recepient
(
ssn      varchar(255) primary key,

--blood_partciles 
bld_particles_needed varchar(255) ,
bags_need  int 
--composite end

constraint Fk_SsnRefClintSsn foreign key (ssn) references client(ssn)
on delete cascade on update cascade,
);
 
create table  staff_status
(
worker_id     varchar(255),
assigned_bag  int,
shft_id int,

constraint Pk_Staff                     primary key (worker_id,assigned_bag),
constraint Fk_AsigndSecRefInvntrySecId  foreign key (worker_id) references central_inventory(worker_id),
constraint fk_shftid                    foreign key (shft_id)   references  central_inventory (shft_id),
constraint Fk_AsigndShftRefSplyShftId   foreign key (assigned_bag) references supply_line(tot_unchkd_quantity)
on update cascade
);

create table  blood_bag
(

bld_bag_date    date not null ,  
client_id		varchar(255) not null ,
blood_type      varchar(255),
constraint Fk_BLdBgDatRefHospPrcsDat   foreign key (bld_bag_date) references hospital(process_date),
constraint fk_blood                    foreign key (client_id)  references client (ssn),
constraint Pk_BLDbags                  primary key (bld_bag_date,blood_type,client_id)
); 
 

-------------------------------------------------------------
create table  request_log
(
--donor/ recep columns will remain null if request is for opposite client
destination_unit int         not null ,
ssn              varchar(255)not null ,
req_date         date        not null ,

--request_status 
is_donor int  unique ,
is_recp  binary ,
is_completed  binary not null , 
cname         varchar(255) not null, 
age			  int not null,
blood_type	  varchar(255) not null,
wieght        decimal,
bags_quantity int default 1,
blood_particles varchar(255) default 'not specified' ,
-- compostie end

constraint Fk_DestUntRefHospUntId foreign key (destination_unit) references hospital(unit_id),
constraint Fk_SsnRefClntIdSsn     foreign key (ssn)              references client(ssn),
constraint Fk_RqstDtRefHopPrcsDt  foreign key (req_date)         references hospital(process_date),
constraint Pk_reqst               primary key (destination_unit,ssn,req_date),
constraint Chk_RqstAge            check (age >= 18),
constraint Chk_DnrXorRecp         check ((is_donor != null and is_recp =  null) or (is_donor = null and is_recp != null))
--previous condition to *prevent* making overlaped request e.g.(donor and recp at same time)
);











--############################################################################################
                             --testing\editing structure  section --
use master
 drop DATABASE BLOOD_Bank;
 alter table  blood_bags add blood_type varchar(3) ;
 alter table hospital add  constraint unique_hos unique (process_date,client_id);
 alter table supply_line drop column stage_id;
 alter table supply_line add  tot_unchkd_quantity int not null unique ;
 alter table supply_line add constraint pk_supply primary key (tot_unchkd_quantity) ;
 alter table blood_bags add bag_no int not null ;--make it auto  with each new_donor
 alter table blood_bags add constraint fk_supply foreign key (bag_no) references supply_line(tot_unchkd_quantity);
 alter table blood_bags drop constraint pk_BLDbags ;
 alter table blood_bags add constraint PK_BldBag primary key (client_id,bag_no);
 alter table supply_line add constraint unique_shft unique (shft_id);
 alter table staff add constraint FK_supply2 foreign key (assigned_shft) references supply_line(shft_id);
ALTER table client alter column ssn varchar(1500)

--##########################################################################################
                                       --triggers section--

--trigger1 to increase tot bags auto (experimental!!!!!!!)
--create inserted table for request_log to record insert  before inserting it to main table:

create table audit_request_log(

destination_unit int         not null ,
ssn              varchar(255)not null ,
req_date         date        not null ,

--request_status 
is_donor        int  unique ,
is_recp         binary ,
is_completed    binary not null , 
cname           varchar(255) not null, 
age			    int not null,
blood_type	    varchar(255) not null,
wieght          decimal,
bags_quantity   int default 1,
blood_particles varchar(255) default 'not specified' ,
-- compostie end

--*new attributes*--
    change_id  INT IDENTITY PRIMARY KEY,
	updated_at DATETIME NOT NULL,
	operation  CHAR(3) NOT NULL,
CHECK(operation = 'INS' or operation='DEL')
--end of new attributes

constraint Fk_TRIG_DestUntRefHospUntId foreign key (destination_unit) references hospital(unit_id),
constraint Fk_TRIG_SsnRefClntIdSsn     foreign key (ssn)              references client(ssn),
constraint Fk_TRIG_RqstDtRefHopPrcsDt  foreign key (req_date)         references hospital(process_date),
--constraint Pk_reqst               primary key (destination_unit,ssn,req_date),
constraint Chk_RqstAge            check (age >= 18),
constraint Chk_DnrXorRecp         check ((is_donor != null and is_recp =  null) or (is_donor = null and is_recp != null))
);

--trigger

CREATE TRIGGER  trg_audit_request_log
ON request_log  

INSTEAD OF insert
AS
begin

set nocount on;

 INSERT INTO audit_reqrequest_log(
 destination_unit,
 ssn,
 req_date,
 is_donor,
 is_recp,
 is_completed,
 cname,
 age,
 blood_type,
 wieght,
 bags_quantity,
 blood_particles,
 updated_at ,
operation  
 )
 values

   SELECT
        i.destination_unit,
        ssn,
        req_date,

        is_donor,
        is_recp,
        is_completed,
		 cname,
		  age,
		   blood_type,
		    wieght,
 bags_quantity,
 blood_particles

        GETDATE(),
        'INS'
    FROM
        inserted as i
    UNION ALL
    SELECT
        d.destination_unit,
        d.ssn,
        d.req_date,

        is_donor,
        is_recp,
        is_completed,
		cname,
		age,
		blood_type,
		wieght,
 bags_quantity,
 blood_particles

        GETDATE(),
        'DEL'
    FROM
        deleted as d;
		 
begin

if  
--if donor makes req supply line fire auto insert statement  to inrease tot_bags no.
end 





 -- alter(add\drop..)\create\drop
--more queries:
--1)  create index on indx_table_name (freq_usedtable1,freq_usedtabl2)
--2) drop table_name.index_name  --deletes index makes updating the table faster --no need to update index
--3)w3school for more commands ddl/mdl : https://www.w3schools.com/sql/sql_create_index.asp

select * from inserted