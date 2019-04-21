//============================================================================
// Name        : hw3_ex5.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class SLNode
{
public:
    SLNode(const int e, SLNode *n = NULL) : elem(e), next(n) {}

private:
    int elem;
    SLNode *next;
    friend class SLList;
};

class SLList
{
  private:
    SLNode *head;
    SLNode* reverse_recursion_prv(SLNode *node);

  public:
    SLList(SLNode *h = NULL) : head(h){};
    ~SLList(){};

    // empty
    void empty();
    bool isEmpty();

    // Front
    void pushFront(int key);
    int topFront();
    void popFront();

    // Back
    void pushBack(int key);
    int topBack();
    void popBack();

    // find, remove
    SLNode* find(int key);
    void erase(int key);
    void remove(SLNode* node);

    // insert
    void addBefore(SLNode* node, int key);
    void addAfter(SLNode* node, int key);

    // print
    void print();

    // reverse
    void reverse_iterative();
    void reverse_recursion();
};

bool SLList::isEmpty()
{
    return (head == NULL);
}

void SLList::empty(){
    while(!isEmpty()){
        popFront();
    }
}


void SLList::print()
{
    if (isEmpty())
    {
        cout << "list is empty" << endl;
    }
    else
    {
        SLNode *cur = head;
        while (cur->next != NULL)
        {
            cout << cur->elem << ", ";
            cur = cur->next;
        }
        cout << cur->elem << endl;
    }
}

void SLList::pushFront(int key)
{
    SLNode *newNode = new SLNode(key);
    if (isEmpty())
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

int SLList::topFront()
{
    if (isEmpty())
    {
        throw out_of_range("list is empty");
    }
    else
    {
        return head->elem;
    }
}

void SLList::popFront()
{
    if (isEmpty())
    {
        throw out_of_range("list is empty");
    }
    else
    {
        SLNode *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void SLList::pushBack(int key)
{
    SLNode *newNode = new SLNode(key);
    if (isEmpty())
    {
        head = newNode;
    }
    else
    {
        SLNode *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }
}
int SLList::topBack()
{
    if (isEmpty())
    {
        throw out_of_range("list is empty");
    }
    else
    {
        SLNode *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        return cur->elem;
    }
    return 0;
}
void SLList::popBack()
{
    if (isEmpty())
    {
        throw out_of_range("list is empty");
    }
    else if (head->next == NULL)
    { // only 1 element
        delete head;
        head = NULL;
    }
    else
    { // more than 1 element
        SLNode *cur = head;
        while (cur->next->next != NULL)
        {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = NULL;
    }
}

SLNode* SLList::find(int key){
    SLNode * cur = head;
    while(cur != NULL){
        if(cur->elem == key) return cur;
        cur = cur->next;
    }
    return NULL;
}

void SLList::erase(int key){
    if(!isEmpty()){
        if(head->elem == key){ // found
            SLNode * tmp = head;
            head = head->next;
            delete tmp;
        }else{
            SLNode * cur = head;
            while(cur->next != NULL){
                if(cur->next->elem == key){ // found
                    SLNode * tmp = cur->next;
                    cur->next = cur->next->next; // new linked
                    delete tmp;
                    break;
                }
                cur = cur->next;    
            }
        }
    }
}

void SLList::remove(SLNode * node){
    if(!isEmpty()){
        if(head == node){
            head = head->next;
            delete node;
        }else{
            SLNode * cur = head;
            while(cur->next != NULL){
                if(cur->next == node){ // match
                    cur->next = cur->next->next;
                    delete node;
                    break;
                }
                cur = cur->next;
            }
        }
    }
}

/*
    Assumption: node belong to list
*/
void SLList::addBefore(SLNode *node, int key){
    if(head == node){
        pushFront(key);
    }else{
        SLNode * cur = head;
        while(cur->next != NULL){
            if(cur->next == node){
                SLNode * newNode = new SLNode(key);
                newNode->next = cur->next;
                cur->next = newNode;
                break;
            }
            cur = cur->next;
        }
    }
}

/*
    Assumption: node belong to list
*/
void SLList::addAfter(SLNode *node, int key){
    if(!node){
        throw invalid_argument("Node should not be equal null");
    }else{
        SLNode *newNode = new SLNode(key);
        newNode->next = node->next;
        node->next = newNode;
    }
}

/* 
Step 1:
    [Linked List]        NULL    head    head->next
    1st                  prev    cur     next
    2nd                          prev    cur         next
    ...
    [Linked List]        tail    NULL
    last                 cur     next
                         prev    cur
Step 2:
    Update head
 */
void SLList::reverse_iterative(){
    if(!isEmpty()){
        SLNode * cur = head;
        SLNode * pre = NULL;
        SLNode * next = NULL;
        while(cur != NULL){
            next = cur->next;
            cur->next = pre; // link the cur to pre
            pre = cur;
            cur = next;
        }
        head = pre;
    }
}

void SLList::reverse_recursion(){
    SLNode * node = reverse_recursion_prv(head);
    node->next = NULL;
}

SLNode* SLList::reverse_recursion_prv(SLNode *node){
    if(node->next == NULL){ // node is tail
        head = node;   // fix head pointer 
        return node;
    }else{
        SLNode * tmp = reverse_recursion_prv(node->next);
        tmp->next = node; // link the rest to curent node
        return node; 
    }
}
void sampleApp()
{
    SLList myList;
    vector<int> myVector1{1, 2, 3, 4, 5};
    vector<int> myVector2{6, 7, 8, 9, 10};

    cout << "current linked list: " << endl;
    myList.print();

    // Front operation
    cout << "push front 1, 2, 3, 4, 5 to linked list: " << endl;
    for (auto it : myVector1)
    {
        myList.pushFront(it);
    }
    myList.print();
    cout << "top front 1 element = " << myList.topFront() << endl;
    cout << "pop front 3 element, current linked list" << endl;
    myList.popFront();
    myList.popFront();
    myList.popFront();
    myList.print();

    // Back operation
    cout << "push back 6, 7, 8, 9, 10 to linked list: " << endl;
    for (auto it : myVector2)
    {
        myList.pushBack(it);
    }
    myList.print();
    cout << "top Back 1 element = " << myList.topBack() << endl;
    cout << "pop Back 1 element, current linked list" << endl;
    myList.popBack();
    myList.print();

    // Find & erase operation
    vector<int> l1{7, 2, 10};
    for(auto it: l1){
        cout << "find and remove element, key = " << it << endl;
        SLNode* tmp = myList.find(it);
        myList.remove(tmp);
        myList.print();
    }
    vector<int> l2{6, 3, 9};
    for(auto it : l2){
        cout << "remove element, key = "<< it << endl;
        myList.erase(it);
        myList.print();
    }

    // Add before/after operation
    SLNode * tmp = myList.find(8);
    vector<int> l3{11, 12, 13};
    for(auto it : l3){
        cout << "addBefore element(8), key = " << it << endl;
        myList.addBefore(tmp, it);
        myList.print();
    }
    tmp = myList.find(1);
    vector<int> l4{15, 16, 17};
    for(auto it : l4){
        cout << "addAfter element(1), key = " << it << endl;
        myList.addAfter(tmp, it);
        myList.print();
    }

    // Reverse
    cout << "reverse linked list" << endl;
    myList.reverse_iterative();
    // myList.reverse_recursion();
    myList.print();

    // empty list
    cout << "empty linked list" << endl;
    myList.empty();
    myList.print();
}

int main(){
    sampleApp();

    return 0;
}