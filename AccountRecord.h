#pragma once
#include "stdafx.h"
#include<string>
class AccountRecord
{
public:
	Date date;
	double amount;
	std::string describtion;
	
	AccountRecord(Date, double, std::string);
	~AccountRecord();
};

