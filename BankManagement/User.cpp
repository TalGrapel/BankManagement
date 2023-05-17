#include "User.hpp"

int User::m_counter = 1;

void User::IncreaseCounter()
{
	++m_counter;
}

int User::GetCounter()
{
	return m_counter;
}

User::User(std::string name, std::string password, Bank& bank): m_id(GetCounter()), m_name(name), m_password(password), m_bank(bank)
{
	IncreaseCounter();
}

std::string User::GetUserName()
{
	return m_name;
}

std::string User::GetPassword()
{
	return m_password;
}

Bank& User::GetBank()
{
	return m_bank;
}

int User::GetID()
{
	return m_id;
}

bool User::Authenticate(std::string password)
{
	return GetPassword() == password;
}

User::~User()
{
	//empty on purpose
}
