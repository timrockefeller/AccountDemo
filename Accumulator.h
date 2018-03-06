#pragma once
#include "stdafx.h"
class Accumulator
{
public:
	Accumulator();
	Accumulator(Date);
	~Accumulator();
	
	Date lastSettle;
	Date lastUpdate;
	double value;
	double sum;
	int timePassed;
};

