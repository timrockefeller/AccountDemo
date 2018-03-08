#pragma once
#include "stdafx.h"
class AccountRecord
{
public:
	Date date;
	double amount;
	std::string describtion;
	
	AccountRecord();

	AccountRecord(Date, double, std::string);
	~AccountRecord();
};

