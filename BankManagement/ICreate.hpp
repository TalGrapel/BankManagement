#ifndef __ICREATE_HPP__
#define __ICREATE_HPP__

#include <string>

class ICreate
{
public:
	virtual void CreateAccount(int customer_id ,std::string type) = 0;
};

#endif // __ICREATE_HPP__
