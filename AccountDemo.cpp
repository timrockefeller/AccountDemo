// AccountDemo.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//中央银行基准时间
Date baseTime(2010, 1, 1);
Account_Credit creditUser[100];
int n_creditUser = 0;
Account_Saving savingUser[100];
int n_savingUser = 0;
enum AccountType {
	CreditAccount,
	SavingAccount
};
int newAccount(AccountType type,Date createDate,std::string uid) {
	switch (type)
	{
	case CreditAccount:
		creditUser[n_creditUser] = Account_Credit(createDate,uid);
		creditUser[n_creditUser].id = n_creditUser;
		return n_creditUser++;
	case SavingAccount:
		savingUser[n_savingUser] = Account_Saving(createDate, uid);
		savingUser[n_savingUser].id = n_savingUser;
		return n_creditUser++;
	default:
		break;
	}
	return -1;
}

int main()
{
	//steps
	Date now(2018, 1, 3);
	int id = newAccount(CreditAccount, now, "TimRockefeller");

	creditUser[id].show();
	creditUser[id].withdraw(now, 9588, "By iPhone X");
	
	//several day passed
	now = Date(2018, 3, 6);
	creditUser[id].settle(now);
	creditUser[id].show();
    return 0;
}


