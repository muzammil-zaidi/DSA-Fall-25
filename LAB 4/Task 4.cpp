#include<iostream>
#include<algorithm>
using namespace std;

int interpolationSearch(int arr[],int n,int key){
    int low=0;
    int high=n-1;

    while(low<=high && key>=arr[low] && key<=arr[high]){
        if(arr[high]==arr[low]){
            if(arr[low]==key){
                return low;
            }
            else{
                return -1;
            }
        }

        int pos=low+((key-arr[low])*(high-low))/(arr[high]-arr[low]);

        if(arr[pos]==key){
            return pos;
        }
        else if(arr[pos]<key){
            low = pos + 1;
        }
        else{
            high=pos-1;
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

    sort(arr,arr+n);

    cout<<"\nSorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    int key;
    cout<<"Enter value to search: ";
    cin>>key;

    int result=interpolationSearch(arr,n,key);

    if(result!=-1){
        cout<<"Element "<<key<<" found at index "<<result<<".\n";
    }
    else{
        cout<<"Element "<<key<<" not found in array.\n";
    }

    return 0;
}
