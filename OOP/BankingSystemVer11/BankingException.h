#ifndef __BANKINGEXCEPTION_H__
#define __BANKINGEXCEPTION_H__

#include <iostream>
using namespace std;

class MinusException
{
private:
    int exval;
public:
    MinusException(int val) : exval(val)
    {}
    void ShowExceptionReason(void) const
    {
        cout<<"Deposit/Withdraw amount "<<exval<<" is not valid."<<endl;
    }
};

class InsuffException
{
private:
    int balance;
    int reqval;
public:
    InsuffException(int val, int req) : balance(val), reqval(req)
    {}

    void ShowExceptionReason(void) const
    {
        cout<<"Insufficient balance. Balance: "<<balance<<", Required: "<<reqval<<endl;
    }
};

#endif