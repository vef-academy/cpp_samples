//============================================================================
// Name        : AvlTree.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description : This program shows that stack variables, be they objects or
// pointers, get destroyed when they go out of scope
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class AvlNode {
private:    
    int key;
    AvlNode * LeftNode;
    AvlNode * RightNode;
    AvlNode *Parent;     // ignore if you don't need it
    int height;          // need to recompute during rebalance
                         // or use height() function instead
friend class AvlTree;

public:
    AvlNode(int key): key(key), LeftNode(NULL), RightNode(NULL),
        Parent(NULL), height(0){}  
};

class AvlTree{
private:
    AvlNode * root;
public:
    AvlTree(): root(NULL){};
    AvlTree(int key): root(new AvlNode(key)){};

    void Insert(int key);
    void Delete(AvlNode * node);
    AvlNode * Search(int key) const;
    // Check function
    bool isTreeBalanced() const;
    void printInOrder() const;
    void printPreOrder() const;
    void printPostOrder() const;
};

void AvlTree::Insert(int key){
    // Implement correct algorithm here
    
}

void AvlTree::Delete(AvlNode * node){
    // Implement correct algorithm here

}

AvlNode * AvlTree::Search(int key) const{
    // Implement correct algorithm here

    return new AvlNode(key);
}

bool AvlTree::isTreeBalanced() const{
    // Implement correct algorithm here

    return false;
}

void AvlTree::printInOrder() const{
    // Implement correct algorithm here

}

void AvlTree::printPreOrder() const{
    // Implement correct algorithm here

}
void AvlTree::printPostOrder() const{
    // Implement correct algorithm here

}

int main(){
    AvlTree tree;
    // Basic test insert function
    vector<int> listNode{40, 20, 60, 10, 30, 50, 70, \
                         5, 1, 35, 37, 45, 47, 75, 72};
    for(auto it: listNode){
        tree.Insert(it);
        if(!tree.isTreeBalanced()){
            cout << "Tree is un-balance, after inserting " << it << endl;
            break;
        }
    }

    return 0;
}