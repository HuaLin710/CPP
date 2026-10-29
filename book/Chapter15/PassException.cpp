#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
    if(num2==0)
    {
        throw num2;
    }
    cout<<"Division result: "<<num1/num2<<endl;
    cout<<"Remainder: "<<num1%num2<<endl;
}

int main(void)
{
    int num1, num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;

    try
    {
        Divide(num1, num2);
        cout<<"Division successful"<<endl;
    }
    catch(int expn)
    {
        cout<<"Division by "<<expn<<" is not possible"<<endl;
        cout<<"Exception caught"<<endl;
    }
    return 0;
}