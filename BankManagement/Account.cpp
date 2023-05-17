#include "Account.hpp"
#include <stdexcept>
#include <iostream>

int Account::m_counter = 1;

void Account::IncreaseCounter()
{
	++m_counter;
}

int Account::GetCounter()
{
	return m_counter;
}

Account::Account(std::string type, std::string name) : m_id(GetCounter()),m_balance(0), m_type(type), m_name(name)
{
	//empty on purpose
}

int Account::GetId()
{
	return m_id;
}

std::string Account::GetType()
{
	return m_type;
}

double Account::GetBalance()
{
	return m_balance;
}

void Account::Deposit(double amount)
{
	m_balance += amount;
}

void Account::Withdraw(double amount)
{
	if (amount > m_balance)
	{
		std::cout << "Amount is bigger than balance!";
		return;
	}

	m_balance -= amount;
}

void Account::DisplayDetails()
{
	std::cout << "Account details:" << std::endl;
	std::cout << "Account id: " << m_id << std::endl;
	std::cout << "Balance: " << m_balance << std::endl;
	std::cout << "Type: " << m_type << std::endl;
	std::cout << "Name: " << m_name << std::endl;
}

std::string Account::GetName()
{
	return m_name;
}

