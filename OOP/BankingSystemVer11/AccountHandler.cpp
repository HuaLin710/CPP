#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::ShowMenu(void) const
{
    cout<<"-----Menu------"<<endl;
    cout<<"1. Make Account"<<endl;
    cout<<"2. Deposit"<<endl;
    cout<<"3. Withdraw"<<endl;
    cout<<"4. Show All Accounts"<<endl;
    cout<<"5. Exit"<<endl;
}

void AccountHandler::MakeAccount(void)
{
    int sel;
    cout<<"[Select Account Type]"<<endl;
    cout<<"1. Normal Account 2. High Credit Account"<<endl;
    cout<<"Select: ";
    cin>>sel;

    if(sel==NORMAL)
    {
        MakeNormalAccount();
    }
    else
    {
        MakeCreditAccount();
    }
}

void AccountHandler::MakeNormalAccount(void)
{
    int id;
    String name;
    int balance;
    int interRate;

    cout<<"[Normal Account Creation]"<<endl;
    cout<<"Account ID: "; cin>>id;
    cout<<"Customer Name: "; cin>>name;
    cout<<"Deposit Amount: "; cin>>balance;
    cout<<"Interest Rate: "; cin>>interRate;
    cout<<endl;

    accArr[accNum++]=new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
    int id;
    String name;
    int balance;
    int interRate;
    int creditLevel;

    cout<<"[High Credit Account Creation]"<<endl;
    cout<<"Account ID: "; cin>>id;
    cout<<"Customer Name: "; cin>>name;
    cout<<"Deposit Amount: "; cin>>balance;
    cout<<"Interest Rate: "; cin>>interRate;
    cout<<"Credit Level (1 to A, 2 to B, 3 to C): "; cin>>creditLevel;
    cout<<endl;

    switch(creditLevel)
    {
    case 1:
        accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
        break;
    case 2:
        accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
        break;
    case 3:
        accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
    }
}

void AccountHandler::DepositMoney(void)
{
    int id;
    int money;
    cout<<"[Deposit]"<<endl;
    cout<<"Account ID: "; cin>>id;

    while(true)
    {
        cout<<"Deposit amount: "; cin>>money;
        try
        {
            for(int i=0; i<accNum; i++)
            {
                if(accArr[i]->GetAccID()==id)
                {
                    accArr[i]->Deposit(money);
                    cout<<"Deposit completed"<<endl<<endl;
                    return;
                }
            }
            cout<<"This account does not exist"<<endl<<endl;
        }
        catch(MinusException& expn)
        {
            expn.ShowExceptionReason();
            cout<<"Enter deposit money again."<<endl;
        }
    }
}

void AccountHandler::WithdrawMoney(void)
{
    int id;
    int money;
    cout<<"[Withdraw]"<<endl;
    cout<<"Account ID: "; cin>>id;

    while(true)
    {
        cout<<"Withdraw amount: "; cin>>money;
        try
        {
            for(int i=0; i<accNum; i++)
            {
                if(accArr[i]->GetAccID()==id)
                {
                    accArr[i]->Withdraw(money);
                    cout<<"Withdraw completed"<<endl<<endl;
                    return;
                }
            }
            cout<<"This account does not exist"<<endl<<endl;
            return;
        }
        catch(MinusException& expn)
        {
            expn.ShowExceptionReason();
            cout<<"Enter withdraw money again."<<endl;
        }
    }
}

AccountHandler::AccountHandler() : accNum(0)
{}

void AccountHandler::ShowAllAccInfo(void) const
{
    for(int i=0; i<accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout<<endl;
    }
}

AccountHandler::~AccountHandler()
{
    for(int i=0; i<accNum; i++)
    {
        delete accArr[i];
    }
}


