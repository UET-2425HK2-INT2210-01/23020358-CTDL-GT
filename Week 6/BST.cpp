#include<iostream>
using std::cin, std::cout;

struct Node {
    int val;
    Node* leftchild;
    Node* rightchild;
    //Constructor
    Node(int val) : val(val), leftchild(nullptr), rightchild(nullptr) {};
};
class BST {
    private: 
        Node* root;
    public:
        //Constructor
        BST() : root(nullptr) {};
        //insert
        void insert(int value) {
            Node *newNode = new Node(value);
            //if BST has no node, take new node as root
            if (root == nullptr) {
                root = newNode;
                return;
            }
            //traversal through BST to insert new node
            Node *temp = root;
            Node *curr = root;
            while (curr) {
                temp = curr;
                if (curr->val > newNode->val) {
                    curr = curr->leftchild;
                } else if (curr->val < newNode->val) {
                    curr = curr->rightchild;
                }
            }
            //insert node
            if (temp->val > newNode->val) {
                temp->leftchild = newNode;
            } else if (temp->val < newNode->val) {
                temp->rightchild = newNode;
            }
        }
        //find min in right sub-tree
        Node* min(Node* root) {
            if (root->rightchild != nullptr) return min(root->rightchild);
            else return min(root->leftchild);
        }

        Node* del(Node *root, int value) {
            //recursion
            if (root == nullptr) return root;
            else if (root->val > value) {
                root->leftchild = del(root->leftchild, value);
            } else if (root->val < value) {
                root->rightchild = del(root->rightchild, value);
            } else {
                //delete if has no node or 1 node
                if (root->leftchild == nullptr) {
                    Node *temp = root->rightchild;
                    delete root;
                    return temp;
                }
                if(root->rightchild == nullptr) {
                    Node *temp = root->leftchild;
                    delete root;
                    return temp;
                }
                //if node has 2 child
                Node* temp = min(root);
                root->val = temp->val;
                root->rightchild = del(root->rightchild,temp->val);
            }
            return root;
        }
        void DELETE(int val) {
            root = del(root,val);
        }

        //print tree In Order using recursion
        void Inorder(Node* temp) {
            if (temp == nullptr) return;
            //print firstchild
            Inorder(temp->leftchild);
            //print parent of firstchild
            cout<<temp->val<<" ";
            //print sibling of firstchild
            Inorder(temp->rightchild);
        }
        void printInorder() {
            Inorder(root);
        }

};
int main() {
    int m;
    BST Tree;
    cin>>m;
    for (int i = 0; i < m; i++) {
        int k;
        cin>>k;
        Tree.insert(k);
    }
    Tree.printInorder();
}