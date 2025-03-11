#include<iostream>
using namespace std;
struct Node{
    char data;
    Node* next;
};
class Stack{
    Node* head;
    public:
        Stack() : head(NULL){}
        void push(char x){
            Node* newNode = new Node();
            newNode->data = x;
            newNode->next = head;
            head = newNode;
            return;
        }
        void pop(){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        char top(){
            if (head == nullptr) return ' ';
            return head->data;
        }
        bool isempty() {
            if(head == nullptr) return true;
            else return false;
        }
};
bool ispair(char a, char b) {
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    else return false;
}
int main() {
    Stack s;
    string input;
    cin>>input; 
    for (int i = 0; i < input.length(); i++) {
        if (!ispair(s.top(), input[i]) || s.isempty()) s.push(input[i]);
        else s.pop();
    }
    if (s.isempty()) cout<<"Valid";
    else cout<<"Invalid";
}