#define FMT_HEADER_ONLY
#include <iostream>
#include <ctime>
#include "core.h"

void today(){
		time_t now = time(0);
		char* date_time = ctime(&now);
		std::cout << date_time << std::endl;
}




int main()
{
		std::string date;
		std::string title;
		std::string blogmsg;
		std::string author {"Jason R. Pittman"};
		std::string subject;
		std::cin >> date >> title >> blogmsg >> subject;
		std::string sql = fmt::format("'{}','{}','{}','{}','{}');",date,title,blogmsg,author,subject);
		std::cout << sql << std::endl;
		return 0;
}



