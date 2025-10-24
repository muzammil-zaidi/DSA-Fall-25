#include<iostream>
#include<string>
using namespace std;

struct Runner{
    string name;
    int time;
};

void merge(Runner arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    Runner* L=new Runner[n1];
    Runner* R=new Runner[n2];

    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(L[i].time<=R[j].time){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }

    while(i<n1){
        arr[k++] = L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void displayTop5(Runner arr[],int n){
    cout<<"\nTop 5 Fastest Runners:\n";
    cout<<"-----------------------------\n";
    cout<<"Name\t\tTime (s)\n";
    cout<<"-----------------------------\n";

    for(int i=0;i<5 && i<n;i++){
        cout<<arr[i].name<<"\t\t"<<arr[i].time<<endl;
    }

    cout<<"-----------------------------\n";
}

int main(){
    const int n=10;
    Runner runners[n];

    cout<<"Enter names and finish times of 10 runners:\n";
    for(int i=0;i<n;i++){
        cout<<"Runner "<<i+1<<" name: ";
        cin>>runners[i].name;
        cout<<"Finish time (in seconds): ";
        cin>>runners[i].time;
    }

    cout<<"\nSorting marathon results using Merge Sort...\n";
    mergeSort(runners,0,n-1);

    displayTop5(runners,n);

    return 0;
}
