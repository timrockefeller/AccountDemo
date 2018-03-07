#pragma once
#include "BaseAccount.h"
class Account_Credit :
	public BaseAccount
{
public:
	Account_Credit();
	Account_Credit(Date, std::string);
	~Account_Credit();

	void deposit(Date, double, std::string);

	void withdraw(Date, double, std::string);

	const void show();

	//override
	//int settleTime = 30;
	//double rate = 0.005;

	//addition
	double credit = 100000;

	///amount setting
	//void deposit(Date, double, std::string);

	//void withdraw(Date, double, std::string);

};

