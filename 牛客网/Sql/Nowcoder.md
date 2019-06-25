# 牛客网数据库SQL实战

### 题目一
查找最晚入职员工的所有信息
```sql
CREATE TABLE `employees` (
`emp_no` int(11) NOT NULL,
`birth_date` date NOT NULL,
`first_name` varchar(14) NOT NULL,
`last_name` varchar(16) NOT NULL,
`gender` char(1) NOT NULL,
`hire_date` date NOT NULL,
PRIMARY KEY (`emp_no`));
```

```sql
select * from employees
where hire_date = 
(select max(hire_date) from employees);
```

### 题目二
查找入职员工时间排名倒数第三的员工所有信息。
```sql
select * from employees
where hire_date = 
(select distinct hire_date from employees 
order by hire_date desc limit 2, 1);
```

#### Limit复习

