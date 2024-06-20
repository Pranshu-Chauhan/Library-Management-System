#include "student.h"

void student::create_student() {
    cout << "\nNEW STUDENT ENTRY...\n";
    cout << "\nEnter The Admission No.: ";
    cin >> admno;
    cin.ignore();
    cout << "Enter The Student Name: ";
    cin.getline(name, 20);
    token = 0;
    for (int i = 0; i < 3; ++i) {
        stbno[i][0] = '\0'; // Initialize book numbers to empty
    }
    cout << "\n\nStudent Record Created...";
}

void student::show_student() const {
    cout << "\nStudent ID: " << admno;
    cout << "\nStudent Name: " << name;
    cout << "\nNumber of Books Issued: " << token;
    for (int i = 0; i < token; ++i) {
        cout << "\nBook Number " << i + 1 << ": " << stbno[i];
    }
}

void student::modify_student() {
    cout << "\nStudent ID: " << admno;
    cout << "\nModify Student Name: ";
    cin.getline(name, 20);
}

char* student::retadmno() {
    return admno;
}

const char* student::retstbno(int index) const {
    return stbno[index];
}

int student::rettoken() const {
    return token;
}

void student::addtoken(const char* bookno) {
    if (token < 3) {
        strcpy(stbno[token], bookno);
        token++;
    }
}

void student::resettoken(const char* bookno) {
    for (int i = 0; i < token; ++i) {
        if (strcmp(stbno[i], bookno) == 0) {
            for (int j = i; j < token - 1; ++j) {
                strcpy(stbno[j], stbno[j + 1]);
            }
            stbno[token - 1][0] = '\0';
            token--;
            break;
        }
    }
}

void student::report() const {
    cout << "\t" << admno << setw(20) << name << setw(10) << token << endl;
}


