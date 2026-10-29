#include <iostream>
using namespace std;

class Calculator
{
private:
    int numOfAdd;
    int numOfSub;
    int numOfMul;
    int numOfDiv;
public:
    void Init();
    double Add(double num1, double num2);
    double Min(double num1, double num2);
    double Mul(double num1, double num2);
    double Div(double num1, double num2);
    void ShowOpCount();
};

void Calculator::Init()
{
    numOfAdd = 0;
    numOfSub = 0;
    numOfMul = 0;
    numOfDiv = 0;
}
double Calculator::Add(double num1, double num2)
{
    numOfAdd++;
    return num1 + num2;
}
double Calculator::Min(double num1, double num2)
{
    numOfSub++;
    return num1 - num2;
}
double Calculator::Mul(double num1, double num2)
{
    numOfMul++;
    return num1 * num2;
}
double Calculator::Div(double num1, double num2)
{
    numOfDiv++;
    return num1 / num2;
}
void Calculator::ShowOpCount()
{
    cout<<"Addition: "<<numOfAdd<<endl;
    cout<<"Subtraction: "<<numOfSub<<endl;
    cout<<"Multiplication: "<<numOfMul<<endl;
    cout<<"Division: "<<numOfDiv<<endl;
}

int main(void)
{
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();
    return 0;
}
