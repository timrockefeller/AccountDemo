#pragma once
#include "stdafx.h"
class Date
{
public:
	Date();
	Date(int _year, int _month, int _day);
	~Date();

	int year;
	int month;
	int day;
	int getDistance(Date baseDate);
	void addDay(int);
	bool checkLeap(int year);

	std::string show();
};

