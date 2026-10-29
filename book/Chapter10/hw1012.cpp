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
    Point operator+=(const Point &ref)
    {
        xpos+=ref.xpos;
        ypos+=ref.ypos;
        return *this;
    }

    Point operator-=(const Point &ref)
    {
        xpos-=ref.xpos;
        ypos-=ref.ypos;
        return *this;
    }
};

int main(void)
{
    Point pos1(30, 40);
    Point pos2(10, 20);
    Point pos3(5, 6);

    pos1.ShowPosition();
    pos2.ShowPosition();
    (pos1+=pos2).ShowPosition();
    (pos2-=pos3).ShowPosition();

    return 0;
}