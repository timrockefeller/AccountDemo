#pragma once
#include "stdafx.h"

enum AccountType {
	CreditAccount,
	SavingAccount
};


class BaseAccount
{
public:
	//BaseAccount();
	~BaseAccount();
	int id;///账户id
	std::string uid;
	Date createDate;

	AccountType accountType;

	double balance=0;///余额
	double rate=0;///单次结算利率
	int settleTime=30;///结算周期

	//AccountRecord historyRecord[];

	Accumulator acc;///累计利润/债务
	///impletment function
	std::string getUid();
	double getBalance();
	double getRate();


	///amount settlement
	virtual void deposit(Date, double, std::string) = 0;

	virtual void withdraw(Date, double, std::string) = 0;

	void record(Date, double, std::string);

	void settle(Date);

	///display

	virtual const void show() = 0;

};

class Account_Null:public BaseAccount {
public:
	Account_Null() {
		this->id = -1;
	}
	void deposit(Date, double, std::string) {}
	void withdraw(Date, double, std::string) {}
	void const show() {}
};