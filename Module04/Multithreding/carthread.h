#ifndef CARTHREAD_H
#define CARTHREAD_H
#include <QThread>
#include <QMutex>
#include "car.h"
#include "racetrack.h"

// 자동차를 움직이는 쓰레드 클래스입니다.
// QThread를 상속받아 run() 함수에서 동작을 정의합니다.
class CarThread:public QThread
{
    Q_OBJECT

private:
    Car* m_car; //움직일 자동차
    RaceTrack* m_track; //트랙 정보
    QMutex* m_mutex;    //스레드 동기화를 위한 뮤텍스

public:
    CarThread(Car* car, RaceTrack* track, QObject *parent = nullptr);

    void run() override; // 쓰레드가 시작되면 실행되는 함수 (자동차를 계속 움직임)
                         // QThread 클래스에 run()함수가 가상함수로 존재함

signals:
    void finished(Car* car);  // 도착한 자동차 정보를 전달
};


#endif // CARTHREAD_H
