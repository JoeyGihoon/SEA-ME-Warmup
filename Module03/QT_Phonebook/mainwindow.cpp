#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /////////////////////////

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddContact); //버튼 클릭 시 Add 슬롯 연결
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchContact); //버튼 클릭 시 Search 슬롯 연결
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveContact); //버튼 클릭 시 Remove 슬롯 연결

    refreshContactList(contactList.getAllContacts());
    /////////////////////////
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddContact()  // 연락처 추가 함수
{
    QString name = ui->nameLineEdit->text();  // 이름 입력창에서 텍스트 가져옴
    QString phone = ui->phoneLineEdit->text(); // 전화번호 입력창에서 텍스트 가져옴
    QString email = ui->emailLineEdit->text(); // 이메일 입력창에서 텍스트 가져옴

    if (name.isEmpty() || phone.isEmpty())     // 이름이나 전화번호가 비어있으면 추가 안 함
        return;

    Contact newContact(name, phone, email);    // 새 연락처 객체 생성
    contactList.addContact(newContact);        // 연락처 목록에 추가

    refreshContactList(contactList.getAllContacts()); // 목록 새로고침

    // 입력창 초기화
    ui->nameLineEdit->clear();
    ui->phoneLineEdit->clear();
    ui->emailLineEdit->clear();
}

void MainWindow::onSearchContact() // 검색 버튼 눌렀을 때
{
    QString keyword = ui->searchLineEdit->text();         // 검색창에서 키워드 가져오기
    QList<Contact> results = contactList.searchContact(keyword); // 키워드로 검색 실행
    refreshContactList(results);                          // 결과를 화면에 표시
}

void MainWindow::onRemoveContact(){
    QString name = ui->nameLineEdit->text();  // 이름 입력창에서 텍스트 가져옴
    if(contactList.removeContact(name)){
        refreshContactList(contactList.getAllContacts()); // 목록 새로고침
    }

    QListWidgetItem* selectedItem = ui->contactListWidget->currentItem();
    delete selectedItem;
}

void MainWindow::refreshContactList(const QList<Contact>& contacts)
// 연락처 목록을 화면에 새로 표시하는 함수
{
    ui->contactListWidget->clear();  // 리스트 위젯 초기화

    for (const Contact& c : contacts) {
        QString item = c.getName() + " | " + c.getPhonenumber() + " | " + c.getEmail();
        ui->contactListWidget->addItem(item);  // 연락처 정보를 한 줄로 표시
    }
}
