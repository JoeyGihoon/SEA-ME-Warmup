#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "car.h"
#include "racetrack.h"
#include "carthread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;// Qt Designer에서 만든 UI 포인터
    RaceTrack* m_track;// 트랙 정보
    Car* m_car1;// 자동차 객체
    Car* m_car2;
    CarThread* m_thread1;// 자동차 움직임 쓰레드
    CarThread* m_thread2;
    QLabel* m_carLabel1;// 자동차를 표시할 UI 라벨
    QLabel* m_carLabel2;
    bool m_raceOver = false;  // 중복 종료 방지용

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartRace(); //버튼 클릭 시 레이스 시작
    void onCarPositionChanged(int pos); //자동차 위치가 변경될 때마다 실행되는 슬롯
    void onRaceFinished(Car* winner);
    void onResetRace();
};
#endif // MAINWINDOW_H
