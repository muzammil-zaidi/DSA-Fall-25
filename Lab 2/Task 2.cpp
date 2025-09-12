#include<iostream>
using namespace std;

class DynamicMatrix{
private:
    int** matrix;
    int rows;
    int cols;

public:
    DynamicMatrix(int r,int c){
        rows=r;
        cols=c;
        matrix=new int*[rows];
        for(int i=0;i<rows;i++){
            matrix[i]=new int[cols];
        }
    }

    ~DynamicMatrix(){
        for(int i=0;i<rows;i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void resize(int newRows,int newCols,int fillValue){
        int** newMatrix=new int*[newRows];
        for(int i=0;i<newRows;i++){
            newMatrix[i]=new int[newCols];
            for(int j=0;j<newCols;j++){
                if(i<rows && j<cols){
                    newMatrix[i][j]=matrix[i][j];
                }
                else{
                    newMatrix[i][j]=fillValue;
                }
            }
        }

        for(int i=0;i<rows;i++){
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix=newMatrix;
        rows=newRows;
        cols=newCols;
    }

    void transpose(){
        int** transposed=new int*[cols];
        for(int i=0;i<cols;i++){
            transposed[i]=new int[rows];
            for(int j=0;j<rows;j++){
                transposed[i][j]=matrix[j][i];
            }
        }

        for(int i=0;i<rows;i++){
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix=transposed;
        swap(rows,cols);
    }

    void addToOddIndex(int value){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if((i+j)%2!=0){
                    matrix[i][j]+=value;
                }
            }
        }
    }

    void print(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void fill(int value){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                matrix[i][j]=value;
            }
        }
    }

    int getRows(){
        return rows;
    }

    int getCols(){
        return cols;
    }
};

int main(){
    DynamicMatrix m(3,3);
    m.fill(7);

    cout<<"Original Matrix: \n";
    m.print();

    m.addToOddIndex(2);
    cout<<"\nMatrix after adding 2 to odd indices: \n";
    m.print();

    m.resize(4,4,2);
    cout<<"\nResized Matrix (4x4): \n";
    m.print();

    m.transpose();
    cout<<"\nTransposed Matrix: \n";
    m.print();

    return 0;
}
