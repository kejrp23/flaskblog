#include <iostream>
#include "sqlite3.h"


using namespace std;



static int callback(void *NotUsed, int count, char **value, char **column) {
   int i;
   for(i = 0; i< count; i++) {
		   cout << column[i]<< " : " << value[i] << endl;
   }
   cout << endl;
   return 0;
}

static int sql_insert(){
		sqlite3 *db;
		int response;
		response = sqlite3_open("./db/blogs.db", &db);
		string sql("Insert into BlogEntries(Date,Title,Post,Author,Subject) Values(2023-04-05,'SQLITE','It will be hard at first depending on which programming language you use.I suggest you start with python if you write in that language. It will be the easiest, but once you master it, SQLITE will become your best friend. It is amazing','Jason R. Pittman','Tips');");
		response = sqlite3_exec(db,sql.c_str(),NULL,0,NULL);
		if (response != SQLITE_OK){
				cerr << "Error with insert" << endl;
		}
		else{
				cout << "Data inserted successfully" << endl;
		};
	return 0;
};


static int sql_query(){

		sqlite3* db;
		int response;
		string sql("select * from BlogEntries");
		response = sqlite3_open("./db/blogs.db", &db);
		
		response = sqlite3_exec(db,sql.c_str(),callback,NULL,NULL);
		if (response != SQLITE_OK){
				cerr << "Error"<<endl;
		}
		return 0;
}

void program(){
		int action;				
		cin >> action;	
		if (action == 1){
			sql_insert();
		}
		else if (action == 2){
			sql_query();
		}
		else {
				cout << "entry not allowed\n";
		}
}
			


int main(){
		sqlite3* db;
		int response;
		response = sqlite3_open("./db/blogs.db",&db);
		if(response != SQLITE_OK){
				cerr << "Error occurred: File not opened"<< endl;
		}
		else {
				cout << "File Opened successfully \n";
		}
		cout << "**** Welcome to the Blog Editor ****\n\n" << endl;
		cout << "What Would you like to do?\n" << endl;
		cout << "1. Add entry \n2.query database\n";
		cout << ">";
		program();
		return 0;
}
