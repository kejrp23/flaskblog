CREATE TABLE BlogEntries (
	Date INTEGER,
	Title TEXT,
	Post TEXT,
	Author TEXT,
	Subject TEXT
);


INSERT into BlogEntries  (Date,Title,Post,Author,Subject)
values 	('20230404', 'Test','Today is always a great day for coding', 'Jason R. Pittman', 'Tips'),
 		('20230403', 'Test1','Everyday is always a great day for coding', 'Jason R. Pittman', 'Tips'),
 		('20230401', 'Test2','Download and learn Rich today', 'Jason R. Pittman', 'Python'),
 		('20230331', 'Test3','C++ is the best', 'Jason R. Pittman', 'C++'),
 		('20230330', 'Test4','SQL is a get business language to know','Jason R. Pittman', 'Tips'),
 		('20230329', 'Test5','Pointers, Pointers, Pointers, learn them', 'Jason R. Pittman', 'C++'),
		('20230328', 'Test6','Heap vs Stack? when in doubt, Heap', 'Jason R. Pittman', 'C++');

select title, post from BlogEntries --where Subject = 'Python' 
select * from BlogEntries be order by Subject asc

--drop table BlogEntries 