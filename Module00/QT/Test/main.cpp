#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QTranslator>
#include <QLocale>

QString toUpper(const QString& input) {
    return input.toUpper();
}

QString toLower(const QString& input) {
    return input.toLower();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("String Case Converter");

    // UI 요소 생성
    QLineEdit *inputField = new QLineEdit();
    QPushButton *upperButton = new QPushButton("Convert to UPPER");
    QPushButton *lowerButton = new QPushButton("Convert to lower");
    QLabel *resultLabel = new QLabel("Result will appear here");

    // 레이아웃 구성
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(inputField);
    layout->addWidget(upperButton);
    layout->addWidget(lowerButton);
    layout->addWidget(resultLabel);
    window.setLayout(layout);

    // 시그널-슬롯 연결
    QObject::connect(upperButton, &QPushButton::clicked, [&]() {
        QString input = inputField->text();
        resultLabel->setText(toUpper(input));
    });

    QObject::connect(lowerButton, &QPushButton::clicked, [&]() {
        QString input = inputField->text();
        resultLabel->setText(toLower(input));
    });

    window.show();
    return app.exec();
}
