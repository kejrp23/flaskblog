
#include <iostream>






void printmsg(std::string y,std::string x){
		std::cout << "Insert into BlogEntries Values('" << y << "','"<< x << "',"<< ");";
}

int main()
{
		std::string message;
		std::string title;
		std::cout << "Please Enter a title: ";
		std::cin >> title;
		std::cout << "Please begin typing, please a ';' to the end when you are done\n >";
		getline(std::cin,message,';');	
		std::system("cls");
		printmsg(title,message);
		
		return 0;
}



