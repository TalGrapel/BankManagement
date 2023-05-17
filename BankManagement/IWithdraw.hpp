#ifndef __IWITHDRAW_HPP__
#define __IWITHDRAW_HPP__


class IWithdraw
{
public:
	virtual void Withdraw(int account_id, double amount) = 0;
};

#endif // __IWITHDRAW_HPP__
