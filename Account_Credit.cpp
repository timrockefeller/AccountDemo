#include "stdafx.h"

Account_Credit::Account_Credit(){}
Account_Credit::Account_Credit(Date _createDate,std::string _uid)
{
	this->createDate = _createDate;
	this->acc = Accumulator(_createDate);
	this->uid = _uid;
	this->balance = 0;
	this->settleTime = 30;
	this->rate = 0.005;
}


Account_Credit::~Account_Credit()
{
}

void Account_Credit::deposit(Date _date, double _amount, std::string _disc)
{
	if (-_amount + this->balance + this->acc.value > 0) {
		if (_amount > this->acc.value) {
			this->acc.value = 0;
			this->balance -= - this->acc.value + _amount;
		}
		else {
			this->acc.value -= _amount;
		}
	}
	else {
		//Error : over Stored
		std::cout << "Error : Over Stored (you have enough money to retire)" << std::endl;
		std::cout << "You have " << (int)(this->balance * 100 + 0.5) / 100.0 << " in using" << std::endl;
	}
}

void Account_Credit::withdraw(Date _date, double _amount, std::string _disc)
{
	if (_amount + this->balance + this->acc.value <= credit) {
		this->record(_date, _amount, _disc);
	}
	else {
		//Error : overwithdraw
		std::cout << "Error : overwithdraw" << std::endl;
	}
}

const void Account_Credit::show() {
	//this->settle();
	std::cout << "log of account " << this->getUid()<<std::endl;
	std::cout << "Avalable Credit : " << (int)((this->credit - this->balance - this->acc.value) * 100 + 0.5) / 100.0 << std::endl;
	std::cout << "Used Credit : " << (int)(this->balance * 100 + 0.5) / 100.0 << std::endl;
	std::cout<<"Accumulate : "<< (int)(this->acc.value * 100 + 0.5) / 100.0 << std::endl;
}