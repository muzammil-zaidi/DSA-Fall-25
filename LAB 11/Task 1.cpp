#include<iostream>
#include<string>
using namespace std;

struct Node{
    string data;
    Node* next;

    Node(string d){
        data=d;
        next=nullptr;
    }
};

class HashTable{
private:
    int bucketCount;
    Node** table;

    int hashFunction(const string &str){
        int sum=0;

        for(int i=0;i<str.length();i++){
            sum+=str[i];
        }

        return sum%bucketCount;
    }

public:
    HashTable(int buckets){
        bucketCount=buckets;
        table=new Node*[bucketCount];

        for(int i=0;i<bucketCount;i++){
            table[i]=nullptr;
        }
    }

    void insert(const string &str){
        int index=hashFunction(str);

        Node* newNode=new Node(str);
        newNode->next=table[index];
        table[index]=newNode;
    }

    bool search(const string &str){
        int index=hashFunction(str);

        Node* temp=table[index];
        while(temp!=nullptr){
            if(temp->data==str){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void display(){
        cout<<"Hash Table:\n";

        for(int i=0;i<bucketCount;i++){
            cout<<"Bucket "<<i<<": ";

            if(table[i]==nullptr){
                cout<<"NULL\n";
                continue;
            }

            Node* temp=table[i];
            while(temp!=nullptr){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }
        cout<<endl;
    }

    ~HashTable(){
        for(int i=0;i<bucketCount;i++){
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
    HashTable h(10);

    h.insert("apple");
    h.insert("mango");
    h.insert("apple");
    h.insert("grapes");
    h.insert("peach");
    h.insert("banana");

    h.display();

    if(h.search("apple")){
        cout<<"Searching 'apple': Found"<<endl;
    }
    else{
        cout<<"Searching 'apple': Not Found"<<endl;
    }

    if(h.search("orange")){
        cout<<"Searching 'orange': Found"<<endl;
    }
    else{
        cout<<"Searching 'orange': Not Found"<<endl;
    }

    return 0;
}
