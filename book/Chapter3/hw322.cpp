#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
    char str[100];
public:
    void SetString(const char* input);
    void ShowString();
};

void Printer::SetString(const char* input)
{
    strcpy(str, input);
}
void Printer::ShowString()
{
    cout<<str<<endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}