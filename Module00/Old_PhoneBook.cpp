#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip> //setw
using namespace std;

struct Contact{
    string Name;
    string PhoneNumber;
    string Nickname;
    bool isBookmarked;

    Contact(string n, string p, string nick) : Name(n), PhoneNumber(p), Nickname(nick), isBookmarked(false) {}

};

vector<Contact> phonebook;

void ADD(){
    string Name;
    string Phone;
    string Nickname;
    cin.ignore();
    cout<< "Name: "; //cin 이용해 입력받으면 항상 \n이 남아 있음 *cin.ignore()
    getline(cin, Name);
    cout<< "Phonenumber: ";
    getline(cin, Phone);
    cout<< "Nickname: ";
    getline(cin, Nickname);

    phonebook.emplace_back(Name, Phone, Nickname); //vs push_back
    cout<< "Contact added"<<'\n';
}

void SEARCH(){
    cout << left << setw(10) << "Index" << setw(20) << "Name" << setw(20) << "Phone" << setw(15) << "Nickname" << endl << "--------------------------------------------------------------" << endl;

    for(int i=0; i<phonebook.size(); i++){
        cout<<setw(10)<<i+1 << setw(20) << phonebook[i].Name << setw(20) <<phonebook[i].PhoneNumber<<setw(15)<<phonebook[i].Nickname<<endl;
    }

    cin.ignore();
    cout<<"Enter index: ";
    int idx;
    cin >> idx;
    cout<< '\n'<<"Name: " << phonebook[idx-1].Name << endl;
    cout<< "Phone: " << phonebook[idx-1].PhoneNumber << endl;
    cout<< "Nickname: " << phonebook[idx-1].Nickname << endl;
    cout<< "Bookmarked: ";
    if(phonebook[idx].isBookmarked == false) cout<< "N" << endl;
    else cout<<"Y" << endl;
    cout<< "Do you want to bookmark? (Y/N): ";
    string choice;
    cin>> choice;
    if(choice == "Y"){
        phonebook[idx].isBookmarked = true;
        cout<< "Contact bookmarked."<< endl;
    }
}

void REMOVE(){
    cout<<"1: Romove via index/ 2: Remove via phone number"<<endl;
    int choice;
    cin>>choice;
    if(choice == 1){
        int idx;
        cout<< "Index: ";
        cin>> idx;
        phonebook.erase(phonebook.begin() + idx-1);
        cout<< "Contact(Index: "<< idx <<") removed."<<'\n';
    }
    else{
        string phone;
        cout<< "Phone number: ";
        cin>> phone;
        for(int i=0; i<phonebook.size(); i++){
            if(phonebook[i].PhoneNumber == phone){
                phonebook.erase(phonebook.begin() + i);
                cout<< "Contact(Phone Number: "<< phone <<") removed."<<'\n';
                return;
            }
        }
    }
}

void BOOKMARK(){
    bool found = false;
    for(int i=0; i<phonebook.size(); i++){
        if(phonebook[i].isBookmarked == true){
            cout<<setw(10)<<i << setw(20) << phonebook[i].Name << setw(20) <<phonebook[i].PhoneNumber<<setw(15)<<phonebook[i].Nickname<<endl;
            found = true;
        }
    }
    if(!found) cout<<"No bookmarked contract!" <<'\n';
}
int main(){
    while (true){
        string function;
        cin >> function;
        if(function == "ADD"){
            ADD();
        }
        else if(function == "SEARCH"){
            SEARCH();
        }
        else if(function == "REMOVE"){
            REMOVE();
        }
        else if(function == "BOOKMARK"){
            BOOKMARK();
        }
        else if(function == "EXIT"){
            cout<< "Shutting down.."<<'\n';
            break;
        }
        else{
            cout<< "Unvalid command"<<'\n';
        }
    }
    
}