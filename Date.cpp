#include "stdafx.h"
#include "Date.h"

int monthSet[] = { 31, 28, 31, 30, 31,30,31,31,30,31,30,31 };
Date::Date(){}

Date::Date(int _year, int _month, int _day)
{
	this->year = _year;
	this->month = _month;
	this->day = _day;
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
				
				if (checkLeap(baseDate.year))  monthSet[1] = 29; else monthSet[1] = 28;
				for (int m = 0; m < baseDate.month - 1; m++) {
					distance -= monthSet[m];
				}
				if (checkLeap(this->year)) monthSet[1] = 29; else monthSet[1] = 28;
				for (int m2 = 0; m2 < this->month -1; m2++) {
					distance += monthSet[m2];
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
		if (this->day > monthSet[this->month - 1]) {
			this->day = 1;
			this->month += 1;
			if (this->month > 11) {
				this->year++;
				if (checkLeap(this->year)) monthSet[1] = 29; else monthSet[1] = 28;
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

