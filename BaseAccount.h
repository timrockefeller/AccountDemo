#pragma once
#include "stdafx.h"
class BaseAccount
{
public:
	BaseAccount();
	~BaseAccount();
	int id;///�˻�id
	std::string uid;
	Date createDate;

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

	void record(Date, double, std::string);

	void settle(Date);

	///display

	//virtual void show() const = 0;

};

