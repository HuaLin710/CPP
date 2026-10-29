#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(const int &xpos, const int &ypos)
{
    x = xpos;
    y = ypos;
}

int Point::GetX() const {return x;}
int Point::GetY() const {return y;}

bool Point::SetX(int xpos)
{
    if (xpos < 0 || xpos > 100)
    {
        cout<<"The value is out of range."<<endl;
        return false;
    }
    x = xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if (ypos < 0 || ypos > 100)
    {
        cout<<"The value is out of range."<<endl;
        return false;
    }
    y = ypos;
    return true;
}
