#include <iostream>
#include <sqlite3.h>


using namespace std;



static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
		   cout << azColName[i]<< " : " << argv[i] << endl;
   }
   cout << endl;
   return 0;
}

static int sql_insert(){
		sqlite3 *db;
		int response;
		response = sqlite3_open("blogs.db", &db);
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
		response = sqlite3_open("blogs.db", &db);
		
		response = sqlite3_exec(db,sql.c_str(),callback,NULL,NULL);
		if (response != SQLITE_OK){
				cerr << "Error"<<endl;
		}
		return 0;
}




int main(){
		sqlite3* db;
		int response;
		response = sqlite3_open("blogs.db",&db);
		if(response != SQLITE_OK){
				cerr << "Error occurred: File not opened"<< endl;
		}
		else {
				cout << "File Opened successfully \n";
		}
//		sql_insert();
		sql_query();
		return 0;
}
