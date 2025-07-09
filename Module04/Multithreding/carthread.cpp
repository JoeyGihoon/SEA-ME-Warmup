#include "carthread.h"
#include <QRandomGenerator>
#include <QThread>

CarThread::CarThread(Car* car, RaceTrack* track, QObject *parent) : QThread(parent), m_car(car), m_track(track){
    m_mutex = new QMutex(); //동기화용 뮤텍스
}

void CarThread::run() {
    while (m_car->getPosition() < m_track->getFinishLine()) {   //자동차가 결승선에 도달할 때까지
        QThread::msleep(100); // 0.1초 간격으로 움직임


        int newPos = m_car->getPosition() + m_car->getSpeed(); //새로운 위치 계산
        m_car->setPosition(newPos); //위치 설정(시그널 발생)

    }
    emit finished(m_car);
}

