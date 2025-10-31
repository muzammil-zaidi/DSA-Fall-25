#include<iostream>
#include<string>
using namespace std;

struct Node{
    string data;
    Node* left;
    Node* right;

    Node(string d){
        data=d;
        left=right=nullptr;
    }
};

class BinaryTree{
private:
    Node* root;

    Node* insert(Node* node,string value){
        if(node==nullptr){
            return new Node(value);
        }

        char choice;
        cout<<"Where do you want to add \""<<value<<"\" under \""<<node->data<<"\"? (L for left / R for right): ";
        cin>>choice;

        if(choice=='L' || choice=='l'){
            node->left=insert(node->left,value);
        }
        else{
            node->right=insert(node->right,value);
        }

        return node;
    }

    void display(Node* node,int level=0){
        if(node==nullptr){
            return;
        }

        display(node->right,level+1);
        for(int i=0;i<level;i++){
            cout<< "    ";
        }
        cout<<"|-- "<<node->data<<endl;
        display(node->left,level+1);
    }

    bool isFullBinaryTree(Node* node){
        if(node==nullptr){
            return true;
        }

        if(node->left==nullptr && node->right==nullptr){
            return true;
        }

        if(node->left!=nullptr && node->right!=nullptr){
            return isFullBinaryTree(node->left) && isFullBinaryTree(node->right);
        }

        return false;
    }

public:
    BinaryTree(){
        root=nullptr;
    }

    void createRoot(string value){
        if(root==nullptr){
            root=new Node(value);
        }
        else{
            cout<<"Root already exists!\n";
        }
    }

    void addNode(string value){
        if(root==nullptr){
            cout<<"Please create the root node first.\n";
            return;
        }
        root=insert(root,value);
    }

    void showTree(){
        cout<<"\n==== TREE STRUCTURE ====\n";
        display(root);
    }

    void checkFullBinaryTree(){
        cout<<"\n==== FULL BINARY TREE CHECK ====\n";
        if(isFullBinaryTree(root)){
            cout<<"The tree IS a Full Binary Tree.\n";
        }
        else{
            cout<<"The tree is NOT a Full Binary Tree.\n";
        }
    }
};

int main(){
    BinaryTree tree;
    int choice;
    string value;

    do{
        cout<<"\n--- FULL BINARY TREE CHECK ---\n";
        cout<<"1. Create Root Node\n";
        cout<<"2. Add Child Node\n";
        cout<<"3. Display Tree Structure\n";
        cout<<"4. Check if Tree is Full Binary Tree\n";
        cout<<"0. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        cin.ignore();

        switch (choice){
            case 1:
                cout<<"Enter root node value: ";
                getline(cin,value);
                tree.createRoot(value);
                break;

            case 2:
                cout<<"Enter node value to add: ";
                getline(cin,value);
                tree.addNode(value);
                break;

            case 3:
                tree.showTree();
                break;

            case 4:
                tree.checkFullBinaryTree();
                break;

            case 0:
                cout<<"Exiting program...\n";
                break;

            default:
                cout<<"Invalid choice! Try again.\n";
        }

    }
    while(choice!=0);

    return 0;
}
