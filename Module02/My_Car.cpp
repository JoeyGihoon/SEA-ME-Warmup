#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Part {
public:
    virtual void print() = 0;
    virtual ~Part() {}
};

class Engine : public Part{
private:
    string combustion;
    string fuel;

public: 
    Engine(string comb, string gas) : combustion(comb), fuel(gas){}
    
    string getCombustion() {return combustion;}
    string getFuel() {return fuel;}

    virtual void print() override{
        cout << "Engine Info" << "\n---------------------------------\n";
        cout << "Combustion: " << combustion << " / " << "Fuel: " << fuel <<endl<<endl;
    }

    virtual ~Engine() {}
};

class Wheel : public Part{
private:
    string material;
    string use;
    Engine* engine_;

public:
    Wheel(string mat, string u, Engine* eng) : material(mat), use(u), engine_(eng) {}

    string getMaterial() {return material;}
    string getUse() {return use;}

    virtual void print() override{
        cout<< "Wheel Info" << "\n---------------------------------\n";
        cout<< "Material: " << material << " / " << "Use: " << use << endl;
        cout<< "Need to see if " << material <<" Wheel is compatible with "<< engine_->getCombustion() << " Engine." <<endl<<endl; 
    }

    virtual ~Wheel() {}
};

class Brake : public Part{
private:
    string Pad;
    string Size;
    string Year;

public:
    Brake(string pad, string size, string year) : Pad(pad), Size(size), Year(year){}

    string getPad() {return Pad;}
    string getSize() {return Size;}
    string getYear() {return Year;}

    virtual void print() override{
        cout<< "Break Info" << "\n---------------------------------\n";
        cout<< "Pad: " << Pad << " / " << "Size: " << Size << " / " << "Year: " << Year << endl;
        cout<< "Need repair if the Brake Pad has been more than 5 years.\n"<<endl;
    }

    virtual ~Brake() {}
};

class Car {
private:
    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    
public:
    Car() {
        engine_ = new Engine("Internal", "Gasoline");
        wheels_ = new Wheel("Ceramic", "4-Seasons", engine_);
        brakes_ = new Brake("Rubber", "Big", "2015");
    }
    
    void printParts() {
        engine_->print();
        wheels_->print();
        brakes_->print();
    }
    
    ~Car() {
        delete engine_;
        delete wheels_;
        delete brakes_;
    }
    

};

int main() {
    Car myCar;
    myCar.printParts();
    
    return 0;
}