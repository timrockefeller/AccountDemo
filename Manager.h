#pragma once
#include "stdafx.h"



class Manager
{
public:
	Manager();
	Manager(Date);
	~Manager();

	bool runflag = false;
	///Time Manager
	//中央银行基准时间
	
	Date now = Date(2010, 1, 1);
	
	///User Manager
	int n_User = 0;
	std::vector<BaseAccount> userList;
	
	int newAccount(AccountType, Date, std::string);
	
	///Command setting
	

	///File Manager
	FileIO fio;
private:
	Date baseTime = Date(2010, 1, 1);
	void setTime(std::string);
	//void init();
	void Run();
	void command(std::string);
	std::string helpmessage = //vetory
"add [s|c] [username]\tAdd Account with username, return Card ID(important)\n\
exit\tExit\n\
";
};
