#pragma once
#include "BaseAccount.h"
class Account_Saving :
	public BaseAccount
{
public:
	Account_Saving();
	~Account_Saving();

	///amount setting

	void deposit(Date, double,std::string);

	void withdraw(Date, double, std::string);
};

