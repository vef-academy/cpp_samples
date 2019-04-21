//============================================================================
// Name        : hw3_ex2.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description : Tower of Hanoi recursive solution
//============================================================================

#include <iostream>
#include <vector>
#include <exception>
#include <stack>
#include <string>
using namespace std;

struct myStack{
    myStack(string name="src"):name(name){}
    stack<int> disk;
    string name;
};

void moveOneDisk(myStack& src, myStack& dest){
    if(src.disk.empty()){
        throw out_of_range("Error: stack is empty");
    }
    int val = src.disk.top();
    src.disk.pop();
    dest.disk.push(val);
    cout << "move disk = " << val << 
        " from " << src.name << " to " << dest.name << endl;
}

void moveDisk(int num_disks, myStack& src, myStack& dest, myStack& aux){
    if(num_disks == 1){
        // move src -> dest
        moveOneDisk(src, dest);
    }else{
        // move n-1 disks src -> tmp
        moveDisk(num_disks - 1, src, aux, dest);
        // move 1 disk src -> dest
        moveOneDisk(src, dest);
        // move n-1 disks tmp -> dest
        moveDisk(num_disks - 1, aux, dest, src);
    }
}

int main(){
    myStack src("src");
    myStack dest("dest");
    myStack aux("aux");
    // vector<int> v1{4, 3, 2, 1};
    vector<int> v1{2, 1};
    for(auto it: v1){
        src.disk.push(it);
    }
    moveDisk(src.disk.size(), src, dest, aux);
}