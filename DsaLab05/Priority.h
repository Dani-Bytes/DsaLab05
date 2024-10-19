#pragma once
#include <iostream>
using namespace std;

class Priority {
private:
    int front, rear, currSize;
    int maxSize;
    int* arr;

public:
    Priority(int maxSize) : maxSize(maxSize), currSize(0), front(0), rear(-1) {
        arr = new int[maxSize];
    }

    ~Priority() {
        delete[] arr;
    }

    bool isempty() {
        return currSize == 0;
    }

    bool isfull() {
        return currSize == maxSize;
    }

    void insert(int a) {
        if (isfull()) {
            return; 
        }

        rear++;
        arr[rear] = a;
        currSize++;
    }

    void remove() {
        if (isempty()) {
            return; 
        }

        front++;
        currSize--;

        if (currSize == 0) {
            front = 0;
            rear = -1;
        }
    }

    int size() {
        return currSize;
    }

    int getValue(int index) {
        return arr[index];
    }

    void merge(Priority& other) {
        for (int i = 0; i < other.size(); i++) {
            insert(other.getValue(i)); 
        }
    }

    void clear() {
        front = 0;
        rear = -1;
        currSize = 0;
    }
};