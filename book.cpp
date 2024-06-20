#include <iostream>
#include <iomanip> 
#include <cstring>
#include "book.h"

using namespace std;

void book::create_book() {
    cout << "\nNEW BOOK ENTRY...\n";
    cout << "\nEnter The book no.: ";
    cin >> bno;
    cin.ignore();
    cout << "\n\nEnter The Name of The Book: ";
    cin.getline(bname, 50);
    cout << "\n\nEnter The Author's Name: ";
    cin.getline(aname, 20);
    cout << "\n\n\nBook Created..";
}

void book::show_book() const {
    cout << "\nBook no.: " << bno;
    cout << "\nBook Name: " << bname;
    cout << "\nAuthor Name: " << aname;
}

void book::modify_book() {
    cout << "\nBook no.: " << bno;
    cout << "\nModify Book Name: ";
    cin.getline(bname, 50);
    cout << "\nModify Author's Name: ";
    cin.getline(aname, 20);
}

const char* book::retbno() const {
    return bno;
}

void book::report() const {
    cout << bno << setw(30) << bname << setw(30) << aname << endl;
}
