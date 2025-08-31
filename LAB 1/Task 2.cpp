#include<iostream>
using namespace std;

class StudentRecord{
private:
    int *marks;
    int size;

public:
    StudentRecord(int n){
        size=n;
        marks=new int[size];
        for(int i=0;i<size;i++){
            marks[i]=0;
        }
    }

    ~StudentRecord(){
        delete[] marks;
    }

    void setMark(int index,int value){
        if(index>=0 && index<size){
            marks[index]=value;
        }
    }

    void display() const{
        for(int i=0;i<size;i++){
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    StudentRecord student1(3);

    student1.setMark(0,85);
    student1.setMark(1,90);
    student1.setMark(2,95);

    cout<<"Original student marks: ";
    student1.display();

    StudentRecord student2=student1;

    cout<<"Copied student marks (before modification): ";
    student2.display();

    student2.setMark(0,50);

    cout<<"After modifying copied student marks:"<<endl;
    cout<<"Original student marks: ";
    student1.display();
    cout<<"Copied student marks: ";
    student2.display();

    return 0;
}
