#ifndef QUEUE_H              
#define QUEUE_H           

#include <iostream>             

template <typename elemType>  
class Queue {                 
public:              

    Queue(int initialSize = 8)                            
        : arr(nullptr),                                
          capacity(initialSize),                      
          frontData(0),                              
          rear(0),                                 
          count(0) {                        
        if (capacity < 1)                  
            capacity = 1;                   
        arr = new elemType[capacity];         
    }                                          

    Queue(const Queue& other)               
        : arr(nullptr),                                
          capacity(other.capacity),                      
          frontData(0),                                   
          rear(0),                                       
          count(other.count) {                           
        arr = new elemType[capacity];                   
        for (int i = 0; i < count; ++i)                 
            arr[i] = other.arr[(other.frontData + i) % other.capacity]; 
        rear = count % capacity;                        
    }                                                

    Queue& operator=(const Queue& other) {              
        if (this != &other) {                        
            delete[] arr;                    
            capacity = other.capacity;    
            count = other.count;           
            frontData = 0;                      
            arr = new elemType[capacity];          
            for (int i = 0; i < count; ++i)           
                arr[i] = other.arr[(other.frontData + i) % other.capacity];  
            rear = count % capacity;                    
        }                                           
        return *this;
    }                         

    ~Queue() { delete[] arr; }               

    int size() const { return count; }              
    bool isEmpty() const { return count == 0; }   

    elemType& front() {                          
        if (isEmpty())                         
            std::cout << "queue is empty" << std::endl;  
        return arr[frontData];                          
    }
    const elemType& front() const {                 
        if (isEmpty())                         
            std::cout << "queue is empty" << std::endl;
        return arr[frontData];                        
    }


    void enqueue(const elemType& value) {            
        if (count == capacity)                     
            grow();                              
        arr[rear] = value;                      
        rear = (rear + 1) % capacity;              
        ++count;                                      
    }                                      

    elemType dequeue() {                                
        if (isEmpty()) {                                 
            std::cout << "queue is empty" << std::endl;  
            return elemType();                           
        }                                                
        elemType value = arr[frontData];                 
        frontData = (frontData + 1) % capacity;          
        --count;                                         
        return value;                                    
    }                                                   

private:                                                 
    elemType* arr;                                       
    int capacity;                                       
    int frontData;                                       
    int rear;                                           
    int count;

    void grow() {                                       
        int newCap = capacity * 2;                       
        elemType* newArr = new elemType[newCap];        
        for (int i = 0; i < count; ++i)                  
            newArr[i] = arr[(frontData + i) % capacity]; 
        delete[] arr;                                    
        arr = newArr;                                    
        capacity = newCap;                              
        frontData = 0;                                  
        rear = count;                                  
    }                                                   
};                                                       

#endif                                                  