#ifndef CONTACTLIST_H
#define CONTACTLIST_H
#include "contact.h"
#include <QList>

class ContactList{
private:
    QList<Contact> mcontacts;

public:
    void addContact(Contact &contact);
    bool removeContact(QString &name);
    QList<Contact> searchContact(QString &keyword);
    QList<Contact> getAllContacts();
};

#endif // CONTACTLIST_H
