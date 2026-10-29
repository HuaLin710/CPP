#include <iostream>
using namespace std;

class CountryArea
{
public:
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 957290;
    const static int SOUTH_KOREA = 9922;
};

int main(void)
{
    cout<<"The area of Russia: "<<CountryArea::RUSSIA<<endl;
    cout<<"The area of Canada: "<<CountryArea::CANADA<<endl;
    cout<<"The area of China: "<<CountryArea::CHINA<<endl;
    cout<<"The area of South Korea: "<<CountryArea::SOUTH_KOREA<<endl;
    return 0;
}