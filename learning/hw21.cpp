# include <iostream>
using namespace std;

void IncreOne(int &num)
{
    num++;
}

void InverSign(int &num)
{
    num*=(-1);
}

int main(void)
{
    int num=20;
    IncreOne(num);
    cout<<num<<endl;

    InverSign(num);
    cout<<num<<endl;
    return 0;
}