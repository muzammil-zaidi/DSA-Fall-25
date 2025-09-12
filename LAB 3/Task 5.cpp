#include<iostream>
#include<string>
using namespace std;

struct Node{
    string song;
    Node* next;

    Node(string val){
        song=val;
        next=NULL;
    }
};

class Playlist{
private:
    Node* head;

public:
    Playlist(){
        head=NULL;
    }

    void addSong(string songName){
        Node* newNode=new Node(songName);
        if(head==NULL){
            head=newNode;
            head->next=head;
            return;
        }
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
    }

    void display(){
        if(head==NULL){
            cout<<"Playlist is empty.\n";
            return;
        }
        Node* temp=head;
        cout<<"Playlist Songs: \n";
        do{
            cout<< "- "<<temp->song<<endl;
            temp=temp->next;
        }
        while(temp!=head);
    }

    void play(int count){
        if(head==NULL){
            cout<<"Playlist is empty. Nothing to play.\n";
            return;
        }
        Node* temp=head;
        cout<<"\nPlaying songs continuously:\n";
        for(int i=0;i<count;i++){
            cout<<"Playing: "<<temp->song<<endl;
            temp=temp->next;
        }
    }
};

int main(){
    Playlist p;

    p.addSong("Shape of You");
    p.addSong("Blinding Lights");
    p.addSong("Closer");
    p.addSong("Believer");

    cout<<"\nCurrent Playlist:\n";
    p.display();

    p.play(7);

    return 0;
}
