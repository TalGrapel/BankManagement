#ifndef __IADD_HPP__
#define __IADD_HPP__

#include <string>

class IAdd
{
public:
	virtual void AddUser(std::string name, std::string password, std::string role) = 0;
};

#endif // !__IADD_HPP__
