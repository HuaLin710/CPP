# include <iostream>
using namespace std;

void swap(int a, int b)
{
    cout<<a<<' '<<b<<endl;
}

void swap(char a, char b)
{
    cout<<a<<' '<<b<<endl;
}

void swap(double n1, double n2)
{
    cout<<n1<<' '<<n2<<endl;
}

int main(void)
{
    swap(20, 30);
    swap('A', 'Z');
    swap(1.111, 5.555);
    return 0;
}