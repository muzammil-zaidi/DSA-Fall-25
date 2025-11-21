#include<iostream>
#include<string>
using namespace std;

struct Node{
    string word;
    Node* next;

    Node(string w){
        word=w;
        next=nullptr;
    }
};

class Dictionary{
private:
    Node** table;
    const int SIZE=100;

    int hashFunction(const string &str){
        int sum=0;

        for(int i=0;i<str.length();i++){
            sum+=str[i];
        }

        return sum%SIZE;
    }

public:
    Dictionary(){
        table=new Node*[SIZE];

        for(int i=0;i<SIZE;i++){
            table[i]=nullptr;
        }
    }

    void insert(const string &word){
        int index=hashFunction(word);

        Node* newNode=new Node(word);
        newNode->next=table[index];
        table[index]=newNode;
        cout<<"Record added: "<<word<<endl;
    }

    void search(const string &word){
        int index=hashFunction(word);

        Node* temp=table[index];
        while(temp!=nullptr){
            if(temp->word==word){
                cout<<"WORD FOUND: "<<word<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"ERROR: Word '"<<word<<"' NOT FOUND in Dictionary."<<endl;
    }

    void display(){
        cout<<"\n--- Complete Dictionary ---\n";
        
        for(int i=0;i<SIZE;i++){
            cout<<"Bucket "<<i<<": ";

            if(table[i]==nullptr){
                cout<<"NULL\n";
                continue;
            }

            Node* temp=table[i];
            while(temp!=nullptr){
                cout<<temp->word<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }
        cout<<endl;
    }

    ~Dictionary(){
        for(int i=0;i<SIZE;i++){
            Node* temp=table[i];
            while(temp){
                Node* nextNode=temp->next;
                delete temp;
                temp=nextNode;
            }
        }
        delete[] table;
    }
};

int main(){
    Dictionary d;

    d.insert("apple");
    d.insert("banana");
    d.insert("cat");
    d.insert("dog");
    d.insert("zebra");
    cout<<endl;

    d.search("banana");
    d.search("mango");

    cout<<endl;
    d.display();

    return 0;
}
