#include "stdafx.h"


Manager::Manager()
{
	this->fio.loadHistory();
}


Manager::~Manager()
{
}

int Manager::newAccount(AccountType type, Date createDate, std::string uid)
{
	switch (type)
	{
	case CreditAccount:
		userList[n_User] = Account_Credit(createDate, uid);
		userList[n_User].id = n_User;
		return n_User++;
	case SavingAccount:
		userList[n_User] = Account_Saving(createDate, uid);
		userList[n_User].id = n_User;
		return n_User++;
	default:
		break;
	}
	return -1;
}

void Manager::command(std::string)
{
}
