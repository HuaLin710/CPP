# include <iostream>
using namespace std;

int main(void)
{
    int sales;
    while (sales != -1)
    {
        cout<<"Enter the sales: ";
        cin>>sales;
        if (sales == -1)
        {
            break;
        }
        cout<<"The salary is "<<50+sales*0.12<<endl;
    }
    return 0;
}