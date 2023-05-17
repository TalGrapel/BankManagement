#include "Bank.hpp"
#include <iostream>
#include "Admin.hpp"
#include "Customer.hpp"

Bank::Bank() :m_factory(Factory<std::string,User, Parameters>::GetInstance())
{
	//empty on purpose
}

void Bank::CreateAccount(int customer_id, std::string type)
{
	if (m_users_by_id.find(customer_id) == m_users_by_id.end())
	{
		std::cout << "Customer doesnt exist!" << std::endl;
		return;
	}

	Customer* cust = dynamic_cast<Customer*>(m_users_by_id[customer_id]);
	if (!cust)
	{
		std::cout << "Invalid customer id!" << std::endl;
		return;
	}

	Account* new_account = new Account(type, cust->GetUserName());
	m_accounts[new_account->GetId()] = new_account;

	std::cout << "Account created successfuly!" << std::endl;
}

void Bank::Deposit(int account_id, double amount)
{
	if (m_accounts.find(account_id) == m_accounts.end())
	{
		std::cout << "Account doesnt exists!" << std::endl;
		return;
	}
	std::cout << account_id << std::endl;

	m_accounts[account_id]->Deposit(amount);
}

void Bank::Withdraw(int account_id, double amount)
{
	if (m_accounts.find(account_id) == m_accounts.end())
	{
		std::cout << "Account doesnt exsits!" << std::endl;
		return;
	}

	m_accounts[account_id]->Withdraw(amount);
}

void Bank::DeleteAccount(int account_id)
{
	if (m_accounts.find(account_id) == m_accounts.end())
	{
		std::cout << "Account doesnt exists!" << std::endl;
		return;
	}

	Account* acc = m_accounts[account_id];
	delete acc;
	acc = nullptr;

	m_accounts.erase(account_id);

	std::cout << "Account deleted successfuly!" << std::endl;
}

void Bank::DisplayAccount(int account_id)
{
	if (m_accounts.find(account_id) == m_accounts.end())
	{
		std::cout << "Account doesnt exists!" << std::endl;
		return;
	}

	m_accounts[account_id]->DisplayDetails();
}

void Bank::AddUser(std::string name, std::string password, std::string role)
{
	User* new_user = m_factory->Create(role, Parameters(name, password, *this));
	std::cout << new_user->GetID() << std::endl;
	m_users_by_id[new_user->GetID()] = new_user;
	m_users_by_name[new_user->GetUserName()] = new_user;
}

void Bank::AddFactoryMethod(std::string key, User* (*func)(Parameters))
{
	m_factory->Add(key, func);
}

User* Bank::Login(std::string name, std::string password)
{
	if (m_users_by_name.find(name) == m_users_by_name.end())
	{
		std::cout << "User doesnt exsits!" << std::endl;
		return nullptr;
	}

	if (!m_users_by_name[name]->Authenticate(password))
	{
		std::cout << "Invalid name or password!" << std::endl;
		return nullptr;
	}

	return m_users_by_name[name];
}

bool Bank::ValidateAccount(int account_id, std::string name)
{
	if (m_accounts.find(account_id) == m_accounts.end())
	{
		std::cout << "Account doesnt exists!" << std::endl;
		return false;
	}
	if (m_accounts[account_id]->GetName() != name)
	{
		return false;
	}

	return true;
}

Bank::~Bank()
{
	for (auto it = m_accounts.begin(); it != m_accounts.end(); it++)
	{
		delete it->second;
		it->second = nullptr;
	}

	for (auto it = m_users_by_id.begin(); it != m_users_by_id.end(); it++)
	{
		delete it->second;
		it->second = nullptr;
	}

	for (auto it = m_users_by_name.begin(); it != m_users_by_name.end(); it++)
	{
		it->second = nullptr;
	}
}
