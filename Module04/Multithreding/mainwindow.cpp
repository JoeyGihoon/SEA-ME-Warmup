#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 배경 추가
    QLabel* m_backgroundLabel;
    m_backgroundLabel = new QLabel(this);
    QPixmap bgPixmap("/home/gihoon/Pictures/Screenshots/Track.png"); // 트랙 배경 이미지
    m_backgroundLabel->setPixmap(bgPixmap);
    m_backgroundLabel->setScaledContents(true); // 라벨 크기에 맞게 이미지 조정
    m_backgroundLabel->setGeometry(0, 0, width(), height()-100); // 창 크기에 맞게 설정
    m_backgroundLabel->lower(); // 가장 뒤로 보내기 (자동차보다 뒤에 있도록)

    m_backgroundLabel->show();


    // 트랙과 자동차 생성
    int tracksize = this->width();
    m_track = new RaceTrack(tracksize-150);

    m_car1 = new Car();
    //m_car1->setPosition(50);
    m_car1->setSpeed(5);
    m_car1->setName("Red Car");

    m_car2 = new Car();
    //m_car2->setPosition(30);
    m_car2->setSpeed(10);
    m_car2->setName("Blue Car");


    // 자동차 아이콘을 보여줄 라벨 생성
    m_carLabel1 = new QLabel(this);
    QPixmap car1Img("/home/gihoon/Pictures/Screenshots/Car1_.png");
    m_carLabel1->setPixmap(car1Img);
    m_carLabel1->setScaledContents(true);
    m_carLabel1->setFixedSize(120, 120);
    m_carLabel1->move(0, 20);
    m_carLabel1->show();

    m_carLabel2 = new QLabel(this);
    QPixmap car2Img("/home/gihoon/Pictures/Screenshots/Car3.png");  // 내 컴퓨터 이미지 경로
    m_carLabel2->setPixmap(car2Img);
    m_carLabel2->setScaledContents(true);
    m_carLabel2->setFixedSize(110, 120);
    m_carLabel2->move(0, 150);
    m_carLabel2->show();


    // 버튼 클릭과 자동차 위치 변경 시그널 연결
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartRace);
    connect(m_car1, &Car::positionChanged, this, [=](int pos){
        m_carLabel1->move(pos, 20);
    });
    connect(m_car2, &Car::positionChanged, this, [=](int pos){
        m_carLabel2->move(pos, 150);
    });

    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetRace);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStartRace() {
    m_thread1= new CarThread(m_car1, m_track);
    m_thread2= new CarThread(m_car2, m_track);

    connect(m_thread1, &CarThread::finished, this, &MainWindow::onRaceFinished);
    connect(m_thread2, &CarThread::finished, this, &MainWindow::onRaceFinished);

    m_thread1->start();// 자동차가 움직이기 시작함
    m_thread2->start();
}

// 자동차의 위치가 바뀌면 라벨 위치도 갱신
void MainWindow::onCarPositionChanged(int pos) {
    m_carLabel1->move(pos, 50); // 자동차 이미지를 오른쪽으로 이동
    m_carLabel2->move(pos, 150);
}

void MainWindow::onRaceFinished(Car* winner)
{
    // 이미 누가 도착했는지 체크 (중복 처리 방지용)
    if (m_raceOver)
        return;

    m_raceOver = true;

    // 나머지 쓰레드 정지
    m_thread1->requestInterruption();
    m_thread2->requestInterruption();

    // 메시지 박스로 승자 알림
    ui->textBrowser->setHtml(
        "<div style='text-align: center;'>"
        "<span style='font-size: 36px; font-weight: bold; color: black;'>"
        + winner->getName() + " Won!"
        + "</span></div>"
        );
}

void MainWindow::onResetRace()
{
    m_raceOver = false;

    // 쓰레드가 살아 있으면 중단 및 제거
    if (m_thread1 && m_thread1->isRunning()) {
        m_thread1->requestInterruption();
        m_thread1->wait();
        delete m_thread1;
        m_thread1 = nullptr;
    }

    if (m_thread2 && m_thread2->isRunning()) {
        m_thread2->requestInterruption();
        m_thread2->wait();
        delete m_thread2;
        m_thread2 = nullptr;
    }

    // 자동차 위치 초기화
    m_car1->setPosition(0);
    m_car2->setPosition(0);

    m_carLabel1->move(0, 20);
    m_carLabel2->move(0, 150);

    // 결과 메시지 초기화
    ui->textBrowser->clear();
}
