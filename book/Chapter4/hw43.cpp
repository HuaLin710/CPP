#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) : xpos(x), ypos(y)
    {}
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle
{
private:
    int radius;
    Point center;
public:
    /*
    Circle(int x, int y, int rad) : center(x, y)
    {
        radius=rad;
    }
    */
    Circle(int x, int y, int rad) : radius(rad), center(x, y)
    {}
    void ShowCircleInfo() const
    {
        cout<<"radius: "<<radius<<endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle inCircle;
    Circle outCircle;
public:
    Ring(int inX, int inY, int inRadius, int outX, int outY, int outRadius)
        : inCircle(inX, inY, inRadius), outCircle(outX, outY, outRadius)
    {}
    void ShowRingInfo() const
    {
        cout<<"Inner Circle Info..."<<endl;
        inCircle.ShowCircleInfo();
        cout<<"Outter Circle Info..."<<endl;
        outCircle.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}