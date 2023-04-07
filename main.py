from flask import Flask, render_template
import requests
import datetime
import sqlite3
#import myemail

connection = sqlite3.connect('./db/blogs.db')
cursor = connection.cursor()
results = cursor.execute("Select * from BlogEntries order by date desc")
posts = results.fetchall()



url = 'https://api.npoint.io/4c57b38e46d5120b6da8'
content = requests.get(url).json()

year = datetime.datetime.now().year

app = Flask(__name__)



@app.route("/")
def home_page():
    return render_template('index.html', year=year)

@app.route("/about")
def get_about():
    return render_template("about.html",year=year)


@app.route('/blog')
def get_blog():
    pass

@app.route("/contact")
def get_contact():
    return render_template('contact.html', year=year)

@app.route("/posts")
def get_posts():
    return render_template('post.html', year=year, posts = posts)


if __name__ == "__main__":
    app.run(debug=True)
