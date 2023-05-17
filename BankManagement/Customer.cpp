#include "Customer.hpp"
#include <iostream>

const int EXIT = 7;

Customer::Customer(std::string name, std::string password ,Bank& bank) :User(name, password, bank)
{
	m_operations[1] = [this]() {std::cout << "Please enter account_id and amount" << std::endl; int account; int amount; std::cout << "Account ID: "; std::cin >> account;
	std::cout << "\n"; std::cout << "Amount:";  std::cin >> amount; this->ValidateAccount(account); this->Deposit(account, amount); };
	m_operations[2] = [this]() {std::cout << "Please enter account_id and amount" << std::endl; int account; int amount; std::cout << "Account ID: "; std::cin >> account;
	std::cout << "\n"; std::cout << "Amount:"; std::cin >> amount; this->ValidateAccount(account); this->Withdraw(account, amount); };
	m_operations[3] = [this]() {std::cout << "Please enter account_id" << std::endl; int account; std::cout << "Account ID: "; std::cin >> account; this->ValidateAccount(account);
	this->DisplayAccount(account); };
}

void Customer::Withdraw(int account_id, double amount)
{
	GetBank().Withdraw(account_id, amount);
}

void Customer::Deposit(int account_id, double amount)
{
	GetBank().Deposit(account_id, amount);
}

void Customer::DisplayAccount(int account_id)
{
	GetBank().DisplayAccount(account_id);
}


void Customer::Operate(int operation)
{
	m_operations[operation]();
}

void Customer::Welcome()
{
	int operation = 0;
	while (operation != EXIT)
	{
		std::cout << "Choose operation: 1.Deposit, 2.Withdraw, 3.Display ,7. Exit" << std::endl;
		std::cin >> operation;
		if (operation != EXIT)
		{
			Operate(operation);
		}
	}
}

void Customer::ValidateAccount(int account_id)
{
	if (!GetBank().ValidateAccount(account_id, GetUserName()))
	{
		std::cout << "Invalid account id!" << std::endl;
		return;
	}
}

Customer::~Customer()
{
	//empty on purpose
}