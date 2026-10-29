# include <iostream>
using namespace std;

void Volume(int length, int width, int height)
{
    int volume = length * width * height;
    cout<<"["<<length<<", "<<width<<", "<<height<<"]: "<<volume<<endl;
}

void Volume(int length, int width)
{
    int volume = length * width * 1;
    
    cout<<"["<<length<<", "<<width<<", D]: "<<volume<<endl;
}

void Volume(int length)
{
    int volume = length * 1 * 1;
    cout<<"["<<length<<", D, D]: "<<volume<<endl;
}

int main(void)
{
    Volume(3, 3, 3);
    Volume(5, 5);
    Volume(7);
    return 0;
}