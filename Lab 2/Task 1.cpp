#include<iostream>
using namespace std;

class DynamicArray{
private:
    int* data;
    int size;
    int capacity;

    void resize(){
        int newCapacity=capacity*2;
        int* newData=new int[newCapacity];

        for(int i=0;i<size;i++){
            newData[i]=data[i];
        }

        delete[] data;

        data=newData;
        capacity=newCapacity;
    }

public:
    DynamicArray(int initialCapacity=2){
        capacity=initialCapacity;
        data=new int[capacity];
        size=0;
    }

    ~DynamicArray(){
        delete[] data;
    }

    void push_back(int value){
        if(size==capacity){
            resize();
        }
        data[size++]=value;
    }

    void print() const{
        cout<<"Array elements: ";
        for(int i=0;i<size;i++){
            cout<<data[i]<<' ';
        }
        cout<<endl;
    }

    int getSize() const{
        return size;
    }

    int getCapacity() const{
        return capacity;
    }
};

int main(){
    DynamicArray arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.print();

    cout<<"Size: "<<arr.getSize()<<endl;
    cout<<"Capacity: "<<arr.getCapacity()<<endl;

    return 0;
}
