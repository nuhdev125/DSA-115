#include "array.h"
#include <iostream>

using namespace std;

class newList : public listADT {
public:
    newList() {
        cout << "Enter the size of the array: ";
        cin >> size;
        arr = new int[size];
    }

    ~newList() {
        delete[] arr;
    }

    void fullDate() override {
        for (int i = 0; i < size; ++i) {
            arr[i] = i * 2;
        }
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << "--";
        }
        cout << endl;
    }

    void increaseSize() override {
        int newSize = size * 2;
        int* newarr = new int[newSize];

        for (int k = 0; k < newSize; ++k) {
            if (k < size) {
                newarr[k] = arr[k];
            } else {
                newarr[k] = k * 2;
            }
        }

        delete[] arr;
        arr = newarr;
        size = newSize;

        for (int k = 0; k < size; ++k) {
            cout << arr[k] << "--";
        }
        cout << endl;
    }

    void push() override {
        int newSize = size - 1;
        int* newarray = new int[newSize];

        for (int a = 0; a < size; a++) {
            newarray[a] = arr[a];
        }

        delete[] arr;
        arr = newarray;
        size = newSize;

        for (int a = 0; a < size; a++) {
            cout << arr[a] << endl;
        }
    }
};

int main() {
    newList obj;
    obj.fullDate();
    obj.increaseSize();
    obj.push();

    return 0;
}
