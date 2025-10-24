#include<iostream>
#include<string>
using namespace std;

struct Product{
    string name;
    float price;
    string description;
    string availability;
};

int partition(Product arr[],int low,int high){
    float pivot=arr[high].price;
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j].price<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(Product arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void display(Product arr[],int n){
    cout<<"\nSorted Product List by Price:\n";
    cout<<"----------------------------------------------------------\n";
    cout<<"Name\t\tPrice\t\tAvailability\tDescription\n";
    cout<<"----------------------------------------------------------\n";
    for(int i=0;i<n;i++){
        cout<<arr[i].name<<"\t\t"<<arr[i].price<<"\t\t"<<arr[i].availability<<"\t\t"<<arr[i].description<<endl;
    }
    cout<<"----------------------------------------------------------\n";
}

int main(){
    int n=3;
    Product products[n];

    cout<<"Enter details of 3 products:\n";
    for(int i=0;i<n;i++){
        cout<<"\nProduct "<<i+1<<" name: ";
        cin>>products[i].name;
        cout<<"Enter price: ";
        cin>>products[i].price;
        cin.ignore();
        cout<<"Enter description: ";
        getline(cin,products[i].description);
        cout<<"Enter availability (In-stock / Out-of-stock): ";
        getline(cin,products[i].availability);
    }

    cout<<"\nSorting products by price using Quick Sort...\n";
    quickSort(products,0,n-1);

    display(products,n);

    return 0;
}
