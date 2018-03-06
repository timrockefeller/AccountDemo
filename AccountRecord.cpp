#include "stdafx.h"


AccountRecord::AccountRecord(Date _date, double _amount, std::string _desc)
{
	this->date = _date;
	this->amount = _amount;
	this->describtion = _desc;
}

AccountRecord::~AccountRecord()
{
}