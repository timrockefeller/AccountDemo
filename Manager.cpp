#include "stdafx.h"
std::vector<std::string> splitString(const std::string& s, const std::string& seperator =" ") {
	std::vector<std::string> result;
	typedef std::string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {
					++i;
					flag = 0;
					break;
				}
		}

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	if (result.size()) { return result; }
	result.push_back("");
	return result;
}

Manager::Manager()
{
	std::cout << "Loading system...\nPlease Insert Date of NOW (yyyy-mm-dd):\n";
	std::string dateS;
	std::cin >> dateS;
	this->setTime(dateS);
	this->fio.loadHistory();
	this->Run();
}
Manager::Manager(Date _date)
{
	std::cout << "Loading system...\n";
	std::cout << "Today is " << _date.year << "-" << _date.month << "-" << _date.day << ".\n";
	this->now = _date;
	this->fio.loadHistory();
	this->Run();
}

Manager::~Manager()
{
}

void Manager::setTime(std::string _Date)
{
	std::vector<std::string> _ = splitString(_Date, "-");
	this->now = Date(std::atoi(_[0].c_str()), std::atoi(_[1].c_str()), std::atoi(_[2].c_str()));
}

int Manager::newAccount(AccountType type, Date createDate, std::string uid)
{

	///Name use Check
	for (BaseAccount*  ba : userList) {
		if (uid == ba->uid) {
			std::cout << "Error : Username have been used!\n";
			return -1;
		}
	}
	std::cout << "Account Created: " << uid<<std::endl;
	switch (type)
	{
	case CreditAccount:
		userList.push_back(new Account_Credit(createDate, uid));
		userList[n_User]->id = n_User;
		break;
	case SavingAccount:
		userList.push_back(new Account_Saving(createDate, uid));
		userList[n_User]->id = n_User;
		break;
	default:
		break;
	}
	std::cout << "Your Account ID : " << n_User << std::endl;
	return n_User++;
}

void Manager::command(std::string _)
{
	try {
		std::vector<std::string> _COM = splitString(_);
		if (_ == "" || _COM[0] == "")return;
		BaseAccount*pba=NULL;
		Account_Credit*pca = NULL;
		Account_Saving*psa = NULL;
		if (_COM[0] == "add" || _COM[0] == "a") {//add Account
			if (_COM[1] == "c") {
				this->newAccount(CreditAccount, this->now, _COM[2]);
				return;
			}
			else if (_COM[1] == "s") {
				this->newAccount(SavingAccount, this->now, _COM[2]);
				return;
			}
			throw("unknow Account type.\n    \"s\" for Saving Account.\n    \"c\" for Credit Account\n");
		}
		else if (_COM[0] == "deposit" || _COM[0] == "d") {
			pba = this->getAccountById(std::atoi(_COM[1].c_str()));
			if (pba->id>=0) {
				pba->deposit(this->now, std::atof(_COM[2].c_str()), "");
				return;
			}
			throw("your id entered does not exist.");
		}
		else if (_COM[0] == "withdraw" || _COM[0] == "w") {
			pba = this->getAccountById(std::atoi(_COM[1].c_str()));
			if (pba->id >= 0) {
				pba->withdraw(this->now, std::atof(_COM[2].c_str()), "");
				return;
			}
			throw("your id entered does not exist.");
		}
		else if (_COM[0] == "show" || _COM[0] == "s") {
			pba = this->getAccountById(std::atoi(_COM[1].c_str()));
			if (pba->id >= 0) {
				pba->show();
				return;
			}
			throw("your id entered does not exist.");
		}
		else if (_COM[0] == "ls") {
			std::cout << "All Account Listed (" << userList.size() << ")\n";
			std::cout << "ID\tUsername\tAccountType\n";
			std::vector<BaseAccount*>::const_iterator ba;
			for (ba = this->userList.begin(); ba != this->userList.end();++ba) {
				if((*ba)->id>=0)
					std::cout << (*ba)->id << "\t" << (*ba)->uid << "\t" << ((*ba)->accountType == SavingAccount ? "SavingAccount" : "CreditAccount") << std::endl;
			}
			return;
		}
		else if (_COM[0] == "help" || _COM[0] == "?") {
			std::cout << "    Help Page\n" << this->helpmessage<<std::endl;
			return;
		}
		else if (_COM[0] == "exit") {
			this->runflag = false;
			std::cout << "Saved. Press any key to exit...";
			std::getchar();
			return;
		}
		throw("unknow Command " + _COM[0]);
	}
	catch (char *str)
	{
		std::cout << "Error : "<< str << std::endl;
	}
	catch (std::string str) 
	{
		std::cout << "Error : " << str << std::endl;
	}
	catch (int i)
	{
		std::cout << i << std::endl;
	}
}

BaseAccount* Manager::getAccountById(int _)
{
	std::vector<BaseAccount*>::const_iterator ba;
	for (ba = this->userList.begin(); ba != this->userList.end();++ba) {
		if (_ == (*ba)->id) {
			return  (*ba);
		}
	}
	return new Account_Null();
}


void Manager::Run()
{
	this->runflag = true;
	std::cout << "Input \"help\" or \"?\" to get further information..\n";
	while (runflag) {
		std::string _;
		std::cout << ">> ";
		std::getline(std::cin, _);
		this->command(_);
	}
}
