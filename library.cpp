#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "student.h"
#include "book.h"
#include "library.h"

using namespace std;

fstream fp, fp1;
student st;
book bk;

void writestudent() {
    fp.open("student.dat", ios::out | ios::app);
    st.create_student();
    fp.write(reinterpret_cast<char*>(&st), sizeof(student));
    fp.close();
    cout << "\n\nStudent record has been created";
    cin.ignore();
}

void writebook() {
    fp.open("book.dat", ios::out | ios::app);
    bk.create_book();
    fp.write(reinterpret_cast<char*>(&bk), sizeof(book));
    fp.close();
    cout << "\n\nBook has been created";
    cin.ignore();
}

void displaysps(const char* n) {
    cout << "\nSTUDENT DETAILS\n";
    int flag = 0;
    fp.open("student.dat", ios::in);
    while (fp.read(reinterpret_cast<char*>(&st), sizeof(student))) {
        if (strcmp(st.retadmno(), n) == 0) {
            st.show_student();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nStudent does not exist";
    cin.ignore();
}

void displayspb(const char* n) {
    cout << "\nBOOK DETAILS\n";
    int flag = 0;
    fp.open("book.dat", ios::in);
    while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book))) {
        if (strcmp(bk.retbno(), n) == 0) {
            bk.show_book();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nBook does not exist";
    cin.ignore();
}

void modifystudent() {
    char n[6];
    int found = 0;
    cout << "\n\n\tMODIFY STUDENT RECORD.... ";
    cout << "\n\n\tEnter The Student ID of The student";
    cin >> n;
    cin.ignore();
    fp.open("student.dat", ios::in | ios::out);
    while (fp.read(reinterpret_cast<char*>(&st), sizeof(student)) && found == 0) {
        if (strcmp(st.retadmno(), n) == 0) {
            st.show_student();
            cout << "\nEnter The New Details of student";
            st.modify_student();
            int pos = -1 * static_cast<int>(sizeof(st));
            fp.seekp(pos, ios::cur);
            fp.write(reinterpret_cast<char*>(&st), sizeof(student));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    cin.ignore();
}

void modifybook() {
    char n[6];
    int found = 0;
    cout << "\n\n\tMODIFY BOOK RECORD... ";
    cout << "\n\n\tEnter The book no. of The book";
    cin >> n;
    cin.ignore();
    fp.open("book.dat", ios::in | ios::out);
    while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book)) && found == 0) {
        if (strcmp(bk.retbno(), n) == 0) {
            bk.show_book();
            cout << "\nEnter The New Details of book";
            bk.modify_book();
            int pos = -1 * static_cast<int>(sizeof(bk));
            fp.seekp(pos, ios::cur);
            fp.write(reinterpret_cast<char*>(&bk), sizeof(book));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    cin.ignore();
}

void deletestudent() {
    char n[6];
    int flag = 0;
    cout << "\n\n\n\tDELETE STUDENT...";
    cout << "\n\nEnter The Student ID of The Student You Want To Delete: ";
    cin >> n;
    cin.ignore();
    fp.open("student.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read(reinterpret_cast<char*>(&st), sizeof(student))) {
        if (strcmp(st.retadmno(), n) != 0) {
            fp2.write(reinterpret_cast<char*>(&st), sizeof(student));
        } else {
            flag = 1;
        }
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    if (flag == 1)
        cout << "\n\n\tRecord Deleted ..";
    else
        cout << "\n\nRecord not found";
    cin.ignore();
}

void deletebook() {
    char n[6];
    int flag = 0;
    cout << "\n\n\n\tDELETE BOOK ...";
    cout << "\n\nEnter The Student ID of The Book You Want To Delete: ";
    cin >> n;
    cin.ignore();
    fp.open("book.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book))) {
        if (strcmp(bk.retbno(), n) != 0) {
            fp2.write(reinterpret_cast<char*>(&bk), sizeof(book));
        } else {
            flag = 1;
        }
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("temp.dat", "book.dat");
    if (flag == 1)
        cout << "\n\n\tRecord Deleted ..";
    else
        cout << "\n\nRecord not found";
    cin.ignore();
}

void displayallstudents() {
    fp.open("student.dat", ios::in);
    if (!fp) {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\t\tSTUDENT LIST\n\n";
    cout << "====================================================\n";
    cout << "Student ID         Name          Book Issued\n";
    cout << "====================================================\n";
    while (fp.read(reinterpret_cast<char*>(&st), sizeof(student))) {
        st.report();
    }
    fp.close();
    cin.ignore();
    cin.get();
}

void displayallbooks() {
    fp.open("book.dat", ios::in);
    if (!fp) {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\t\tBOOK LIST\n\n";
    cout << "====================================================\n";
    cout << "Book Number           Book Name                Author\n";
    cout << "====================================================\n";
    while (fp.read(reinterpret_cast<char*>(&bk), sizeof(book))) {
        bk.report();
    }
    fp.close();
    cin.ignore();
    cin.get();
}

void bookissue() {
    char sn[6], bn[6];
    int found = 0, flag = 0;
    cout << "\n\nBOOK ISSUE ...";
    cout << "\n\n\tEnter The student's ID: ";
    cin >> sn;
    cin.ignore();
    fp.open("student.dat", ios::in | ios::out);
    fp1.open("book.dat", ios::in | ios::out);
    while (fp.read(reinterpret_cast<char*>(&st), sizeof(student)) && found == 0) {
        if (strcmp(st.retadmno(), sn) == 0) {
            found = 1;
            if (st.rettoken() < 3) {
                cout << "\n\n\tEnter the book no.: ";
                cin >> bn;
                cin.ignore();
                while (fp1.read(reinterpret_cast<char*>(&bk), sizeof(book)) && flag == 0) {
                    if (strcmp(bk.retbno(), bn) == 0) {
                        bk.show_book();
                        flag = 1;
                        st.addtoken(bk.retbno());
                        int pos = -1 * static_cast<int>(sizeof(st));
                        fp.seekp(pos, ios::cur);
                        fp.write(reinterpret_cast<char*>(&st), sizeof(student));
                        cout << "\n\n\t Book issued successfully\n\nPlease Note: Write the current date in backside of your book and submit within 15 days fine Rs. 1 for each day after 15 days period";
                    }
                }
                if (flag == 0)
                    cout << "Book no does not exist";
            } else
                cout << "You have already issued 3 books. Return a book to issue a new one.";
        }
    }
    if (found == 0)
        cout << "Student record not exist...";
    fp.close();
    fp1.close();
    cin.ignore();
    cin.get();
}


void bookdeposit() {
    char sn[6], bn[6];
    int found = 0, flag = 0, day, fine;
    cout << "\n\nBOOK DEPOSIT ...";
    cout << "\n\n\tEnter The student's ID: ";
    cin >> sn;
    cin.ignore();
    fp.open("student.dat", ios::in | ios::out);
    fp1.open("book.dat", ios::in | ios::out);
    while (fp.read(reinterpret_cast<char*>(&st), sizeof(student)) && found == 0) {
        if (strcmp(st.retadmno(), sn) == 0) {
            found = 1;
            if (st.rettoken() > 0) {
                cout << "\n\n\tEnter the book no.: ";
                cin >> bn;
                cin.ignore();
                while (fp1.read(reinterpret_cast<char*>(&bk), sizeof(book)) && flag == 0) {
                    if (strcmp(bk.retbno(), bn) == 0) {
                        bk.show_book();
                        flag = 1;
                        cout << "\n\nEnter the number of days the book was issued: ";
                        cin >> day;
                        cin.ignore();
                        if (day > 15) {
                            fine = (day - 15) * 1;
                            cout << "\n\nFine = " << fine;
                        }
                        st.resettoken(bn);
                        int pos = -1 * static_cast<int>(sizeof(st));
                        fp.seekp(pos, ios::cur);
                        fp.write(reinterpret_cast<char*>(&st), sizeof(student));
                        cout << "\n\n\t Book deposited successfully";
                    }
                }
                if (flag == 0)
                    cout << "Book no does not exist";
            } else
                cout << "No books issued currently.";
        }
    }
    if (found == 0)
        cout << "Student record not exist...";
    fp.close();
    fp1.close();
    cin.ignore();
    cin.get();
}

void intro() {
    cout << "\n\n\t\tLIBRARY MANAGEMENT SYSTEM";
    cout << "\n\n\t\tMADE BY : Pranshu Chauhan";
    cout << "\n\t\tDATE: 2024";
    cin.get();
}

void adminmenu() {
    char ch2;
    cout << "\n\n\n\tADMIN MENU";
    cout << "\n\n\t1.CREATE STUDENT RECORD";
    cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout << "\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout << "\n\n\t4.MODIFY STUDENT RECORD";
    cout << "\n\n\t5.DELETE STUDENT RECORD";
    cout << "\n\n\t6.CREATE BOOK ";
    cout << "\n\n\t7.DISPLAY ALL BOOKS ";
    cout << "\n\n\t8.DISPLAY SPECIFIC BOOK ";
    cout << "\n\n\t9.MODIFY BOOK ";
    cout << "\n\n\t10.DELETE BOOK ";
    cout << "\n\n\t11.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-11) ";
    ch2 = cin.get();
    cin.ignore();
    switch (ch2) {
    case '1':
        writestudent();
        break;
    case '2':
        displayallstudents();
        break;
    case '3': {
        char num[6];
        cout << "\n\n\tPlease Enter The Admission No.: ";
        cin >> num;
        cin.ignore();
        displaysps(num);
        break;
    }
    case '4':
        modifystudent();
        break;
    case '5':
        deletestudent();
        break;
    case '6':
        writebook();
        break;
    case '7':
        displayallbooks();
        break;
    case '8': {
        char num[6];
        cout << "\n\n\tPlease Enter The book No.: ";
        cin >> num;
        cin.ignore();
        displayspb(num);
        break;
    }
    case '9':
        modifybook();
        break;
    case '10':
        deletebook();
        break;
    case '11':
        return;
    default:
        cout << "\a";
        adminmenu();
    }
}

