//============================================================================
// Name        : hw3_pb2.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <forward_list>
#include <unordered_map>
using namespace std;

/* 
    Using hash table to check duplicate value in linked list
 */
void remove_duplicate(forward_list<int>& lst){
    unordered_map<int, int> umap;
    umap[*lst.begin()]++; // store head node value in hash

    for(auto it = lst.begin(); it != lst.end();){
        auto nextNode = next(it);
        if(nextNode == lst.end()){ // escape loop when reach tail
            break;
        }
        if (umap.find(*nextNode) != umap.end()){
            lst.erase_after(it);  
        }else{
            umap[*nextNode]++;
            it++;
        }
    }

}

void print(const forward_list<int>& l){
    for(auto it: l){
        cout << it << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1{1, 1, 1, 2, 3, 4, 10, 9, 9, 10, 3, 4, 5, 5, 5};
    forward_list<int> l1;
    for(auto it: v1){
        l1.push_front(it);
    }
    cout << "current list is " << endl;
    print(l1); 

    cout << "after remove duplicate " << endl;
    remove_duplicate(l1);
    print(l1);

    return 0;
}