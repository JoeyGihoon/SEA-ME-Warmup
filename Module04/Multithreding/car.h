#ifndef CAR_H
#define CAR_H

#include <QObject>

class Car:public QObject{ // QObject를 상속받아 Signal/Slot을 사용할 수 있도록 합니다.
    Q_OBJECT

private:
    int position;
    int speed;
    int direction;
    QString name;

public:
    Car(QObject *parent = nullptr); //부모 객체가 없다는 뜻

    int getPosition();
    int getSpeed();
    int getDirection();
    QString getName();

    void setPosition(int pos);
    void setSpeed(int sp);
    void setDirection(int dir);
    void setName(QString nme);

signals:
    void positionChanged(int newPosition); // 위치가 변경될 때 발생하는 시그널
};

#endif // CAR_H
