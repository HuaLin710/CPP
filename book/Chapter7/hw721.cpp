#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;
public:
    Rectangle(int leng, int wid) : length(leng), width(wid)
    {}
    void ShowAreaInfo()
    {
        cout<<"Area: "<<length*width<<endl;
    }
};

class Square : public Rectangle
{
private:
    int side;
public:
    Square(int s) : Rectangle(s, s), side(s)
    {}
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}