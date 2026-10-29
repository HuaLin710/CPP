#include "Account.h"
#include "BankingCommonDecl.h"
#include "BankingException.h"

Account::Account(int ID, int money, String name)
    : accID(ID), balance(money)
{
    cusName=name;
}

int Account::GetAccID() const
{
    return accID;
}

void Account::Deposit(int money)
{
    if(money<0)
    {
        throw MinusException(money);
    }
    balance+=money;
}

int Account::Withdraw(int money)
{
    if(money<0)
    {
        throw MinusException(money);
    }

    if(balance<money)
    {
        throw InsuffException(balance, money);
    }

    balance-=money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout<<"Account ID: "<<accID<<endl;
    cout<<"Name: "<<cusName<<endl;
    cout<<"Balance: "<<balance<<endl;
}