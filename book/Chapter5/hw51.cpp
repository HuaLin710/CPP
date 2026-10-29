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
                break;
            case MANAGER:
                cout<<"MANAGER"<<endl;
        }
    }
};

class NameCard
{
private:
    char *name;
    char *company;
    char *phone;
    int position;
public:
    NameCard(char *name, char *company, char *phone, int pos)
        : position(pos)
    {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this->company = new char[strlen(company)+1];
        strcpy(this->company, company);
        this->phone = new char[strlen(phone)+1];
        strcpy(this->phone, phone);
    }
    NameCard(const NameCard & ref) : position(ref.position)
    {
        name = new char[strlen(ref.name)+1];
        company = new char[strlen(ref.company)+1];
        phone = new char[strlen(ref.phone)+1];
        strcpy(name, ref.name);
        strcpy(company, ref.company);
        strcpy(phone, ref.phone);
    }
    void ShowNameCardInfo()
    {
        cout<<"name: "<<name<<endl;
        cout<<"company: "<<company<<endl;
        cout<<"phone: "<<phone<<endl;
        cout<<"position: ";
        COMP_POS::ShowPositionInfo(position);
        cout<<endl;
    }
    ~NameCard()
    {
        delete []name;
        delete []company;
        delete []phone;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSenior;
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    NameCard copy3 = manAssist;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    copy3.ShowNameCardInfo();
    return 0;
}