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
	int id;///�˻�id
	std::string uid;
	Date createDate;

	AccountType accountType;

	double balance=0;///���
	double rate=0;///���ν�������
	int settleTime=30;///��������

	//AccountRecord historyRecord[];

	Accumulator acc;///�ۼ�����/ծ��
	///impletment function
	std::string getUid();
	double getBalance();
	double getRate();


	///amount settlement
	virtual void deposit(Date, double, std::string) {}

	virtual void withdraw(Date, double, std::string) {}

	void record(Date, double, std::string);

	void settle(Date);

	///display

	virtual const void show() {}

};

