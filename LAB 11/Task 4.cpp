#include<iostream>
#include<string>
using namespace std;

struct Student{
    int roll;
    string name;
    bool occupied;

    Student(){
        roll=-1;
        name="";
        occupied=false;
    }
};

class StudentHashTable{
private:
    Student table[15];
    const int SIZE=15;

    int hashFunction(int roll){
        return roll%SIZE;
    }

public:
    void InsertRecord(int roll,const string &name){
        int index=hashFunction(roll);

        for(int attempt=0;attempt<SIZE;attempt++){
            int newIndex=(index+attempt*attempt)%SIZE;

            if(!table[newIndex].occupied){
                table[newIndex].roll=roll;
                table[newIndex].name=name;
                table[newIndex].occupied=true;
                cout<<"Record inserted at index "<<newIndex<<endl;
                return;
            }
        }

        cout<<"Hash Table FULL. Cannot insert record."<<endl;
    }

    void SearchRecord(int roll){
        int index=hashFunction(roll);

        for(int attempt=0;attempt<SIZE;attempt++){
            int newIndex=(index+attempt*attempt)%SIZE;

            if(table[newIndex].occupied && table[newIndex].roll==roll){
                cout<<"Record found: " <<table[newIndex].name<<endl;
                return;
            }

            if(!table[newIndex].occupied){
                break;
            }
        }

        cout<<"Record not found"<<endl;
    }
};

int main(){
    StudentHashTable h;

    h.InsertRecord(101,"Alice");
    h.InsertRecord(116,"Bob");
    h.InsertRecord(131,"John");

    h.SearchRecord(116);
    h.SearchRecord(200);

    return 0;
}
