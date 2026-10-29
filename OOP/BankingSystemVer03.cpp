#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};    

class Account
{
private:
    int accID;
    int balance;
    char *cusName;
public:
    Account(int ID, int money, char *name): accID(ID), balance(money)
    {
        cusName=new char[strlen(name)+1];
        strcpy(cusName, name);
    }

    Account(const Account& ref) : accID(ref.accID), balance(ref.balance)
    {
        cusName=new char[strlen(ref.cusName)+1];
        strcpy(cusName, ref.cusName);
    }

    int GetAccID()
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

    void ShowAccInfo()
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

Account *accArr[100];
int accNum=0;

int main(void)
{
    int choice;
    while(1)
    {
        ShowMenu();
        cout<<"Select menu: ";
        cin>>choice;
        cout<<endl;

        switch(choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            for(int i=0; i<accNum; i++)
                delete accArr[i];
            return 0;
        default:
            cout<<"Illegal slection."<<endl;
        }
    }

    return 0;
}

void ShowMenu(void)
{
    cout<<"-----Menu-----"<<endl;
    cout<<"1. Make Account"<<endl;
    cout<<"2. Deposit"<<endl;
    cout<<"3. Withdraw"<<endl;
    cout<<"4. Show All Account Info"<<endl;
    cout<<"5. Exit"<<endl;
}

void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[Make Account]:"<<endl;
    cout<<"Account ID: ";
    cin>>id;
    cout<<"Name: ";
    cin>>name;
    cout<<"Deposit amount: ";
    cin>>balance;
    cout<<endl;

    accArr[accNum++]=new Account(id, balance, name);
}

void DepositMoney(void)
{
    int money;
    int id;
    cout<<"[Deposit]"<<endl;
    cout<<"Account ID: ";
    cin>>id;
    cout<<"Deposit amount: ";
    cin>>money;
    
    for(int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            accArr[i]->Deposit(money);
            cout<<"Deposit completed."<<endl;
            return;
        }
    }
    cout<<"Account ID not found."<<endl;
}

void WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"[Withdraw]"<<endl;
    cout<<"Account ID: ";
    cin>>id;
    cout<<"Withdraw amount: ";
    cin>>money;

    for (int i=0; i<accNum; i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            if(accArr[i]->Withdraw(money)==0)
            {
                cout<<"Balance not enough."<<endl<<endl;
                return;
            }

            cout<<"Withdraw completed."<<endl<<endl;
            return;
        }
    }
    cout<<"Account ID not found."<<endl<<endl;
}

void ShowAllAccInfo(void)
{
    for(int i=0; i<accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout<<endl;
    }
}
