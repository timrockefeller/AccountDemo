#pragma once
#include "BaseAccount.h"
class Account_Saving :
	public BaseAccount
{
public:
	Account_Saving();
	Account_Saving(Date,std::string);
	~Account_Saving();

	void deposit(Date, double, std::string);

	void withdraw(Date, double, std::string);

	const void show();

	//override
	int settleTime = 350;
	double rate = 0.015;
	
	///amount setting

	//void deposit(Date, double,std::string);

	//void withdraw(Date, double, std::string);
};

