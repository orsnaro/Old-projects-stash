                            -- ExampleS ON SELECT --
--show donation date 
select
client.cname , blood_bag.bld_bag_date ,client.blood_type

from client  inner join  blood_bag ON client.ssn=blood_bag.client_id;

--other examples
select client.cname,request_log.re from 

select * from central_inventory;

select * from hospital;

select * from supply_line;

select * from client;

select * from staff_status where assigned_bag between 2001 and 2004;

select * from request_log where is_completed = 1 ;


select top 10 * from client order by age DESC;



select * from client where blood_type = 'AB+' ; 


select  last_donation from donor ;

select ssn from client ;

select *from client ;