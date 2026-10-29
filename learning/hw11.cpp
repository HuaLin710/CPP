# include <iostream>
using namespace std;
int main()
{
    int val1, val2, val3, val4, val5;
    cout<<"The first number is ";
    cin>>val1;

    cout<<"The second number is ";
    cin>>val2;

    cout<<"The third number is ";
    cin>>val3;

    cout<<"The fourth number is ";
    cin>>val4;

    cout<<"The fifth number is ";
    cin>>val5;

    int result;
    result = val1 + val2 + val3 + val4 + val5;
    cout<<"The sum of the five numbers is "<<result<<endl;

    return 0;
}