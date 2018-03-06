#pragma once
#include "stdafx.h"
#include <string.h>
class BaseAccount
{
public:
	BaseAccount();
	~BaseAccount();
	int id;///账户id
	std::string uid;
	Date createDate;

	double balance;///余额
	double rate;///单次结算利率
	int settleTime;///结算周期

	//AccountRecord historyRecord[];

	Accumulator acc;///累计利润/债务
	///impletment function
	std::string getUid();
	double getBalance();
	double getRate();


	///amount settlement

	void record(Date, double, std::string);

	void settle(Date);

	///display

	virtual void show() const = 0;

};

