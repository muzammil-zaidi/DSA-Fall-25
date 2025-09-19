#include<iostream>
using namespace std;

void shellSort(int arr[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j=i;

            while(j>=gap && arr[j-gap]>temp){
                arr[j]=arr[j-gap];
                j-=gap;
            }
            arr[j]=temp;
        }
    }
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

    cout<<"\nOriginal Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    shellSort(arr,n);

    cout<<"Sorted Array (Shell Sort): ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
