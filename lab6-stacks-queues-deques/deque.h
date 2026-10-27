#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

template <typename elemType>
class Deque {
public:

    Deque(int initialSize = 8)
        : arr(nullptr),
          capacity(initialSize),
          front(0),
          rear(0),
          count(0) {
        if (capacity < 1)
            capacity = 1;
        arr = new elemType[capacity];
    }

    Deque(const Deque& other)
        : arr(nullptr),
          capacity(other.capacity),
          front(0),
          rear(0),
          count(other.count) {
        arr = new elemType[capacity];
        for (int i = 0; i < count; ++i)
            arr[i] = other.arr[(other.front + i) % other.capacity];
        rear = count % capacity;
    }

    Deque& operator=(const Deque& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            count = other.count;
            front = 0;
            arr = new elemType[capacity];
            for (int i = 0; i < count; ++i)
                arr[i] = other.arr[(other.front + i) % other.capacity];
            rear = count % capacity;
        }
        return *this;
    }

    ~Deque() { delete[] arr; }

    int size() const { return count; }
    bool isEmpty() const { return count == 0; }

    elemType& first() {
        if (isEmpty())
            std::cout << "deque is empty" << std::endl;
        return arr[front];
    }
    const elemType& first() const {
        if (isEmpty())
            std::cout << "deque is empty" << std::endl;
        return arr[front];
    }

    elemType& last() {
        if (isEmpty())
            std::cout << "deque is empty" << std::endl;
        return arr[(rear - 1 + capacity) % capacity];
    }
    const elemType& last() const {
        if (isEmpty())
            std::cout << "deque is empty" << std::endl;
        return arr[(rear - 1 + capacity) % capacity];
    }

    void insertFront(const elemType& value) {
        if (count == capacity)
            grow();
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        ++count;
    }

    void insertBack(const elemType& value) {
        if (count == capacity)
            grow();
        arr[rear] = value;
        rear = (rear + 1) % capacity;
        ++count;
    }

    elemType removeFront() {
        if (isEmpty()) {
            std::cout << "deque is empty" << std::endl;
            return elemType();
        }
        elemType value = arr[front];
        front = (front + 1) % capacity;
        --count;
        return value;
    }

    elemType removeBack() {
        if (isEmpty()) {
            std::cout << "deque is empty" << std::endl;
            return elemType();
        }
        rear = (rear - 1 + capacity) % capacity;
        elemType value = arr[rear];
        --count;
        return value;
    }

private:
    elemType* arr;
    int capacity;
    int front;
    int rear;
    int count;

    void grow() {
        int newCap = capacity * 2;
        elemType* newArr = new elemType[newCap];
        for (int i = 0; i < count; ++i)
            newArr[i] = arr[(front + i) % capacity];
        delete[] arr;
        arr = newArr;
        capacity = newCap;
        front = 0;
        rear = count;
    }
};

#endif