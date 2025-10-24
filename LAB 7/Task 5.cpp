#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int comparisons=0;

int partition(int arr[],int low,int high,string pivotType){
    int pivotIndex;
    
    if(pivotType=="first"){
        pivotIndex=low;
    }
    else if(pivotType=="random"){
        pivotIndex=low+rand()%(high-low+1);
    }
    else if(pivotType=="middle"){
        pivotIndex=low+(high-low)/2;
    }
    else if(pivotType=="median3"){
        int mid=low+(high-low)/2;
        int a=arr[low],b=arr[mid],c=arr[high];
        if((a>b) != (a>c)){
            pivotIndex=low;
        }
        else if((b>a) != (b>c)){
            pivotIndex=mid;
        }
        else{
            pivotIndex=high;
        }
    }

    swap(arr[pivotIndex],arr[high]);
    int pivot=arr[high];

    int i=low-1;

    for(int j=low;j<high;j++){
        comparisons++;
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high,string pivotType){
    if(low<high){
        int pi=partition(arr,low,high,pivotType);
        quickSort(arr,low,pi-1,pivotType);
        quickSort(arr,pi+1,high,pivotType);
    }
}

void displayArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    srand(time(0));

    int arr[]={10,7,8,9,1,5,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    string methods[]={"first","random","middle","median3"};

    cout<<"Original Array:\n";
    displayArray(arr,n);
    cout<<endl;

    for(int i=0;i<4;i++){
        string method=methods[i];
        int temp[n];
        for(int i=0;i<n;i++){
            temp[i]=arr[i];
        }

        comparisons=0;
        quickSort(temp,0,n-1,method);

        cout<<"Pivot Method: "<<method<<endl;
        cout<<"Sorted Array: ";
        displayArray(temp,n);
        cout<<"Comparisons: "<<comparisons<<"\n\n";
    }

    return 0;
}
