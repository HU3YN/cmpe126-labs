#ifndef STACKQUEUE_H         
#define STACKQUEUE_H        

#include "queue.h"           


template <typename elemType>  
class StackQueue {              
public:                        


    StackQueue(int initialSize = 8)                     
        : q(initialSize) {}                         


    StackQueue(const StackQueue& other)                  
        : q(other.q) {}                                

    StackQueue& operator=(const StackQueue& other) {     
        if (this != &other)                             
            q = other.q;                                
        return *this;                                 
    }                                          

    ~StackQueue() {}                            

    int size() const { return q.size(); }               
    bool isEmpty() const { return q.isEmpty(); }       

    elemType& top() { return q.front(); }               
    const elemType& top() const { return q.front(); }   


    void push(const elemType& value) {                   
        int olderCount = q.size();                      
        q.enqueue(value);                               
        for (int i = 0; i < olderCount; ++i)            
            q.enqueue(q.dequeue());                     
    }                                                  

    elemType pop() {                                     
        return q.dequeue();                             
    }                                              

private:                                                
    Queue<elemType> q;                                  
};                                      

#endif                                   