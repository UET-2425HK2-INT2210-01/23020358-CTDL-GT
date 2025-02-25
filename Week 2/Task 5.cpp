#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class Stack{
    Node* head;
    public:
        Stack() : head(NULL){}
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
int main(){
    Stack s;
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i){
        string a;
        cin>>a;
        if (a == "push"){
            int k;
            cin>>k;
            s.push(k);
        } else s.pop();
    }
    s.display();
}
