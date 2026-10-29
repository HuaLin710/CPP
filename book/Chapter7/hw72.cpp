#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char *name;
    int age;
public:
    MyFriendInfo(char *myname, int myage) : age(myage)
    {
        name=new char[strlen(myname)+1];
        strcpy(name, myname);
        cout<<"MyFriendInfo"<<endl;
    }
    void ShowMyFriendInfo()
    {
        cout<<"name: "<<name<<endl;
        cout<<"age: "<<age<<endl;
    }
    ~MyFriendInfo()
    {
        delete []name;
        cout<<"~MyFriendInfo"<<endl;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char *addr;
    char *phone;
public:
    MyFriendDetailInfo(char *myname, int myage, char *myaddr, char *myphone) : MyFriendInfo(myname, myage)
    {
        addr=new char[strlen(myaddr)+1];
        strcpy(addr, myaddr);
        phone=new char[strlen(myphone)+1];
        strcpy(phone, myphone);
        cout<<"MyFriendDetailInfo"<<endl;
    }
    void ShowMyFriendDetailedInfo()
    {
        ShowMyFriendInfo();
        cout<<"addr: "<<addr<<endl;
        cout<<"phone: "<<phone<<endl<<endl;
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
        cout<<"~MyFriendDetailedInfo"<<endl;
    }
};

int main(void)
{
    MyFriendDetailInfo mfdi("Lee", 15, "Shanghai", "15900000000");
    mfdi.ShowMyFriendDetailedInfo();
    return 0;
}
