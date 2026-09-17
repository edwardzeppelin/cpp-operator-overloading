#ifndef STACK_H
#define STACK_H

#include <iostream>

struct node {
    int data;
    node* next;

    void setdata(int newdata) { data = newdata; }
    int getdata() { return data; }

};

class stack {
private:
    node* top;
    int size;
    int maxsize;

public:
    stack(int max);
    explicit stack();
    ~stack();

    void add(int x);
    void del();
    int peek();

    bool isempty() const;
    bool isfull();

    friend std::ostream& operator<<(std::ostream& os, const stack& st);
    friend std::istream& operator>>(std::istream& is, stack& st);

    stack& operator=(const stack& other);
    bool operator==(const stack& other) const;
    bool operator<(const stack& other) const;
    bool operator>(const stack& other) const;
    bool operator!() const;

    //friend stack operator-(const stack& stack1, const stack& stack2);

    friend stack operator-(const stack& stack1, const int x);

    stack& operator-=(const stack& other);
    stack& operator/=(const stack& other);

    stack operator/(int divisor);
    
    //friend stack operator/(stack stack1, const stack& stack2);

    //stack operator/(const stack& other) const;

    //stack operator/(const stack& otherStack);

};

#endif