#include <iostream>            
#include <string>           
#include <vector>               

#include "queue.h"          
#include "stackqueue.h"  
#include "deque.h"        

using namespace std;           

vector<double> movingAverage(const vector<int>& data, int k) {
    vector<double> result;                               
    int n = static_cast<int>(data.size());         
    if (k <= 0 || k > n)                               
        return result;                           

    Queue<int> window(k + 1);                           
    long long sum = 0;                                   

    for (int i = 0; i < n; ++i) {                       
        window.enqueue(data[i]);                        
        sum += data[i];                                  
        if (window.size() > k)                           
            sum -= window.dequeue();                    
        if (window.size() == k)                          
            result.push_back(static_cast<double>(sum) / k);  
    }                                         
    return result;                       
}                                         

bool isPalindrome(const string& s) {
    StackQueue<char> stack(static_cast<int>(s.size()) + 1); 
    for (size_t i = 0; i < s.size(); ++i)              
        stack.push(s[i]);                            

    size_t half = s.size() / 2;                         
    for (size_t i = 0; i < half; ++i) {                
        if (s[i] != stack.pop())                         
            return false;                           
    }                                             
    return true;                                       
}                                              

vector<int> windowMax(const vector<int>& data, int k) {
    vector<int> result;                    
    int n = static_cast<int>(data.size());            
    if (k <= 0 || k > n)                      
        return result;                     

    const vector<int>& arr = data;                  
    Deque<int> dq(k + 1);                              

    for (int i = 0; i < n; ++i) {            
        if (!dq.isEmpty() && dq.first() <= i - k)     
            dq.removeFront();                       
        while (!dq.isEmpty() && arr[dq.last()] <= arr[i]) 
            dq.removeBack();                            
        dq.insertBack(i);                         
        if (i >= k - 1)                            
            result.push_back(arr[dq.first()]);         
    }                                              
    return result;                               
}                                    


int main() {
    vector<int> a;                                      
    a.push_back(2);
    a.push_back(-1); 
    a.push_back(3); 
    a.push_back(-4); 
    a.push_back(5); 
    a.push_back(1);  
    vector<double> avg = movingAverage(a, 3);   
    cout << "movingAverage: ";                       
    for (size_t i = 0; i < avg.size(); ++i)         
        cout << avg[i] << " ";                         
    cout << endl;                            

    cout << boolalpha;    
    cout << "racecar  " << isPalindrome("racecar") << endl;  
    cout << "bbcddcbb  " << isPalindrome("bbcddcbb") << endl;  
    cout << "abca   " << isPalindrome("abca") << endl;       
    cout << "(empty)  " << isPalindrome("") << endl;      

    vector<int> b;                            
    b.push_back(1); 
    b.push_back(3); 
    b.push_back(-1); 
    b.push_back(-3);
    b.push_back(5); 
    b.push_back(3); 
    b.push_back(6); 
    b.push_back(7); 
    vector<int> mx = windowMax(b, 3);       
    cout << "windowMax: ";              
    for (size_t i = 0; i < mx.size(); ++i)    
        cout << mx[i] << " ";           
    cout << endl;                           
    return 0;
}                        
                        