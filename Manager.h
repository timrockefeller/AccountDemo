#pragma once
#include "stdafx.h"



class Manager
{
public:
	Manager();
	Manager(Date);
	~Manager();

	
	///Time Manager
	//中央银行基准时间
	
	Date now = Date(2010, 1, 1);
	
	///User Manager
	int n_User = 0;
	std::vector<BaseAccount*> userList;
	
	int newAccount(AccountType, Date, std::string);
	
	///Command setting
	

	///File Manager
	const std::string DATA_PATH = "userdata.txt";
	void loadHistory();
	void log(std::string);

private:
	bool _RUN_FLAG = false;
	bool _COUT_MUTE = false;

	Date baseTime = Date(2010, 1, 1);
	void setTime(std::string);
	//void init();
	void Run();
	bool command(std::string);
	std::string helpmessage = //vetory
"\
add(a) [s|c] [username] : Add Account with username, return Card ID(important)\n\
deposit(d) [ID] [amount]\n\
withdraw(w) [ID] [amount]\n\
show(s) [ID] : show information of the account\n\
ls : list all Account\n\
exit : Save and exit\n\
";
	BaseAccount* getAccountById(int);
};
