# 一、基础语法

## 1.1.查询-全表查询

~~~sql
selete * from table_name;
~~~

## 1.2.查询-选择查询

~~~sql
selete key1_name, key2_name from table_name;
~~~

## 1.3.查询-别名

~~~sql
select name as 学生姓名, age as 学生年龄 from student;
~~~

## 1.4.查询-常量和运算

~~~sql
select name, score, score * 2 as double_score from student;
~~~

## 1.5.查询-条件查询-where

~~~sql
select name, score from student where name == "鱼皮";
~~~

## 1.6.条件查询运算符

~~~sql
select name, age from student where name != '热dog';
select name, age from student where score > 50;
~~~

## 1.7.条件查询空值

~~~sql
select name, age, score from student where age is not null;
~~~

## 1.8.条件查询-模糊查询

~~~sql
select name, score from student where name not like '%李%';
select name, score from student where name not like '李%';
select name, score from student where name not like '%李';
~~~

## 1.9.条件查询-逻辑查询

~~~sql
select name, score from student where name like '%李%' or score > 500;
select name, score from student where name like '%李%' and score > 500;
~~~

## 1.10.去重

~~~sql
语法：distinct 字段1, 字段2, 字段3, ...
select distinct class_id, exam_num from student;
~~~

## 1.11.排序

~~~sql
语法：order by 字段1 [升序/降序], 字段2 [升序/降序], ...
select name, age, score from student order by score desc, age asc;
~~~

## 1.12.截断与偏移

~~~sql
语法：limit number 表示获取第几条
语法：limit number1 number2 表示从几条开始（下标从0开始），获取几条
select name, age from student order by age asc limit 1, 3;
select name, age from student order by age asc limit 1;
~~~

## 1.13.条件分支

~~~sql
语法：
CASE WHEN (条件1) THEN 结果1
	   WHEN (条件2) THEN 结果2
	   ...
	   ELSE 其他结果 END

select name,
    case when (age > 60) then '老同学'
    when (age >= 20 and age <= 60) then '年轻'
    else '小同学' end as age_level
from student
order by name asc;
~~~

## 1.14.时间函数

~~~sql
select name, date() as '当前日期' from student
select name, time() as '当前时间' from student
select name, datetime() as '当前日期时间' from student
~~~

## 1.15.字符串处理

~~~sql
select id, name, upper(name) as upper_name from student where (name = '热dog');
select id, name, lower(name) as lower_name from student where (name = '热dog');
select id, name, length(name) as name_length from student where (name = '热dog');
~~~

## 1.16.聚合函数

~~~sql
select sum(score) as total_score, 
avg(score) as avg_score, 
max(score) as max_score, 
min(score) as min_score from student;
~~~

## 1.17.分组聚合-单组分段

~~~sql
select class_id, avg(score) as avg_score from student group by class_id;
~~~

## 1.18.分组聚合-多字段分段

~~~sql
select
  class_id,
  exam_num,
  count(*) as total_num
from
  student
group by
  class_id,
  exam_num;
~~~

## 1.19.分组聚合-having字句

~~~sql

~~~