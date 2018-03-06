#include "stdafx.h"
#include "Account_Saving.h"


Account_Saving::Account_Saving(){}
Account_Saving::Account_Saving(Date _createDate,std::string _uid){
	this->createDate = _createDate;
	this->acc = Accumulator(_createDate);
	this->uid = _uid;
}
Account_Saving::~Account_Saving(){}

void Account_Saving::deposit(Date _date, double _amount, std::string desc)
{
	this->record(_date, _amount, desc);
}
void Account_Saving::withdraw(Date _date, double _amount, std::string desc)
{
	if (this->balance + this->acc.value - _amount >= 0) {
		if (_amount > this->acc.value)
		{
			this->record(_date, -_amount+ this->acc.value, desc);
			this->acc.value = 0;
		}
		else {
			this->acc.value -= _amount;
		}
	}
	else {
		//Error : overwithdraw
	}
}
