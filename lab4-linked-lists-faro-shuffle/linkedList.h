#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct LinkedListNode {
    LinkedListNode<T> *next;
    T elt;

    LinkedListNode(T _elt) : next(nullptr), elt(_elt) {}
    ~LinkedListNode() = default;
};

template <typename T>
class LinkedList {
    private:
        LinkedListNode<T> *head;
        LinkedListNode<T> *tail;
        int count;
    
    public:

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~LinkedList(){
        LinkedListNode<T> *current = head;
        while (current != nullptr){
            LinkedListNode<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    LinkedList(const LinkedList<T>& other){
        head = nullptr;
        tail = nullptr;
        count = 0;

        LinkedListNode<T> *cur = other.head;
        while (cur != nullptr){
            append(cur->elt);
            cur = cur->next;
        }

    }

    bool isEmpty() const {
        return count == 0;
    }

    void append(T elt){
        LinkedListNode<T> *node = new LinkedListNode<T>(elt);
        if(tail == nullptr){
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        count++;
    }

    int getCount(){
        return count;
    }

    LinkedListNode<T>* getHead() const {
        return head;
    }

    LinkedListNode<T>* getTail() const {
        return tail;
    }

    void setHead(LinkedListNode<T>* newHead){
        head = newHead;
        if(head == nullptr){
            tail = nullptr;
            count = 0;
            return;
        }
        LinkedListNode<T>* cur = head;
        int n = 1;
        while(cur->next != nullptr){
            cur = cur->next;
            n++;
        }
        tail = cur;
        count = n;
    }

    bool equals(LinkedList<T>& other){
        if(count != other.count){
            return false;
        }
        LinkedListNode<T> *a = head;
        LinkedListNode<T> *b = other.head;
        while(a != nullptr && b != nullptr){
            if(!(a->elt == b->elt)){
                return false;
            }
            a = a->next;
            b = b->next;
        }
        return a == nullptr && b == nullptr;
    }




};


#endif // LINKEDLIST_H
