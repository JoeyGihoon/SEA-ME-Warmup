#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
////////////////
#include "contactlist.h"
#include "ui_mainwindow.h"
///////////////

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//////////////////////
private slots:
    void onAddContact();
    void onSearchContact();
    void onRemoveContact();
////////////////////

private:
    Ui::MainWindow *ui;
    ////////////////////
    ContactList contactList;
    void refreshContactList(const QList<Contact> &contacts);
    ///////////////////
};
#endif // MAINWINDOW_H
