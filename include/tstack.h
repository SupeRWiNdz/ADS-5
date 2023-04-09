// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class TStack {
 private:
    T arr[size] = { 0 };
    int top;
 public:
    TStack() : top(-1) {}
    void push(const T& value) {
        if (isFull()) {
            throw std::string("Full");
        } else {
            arr[++top] = value;
        }
    }
    const T& pop() { return arr[top--]; }
    const T& getTop() const {
        if (isEmpty())
            throw std::string("Empty!");
        else
            return arr[top];
    }
    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == size - 1; }
};

#endif  // INCLUDE_TSTACK_H_
