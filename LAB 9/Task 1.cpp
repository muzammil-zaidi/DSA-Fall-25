#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* n){
    if(n==nullptr){
        return 0;
    }
    else{
        return n->height;
    }
}

int getBalance(Node* n){
    if(n==nullptr){
        return 0;
    }
    else{
        return getHeight(n->left)-getHeight(n->right);
    }
}

Node* createNode(int key){
    Node* node=new Node();
    node->key=key;
    node->left=nullptr;
    node->right=nullptr;
    node->height=1;
    return node;
}

Node* rightRotate(Node* y){
    Node* x=y->left;
    Node* T2=x->right;

    x->right=y;
    y->left=T2;

    int leftH=getHeight(y->left);
    int rightH=getHeight(y->right);

    if(leftH>rightH){
        y->height=leftH+1;
    }
    else{
        y->height=rightH+1;
    }

    leftH=getHeight(x->left);
    rightH=getHeight(x->right);

    if(leftH>rightH){
        x->height=leftH+1;
    }
    else{
        x->height=rightH+1;
    }

    return x;
}

Node* leftRotate(Node* x){
    Node* y=x->right;
    Node* T2=y->left;

    y->left=x;
    x->right=T2;

    int leftH=getHeight(x->left);
    int rightH=getHeight(x->right);

    if(leftH>rightH){
        x->height=leftH+1;
    }
    else{
        x->height=rightH+1;
    }

    leftH=getHeight(y->left);
    rightH=getHeight(y->right);

    if(leftH>rightH){
        y->height=leftH+1;
    }
    else{
        y->height=rightH+1;
    }

    return y;
}

Node* insertNode(Node* node,int key){
    if (node==nullptr){
        return createNode(key);
    }
    else{
        if (key<node->key){
            node->left=insertNode(node->left,key);
        }
        else{
            if(key>node->key){
                node->right=insertNode(node->right,key);
            }
            else{
                return node;
            }
        }
    }

    int leftH=getHeight(node->left);
    int rightH=getHeight(node->right);

    if(leftH>rightH){
        node->height=leftH+1;
    }
    else{
        node->height=rightH+1;
    }

    int balance=getBalance(node);

    if(balance>1 && key<node->left->key){
        return rightRotate(node);
    }
    else{
        if (balance<-1 && key>node->right->key){
            return leftRotate(node);
        }
        else{
            if(balance>1 && key>node->left->key){
                node->left=leftRotate(node->left);
                return rightRotate(node);
            }
            else{
                if(balance<-1 && key<node->right->key){
                    node->right=rightRotate(node->right);
                    return leftRotate(node);
                }
            }
        }
    }

    return node;
}

void levelOrder(Node* root){
    if(root==nullptr){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int count=q.size();
        while(count--){
            Node* temp=q.front();
            q.pop();

            cout<<temp->key<<" ";
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
        cout<<endl;
    }
}

int main(){
    Node* root=nullptr;

    int rolls[]={10,20,30,40,50};
    int n=5;

    for(int i=0;i<n;i++){
        root=insertNode(root,rolls[i]);
    }

    cout<<"AVL Tree before inserting 15:\n";
    levelOrder(root);

    root=insertNode(root,15);

    cout<<"\nAVL Tree after inserting 15:\n";
    levelOrder(root);

    cout<<"\nHeight after insertion = "<<getHeight(root)<<endl;

    return 0;
}
