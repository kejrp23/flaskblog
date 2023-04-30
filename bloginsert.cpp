#define FMT_HEADER_ONLY
#include <iostream>
#include <ctime>
<<<<<<< HEAD

time_t now = time(0);
char* date = ctime(&now);
=======
#include "core.h"

void today(){
		time_t now = time(0);
		char* date_time = ctime(&now);
		std::cout << date_time << std::endl;
}
>>>>>>> 5ec087c1d1a721bd16e039c57f0e1e9176b3c133




<<<<<<< HEAD

void printmsg(std::string a,std::string b,std::string c,std::string d){
		std::cout << "Insert into BlogEntries Values('" << a << "','"<< b << "',"<< "'," << c << "'," << "'" << d << "'" <<  ");" << std::endl;
}

=======
>>>>>>> 5ec087c1d1a721bd16e039c57f0e1e9176b3c133
int main()
{
		std::string date;
		std::string title;
<<<<<<< HEAD
		std::string author;
		std::string subject;
		std::cout << "Please Enter a title: ";
		std::cin >> title;
		std::cout << "Please begin typing, please a ';' to the end when you are done\n >";
		getline(std::cin,message,';');	
		std::cout << "Enter Author name: ";
		getline(std::cin,author,';');	
		std::cout << "Subject: ";
		getline(std::cin,subject,';');	
		printmsg(title,message,author,subject);
		std::cout << date << std::endl;
=======
		std::string blogmsg;
		std::string author {"Jason R. Pittman"};
		std::string subject;
		std::cin >> date >> title >> blogmsg >> subject;
		std::string sql = fmt::format("'{}','{}','{}','{}','{}');",date,title,blogmsg,author,subject);
		std::cout << sql << std::endl;
>>>>>>> 5ec087c1d1a721bd16e039c57f0e1e9176b3c133
		return 0;
}



