#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y) : xpos(x), ypos(y)
    {}
    void ShowPosition() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
    friend bool operator==(const Point& pos1, const Point& pos2);
    friend bool operator!=(const Point& pos1, const Point& pos2);
};

bool operator==(const Point &pos1, const Point &pos2)
{
    if(pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos)
        return true;
    else
        return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    return ((pos1==pos2) ? false : true);
}

/*
bool operator!=(const Point &pos1, const Point &pos2)
{
    if(pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos)
        return false;
    else
        return true;
}
*/

int main(void)
{
    Point pos1(3, 5);
    Point pos2(3, 5);
    Point pos3(4, 6);

    if (pos1==pos2)
        cout<<"pos1 and pos2 are equal."<<endl;
    else
        cout<<"pos1 and pos2 are not equal."<<endl;

    if (pos1!=pos3)
        cout<<"pos1 and pos3 are not equal."<<endl;
    else
        cout<<"pos1 and pos3 are equal."<<endl;

    return 0;
}