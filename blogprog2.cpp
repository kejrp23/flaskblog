#include <iostream>
#include "sqlite3.h"


void clear(){
		try{
				system("cls");
		}
		catch(...){
				system("clear");
		}
}

void insert(){
		//initializing variables to construct entry	
		std::string message;
	//	std::string title;
	//	std::string author;
	//	std::string subject;
		//char message[2000];
		std::string title;
		char author[30];
//		char subject[20];
		char post[3000];

	//Creating entry	
		std::cout << "Please Enter a title: ";
		getline(std::cin,title,';');
		std::cout << "Please begin typing, please add a ';' to the end when you are done\n >";
		getline(std::cin,message,';');
		std::cout << "Enter Author name: ";
		std::cin >> author;	
//		std::cout << "Subject: ";
//		std::cin >> subject;	
		sprintf(post,"Insert into BlogEntries Values('%s','%s','%s','%s')",title.c_str(),message.c_str(),author,"C++");
		std::cout << post << std::endl;
}


static int callback(void *NotUsed, int count, char **value, char **column) {
   int i;
   for(i = 0; i< count; i++) {
		   std::cout << column[i]<< " : " << value[i] << std::endl;
   }
   std::cout << std::endl;
   return 0;
}

static int sql_insert(){
		sqlite3 *db;
		int response;
		response = sqlite3_open("./db/blogs.db", &db);
//		string sql("Insert into BlogEntries(Date,Title,Post,Author,Subject) Values(2023-04-05,'SQLITE','It will be hard at first depending on which programming language you use.I suggest you start with python if you write in that language. It will be the easiest, but once you master it, SQLITE will become your best friend. It is amazing','Jason R. Pittman','Tips');");
		
	//initializing variables to construct entry	
		std::string message;
	//	std::string title;
	//	std::string author;
	//	std::string subject;
		//char message[2000];
		char title[50];
		char author[50];
		char subject[50];
		char post[5000];
		char date[15];

	//Creating entry	
		std::cout << "Please Enter todays date in YYYY-MM-DD Format\n>";
		std::cin >> date;
		std::cout << "Please Enter a title: ";
		std::cin >> title;
		std::cout << "Please begin typing, please add a ';' to the end when you are done\n>";
		getline(std::cin,message,';');
		std::cout << "Enter Author name: ";
		std::cin >> author;	
		std::cout << "Subject: ";
		std::cin >> subject;	
		sprintf(post,"Insert into BlogEntries(Date,Title,Post,Author,Subject) Values('%s','%s','%s','%s','%s');",date,title,message.c_str(),author,subject);
//		std::cout << post << std::endl;
		
		clear();

		response = sqlite3_exec(db,post,NULL,0,NULL);
		if (response != SQLITE_OK){
				std::cerr << "Error with insert\n";
		}
		else{
				std::cout << "Data inserted successfully\n";
		};
		
		
	
		return 0;
};


static int sql_query(){

		sqlite3* db;
		int response;
		std::string sql("select * from BlogEntries");
		response = sqlite3_open("./db/blogs.db", &db);
		
		response = sqlite3_exec(db,sql.c_str(),callback,NULL,NULL);
		if (response != SQLITE_OK){
				std::cerr << "Error\n";
		}
		return 0;
}



void start(){
		int action;				
		std::cin >> action;	
		if (action == 1){
			sql_insert();
		//	insert();
		}
		else if (action == 2){
			sql_query();
		}
		else if (action == 3){
//				quit();
		}
		else {
				std::cout << "entry not allowed\n";
				start();
		}
}
			


int main(){
		sqlite3* db;
		int response;
		response = sqlite3_open("./db/blogs.db",&db);
		if(response != SQLITE_OK){
				std::cerr << "Error occurred: File not opened\n";
		}
		else {
				clear();
				std::cout << "File Opened successfully \n";
		}
		std::cout << "**** Welcome to the Blog Editor ****\n\n";
		std::cout << "What Would you like to do?\n";
		std::cout << "1. Add entry \n2. Query Database\n3. Quit (work in progress)\n";
		std::cout << ">";
		start();
		return 0;
}
