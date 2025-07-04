#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
#include <memory>
using namespace std;

//Abstraction
class Vehicle{
public:
    virtual void drive() = 0;
    virtual void displayInfo() = 0;
    virtual ~Vehicle() {} //Destructor
};

/////////Base Car Class//////////
class Car : public Vehicle{
private: //Encapsulation
    string make;
    string model;
    string year;

public: 
    Car(string mk, string mdl, string yr) : make(mk), model(mdl), year(yr){
        cout<< "Car Created: "<< make<< " "<< model<< " ("<< year<<" edition)"<< endl;
    }

    string getMake() {return make;}
    string getModel() {return model;}
    string getYear() {return year;}

    //Polymorphism
    virtual void drive() override{
        cout << "Driving " << make << " " << model<< " ("<< year<<" edition)"<< endl;
    }

    virtual void displayInfo() override {
        cout << "<<<<<<<Car Info>>>>>>>" << endl;
        cout << "Company: " << make << " / "
        << "Model: " << model << " / " << "year: " << year << endl;
    }

    virtual ~Car() {}
};

//Polymorphism
class SportsCar : public Car{ //Inheritance
private:
    int topSpeed;

public:
    SportsCar(string mk, string mdl, string yr, int spd) : Car(mk, mdl, yr), topSpeed(spd){
        cout<< "SportsCar Created with TopSpeed: "<< topSpeed <<"km/h"<< endl;
    }

    virtual void drive() override{
        Car::drive();
        cout<< "Engaging Sports Mode with TopSpeed: " << topSpeed << "km/h"<< endl;
    }

    virtual void displayInfo() override {
        Car::displayInfo();
        cout<<"SportsCar TopSpeed: "<< topSpeed <<"km/h"<<endl;
    }
    
    virtual ~SportsCar() {}
};

class ElectricCar : public Car{
private:
    int BatteryCapacity;

public:
    ElectricCar(string mk, string mdl, string yr, int BatCap) : Car(mk, mdl, yr), BatteryCapacity(BatCap){
        cout<< "Battery Capacity: " << BatteryCapacity <<" kWh" <<endl;
    }

    virtual void drive() override{
        cout << "Driving electric " << getMake() << " " << getModel() << " (" << getYear() << " edition)" << endl;
        cout << "Battery Capacity: " << BatteryCapacity << " kWh" <<endl;
    }

    virtual void displayInfo() override {
        Car::displayInfo();
        cout << "Battery Capacity: " << BatteryCapacity << " kWh" <<endl;
    }
};

//Modularity
int main() {
    unique_ptr<Car> car1 = make_unique<Car>("Hyundai", "Ioniq5", "2023");
    car1->drive();
    car1->displayInfo();
    cout<<"\n-------------------------------\n";

    shared_ptr<Car> sc1 = make_shared<SportsCar>("Lahmborghini", "Aventador", "2024", 350);
    sc1->drive();
    sc1->displayInfo();
    cout<<"\n-------------------------------\n";

    unique_ptr<Car> ev1 = make_unique<ElectricCar>("Tesla", "Model S", "2024", 100);
    ev1->drive();
    ev1->displayInfo();
    
    shared_ptr<Car> sc2 = sc1;
    cout << "Shared pointer reference count: " << sc1.use_count() << endl;

}
