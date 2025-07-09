    #include "car.h"

Car::Car(QObject *parent) : QObject(parent), position(0), speed(1){} // 생성자: 위치를 0, 속도를 1로 초기화

int Car::getPosition() {return position;}
int Car::getSpeed() {return speed;}
int Car::getDirection() {return direction;}
QString Car::getName() {return name;}

void Car::setPosition(int pos) {
    if(position != pos){
        position = pos;
        emit positionChanged(pos); // UI나 쓰레드에 변경을 알림
    }
}
void Car::setSpeed(int sp) {speed = sp;}
void Car::setDirection(int dir) {direction = dir;}
void Car::setName(QString nme) {name = nme;}
