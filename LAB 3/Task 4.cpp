#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList(){
        head=NULL;
    }

    void insertEnd(int val){
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

    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    Node* getHead(){
        return head;
    }
    void setHead(Node* h){
        head=h;
    }

    void sortList(){
        if(!head || !head->next){
            return;
        }

        Node* i=head;
        while(i!=NULL){
            Node* j=i->next;
            while(j!=NULL){
                if(i->data>j->data){
                    swap(i->data,j->data);
                }
                j=j->next;
            }
            i=i->next;
        }
    }

    void concatenate(LinkedList& list2){
        if(head==NULL){
            head=list2.getHead();
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=list2.getHead();
    }

    void findMiddle(){
        if(head==NULL){
            cout<<"List is empty.\n";
            return;
        }
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<"Middle element: "<<slow->data<<endl;
    }

    void removeDuplicates(){
        Node* curr=head;
        while(curr!=NULL){
            Node* runner=curr;
            while(runner->next!=NULL){
                if(runner->next->data==curr->data){
                    Node* dup=runner->next;
                    runner->next=runner->next->next;
                    delete dup;
                }
                else{
                    runner=runner->next;
                }
            }
            curr=curr->next;
        }
    }

    LinkedList mergeSorted(LinkedList& list2){
        Node* h1=this->head;
        Node* h2=list2.getHead();

        LinkedList result;
        Node dummy(0);
        Node* tail=&dummy;

        while(h1!=NULL && h2!=NULL){
            if(h1->data<h2->data){
                tail->next=h1;
                h1=h1->next;
            }
            else{
                tail->next=h2;
                h2=h2->next;
            }
            tail=tail->next;
        }
        if(h1!=NULL){
            tail->next=h1;
        }
        if(h2!=NULL){
            tail->next=h2;
        }

        result.setHead(dummy.next);
        return result;
    }
};

int main(){
    LinkedList list1,list2;

    list1.insertEnd(4);
    list1.insertEnd(2);
    list1.insertEnd(5);
    list1.insertEnd(3);
    list1.insertEnd(2);
    list1.insertEnd(6);

    cout<<"Original List1: ";
    list1.display();

    list1.sortList();
    cout<<"Sorted List1: ";
    list1.display();

    list1.removeDuplicates();
    cout<<"List1 after removing duplicates: ";
    list1.display();

    list1.findMiddle();

    list2.insertEnd(8);
    list2.insertEnd(9);
    list2.insertEnd(10);

    cout<<"List2: ";
    list2.display();

    list1.concatenate(list2);
    cout<<"After Concatenation (List1 + List2): ";
    list1.display();

    LinkedList a,b;
    a.insertEnd(1);
    a.insertEnd(3);
    a.insertEnd(5);

    b.insertEnd(2);
    b.insertEnd(4);
    b.insertEnd(6);

    cout<<"List A: ";
    a.display();
    cout<<"List B: ";
    b.display();

    LinkedList merged=a.mergeSorted(b);
    cout<<"Merged Sorted List: ";
    merged.display();

    return 0;
}
