#include <iostream>
using namespace std;
struct Node{
    Node* pre;
    int x;
    Node* next;
};
class Linkedlist{
    Node* head;
    public:
        Linkedlist() : head(NULL){};
        void push(int a){
            Node* newNode = new Node();
            newNode->pre = NULL;   
            newNode->x = a;
            newNode->next = head;
            if (head != NULL) head->pre = newNode;
            head = newNode;
            return;
        }
        int count_triplet(){
            Node* temp;
            temp = head->next;
            int d = 0;
            while(temp->next){
                Node* t1 = temp->next;
                Node* t2 = temp->pre;
                if ((int)t1->x + (int)temp->x + (int)t2->x == 0) ++d;
                temp = temp->next;
            }
            return d;
        }
};
int main(){
    Linkedlist list;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        list.push(k);
    }
    cout<<list.count_triplet();
}