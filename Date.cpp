#include "stdafx.h"
#include "Date.h"

Date::Date(){}

Date::Date(int _year, int _month, int _day)
{
	this->year = _year;
	if(_month>=1 && _month<=12)
		this->month = _month;
	else {
		std::cout << "Error month value! default set to 1\n";
		this->month = 1;
	}
	int Maxday = getMaxday(_year,this->month);
	if (_day >= 1 && _day <= Maxday) {
		this->day = _day;
	}
	else {
		std::cout << "Error day value! default set to 1\n";
		this->day = 1;
	}
}


Date::~Date()
{
}

int Date::getDistance(Date baseDate) {
	if (this->year - baseDate.year >= 0) {
		if (this->year - baseDate.year >=1 || this->month - baseDate.month >= 0) {
			if (this->year - baseDate.year >=1 || this->month - baseDate.month >=1 || this->day - baseDate.day >= 0) {
				//your code here
				//year day
				int distance = 0;
				for (int y = baseDate.year; y < this->year; y++) {
					if ( checkLeap(y) ) {
						distance += 366;
					}
					else {
						distance += 365;
					}
				}
				//month day
				for (int m1 = 1; m1 < baseDate.month; m1++) {
					distance -= getMaxday(baseDate.year,m1);
				}
				for (int m2 = 1; m2 < this->month; m2++) {
					distance += getMaxday(this->year, m2);
				}
				//days' day
				distance -= baseDate.day;
				
				distance += this->day;

				return distance;
			}
		}
	}
	return -1;
}

void Date::addDay(int u)
{
	while (u > 0) {
		this->day++;
		if (this->day > getMaxday(this->year,this->month)) {
			this->day = 1;
			this->month += 1;
			if (this->month > 11) {
				this->year++;
				this->month = 1;
			}
		}
		--u;
	}
}

bool Date::checkLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	return false;
}

std::string Date::show()
{
	return  year + "-" + month + '-' + day;
}

int Date::getMaxday(int year,int month)
{
	if (year > 0 && month >= 1 && month < 12) {
		switch (month)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
		case 4: case 6: case 9: case 11: return 30;
		case 2: if (checkLeap(year)) return 29; else return 28;
		default:
			break;
		}
		
	}
		return 0;
	
}

