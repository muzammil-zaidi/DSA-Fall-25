#include<iostream>
using namespace std;

int sumDigits(int n){
    if(n==0)
        return 0;
    return (n%10)+sumDigits(n/10);
}

int nestedSum(int n){
    if(n<10)
        return n;
    
    int sum=sumDigits(n);
    return nestedSum(sum);
}

int main(){
    int number;
    cout<<"Enter a number: ";
    cin>>number;

    int result=nestedSum(number);
    cout<<"Final single-digit sum: "<<result<<endl;

    return 0;
}
