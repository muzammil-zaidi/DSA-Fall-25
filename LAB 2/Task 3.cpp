#include<iostream>
using namespace std;

class JaggedArray{
private:
    int** array;
    int rows;

public:
    JaggedArray(int r){
        rows=r;
        array=new int*[rows];
    }

    ~JaggedArray(){
        for(int i=0;i<rows;i++){
            delete[] array[i];
        }
        delete[] array;
    }

    void setRow(int row,int n){
        array[row]=new int[n];
    }

    void setValues(int row,int n,int* values){
        for(int i=0;i<n;i++){
            array[row][i]=values[i];
        }
    }

    int sumRow(int row,int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=array[row][i];
        }
        return sum;
    }

    void printRow(int row,int n){
        for(int i=0;i<n;i++) {
            cout<<array[row][i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n=3;
    JaggedArray scores(n);

    int t1[]={10,20,30};  
    int t2[]={15,15};       
    int t3[]={40,10,50,70};  

    scores.setRow(0,3);
    scores.setValues(0,3,t1);

    scores.setRow(1,2);
    scores.setValues(1,2,t2);

    scores.setRow(2,4);
    scores.setValues(2,4,t3);

    for(int i=0;i<n;i++){
        int num;

        if(i==0){
            num=3;
        }
        else if (i==1){
            num=2;
        }
        else{
            num=4;
        }

        cout<<"Team "<<i+1<<" scores: ";
        scores.printRow(i,num);
        cout<<"Sum of Team "<<i+1<<" scores: "<<scores.sumRow(i,num)<<endl;
    }

    return 0;
}
