#include<iostream>
using namespace std;

int generateRandomNumber(){
    static int seed=1;
    seed=(seed*17+23)%100;
    return seed+1;
}

void manualSwap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void bubbleSort(int arr[],int n,int &comparisons){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++){
            comparisons++;
            if(arr[j]>arr[j+1])
                manualSwap(arr[j],arr[j+1]);
        }
}

void insertionSort(int arr[],int n,int &comparisons){
    for(int i=1;i<n;i++){
        int key=arr[i],j=i-1;
        comparisons++;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
            comparisons++;
        }
        arr[j+1]=key;
    }
}

void selectionSort(int arr[],int n,int &comparisons){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            comparisons++;
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        manualSwap(arr[i],arr[minIndex]);
    }
}

void shellSort(int arr[],int n,int &comparisons){
    for(int gap=n/2;gap>0;gap /=2)
        for(int i=gap;i<n;i++){
            int temp=arr[i],j=i;
            comparisons++;
            while(j>=gap && arr[j-gap]>temp){
                arr[j]=arr[j-gap];
                j-=gap;
                comparisons++;
            }
            arr[j]=temp;
        }
}

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void copyArray(int source[],int dest[],int n){
    for(int i=0;i<n;i++)
        dest[i]=source[i];
}

void runSorts(int arr[],int n){
    int arr_copy[100];
    int comparisons;

    copyArray(arr, arr_copy, n);
    comparisons=0;
    bubbleSort(arr_copy,n,comparisons);
    cout<<"Bubble Sort: ";
    displayArray(arr_copy,n);
    cout<<"Comparisons: "<<comparisons<<"\n";

    copyArray(arr,arr_copy,n);
    comparisons=0;
    insertionSort(arr_copy,n,comparisons);
    cout<<"Insertion Sort: ";
    displayArray(arr_copy,n);
    cout<<"Comparisons: "<<comparisons<<"\n";

    copyArray(arr,arr_copy,n);
    comparisons=0;
    selectionSort(arr_copy,n,comparisons);
    cout<<"Selection Sort: ";
    displayArray(arr_copy,n);
    cout<<"Comparisons: "<<comparisons<<"\n";

    copyArray(arr,arr_copy,n);
    comparisons=0;
    shellSort(arr_copy,n,comparisons);
    cout<<"Shell Sort: ";
    displayArray(arr_copy,n);
    cout<<"Comparisons: "<<comparisons<<"\n";
}

int main(){
    int n=20;
    int arr[100];

    cout<<"----- Sorting 20 random integers -----\n";
    for(int i=0;i<n;i++)
        arr[i]=generateRandomNumber();

    cout<<"Original Array: ";
    displayArray(arr,n);

    runSorts(arr,n);

    cout<<"\n----- Sorting 100 random integers -----\n";
    n=100;
    for(int i=0;i<n;i++)
        arr[i]=generateRandomNumber();

    cout<<"Original Array: ";
    displayArray(arr,n);

    runSorts(arr,n);

    return 0;
}
