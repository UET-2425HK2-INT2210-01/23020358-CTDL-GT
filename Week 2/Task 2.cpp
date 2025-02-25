#include <iostream>
using namespace std;
struct Node {
    int x;
    Node* next;
};
class Linkedlist{
    Node* head;
    public:
        Linkedlist() : head(NULL) {}
    void insert(int data, int p){
        if (p == 0){
            Node* newNode = new Node();
            newNode->x = data;
            newNode->next = head;
            head = newNode;
            return;
        }
        else{
            Node* temp = head;
            for(int i = 0; i < p-2 && temp;++i){
                temp = temp->next;
            }
            if(temp->next == NULL){
                Node* newNode = new Node();
                newNode->x = data;
                temp->next = newNode;
                newNode->next = NULL;
                return;
            } else {
                Node* newNode = new Node();
                newNode->x = data;
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
        }
    }
    void del(int p){
        if(p == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* temp = head;
            for(int i = 0; i < p-2 && temp;++i){
                    temp = temp->next;
                }
                    Node* bin = temp->next;
                    temp->next = temp->next->next;
                    delete bin;
        }
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->x<<" ";
            temp = temp->next;
        }
    }
};
int main(){
    Linkedlist list;
    int n;
    cin>>n;
    for(int k = 0; k < n; ++k){
        string a;
        cin>>a;
        if(a == "insert"){
            int i,j;
            cin>>i>>j;
            list.insert(j,i);
        } else {
            int i;
            cin>>i;
            list.del(i);
        }
    }
    list.display();
}