# include <iostream>
using namespace std;
int main()
{
    int val1, val2;
    int result=0;
    cout<<"Enter two integers: ";
    cin>>val1>>val2;

    if (val1<val2)
    {
        for (int i=val1+1; i<val2; i++)
        result+=i;
    }
    else
    {
        for (int i=val2+1; i<val1; i++)
        result+=i;
    }

    cout<<"Sum of all integers between "<<val1<<" and "<<val2<<" is "<<result<<endl;

    return 0;
}