// AccountDemo.cpp:
//

#include "stdafx.h"


int main()
{
	///insert **NOW** every initialization
	struct tm t;
	time_t now;
	time(&now);
	localtime_s(&t, &now);
	Manager manager = Manager(Date(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday));
    return 0;
}


