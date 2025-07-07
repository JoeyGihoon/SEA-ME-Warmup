#include <QApplication>   // GUI 프로그램 필수
#include <QPushButton>    // 버튼 위젯
#include <QString>
#include "mainwindow.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);  // GUI 프로그램의 진입점
    //////////////////
    MainWindow w;
    w.show();
    /////////////////
    return app.exec();  // 이벤트 루프 시작
}
