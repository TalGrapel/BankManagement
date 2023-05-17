#ifndef __USER_HPP__
#define __USER_HPP__

#include <string>
#include "IDisplay.hpp"
#include "IDeposit.hpp"
#include "IWithdraw.hpp"
#include "IAuthenticate.hpp"
#include "Bank.hpp"

class Bank;
class User : public IWithdraw, IDeposit ,IDisplay ,IAuthenticate
{
public:
	explicit User(std::string name ,std::string password, Bank &bank);
	std::string GetUserName();
	std::string GetPassword();
	bool Authenticate(std::string password) override;
	int GetID();
	virtual ~User() = 0;
protected:
	Bank &GetBank();

private:
	int m_id;
	std::string m_name;
	std::string m_password;
	Bank &m_bank;
	static int m_counter;
	static void IncreaseCounter();
	static int GetCounter();
};

#endif

