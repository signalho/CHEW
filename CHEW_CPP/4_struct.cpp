#include <iostream>
using namespace std;

namespace CAR_CONST{
    enum{
        ID_LEN = 20, MAX_SPD = 20, FUEL_STEP = 20,
        ACC_STEP = 20, BRK_STEP = 20,
    };
}
// you can include func in structs in cpp
struct Car{
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    // you can just mention functions in the struct for ease of understanding
    void ShowCarState();
    void Accel();
    void Break();
};
void Car::ShowCarState(){
    cout<<"userID: "<<gamerID<<endl;
    cout<<"current gas: "<<fuelGauge<<"%"<<endl;
    cout<<"current speed: "<<curSpeed<<"km/s"<<endl<<endl;
}
void Car::Accel(){
    if (fuelGauge<=0)
        return;
    else
        fuelGauge -=CAR_CONST::FUEL_STEP;
    
    if((curSpeed+CAR_CONST::ACC_STEP)>=CAR_CONST::MAX_SPD){
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break(){
    if (curSpeed<CAR_CONST::BRK_STEP){
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void){
    Car racer1 = {"racer1", 100, 0};
    racer1.Accel();
    racer1.ShowCarState();
    racer1.Break();
    racer1.ShowCarState();
    return 0;
}