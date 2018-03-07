#include "stdafx.h"

Account_Saving::Account_Saving(){}
Account_Saving::Account_Saving(Date _createDate,std::string _uid)
{
	this->createDate = _createDate;
	this->acc = Accumulator(_createDate);
	this->uid = _uid;
	this->balance = 0;
	this->settleTime = 300;
	this->rate = 0.045;
}


Account_Saving::~Account_Saving()
{
}

void Account_Saving::deposit(Date _date, double _amount, std::string _disc="")
{
	this->record(_date, _amount, _disc);
	std::cout << "Depositted " << (int)(_amount * 100 + 0.5) / 100.0 << std::endl;
}
void Account_Saving::withdraw(Date _date, double _amount, std::string _disc="")
{
	if (this->balance + this->acc.value - _amount >= 0) {
		if (_amount > this->acc.value)
		{
			this->record(_date, -_amount+ this->acc.value, _disc);
			this->acc.value = 0;
		}
		else {
			this->acc.value -= _amount;
		}
		std::cout << "You withdrawed " << _amount << " for " << _disc << std::endl;
	}
	else {
		//Error : overwithdraw
		std::cout << "Overwithdraw! You dont have enough money. Use \"show UID\" to check your balance.\n";
	}
}

const void Account_Saving::show() {
	//this->settle();
	std::cout << "log of account " << this->getUid() << std::endl;
	std::cout << "Balance : " << (int)(this->balance * 100 + 0.5) / 100.0 << std::endl;
	std::cout << "Accumulate : " << (int)(this->acc.value * 100 + 0.5) / 100.0 << std::endl;
}