#include "stdafx.h"
#include "Account_Saving.h"


Account_Saving::Account_Saving(){}


Account_Saving::~Account_Saving(){}
void Account_Saving::deposit(Date _date, double _amount, std::string desc)
{
	this->record(_date, _amount, desc);
}
void Account_Saving::withdraw(Date _date, double _amount, std::string desc)
{
	this->record(_date, -_amount, desc);
}
