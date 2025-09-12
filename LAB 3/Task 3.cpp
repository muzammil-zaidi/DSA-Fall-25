#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

class Train{
private:
    Node* head;

public:
    Train(){
        head=NULL;
    }

    void addCompartment(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }

    void removeFirst(){
        if(head==NULL){
            cout<<"Train has no compartments.\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        cout<<"Removed compartment: "<<temp->data<<endl;
        delete temp;
    }

    void searchCompartment(int val){
        Node* temp=head;
        int pos=1;
        while(temp!=NULL){
            if(temp->data==val){
                cout<<"Compartment "<<val<<" found at position "<<pos<<".\n";
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"Compartment "<<val<<" not found.\n";
    }

    void display(){
        if(head==NULL){
            cout<<"No compartments in the train.\n";
            return;
        }
        Node* temp=head;
        cout<<"Train Compartments (front to end): ";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Train t;

    t.addCompartment(101);
    t.addCompartment(102);
    t.addCompartment(103);
    t.addCompartment(104);

    cout<<"\nInitial Train:\n";
    t.display();

    cout<<"\nRemoving first compartment:\n";
    t.removeFirst();

    cout<<"\nTrain after removal:\n";
    t.display();

    cout<<"\nSearching for compartment 103:\n";
    t.searchCompartment(103);

    cout<<"\nSearching for compartment 110:\n";
    t.searchCompartment(110);

    return 0;
}
