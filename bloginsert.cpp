
#include <iostream>
#include <ctime>

time_t now = time(0);
char* date = ctime(&now);





void printmsg(std::string a,std::string b,std::string c,std::string d){
		std::cout << "Insert into BlogEntries Values('" << a << "','"<< b << "',"<< "'," << c << "'," << "'" << d << "'" <<  ");" << std::endl;
}

int main()
{
		std::string message;
		std::string title;
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
		return 0;
}



