//============================================================================
// Name        : hw3_ex2.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description : Implement queue using 2 stack
//============================================================================

#include <iostream>
#include <vector>
#include <exception>
#include <stack>
using namespace std;

class myQueue{
private:
    stack<int> stackIn;
    stack<int> stackOut;

public:    
    myQueue(){}
    void enqueue(int key);
    int dequeue();
};

void myQueue::enqueue(int key){
    stackIn.push(key);
}

int myQueue::dequeue(){
    if(stackOut.empty()){
        while(!stackIn.empty()){
            int tmp = stackIn.top();
            stackIn.pop();
            stackOut.push(tmp);
        }
    }
    if(stackOut.empty()){
        throw out_of_range("Error: queue is empty");
    }
    int result = stackOut.top();
    stackOut.pop();
    return result;
}

int main(){
    myQueue q;
    try{
        cout << "enqueue " << 1 << endl;
        q.enqueue(1);
        cout << "enqueue " << 2 << endl;
        q.enqueue(2);
        cout << "enqueue " << 3 << endl;
        q.enqueue(3);
        cout << "dequeue = " << q.dequeue() << endl;
        cout << "dequeue = " << q.dequeue() << endl;
        cout << "enqueue " << 7 << endl;
        q.enqueue(7);
        cout << "dequeue = " << q.dequeue() << endl;
        cout << "dequeue = " << q.dequeue() << endl;
        q.dequeue();
    }catch(const exception &e){
        cout << e.what() << endl;
    }

    return 0;
}