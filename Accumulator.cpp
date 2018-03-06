#include "stdafx.h"



Accumulator::Accumulator() {///forbiden to use!!!!
	this->value = 0;
	this->lastUpdate = Date(0, 0, 0);
	this->lastSettle = Date(0, 0, 0);
}

Accumulator::Accumulator(Date date)
{
	this->lastSettle = date;
	this->lastUpdate = date;
	this->value = 0;
	this->sum = 0;
}


Accumulator::~Accumulator()
{
}
