#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;

    if(num2==0)
    {
        cout<<"Division by zero is not possible"<<endl;
    }
    else
    {
        cout<<"Division of "<<num1<<" by "<<num2<<" is: "<<num1/num2<<endl;
        cout<<"Remainder of "<<num1<<" divided by "<<num2<<" is: "<<num1%num2<<endl;
    }
    return 0;
}