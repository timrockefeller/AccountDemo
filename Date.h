#pragma once
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
	bool checkLeap(int year);
};

