#ifndef __ADMIN_HPP__
#define __ADMIN_HPP__

#include "User.hpp"
#include "IAuthenticate.hpp"
#include "ICreate.hpp"
#include "IDelete.hpp"
#include <functional>

class Admin : public User ,ICreate, IDelete
{
public:
	explicit Admin(std::string name, std::string password ,Bank& bank);
	void CreateAccount(int customer_id ,std::string type) override;
	void DeleteAccount(int account_id) override;
	void Withdraw(int account_id, double amount) override;
	void Deposit(int account_id, double amount) override;
	void DisplayAccount(int account_id) override;
	void Operate(int operation);
	void Welcome();
	~Admin();

private:
	std::unordered_map<int, std::function<void()>> m_operations;

};

#endif

