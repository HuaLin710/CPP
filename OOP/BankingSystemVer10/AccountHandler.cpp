#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

void AccountHandler::ShowMenu() const
{
    cout<<"------------Menu------------"<<endl;
    cout<<"1. Create Account"<<endl;
    cout<<"2. Deposit"<<endl;
    cout<<"3. Withdraw"<<endl;
    cout<<"4. Show All Accounts Info"<<endl;
    cout<<"5. Exit"<<endl;
}

void AccountHandler::MakeAccount()
{
    int sel;
    cout<<"[Select Account Type]"<<endl;
    cout<<"1. Normal Account 2. High Credit Account"<<endl;
    cout<<"Select: "; cin>>sel;
    cout<<endl;

    switch(sel)
    {
        case 1:
            MakeNormalAccount();
            break;
        case 2:
            MakeCreditAccount();
            break;
        default:
            cout<<"Invalid Selection"<<endl;
            break;
    }
}

void AccountHandler::MakeNormalAccount(void)
{
    int id;
    String name;
    int balance;
    int interRate;

    cout<<"[Make Normal Account]"<<endl;
    cout<<"Account ID: ";
    cin>>id;
    cout<<"Name: ";
    cin>>name;
    cout<<"Deposit: ";
    cin>>balance;
    cout<<"Interest Rate: ";
    cin>>interRate;
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

    cout<<"Make Credit Account"<<endl;
    cout<<"Account ID: ";
    cin>>id;
    cout<<"Name: ";
    cin>>name;
    cout<<"Deposit: ";
    cin>>balance;
    cout<<"Interest Rate: ";
    cin>>interRate;
    cout<<"Credit Level: ";
    cin>>creditLevel;
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
        break;
    default:
        cout<<"Invalid Selection"<<endl;
    }
}

void AccountHandler::DepositMoney(void)
{
    int money;
    int id;
    cout<<"[Deposit]"<<endl;
    cout<<"Account ID: ";
    cin>>id;
    cout<<"Deposit Amount: ";
    cin>>money;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            accArr[i]->Deposit(money);
            cout<<"Deposit Completed"<<endl<<endl;
            return;
        }
    }
    cout<<"Invalid account!"<<endl;
}

void AccountHandler::WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"Withdraw"<<endl;
    cout<<"Account ID: ";
    cin>>id;
    cout<<"Withdraw Amount: ";
    cin>>money;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            if(accArr[i]->Withdraw(money)==0)
            {
                cout<<"Not enough balance."<<endl<<endl;
                return;
            }
            cout<<"Withdraw Completed"<<endl<<endl;
            return;
        }
    }
    cout<<"Invalid account!"<<endl<<endl;
}

AccountHandler::AccountHandler() : accNum(0)
{}

void AccountHandler::ShowAllAccInfo() const
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