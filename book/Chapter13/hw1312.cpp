#include <iostream>
using namespace std;

template <typename T>

T SumArray(T arr[], int len)
{
    T sum=0;
    for(int i=0; i<len; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int main(void)
{
    int arr1[]={1, 2, 3, 4, 5};
    double arr2[]={1.1, 2.2, 3.3, 4.4, 5.5};
    int len1=sizeof(arr1)/sizeof(int);
    int len2=sizeof(arr2)/sizeof(double);

    cout<<"The sum of arr1 is "<<SumArray(arr1, len1)<<endl;
    cout<<"The sum of arr2 is "<<SumArray(arr2, len2)<<endl;
    return 0;
}