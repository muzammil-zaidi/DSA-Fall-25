#include<iostream>
#include<string>
using namespace std;

class EmployeeHashTable{
private:
    string table[50];
    const int SIZE=50;

    int asciiSum(const string &str){
        int sum=0;
        for(int i=0;i<(int)str.length();i++){
            sum+=str[i];
        }
        return sum;
    }

    int h1(const string &name){
        return asciiSum(name)%SIZE;
    }

    int h2(const string &name){
        return 7-(asciiSum(name)%7);
    }

public:
    EmployeeHashTable(){
        for(int i=0;i<SIZE;i++){
            table[i]="";
        }
    }

    void Add_Employee(const string &name){
        int primary=h1(name);
        int secondary=h2(name);

        int i=0;
        int index=primary;

        while(table[index]!="" && i<SIZE){
            i++;
            index=(primary+i*secondary)%SIZE;
        }

        if(i==SIZE){
            cout<<"Hash Table is full. Cannot insert employee: "<<name<<endl;
            return;
        }

        table[index]=name;
        cout<<"Inserted "<<name<<" at index "<<index<<endl;
    }

    void Search_Employee(const string &name){
        int primary=h1(name);
        int secondary=h2(name);

        int i=0;
        int index=primary;

        while(table[index]!="" && i<SIZE){
            if(table[index]==name){
                cout<<"Employee found: "<<name<<" at index "<<index<<endl;
                return;
            }
            i++;
            index=(primary+i*secondary)%SIZE;
        }

        cout<<"Employee not found in the directory."<<endl;
    }

    void Display_Table(){
        cout<<"\n--- Employee Hash Table ---\n";
        for(int i=0;i<SIZE;i++){
            if(table[i] != ""){
                cout<<"Index "<<i<<": "<<table[i]<<endl;
            }
            else{
                cout<<"Index "<<i<<": "<<"Empty"<<endl;
            }
        }
        cout<<endl;
    }
};

int main(){
    EmployeeHashTable h;

    h.Add_Employee("Alice");
    h.Add_Employee("Bob");
    h.Add_Employee("Zainab Rajput");
    h.Add_Employee("Charlie");
    h.Add_Employee("David");
    cout<<endl;

    h.Search_Employee("Bob");
    h.Search_Employee("Eve");

    cout<<endl;
    h.Display_Table();

    return 0;
}
