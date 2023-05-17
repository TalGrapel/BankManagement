#include "Admin.hpp"
#include <iostream>

const int EXIT = 7;

Admin::Admin(std::string name, std::string password, Bank& bank) : User(name, password, bank)
{
	m_operations[1] = [this]() {std::cout << "Please enter account_id and amount" << std::endl; int account; int amount; std::cout << "Account ID: "; std::cin >> account;
	std::cout << "\n"; std::cout << "Amount:";  std::cin >> amount; this->Deposit(account, amount); };
	m_operations[2] = [this]() {std::cout << "Please enter account_id and amount" << std::endl; int account; int amount; std::cout << "Account ID: "; std::cin >> account;
	std::cout << "\n"; std::cout << "Amount:"; std::cin >> amount; this->Withdraw(account, amount); };
	m_operations[3] = [this]() {std::cout << "Please enter account_id" << std::endl; int account; std::cout << "Account ID: "; std::cin >> account;
	this->DisplayAccount(account); };
	m_operations[4] = [this]() {std::cout << "Please enter customer_id and type" << std::endl; int customer_id; std::string type; std::cout << "Customer ID: ";  std::cin >> customer_id;
	std::cout << "Type: "; std::cin >> type;  this->CreateAccount(customer_id, type); };
	m_operations[5] = [this]() {std::cout << "Please enter account_id" << std::endl; std::cout << "Account ID: "; int account; std::cin >> account;
	this->DeleteAccount(account); };
}

void Admin::CreateAccount(int customer_id, std::string type)
{
	GetBank().CreateAccount(customer_id, type);
}

void Admin::DeleteAccount(int account_id)
{
	GetBank().DeleteAccount(account_id);
}

void Admin::Withdraw(int account_id, double amount)
{
	GetBank().Withdraw(account_id, amount);
}

void Admin::Deposit(int account_id, double amount)
{
	GetBank().Deposit(account_id, amount);
}

void Admin::DisplayAccount(int account_id)
{
	GetBank().DisplayAccount(account_id);
}

void Admin::Operate(int operation)
{
	m_operations[operation]();
}

void Admin::Welcome()
{
	int operation = 0;
	while (operation != EXIT)
	{
		std::cout << "Choose operation: 1.Deposit, 2.Withdraw, 3.Display, 4. Create Account, 5. Delete Account, 7. Exit" << std::endl;
		std::cin >> operation;
		if (operation != EXIT)
		{
			Operate(operation);
		}
	}
}

Admin::~Admin()
{
	//empty on purpose
}