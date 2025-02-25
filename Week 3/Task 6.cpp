//pesudo code operation function for Stack using Linkedlist

#include <iostream>
using namespace std;
//#1 implement Stack
struct Node{
    int data;
    Node* next;
};
class Stack{
    Node* head;
    public:
        Stack() : head(NULL){}

// implement function:
    //push(int x)
        void push(int x){
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = nullptr;
            if(!head) {
                head = newNode;
            } else {
                Node* temp = head;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    //pop()
        void pop(){
            Node* temp = head;
            while(temp->next->next){
                temp = temp->next;
            }
            Node* trash = temp->next;
            temp->next = nullptr;
            delete trash;
        }
        void display(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};
// complexity for both function will be O(n) with n = size of Stack