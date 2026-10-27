#ifndef ARRAYLIST_H
#define ARRAYLIST_H
 
#include <iostream>

template <class T>
class arrayList{
private:
    T* list;
    int capacity;
    int listSize;
public:
    arrayList(int maxSize = 100){
        if (maxSize > 0) {
            capacity = maxSize;
        } else {
            capacity = 1;
        }
        list = new T[capacity];
        listSize = 0;
    }

    arrayList(const arrayList<T>& other){
        capacity = other.capacity;
        listSize = other.listSize;
        list = new T[capacity];
        for(int i = 0; i < listSize; i++){
            list[i] = other.list[i];
        }
    }

    ~arrayList(){
        delete[] list;
    }

    int maxListSize(){
        return capacity;
    }

    int size(){
        return listSize;
    }

    void print() const {
        for (int i = 0; i < listSize; i++) {
            std::cout << list[i];
        }
        std::cout << std::endl;
    }

    bool isItemAtEqual(int pos, T item) const {
        if (pos < 0 || pos >= listSize) {
            std::cout << "isItemAtEqual: position " << pos << " out of range" << std::endl;
            return false;
        }
        return list[pos] == item;
    }

    void insertAt(int pos, T item) {
        if (pos < 0 || pos >= capacity) {
            std::cout << "insertAt: position " << pos << " out of range" << std::endl;
            return;
        }
        list[pos] = item;
        if (pos >= listSize) {
            listSize = pos + 1;
        }
    }

    T retrieveAt(int pos) const {
        if (pos < 0 || pos >= listSize) {
            std::cout << "retrieveAt: position " << pos << " out of range" << std::endl;
            return T();
        }
        return list[pos];
    }

    void retrieveLast() const {
        if (listSize == 0) {
            std::cout << "retrieveLast: list is empty" << std::endl;
            return;
        }
        std::cout << list[listSize - 1] << std::endl;
    }

    arrayList<T>& operator=(const arrayList<T>& other) {
        if (this == &other) {
            return *this;
        }
        delete[] list;
        capacity = other.capacity;
        listSize = other.listSize;
        list = new T[capacity];
        for (int i = 0; i < listSize; i++) {
            list[i] = other.list[i];
        }
        return *this;
    }
};



#endif