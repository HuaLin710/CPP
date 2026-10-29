#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage) : age(myage)
    {
        int len=strlen(myname)+1;
        name=new char[len];
        strcpy(name, myname);
    }
    void ShowPersonInfo() const
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
    Person& operator=(const Person& ref)
    {
        delete []name;
        int len=strlen(ref.name)+1;
        name=new char[len];
        strcpy(name, ref.name);
        age=ref.age;
        return *this;
    }
    ~Person()
    {
        delete []name;
        cout<<"Called destructor!"<<endl;
    }
};

int main(void)
{
    Person man1("Lee Dong Wook", 29);
    Person man2("Yoon Ji Yul", 22);
    man2=man1;

    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}

