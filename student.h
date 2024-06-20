#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class student {
    char admno[6];
    char name[20];
    char stbno[3][6]; // Array to store up to 3 book numbers
    int token; // Count of issued books

public:
    void create_student();
    void show_student() const;
    void modify_student();
    char* retadmno();
    const char* retstbno(int index) const; // Access specific book number
    int rettoken() const;
    void addtoken(const char* bookno); // Add a specific book number
    void resettoken(const char* bookno); // Reset a specific book number
    void report() const;
};

#endif // STUDENT_H

