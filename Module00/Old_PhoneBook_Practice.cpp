#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Contact{
    string Name;
    string Phone_Number;
    string Nickname;
    bool isBookmarked;

    Contact(string N, string P, string Nick) : Name(N), Phone_Number(P), Nickname(Nick), isBookmarked(false) {}
};

class PhoneBook{
private:
    vector<Contact> contacts;

public:
    void ADD(){
        string m_name;
        string m_phone;
        string m_nick;

        cin.ignore();
        cout<<"Name: "<<endl;
        getline(cin, m_name);
        cout<<"Phone Number: "<<endl;
        getline(cin, m_phone);
        cout<<"Nickname: "<<endl;
        getline(cin, m_nick);

        contacts.emplace_back(m_name, m_phone, m_nick);
        cout<<"Contact Added"<< endl;
    }

    void REMOVE(){
        cout<<"Remove by index: 1 / Remove by Phone number: 2" <<endl;
        
        int choice, idx;
        string phone;
        if(choice == 1){
            cout<<"Index: ";
            cin.ignore();
            cin>>idx;
            contacts.erase(contacts.begin()+idx-1);
            cout<< "Contact(Index: "<< idx <<") removed."<<'\n';
        }
        else if(choice == 2){
            cout<<"Phone number: ";
            cin.ignore();
            getline(cin, phone);
            for(int i=0; i<contacts.size(); i++){
                if(phone == contacts[i].Phone_Number){
                    contacts.erase(contacts.begin()+i);
                }
            }
        }
        else{
            cout<<"Invalid Number!"<<endl;
        }
    }

    void SEARCH(){

    }

    void BOOKMARK(){

    }

    void EXIT(){

    }
}