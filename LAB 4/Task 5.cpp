#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int binarySearch(int arr[],int n,int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;

        if (arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" integers:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubbleSort(arr,n);

    cout<<"\nSorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    int key;
    cout<<"Enter value to search: ";
    cin>>key;

    int result=binarySearch(arr,n,key);

    if(result!=-1){
        cout<<"Element "<<key<<" found at index "<<result<<".\n";
    }
    else{
        cout<<"Element "<<key<<" not found in array.\n";
    }

    return 0;
}
