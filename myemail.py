from smtplib import SMTP


server = smtplib.SMTP("smtp.gmail.com", port=587)


sender = 'NoReply@gmail.com'

to = 'unknown@yahoo.com'

username =''
password = ''




server.starttls()
server.sendmail(sender, to, "message" )


