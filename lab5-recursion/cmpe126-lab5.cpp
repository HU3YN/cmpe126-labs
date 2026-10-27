#include <iostream>
#include <vector>
#include <string>

using namespace std;

int factorial(int n){
    if(n < 0){
        return -1;
    }
    if(n <= 1){
        return 1;
    }
    return n * factorial(n-1);
}

bool isSortedHelper(const vector<int> &arr, int i){
    if(i+1 >= (int)arr.size()){
        return true; 
    }
    if(arr[i] > arr[i+1]){
        return false;
    }
    return isSortedHelper(arr, i+1);
}

bool isSorted(const vector<int> &arr){
    return isSortedHelper(arr, 0);
}

string reverse(const string &input){
    if(input.size() <= 1){
        return  input;
    }
    return reverse(input.substr(1)) + input[0];

}

int fibonacci(int n, vector<int> &arr) {
    if(n < 0) return -1;
    arr[n]++;
    if(n == 0 || n == 1) return 1;
    else return fibonacci((n - 1), arr) + fibonacci((n - 2), arr);
}

void printFib(const vector<int> &arr){
    int total = 0;
    cout << "Fibonacci call\tNumber of calls" << endl;
    for (int i = (int)arr.size() - 1; i >= 0; i--){
        cout << "fibonacci(" << i << ")\t" << arr[i] << endl;
        total += arr[i];
    }
    cout << "Total calls\t" << total << endl;
}

int fibonacciMemo(int n, vector<int> &arr, vector<int> &cache) {
    if(n < 0) return -1;
    arr[n]++;
    if(n == 0 || n == 1) return 1;
    if(cache[n] != -1) return cache[n];
    int result = fibonacciMemo((n - 1), arr, cache) + fibonacciMemo((n - 2), arr, cache);
    cache[n] = result;
    return result;
}

struct SNode {
    int elt;
    SNode *next;
};

SNode *merge(SNode *a, SNode *b){
    SNode *head = nullptr;
    SNode *tail = nullptr;

    while(a != nullptr && b != nullptr){
        SNode *smallN;
        if(a->elt <= b->elt){
            smallN = a;
            a = a->next;
        }
        else{
            smallN = b;
            b = b->next;
        }

        if(head == nullptr){
            head = smallN;
            tail = smallN;
        }
        else{
            tail->next = smallN;
            tail = smallN;
        }
    }
    SNode *extra = nullptr;
    if(a == nullptr){
        extra = b;
    }
    else{
        extra = a;
    }

    if(head == nullptr){
        head = extra;
    }
    else{
        tail->next = extra;
    }
    return head;
}

SNode *mergeSort(SNode *head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    SNode *cut = head;
    SNode *end = head->next;
    while(end != nullptr && end->next != nullptr){
        cut = cut->next;
        end = end->next->next;
    }
    SNode *halfHead = cut->next;
    cut->next = nullptr;

    SNode *left = mergeSort(head);
    SNode *right = mergeSort(halfHead);
    return merge(left, right);

}



SNode *makeList(vector<int> arr){
    SNode *head = nullptr;
    SNode *tail = nullptr;
    for(int i = 0; i < (int)arr.size(); i++){
        SNode *node = new SNode{arr[i], nullptr};
        if(head == nullptr){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(SNode *head){
    SNode *temp = head;
    while(temp != nullptr){
        cout << temp->elt;
        if(temp->next != nullptr){
            cout << " ";
        }
        temp = temp->next;
    }
    cout << endl;

}



int main(){

    cout << factorial(10) << endl;

    vector<int> sorted = {0,2,4,5,6};
    vector<int> unsorted = {3,5,2,9,10};

    cout << isSorted(sorted) << endl;
    cout << isSorted(unsorted) << endl;

    string test = "test";
    cout << reverse(test) << endl;

    int num = 39;
    vector<int> fib(num + 1, 0);
    fibonacci(num, fib);
    printFib(fib);

    vector<int> cache(num + 1, -1);
    vector<int> fibmem(num + 1, 0);
    fibonacciMemo(num, fibmem, cache);
    printFib(fibmem);

    vector<int> merge0 = {};
    SNode *test0 = makeList(merge0);
    printList(mergeSort(test0));

    vector<int> merge1 = {1};
    SNode *test1 = makeList(merge1);
    printList(mergeSort(test1));

    vector<int> merge2 = {2, 1};
    SNode *test2 = makeList(merge2);
    printList(mergeSort(test2));

    vector<int> merge3 = {1, 3, 2, 5, 4};
    SNode *test3 = makeList(merge3);
    printList(mergeSort(test3));

    vector<int> merge4 = {4, 2, 4, 9, 10};
    SNode *test4 = makeList(merge4);
    printList(mergeSort(test4));

    vector<int> merge5 = {3, 20, 6, 8, 12, 4, 2, 6, 10, 
        9, 31, 22, 9, 13, 40, 1, 90, 73, 53, 3, 54, 23,
        59, 92, 29, 42, 19, 7, 69, 72, 82, 99, 57, 28, 0};
    SNode *test5 = makeList(merge5);
    printList(mergeSort(test5));

    

    return 0;
}