#ifndef __IDEPOSIT_HPP__
#define __IDEPOSIT_HPP__

class IDeposit
{
public:
	virtual void Deposit(int account_id, double amount) = 0;
};

#endif

