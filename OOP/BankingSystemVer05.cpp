#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN=20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

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
    void Deposit(int money)
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
        int id;
        char name[NAME_LEN];
        int balance;

        cout<<"[Make Account]"<<endl;
        cout<<"Account ID: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
        cout<<"Initial Deposit: ";
        cin>>balance;
        cout<<endl;

        accArr[accNum++]=new Account(id, balance, name);
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
