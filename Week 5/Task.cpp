#include <iostream>
#include <cstring>
using std::cout; 
using std::cin;
struct Node{
    int val;// value of node
    int childnum;// number children node has
    Node* firstchild;
    Node* sibling;
    //constructor
    Node() : val(0), childnum(0), firstchild(nullptr), sibling(nullptr) {};
    Node(int data) : val(data), childnum(0), firstchild(nullptr), sibling(nullptr) {};
};
class Tree{
    Node *root;
    int totalnode;
    int height;
    Node* arr;
    bool* isChild;
    public:
    // constructor
    Tree(int n) : root(), height(0),totalnode(n) {
        arr = new Node[n + 1];
        isChild = new bool[n + 1];
        memset(isChild,false,sizeof(isChild));
    };
    /**
     * add child to parent node if parent node has no child
     * else add sibling to last child of parent
     * 
     * @param u : parent value
     * @param v : child value
     */
    void addchild(int u, int v) {
        // create node
        // check if node has implemented or not
        Node* parent = &arr[u];
        if(parent->val == 0) parent->val = u;
        Node* child = &arr[v];
        if (child->val == 0) child->val = v;
        //implement relationship
        if (parent->firstchild == nullptr) {
            parent->firstchild = child;
        } else {
            Node* temp = parent->firstchild;
            while(temp->sibling) {
                temp = temp->sibling;
            }
            temp->sibling = child;
        }
        parent->childnum++;
        isChild[child->val] = true;
    }
    //setRoot for the tree
    void setRoot() {
        for(int i = 1; i <= totalnode; i++) {
            if (!isChild[i]) {
                root = &arr[i];
                return;
            }
        }
    }   
    //calculate maximum depth by recursion
    int maxdepth(Node* temp){
        if (temp == nullptr) return 0;
        int maxchilddepth = 0;
        // check if temp has child
        if (temp->firstchild) {
            //take temp1 as pointer to sibling of firstchile of temp
            Node* temp1 = temp->firstchild;
            while(temp1) {
                //calculate maximum depth of all sibling of temp
                maxchilddepth = std::max(maxchilddepth,maxdepth(temp1->firstchild));
                temp1 = temp1->sibling;
            }
        }
        return 1 + maxchilddepth;
    }
    // max depth = height
    void printheight() {
        cout<<maxdepth(root)<<std::endl;
    }
    /**
     * all below printing function using same method to recursion
     * start with a subtree which contain parent and children
     * With Pre order: subtree will be printed with the order parent->firstsubtree->siblingsubtree
     * With Post order: subtree will be printed with te order firstsubtree->siblingsubtree->parent
     * With In order: this type require the tree MUST be a binary tree
     * the order will be firstsubtree->parent->siblingsubtree
     */
    //Print Pre Order using recursion
    void Preorder(Node* temp) {
        if (temp == nullptr) return;
        //print parent 
        cout<<temp->val<<" ";
        //print first child of the node 
        Preorder(temp->firstchild);
        //print sibling of this node  
        Preorder(temp->sibling);
    }
    void printPreorder() {
        Preorder(root);
        cout<<"\n";
    }
    //print Post order using recursion
    void Postorder(Node* temp1) {
        if(temp1 == nullptr) return;
        //recursion to last firstchild node
        Postorder(temp1->firstchild);
        //print all the sibling of this node (include itself)
        Node* temp2 = temp1;
        while(temp2) {
            cout<<temp2->val<<" ";
            temp2 = temp2->sibling;
        }
    }
    void printPostorder(){
        Postorder(root);
        cout<<"\n";
    }
    // check if the tree is binary or not
    bool ifbinary(Node* temp) {
        if (temp == nullptr) return true;
        return ifbinary(temp->firstchild);
        while(temp->sibling) {
            if (temp->childnum > 2) return false;
            temp = temp->sibling;
        }
        return true;
    }
    //print tree In Order using recursion
    void Inorder(Node* temp) {
        if (temp == nullptr) return;
        //print firstchild
        Inorder(temp->firstchild);
        //print parent of firstchild
        cout<<temp->val<<" ";
        //print sibling of firstchild
        if (temp->firstchild)
            Inorder(temp->firstchild->sibling);
    }
    void printInorder() {
        if (!ifbinary(root)) {
            cout<<"NOT BINARY TREE\n";
        } else {
            Inorder(root);
            cout<<"\n";
        }
    }
};
int main(){
    int m,n;
    cin>>n>>m;
    Tree tree = Tree(n);
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        tree.addchild(u,v);
    }
    tree.setRoot();
    tree.printheight();
    tree.printPreorder();
    tree.printPostorder();
    tree.printInorder();
}
