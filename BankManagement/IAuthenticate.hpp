#ifndef __IAUTHENTICATE_HPP__
#define __IAUTHENTICATE_HPP__

#include <string>

class IAuthenticate
{
public:
	virtual bool Authenticate(std::string password) = 0;
};

#endif // __IAUTHENTICATE_HPP__
