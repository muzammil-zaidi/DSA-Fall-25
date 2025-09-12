#include<iostream>
#include<string>
using namespace std;

struct Node{
    string data;
    Node* next;

    Node(string val){
        data=val;
        next=NULL;
    }
};

class BookCatalog{
private:
    Node* head;

public:
    BookCatalog(){
        head=NULL;
    }

    void addBookTail(string val){
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
    }

    void deleteFront(){
        if(head==NULL){
            cout<<"Catalog is empty. Nothing to delete.\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        cout<<"Deleted book: "<<temp->data<<endl;
        delete temp;
    }

    void searchByTitle(string title){
        Node* temp=head;
        int pos=1;
        while(temp!=NULL){
            if(temp->data==title){
                cout<<"Book '"<<title<<"' found at position "<<pos<<".\n";
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"Book '"<<title<<"' not found in the catalog.\n";
    }

    void searchByPosition(int position){
        if(position<=0){
            cout<<"Invalid position.\n";
            return;
        }
        Node* temp=head;
        int pos=1;
        while(temp!=NULL){
            if(pos==position){
                cout<<"Book at position "<<position<<" is: "<<temp->data<<endl;
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"No book found at position "<<position<<".\n";
    }

    void display(){
        if(head==NULL){
            cout<<"Catalog is empty.\n";
            return;
        }
        Node* temp=head;
        cout<<"Library Catalog:\n";
        while(temp!=NULL){
            cout<<"- "<<temp->data<<endl;
            temp=temp->next;
        }
    }
};

int main(){
    BookCatalog c;

    c.addBookTail("Data Structures");
    c.addBookTail("Operating Systems");
    c.addBookTail("Computer Networks");
    c.addBookTail("Database Systems");

    cout<<"\nInitial Catalog:\n";
    c.display();

    cout<<"\nDeleting from front:\n";
    c.deleteFront();

    cout<<"\nCatalog after deletion:\n";
    c.display();

    cout<<"\nSearch by Title:\n";
    c.searchByTitle("Database Systems");

    cout<<"\nSearch by Position:\n";
    c.searchByPosition(2);

    return 0;
}
