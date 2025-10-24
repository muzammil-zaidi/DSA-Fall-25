#include<iostream>
#include<string>
#include<cmath>
using namespace std;

struct Student{
    string name;
    int score;
    Student* next;
};

void insert(Student*& head,string name,int score){
    Student* newNode=new Student{name,score,nullptr};
    if(!head){
        head=newNode;
        return;
    }
    Student* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
}

int getMax(Student* head){
    int max=0;
    while(head){
        if(head->score>max){
            max=head->score;
        }
        head=head->next;
    }
    return max;
}

int getDigit(int num,int place){
    return (num/place)%10;
}

void radixSort(Student*& head){
    int maxScore=getMax(head);

    for(int place=1;maxScore/place>0;place*=10){
        Student* buckets[10]={nullptr};
        Student* bucketTails[10]={nullptr};

        Student* curr=head;
        while(curr){
            int digit=getDigit(curr->score,place);
            Student* nextNode=curr->next;
            curr->next=nullptr;

            if(!buckets[digit]){
                buckets[digit]=bucketTails[digit]=curr;
            }
            else{
                bucketTails[digit]->next=curr;
                bucketTails[digit]=curr;
            }

            curr=nextNode;
        }

        head=nullptr;
        Student* tail=nullptr;

        for(int i=0;i<10;i++){
            if(buckets[i]){
                if(!head){
                    head=buckets[i];
                    tail=bucketTails[i];
                }
                else{
                    tail->next=buckets[i];
                    tail=bucketTails[i];
                }
            }
        }
    }
}

void display(Student* head){
    cout<<"\nSorted Student Records:\n";
    cout<<"-----------------------------\n";
    cout<<"Name\tScore\n";
    cout<<"-----------------------------\n";
    while(head){
        cout<<head->name<<"\t\t"<<head->score<<endl;
        head=head->next;
    }
    cout<<"-----------------------------\n";
}

int main(){
    Student* head=nullptr;
    int n;
    cout<<"Enter number of students: ";
    cin>>n;

    for(int i=0;i<n;i++){
        string name;
        int score;
        cout<<"Enter name of student "<<i+1<<": ";
        cin>>name;
        cout<<"Enter score (0-100): ";
        cin>>score;
        insert(head,name,score);
    }

    cout<<"\nSorting student scores using Radix Sort...\n";
    radixSort(head);
    display(head);

    return 0;
}
