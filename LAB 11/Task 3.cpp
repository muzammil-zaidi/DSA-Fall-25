#include<iostream>
using namespace std;

class Hash{
private:
    int arr[100];
    int size;

public:
    Hash(){
        size=0;
    }

    void insert(int value){
        arr[size]=value;
        size++;
    }

    void remove(int value){
        int index=-1;

        for(int i=0;i<size;i++){
            if(arr[i]==value){
                index=i;
                break;
            }
        }

        if(index==-1){
            cout<<value<<" not found"<<endl;
            return;
        }

        cout<<"Remove "<<value<<endl;

        for(int i=index;i<size-1;i++){
            arr[i]=arr[i+1];
        }

        size--;
    }

    void search(int value){
        for(int i=0;i<size;i++){
            if(arr[i]==value){
                cout<<value<<" found"<<endl;
                return;
            }
        }
        cout<<value<<" not found"<<endl;
    }

    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Hash h;

    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);
    h.display();

    h.remove(4);
    h.display();

    h.search(5);
    h.search(6);

    return 0;
}
