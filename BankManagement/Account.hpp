#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <string>

class Account
{
public:
	explicit Account(std::string type, std::string name);
	int GetId();
	std::string GetType();
	double GetBalance();
	void Deposit(double amount);
	void Withdraw(double amount);
	void DisplayDetails();
	std::string GetName();

private:
	int m_id;
	double m_balance;
	std::string m_type;
	std::string m_name;
	static int m_counter;
	static void IncreaseCounter();
	static int GetCounter();
};

#endif

