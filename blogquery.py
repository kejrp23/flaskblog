import sqlite3
from rich import print
import datetime

today = datetime.datetime.now()
day = today.day
month = today.month
year = today.year
postdate = f'{month}/{day}/{year}'
print(postdate)

connection = sqlite3.connect('blogs.db')

cursor = connection.cursor()

#results = cursor.execute('Select * from BlogEntries')


# cursor.execute('''Insert into Blogentries (Date,Title,Post,Author,Subject) values ('20232003','Pointers','Pointers may seem hard at first. However if you are committed to becoming a true programmer. They are a must learn for you. After you master low level programming, no one can take that away from you. You will truly be a wizard amongst mere muggles','Jason R. Pittman','C++')''')
# connection.commit()
# cursor.execute("DELETE FROM BlogEntries WHERE Title = 'Pointers'")
# connection.commit()
# for row in cursor.execute("Select * from BlogEntries "):
#     print(f'[bright_cyan]Title: {row[1]} [green]Post: {row[2]}')


results = cursor.execute('Select * from BlogEntries')
posts = results.fetchall()

for post in posts:
    print(post)
    
