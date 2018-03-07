#include "stdafx.h"



//BaseAccount::BaseAccount(){}
BaseAccount::~BaseAccount(){}

std::string BaseAccount::getUid(){return this->uid;}
double BaseAccount::getBalance(){return this->balance;}
double BaseAccount::getRate(){return this->rate;}



void BaseAccount::record(Date _date, double _amount, std::string _desc)
{
	_amount = (int)(_amount * 100 + 0.5) / 100.0;
	int passedTime = _date.getDistance(this->acc.lastUpdate);
	if (passedTime == 0) {
		this->acc.sum += _amount;
	} else {
		this->acc.sum += passedTime * this->balance;
	}
	this->acc.timePassed += passedTime;
	this->balance += _amount;
	this->settle(_date);
}

void BaseAccount::settle(Date date)
{
	while (date.getDistance(this->acc.lastSettle) >= this->settleTime) {
		if (this->acc.lastUpdate.getDistance(this->acc.lastSettle) > 0) {
			this->acc.sum += this->balance * this->acc.lastUpdate.getDistance(this->acc.lastSettle);
		}
		else {
			this->acc.sum += this->balance * this->settleTime;
		}
		this->acc.value += (this->acc.sum * 1.0 / this->settleTime) * this->rate;
		///reset
		this->acc.lastSettle.addDay(this->settleTime);
		this->acc.lastUpdate = this->acc.lastSettle;
		this->acc.sum = 0;
	}
	this->acc.value = (int)(this->acc.value * 100 + 0.5) *1.0 / 100.0;
}
