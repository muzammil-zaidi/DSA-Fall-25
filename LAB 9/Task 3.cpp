#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    else {
        return n->height;
    }
}

int getBalance(Node* n) {
    if (n == nullptr) {
        return 0;
    }
    else {
        return getHeight(n->left) - getHeight(n->right);
    }
}

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    int LH = getHeight(y->left);
    int RH = getHeight(y->right);
    if (LH > RH) {
        y->height = LH + 1;
    }
    else {
        y->height = RH + 1;
    }

    LH = getHeight(x->left);
    RH = getHeight(x->right);
    if (LH > RH) {
        x->height = LH + 1;
    }
    else {
        x->height = RH + 1;
    }

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    int LH = getHeight(x->left);
    int RH = getHeight(x->right);
    if (LH > RH) {
        x->height = LH + 1;
    }
    else {
        x->height = RH + 1;
    }

    LH = getHeight(y->left);
    RH = getHeight(y->right);
    if (LH > RH) {
        y->height = LH + 1;
    }
    else {
        y->height = RH + 1;
    }

    return y;
}

Node* insertNode(Node* node, int key) {

    if (node == nullptr) {
        return createNode(key);
    }
    else {
        if (key < node->key) {
            node->left = insertNode(node->left, key);
        }
        else {
            if (key > node->key) {
                node->right = insertNode(node->right, key);
            }
            else {
                return node;
            }
        }
    }

    int LH = getHeight(node->left);
    int RH = getHeight(node->right);
    if (LH > RH) {
        node->height = LH + 1;
    }
    else {
        node->height = RH + 1;
    }

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    else {
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }
        else {
            if (balance > 1 && key > node->left->key) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            else {
                if (balance < -1 && key < node->right->key) {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }
            }
        }
    }

    return node;
}

void levelOrder(Node* root) {

    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int count = q.size();
        while (count--) {
            Node* temp = q.front();
            q.pop();

            cout << temp->key << " ";

            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

int main(){

    Node* root=nullptr;

    int arr[]={10,5,15,3,7};
    int n=5;

    for(int i=0;i<n;i++){
        root=insertNode(root,arr[i]);
    }

    cout<<"AVL Tree before inserting 12:\n";
    levelOrder(root);

    root=insertNode(root,12);

    cout<<"\nAVL Tree after inserting 12:\n";
    levelOrder(root);

    cout<<"\nHeight of AVL Tree = " << getHeight(root) << endl;
    cout<<"\nBalance Factors:\n";
    cout<<"BF(10) = "<<getBalance(root) << endl;
    cout<<"BF(5)  = "<<getBalance(root->left) << endl;
    cout<<"BF(15) = "<<getBalance(root->right) << endl;
    cout<<"BF(3)  = "<<getBalance(root->left->left) << endl;
    cout<<"BF(7)  = "<<getBalance(root->left->right) << endl;
    cout<<"BF(12) = "<<getBalance(root->right->left) << endl;

    return 0;
}
