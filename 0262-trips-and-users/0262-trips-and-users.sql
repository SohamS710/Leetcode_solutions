# Write your MySQL query statement below
select t.request_at as 'Day', 
round(sum(case when t.status like 'cancelled%' then 1 else 0 end)/count(*),2) as 'Cancellation Rate'
from trips t
left join users u1
on t.client_id = u1.users_id
left join users u2
on t.driver_id = u2.users_id
where u1.banned = 'No' and 
u2.banned = 'No' and 
t.request_at between '2013-10-01' and '2013-10-03'
group by t.request_at