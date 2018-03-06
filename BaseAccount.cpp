#include "stdafx.h"



BaseAccount::BaseAccount(){}
BaseAccount::~BaseAccount(){}

int BaseAccount::getId(){return this->id;}
double BaseAccount::getBalance(){return this->balance;}
double BaseAccount::getRate(){return this->rate;}



void BaseAccount::record(Date date, double amount, std::string describtion)
{

}

void BaseAccount::settle(Date date)
{
}
