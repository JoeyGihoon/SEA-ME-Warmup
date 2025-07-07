#include "contactlist.h"

void ContactList::addContact(Contact &contact){
    mcontacts.append(contact);
}

bool ContactList::removeContact(QString &name){
    for(int i=0; i<mcontacts.size(); i++){
        if(mcontacts[i].getName() == name){
            mcontacts.removeAt(i);
            return true;
        }
    }
    return false;
}

QList<Contact> ContactList::searchContact(QString &keyword){
    QList<Contact> result;
    for(const Contact &contact : mcontacts){
        if(contact.getName().contains(keyword, Qt::CaseInsensitive) || contact.getPhonenumber().contains(keyword) || contact.getEmail().contains(keyword)){
            result.append(contact);
        }
    }
    return result;
}

QList<Contact> ContactList::getAllContacts(){
    return mcontacts;
}

