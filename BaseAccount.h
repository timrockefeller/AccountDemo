#pragma once
#include "stdafx.h"
#include <string.h>
class BaseAccount
{
public:
	BaseAccount();
	~BaseAccount();
	int id;///账户id
	Date createDate;

	double balance;///余额
	double rate;///年利率

	//AccountRecord historyRecord[];

	Accumulator acc;///累计利润/债务
	///impletment function
	int getId();
	double getBalance();
	double getRate();


	///amount settlement

	void record(Date, double, std::string);

	void settle(Date date);

	///display
	//virtual void show();

};

