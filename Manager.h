#pragma once
#include "stdafx.h"

enum AccountType {
	CreditAccount,
	SavingAccount
};

class Manager
{
public:
	Manager();
	~Manager();
	
	///Time Manager
	//中央银行基准时间
	Date baseTime = Date(2010, 1, 1);
	
	
	///User Manager
	int n_User = 0;
	std::vector<BaseAccount> userList;
	
	int newAccount(AccountType, Date, std::string);
	
	///Command setting
	void command(std::string);

	///File Manager
	FileIO fio;

	//void init();
};
