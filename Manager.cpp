#include "stdafx.h"
std::vector<std::string> splitString(const std::string& s, const std::string& c=" ") {
	std::vector<std::string> v;
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
	return v;
}

Manager::Manager()
{
	this->fio.loadHistory();
}


Manager::~Manager()
{
}

void Manager::setTime(std::string _Date)
{
	std::vector<std::string> _ = splitString(_Date, "-");
	if (_.size == 3) {
		this->now = Date(std::atoi(_[0].c_str()), std::atoi(_[1].c_str()), std::atoi(_[2].c_str()));
	}
	else {
		std::cout << "Error Time Form!\n";
	}
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

void Manager::command(std::string _)
{
	
	std::vector<std::string> _COM = splitString(_);
	if (_COM[0] == "add") {//add Account
		if (_COM[1] == "c") {
			this->newAccount(CreditAccount, this->now, _COM[2]);
		}
	}
}
