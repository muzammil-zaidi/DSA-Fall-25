#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insert(Node*& head,int value){
    Node* newNode=new Node{value,nullptr};
    if(!head){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=newNode;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* getTail(Node* curr){
    while(curr && curr->next){
        curr=curr->next;
    }
    return curr;
}

Node* partition(Node* head,Node* end,Node** newHead,Node** newEnd) {
    Node* pivot=end;
    Node* prev=nullptr;
    Node* curr=head;
    Node* tail=pivot;

    while(curr!=pivot){
        if(curr->data<pivot->data){
            if(!(*newHead))
                *newHead=curr;
            prev=curr;
            curr=curr->next;
        }
        else{
            if(prev){
                prev->next=curr->next;
            }
            Node* tmp=curr->next;
            curr->next=nullptr;
            tail->next=curr;
            tail=curr;
            curr=tmp;
        }
    }

    if(!(*newHead)){
        *newHead=pivot;
    }

    *newEnd=tail;
    return pivot;
}

Node* quickSortRecur(Node* head,Node* end){
    if(!head || head==end)
        return head;

    Node *newHead=nullptr,*newEnd=nullptr;

    Node* pivot=partition(head,end,&newHead,&newEnd);

    if(newHead!=pivot){
        Node* temp=newHead;
        while(temp->next!=pivot)
            temp=temp->next;
        temp->next=nullptr;

        newHead=quickSortRecur(newHead,temp);

        temp=getTail(newHead);
        temp->next=pivot;
    }

    pivot->next=quickSortRecur(pivot->next,newEnd);

    return newHead;
}

void quickSort(Node** headRef){
    *headRef=quickSortRecur(*headRef,getTail(*headRef));
}

int main(){
    Node* head=nullptr;

    int arr[]={10,7,8,9,1,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        insert(head,arr[i]);
    }

    cout<<"Original list:\n";
    printList(head);

    quickSort(&head);

    cout<<"\nSorted list using Quick Sort:\n";
    printList(head);

    return 0;
}
