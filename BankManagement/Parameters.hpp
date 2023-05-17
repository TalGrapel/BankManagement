#ifndef __PARAMETERS_HPP__
#define __PARAMETES_HPP__

#include <string>
class Bank;

class Parameters
{
public:
	Parameters(std::string name, std::string password, Bank& bank);
	std::string GetName();
	std::string GetPassword();
	Bank& GetBank();
private:
	std::string m_name;
	std::string m_password;
	Bank& m_bank;
};

#endif // __PARAMETERS_HPP__
