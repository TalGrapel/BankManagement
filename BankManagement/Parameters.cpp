#include "Parameters.hpp"

Parameters::Parameters(std::string name, std::string password, Bank& bank) : m_name(name), m_password(password), m_bank(bank)
{
	//empty on purpose
}

std::string Parameters::GetName()
{
	return m_name;
}

std::string Parameters::GetPassword()
{
	return m_password;
}

Bank& Parameters::GetBank()
{
	return m_bank;
}
