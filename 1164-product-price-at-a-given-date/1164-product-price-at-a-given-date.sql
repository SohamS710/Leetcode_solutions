# Write your MySQL query statement below
select p.product_id, p.new_price as price
from products p
join (
    select product_id, max(change_date) as change_date
    from products
    where change_date <= '2019-08-16'
    group by product_id
) t
on p.product_id = t.product_id
and p.change_date = t.change_date

union

select distinct product_id, 10 as price
from products
where product_id not in (
    select product_id
    from products
    where change_date <= '2019-08-16'
);