# include <iostream>
using namespace std;
int MyFunOne(int num=7)
{
    return num+1;
}

int MyFunTwo(int num1=5, int num2=7)
{
    return num1+num2;
}

int main(void)
{
    cout<<MyFunOne()<<endl;
    cout<<MyFunOne(9)<<endl;
    cout<<MyFunTwo()<<endl;
    cout<<MyFunTwo(2,3)<<endl;
    return 0;
}

