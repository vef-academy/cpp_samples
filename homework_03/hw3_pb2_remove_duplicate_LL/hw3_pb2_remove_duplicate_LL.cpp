//============================================================================
// Name        : hw3_pb2_remove_duplicate_LL.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description : Remove duplicate in linked list
//============================================================================

#include <iostream>
#include <vector>
#include <forward_list>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* 
    Remove duplicate by sorting linked list
*/
void remove_duplicate_fast(forward_list<int>& lst){
    // sort linked list
    lst.sort();

    // remove duplicate
    for(auto it = lst.begin(); it != lst.end(); ){
        auto nextNode = next(it);
        if(nextNode == lst.end()){ // escape loop when reach tail
            break;
        }
        if(*nextNode == *it){ // duplicated
            lst.erase_after(it);
        }else{
            it++;
        }
    }
}

/* 
    Using hash table to check duplicate value in linked list
 */
void remove_duplicate_faster(forward_list<int>& lst){
    unordered_map<int, bool> umap;
    umap[*lst.begin()] = true; // store head node value in hash table

    for(auto it = lst.begin(); it != lst.end();){
        auto nextNode = next(it);
        if(nextNode == lst.end()){ // escape loop when reach tail
            break;
        }

        // Find next value in hash table
        if (umap.find(*nextNode) != umap.end()){// duplicated
            lst.erase_after(it);  
        }else{
            umap[*nextNode] = true;
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
    // remove_duplicate_fast(l1);
    remove_duplicate_faster(l1);
    print(l1);

    return 0;
}