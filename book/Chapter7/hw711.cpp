#include <iostream>
using namespace std;

class Car
{
private:
    int gasolineGauge;
public:
    Car(int gas) : gasolineGauge(gas)
    {}
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(int gas, int elec) : Car(gas), electricGauge(elec)
    {}
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int WaterGauge;
public:
    HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), WaterGauge(water)
    {}
    void ShowCurrentGauge()
    {
        cout<<"remaining gasoline: "<<GetGasGauge()<<endl;
        cout<<"remaining electric: "<<GetElecGauge()<<endl;
        cout<<"remaining water: "<<WaterGauge<<endl;
    }
};

int main(void)
{
    HybridWaterCar hwcar(100, 200, 300);
    hwcar.ShowCurrentGauge();
    return 0;
}