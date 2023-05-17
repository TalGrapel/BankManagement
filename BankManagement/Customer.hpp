#ifndef __CUSTOMER_HPP__
#define __CUSTOMER_HPP__

#include "User.hpp"
#include "IAuthenticate.hpp"
#include <functional>
#include <unordered_map>

class Customer : public User
{
public:
	explicit Customer(std::string name, std::string password ,Bank &bank);
	void Withdraw(int account_id, double amount) override;
	void Deposit(int account_id, double amount) override;
	void DisplayAccount(int account_id) override;
	void Operate(int operation);
	void Welcome();
	void ValidateAccount(int account_id);
	~Customer();

private:
	std::unordered_map<int, std::function<void()>> m_operations;
};

#endif // !__CUSTOMER_HPP__
