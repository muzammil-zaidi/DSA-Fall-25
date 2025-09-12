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

class BookList{
private:
    Node* head;

public:
    BookList(){
        head=NULL;
    }

    void insertEnd(string val){
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

    void insertFront(string val){
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
    }

    void insertAfter(string afterBook,string newBook){
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==afterBook){
                Node* newNode=new Node(newBook);
                newNode->next=temp->next;
                temp->next=newNode;
                return;
            }
            temp=temp->next;
        }
        cout<<"Book '"<<afterBook<<"' not found in list.\n";
    }

    bool searchBook(string bookName){
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==bookName){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void display(){
        Node* temp=head;
        cout<<"Books in Library:\n";
        while(temp!=NULL) {
            cout<<"- "<<temp->data<<endl;
            temp=temp->next;
        }
    }
};

int main(){
    BookList b;

    b.insertEnd("Data Structures");
    b.insertEnd("Operating Systems");
    b.insertEnd("Computer Networks");
    b.insertEnd("Database Systems");

    b.insertFront("Artificial Intelligence");

    b.insertEnd("Machine Learning");

    b.insertAfter("Operating Systems","Cyber Security");

    string book="Database Systems";
    if(b.searchBook(book)){
        cout<<"\n'"<<book<<"' exists in the list.\n";
    }
    else{
        cout<<"\n'"<<book<<"' does not exist in the list.\n";
    }

    cout<<endl;
    b.display();

    return 0;
}
