#ifndef __BANK_HPP__
#define __BANK_HPP__

#include <unordered_map>
#include <string>
#include "User.hpp"
#include "Account.hpp"
#include "IDelete.hpp"
#include "IDeposit.hpp"
#include "IDisplay.hpp"
#include "ICreate.hpp"
#include "IWithdraw.hpp"
#include "IAdd.hpp"
#include "Factory.hpp"
#include "Parameters.hpp"


class User;

class Bank : public IDelete, IDeposit, IDisplay, ICreate, IWithdraw, IAdd
{
public:
	class Params;
	explicit Bank();
	void CreateAccount(int customer_id, std::string type) override;
	void Deposit(int account_id, double amount) override;
	void Withdraw(int account_id, double amount) override;
	void DeleteAccount(int account_id) override;
	void DisplayAccount(int account_id) override;
	void AddUser(std::string name, std::string password, std::string role) override;
	void AddFactoryMethod(std::string key, User *(*)(Parameters));
	bool ValidateAccount(int account_id, std::string name);
	User* Login(std::string name, std::string password);
	~Bank();

private:

	std::unordered_map<std::string, void(*)(User*)>m_operations;
	std::unordered_map<int, Account *> m_accounts;
	std::unordered_map<int, User *>m_users_by_id;
	std::unordered_map<std::string, User*> m_users_by_name;
	Factory<std::string, User, Parameters> *m_factory;

};


#endif // __BANK_HPP__
