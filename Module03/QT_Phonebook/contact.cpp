#include "contact.h"

Contact::Contact(QString &n, QString &p, QString &e) : name(n), phonenumber(p), email_address(e){}

QString Contact::getName() const{return name;}
QString Contact::getPhonenumber() const{return phonenumber;}
QString Contact::getEmail() const{return email_address;}

void Contact::setName(QString &n) {name = n;}
void Contact::setPhone(QString &p) {phonenumber = p;}
void Contact::setEmail(QString &e) {email_address = e;}
