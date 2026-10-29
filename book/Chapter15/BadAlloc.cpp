#include <iostream>
#include <new>
using namespace std;

int main(void)
{
    int num=0;

    try
    {
        while(1)
        {
            num++;
            cout<<num<<"th allocation trial"<<endl;
            new int[10000][10000];
        }
    }
    catch(bad_alloc & bad)
    {
        cout<<bad.what()<<endl;
        cout<<"No more allocation possible!"<<endl;
    }
    return 0;
}