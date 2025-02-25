//pseudo code operation function for Queue using Linkedlist
#include <iostream>
using namespace std;
//#1 implement Queue structure with Linkedlist
struct Node {
    int data;
    Node* next;
};
class Queue {
    Node* head;
    public:
    Queue() : head(nullptr){};
//#2 implement operation include:
    //enqueue:
        void enqueue(int x) {
            Node* temp = new Node();
            temp->data = x;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                return;
            } else {
                Node* ptr = head;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = temp;
                return;
            }
        }
    //dequeue:
        void dequeue() {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
};
//the function enqueue() require n + 3 step (with n = size of queue) so the function has complexity O(n)
//the function dequeue() require 3 step so the function has complexity O(1)