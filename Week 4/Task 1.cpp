#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class Linkedlist {
    public:
    Node* head;
    int size;
    Linkedlist() : head(nullptr), size(0) {}
    void append(int a) {
        Node* temp = new Node();
            temp->data = a;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                size++;
                return;
            } else {
                Node* ptr = head;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = temp;
                size++;
                return;
            }
        }
    string search(int x) {
        Node* temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->data == x) {
                return to_string(i);
            }
            temp = temp->next;
        }
        if (!temp) return "NO";
    }
    void push(int x) {
        Node* temp;
        temp->data = x;
        temp->next = head;
        head = temp;
        size++;
    }
    void reverse(Node* temp) {
        if (temp == nullptr) return;
        reverse(temp->next);
        cout<<temp->data<<' ';
    }
};
int main() {
    int n;
    Linkedlist list;
    cin>>n;
    for (int i = 0; i < n; i++) {
        string s;
        cin>>s;
        if (s == "append") {
            int k;
            cin>>k;
            list.append(k);
        }
        else if (s == "search") {
            int k;
            cin>>k;
            cout<<list.search(k);
        } else {
            list.reverse(list.head);
        }
    }
}