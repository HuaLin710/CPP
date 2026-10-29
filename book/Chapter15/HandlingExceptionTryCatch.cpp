#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;

    try
    {
        if(num2==0)
            throw num2;
        cout<<"Division = "<<num1/num2<<endl;
        cout<<"Remainder = "<<num1%num2<<endl;
    }
    catch(int expn)
    {
        cout<<"Division by zero is not possible!"<<endl;
        cout<<"Exception caught!"<<endl;
    }
    cout<<"end of main"<<endl;
    return 0;
}