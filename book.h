#ifndef BOOK_H
#define BOOK_H

class book {
private:
    char bno[6];
    char bname[50];
    char aname[20];
public:
    void create_book();
    void show_book() const;
    void modify_book();
    const char* retbno() const;
    void report() const;
};

#endif
