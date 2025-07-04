#include <iostream>
#include <string>
using namespace std;

class Car{
public: //member variable
    string make;
    string model;
    string year;

    Car(string mk, string mdl, string yr) : make(mk), model(mdl), year(yr){
        cout<<"Constructor Car called: "<< make<<" "<<model<<" "<<year<<"edition"<<endl;
    }

    //member function
    void drive(){
        cout<<"Driving "<<make<<" "<<model<<" "<<year<<"edition"<<endl;
    }
};

class SportsCar : public Car {
public:
    int topSpeed;

    SportsCar(string mk, string mdl, string yr, int spd) : Car(mk, mdl, yr), topSpeed(spd){
        cout<< "Constructor SportsCar called: Top speed is "<<topSpeed<< "km/h"<< endl;
    }

    void drive(){
        Car::drive();
        cout<<"Top Speed: "<<topSpeed<<endl;
    }
};

int main(){
    Car car1("Hyundai", "Ioniq5", "2023");
    car1.drive();
    cout<<"-------------------------------------"<<endl;

    SportsCar sc1("Lambo", "Aventador", "2023", 340);
    sc1.drive();
}