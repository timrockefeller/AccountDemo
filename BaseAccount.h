#pragma once
#include "stdafx.h"
#include <string.h>
class BaseAccount
{
public:
	BaseAccount();
	~BaseAccount();
	int id;///�˻�id
	Date createDate;

	double balance;///���
	double rate;///������

	//AccountRecord historyRecord[];

	Accumulator acc;///�ۼ�����/ծ��
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

