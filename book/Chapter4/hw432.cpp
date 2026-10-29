#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };

    void ShowPositionInfo(int pos)
    {
        switch(pos)
        {
            case CLERK:
                cout<<"CLERK"<<endl;
                break;
            case SENIOR:
                cout<<"SENIOR"<<endl;
                break;
            case ASSIST:
                cout<<"ASSIST"<<endl;
            case MANAGER:
                cout<<"MANAGER"<<endl;
        }
    }
}

class NameCard
{
private:
    char * name;
    char * company;
    char * phone;
    int position;
public:
    NameCard(const char * manName, const char * comName, const char *manPhone, int pos)
        : position(pos)
    {
        int lenName = strlen(manName) + 1;
        name = new char[lenName];
        strcpy(name, manName);
        int lenCom = strlen(comName) + 1;
        company = new char[lenCom];
        strcpy(company, comName);
        int lenPhone = strlen(manPhone) + 1;
        phone = new char[lenPhone];
        strcpy(phone, manPhone);
    }
    void ShowNameCardInfo() const
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Company: "<<company<<endl;
        cout<<"Phone number: "<<phone<<endl;
        cout<<"Position: "; 
        COMP_POS::ShowPositionInfo(position);
        cout<<endl;
    }
    ~NameCard()
    {
        delete []name;
        delete []company;
        delete []phone;
        cout<<"called destructor!"<<endl;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}