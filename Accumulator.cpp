#include "stdafx.h"



Accumulator::Accumulator() {///forbiden to use!!!!
	this->value = 0;
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
