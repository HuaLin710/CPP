# include <iostream>
using namespace std;

int main(void)
{
    int num=12;
    int *ptr=&num;
    int **dptr=&ptr;

    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<dptr<<endl;
    cout<<*dptr<<endl;
    cout<<**dptr<<endl;
    cout<<&dptr<<endl<<endl;

    int &ref=num;
    int *(&pref)=ptr;
    int**(&dpref)=dptr;

    cout<<ref<<endl;
    cout<<*(&pref)<<endl;
    cout<<*pref<<endl;
    cout<<**(&dpref)<<endl;
    cout<<**dpref<<endl;
    return 0;
}