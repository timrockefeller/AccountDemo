#pragma once
#include "stdafx.h"
class Accumulator
{
public:
	Accumulator();
	Accumulator(Date);
	~Accumulator();
	
	Date lastUpdate;
	double value;

};

