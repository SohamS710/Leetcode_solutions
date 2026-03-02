# Write your MySQL query statement below
select q1.person_name from queue q1 where 
(
    select sum(q2.weight) from queue q2 where q2.turn <= q1.turn
) <= 1000
order by q1.turn desc limit 1;