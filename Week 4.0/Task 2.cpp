#include<iostream>
using namespace std;
struct Node {
    int key;
    int data;
    Node* pre;
    Node* next;
    Node(int val, int prio) : data(val), key(prio), pre(NULL), next(NULL) {} 
}; 
class PrioQueue {
    Node* head;
    public:
    PrioQueue() : head(nullptr){}
    void enqueue(int val, int prio) {
        Node* newnode = new Node(val, prio);
    if (head == nullptr) {
        head = newnode;
    } else {
        Node* temp = head;
        if (newnode->key > temp->key) {
            newnode->next = head;
            head->pre = newnode;
            head = newnode;
            return;
        } else {
            while (temp->next != nullptr && temp->key >= newnode->key) {
                temp = temp->next;
            }
            if (temp->next == nullptr) {
                temp->next = newnode;
                newnode->pre = temp;
                return;
            } else {
                newnode->next = temp;
                if (temp->pre != nullptr) {
                    temp->pre->next = newnode;
                }
                newnode->pre = temp->pre;
                temp->pre = newnode;
                return;
            }
        }
    }
}
    void dequeue() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            head = NULL;
            return;
        }
        head = head->next;
        head->pre = nullptr;
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout<<'('<<temp->data<<", "<<temp->key<<");";
            temp = temp->next;
        }
    }
};
int main() {
    int n;
    PrioQueue queue;
    cin>>n;
    for (int i = 0; i < n; i++) {
        string s;
        int v,k;
        cin>>s;
        if (s == "enqueue") {
            cin>>v>>k;
            queue.enqueue(v,k);
        } else {
            queue.dequeue();
        }
    }
    queue.display();
}