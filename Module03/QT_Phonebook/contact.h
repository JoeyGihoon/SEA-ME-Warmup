#ifndef CONTACT_H
#define CONTACT_H
#include <QString>
#include <QObject>

class Contact{
private:
    QString name;
    QString phonenumber;
    QString email_address;

public:
    Contact(QString &n, QString &p, QString &e);

    QString getName() const;
    QString getPhonenumber() const;
    QString getEmail() const;

    void setName(QString &n);
    void setPhone(QString &p);
    void setEmail(QString &e);
};


#endif // CONTACT_H
