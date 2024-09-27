#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>

class listADT {
protected:
    int size;
    int* arr;

public:
    listADT() : size(0), arr(nullptr) {}

    ~listADT() {
        delete[] arr;
    }

    virtual void fullDate() = 0;
    virtual void increaseSize() = 0;
    virtual void push() = 0;
};

#endif 
