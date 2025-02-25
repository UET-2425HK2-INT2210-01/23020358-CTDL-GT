#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class Queue{
    Node* head;
    public:
        Queue() : head(NULL){}
        void enqueue(int x){
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
        void dequeue(){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        void display(){
            Node* temp = head;
            while(temp) {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};
int main(){
    Queue q;
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i){
        string a;
        cin>>a;
        if(a == "enqueue"){
            int k;
            cin>>k;
            q.enqueue(k);
        } else if (a == "dequeue") {
            q.dequeue();
        }
    }
    q.display();
}