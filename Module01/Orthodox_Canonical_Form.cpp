#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string name;
    int speed;

public:
    //기본 생성자 (Constructor)
    Car(string n = "", int s = 0) : name(n), speed(s){
        cout<< "Constructor called"<< endl;
    }

    //복사 생성자 (Copy Constructor) -> 새로 만드는 객체를 기존 객체로 복사
    Car(Car& other) : name(other.name), speed(other.speed){
        cout<< "Copy Constructor called"<< endl;
    }

    //복사 대입 연산자 (Copy assignment operator override)
    Car& operator=(Car& other){
        cout<<"Copy Assignment Operator called"<<endl;
        if(this != &other){ //자기 자신인지 확인
            name = other.name; // 이름 복사
            speed = other.speed; // 속도 복사
        }

        return *this; //자기 자신 반환
    }

    //소멸자
    ~Car(){
        cout<< "Destructor called" <<endl;
    }

    void print(){
        cout<< "Car name: "<<name <<", Speed: "<<speed<<" km/h"<<endl;
    }
};

int main(){
    Car car1("BMW", 220);
    car1.print();

    Car car2 = car1;
    car2.print();

    Car car3;
    car3 = car1;
    car3.print();

    return 0;
}