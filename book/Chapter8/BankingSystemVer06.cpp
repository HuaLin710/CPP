#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN=20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};
enum {NORMAL=1, CREDIT=2};

//Entity class
class Account
{
private:
    int accID;
    int balance;
    char *cusName;
public:
    Account(int ID, int money, char *name) : accID(ID), balance(money)
    {
        cusName=new char[strlen(name)+1];
        strcpy(cusName, name);
    }
    Account(const Account &ref) : accID(ref.accID), balance(ref.balance)
    {
        cusName=new char[strlen(ref.cusName)+1];
        strcpy(cusName, ref.cusName);
    }

    int GetAccID() const
    {
        return accID;
    }
    virtual void Deposit(int money)
    {
        balance+=money;
    }
    int Withdraw(int money)
    {
        if(balance<money)
            return 0;
        balance-=money;
        return money;
    }
    void ShowAccInfo() const
    {
        cout<<"Account ID: "<<accID<<endl;
        cout<<"Name: "<<cusName<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    ~Account()
    {
        delete []cusName;
    }
};

class NormalAccount : public Account
{
private:
    int interRate;
public:
    NormalAccount(int ID, int money, char *name, int rate) : Account(ID, money, name), interRate(rate)
    {}
    virtual void Deposit(int money)
    {
        Account::Deposit(money);
        Account::Deposit(money*(1+interRate/100.0));
    }
};

class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;
public:
    HighCreditAccount(int ID, int money, char *name, int rate, int special)
        : NormalAccount(ID, money, name, rate), specialRate(special)
    {}
    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money);
        Account::Deposit(money*(specialRate/100.0));
    }
};

//Control class
class AccountHandler
{
private:
    Account *accArr[100];
    int accNum;
public:
    AccountHandler() : accNum(0)
    {}
    void ShowMenu(void) const
    {
        cout<<"-----Menu-----"<<endl;
        cout<<"1. Make Account"<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. Withdraw"<<endl;
        cout<<"4. Inquire"<<endl;
        cout<<"5. Exit"<<endl;
    }
    void MakeAccount(void)
    {
        int sel;
        cout<<"[select account type]"<<endl;
        cout<<"1. Normal Account"<<endl;
        cout<<"2. Credit Account"<<endl;
        cout<<"Select: ";
        cin>>sel;

        if(sel==NORMAL)
            MakeNormalAccount();
        else
        {
            if(sel==CREDIT)
                MakeCreditAccount();
            else
                cout<<"Wrong selection!"<<endl;
        }
    }
    void DepositMoney(void)
    {
        int id;
        int money;
        cout<<"[Deposit]"<<endl;
        cout<<"Account ID: ";
        cin>>id;
        cout<<"Deposit: ";
        cin>>money;
        cout<<endl;

        for(int i=0; i<accNum; i++)
        {
            if(accArr[i]->GetAccID()==id)
            {
                accArr[i]->Deposit(money);
                cout<<"Deposit completed!"<<endl;
                return;
            }
        }
        cout<<"Account not found!"<<endl;
    }
    void WithdrawMoney(void)
    {
        int id;
        int money;
        cout<<"[Withdraw]"<<endl;
        for (int i=0; i<accNum; i++)
        {
            if(accArr[i]->GetAccID()==id)
            {
                if(accArr[i]->Withdraw(money)==0)
                {
                    cout<<"Not enough balance!"<<endl;
                    return;
                }
                accArr[i]->Withdraw(money);
                cout<<"Withdraw completed!"<<endl<<endl;
                return;
            }
        }
        cout<<"Account not found!"<<endl<<endl;
    }
    void ShowAllAccInfo(void) const
    {
        for(int i=0; i<accNum; i++)
        {
            accArr[i]->ShowAccInfo();
            cout<<endl;
        }
    }
    ~AccountHandler()
    {
        for(int i=0; i<accNum; i++)
        {
            delete accArr[i];
        }
    }
protected:
    void MakeNormalAccount(void)
    {
        int id;
        char name[NAME_LEN];
        int balance;
        int interRate;

        cout<<"[Make Noral Account]"<<endl;
        cout<<"Account ID: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
        cout<<"Initial Deposit: ";
        cin>>balance;
        cout<<"Interest rate: ";
        cin>>interRate;
        cout<<endl;

        accArr[accNum++]=new NormalAccount(id, balance, name, interRate);
    }
    void MakeCreditAccount(void)
    {
        int id;
        char name[NAME_LEN];
        int balance;
        int interRate;
        int creditLevel;

        cout<<"Make Credit Account]"<<endl;
        cout<<"Account ID: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
        cout<<"Initial Deposit: ";
        cin>>balance;
        cout<<"Interest rate: ";
        cin>>interRate;
        cout<<"Credit Level (1toA, 2toB, 3toC): ";
        cin>>creditLevel;
        cout<<endl;

        switch(creditLevel)
        {
        case LEVEL_A:
            accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
            break;
        case LEVEL_B:
            accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
            break;
        case LEVEL_C:
            accArr[accNum++]=new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
            break;
        default:
            cout<<"Wrong credit level!"<<endl;
        }
    }
};

int main(void)
{
    AccountHandler manager;
    int choice;

    while(1)
    {
        manager.ShowMenu();
        cout<<"Select: ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout<<"Illegal selection. "<<endl;
        }
    }
    return 0;
}
