# include <iostream>
using namespace std;
int main(void)
{
    char name[100];
    char lang[200];

    cout<<"What is your name? ";
    cin>>name;

    cout<<"What is your favorite programming language? ";
    cin>>lang;

    cout<<"My name is "<<name<<".\n";
    cout<<"My favorite programming language is "<<lang<<"."<<endl;

    return 0;
}