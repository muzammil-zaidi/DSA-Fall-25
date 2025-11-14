#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

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
            return new Node(key);
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

    void insert(int key) {
        root = insertNode(root, key);
    }

    void levelOrder(Node* root) {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int c = q.size();

            while (c--) {
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
};

int main(){
    AVLTree tree;

    int values[]={50,30,70,20,40,60,80};
    int n=7;

    for(int i=0;i<n;i++){
        tree.insert(values[i]);
    }

    cout<<"AVL Tree before inserting 55:\n";
    tree.levelOrder(tree.root);

    tree.insert(55);

    cout<<"\nAVL Tree after inserting 55:\n";
    tree.levelOrder(tree.root);

    tree.root=tree.leftRotate(tree.root);

    cout<<"\nAVL Tree after LEFT ROTATION on root:\n";
    tree.levelOrder(tree.root);

    return 0;
}
