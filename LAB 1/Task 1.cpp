#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    char **courses;

    cout<<"How many courses do you want to register? ";
    cin>>n;
    cin.ignore();

    courses=new char*[n];

    for(int i=0;i<n;i++){
        char temp[100];
        cout<<"Enter course name "<<i+1<<": ";
        cin.getline(temp,100);

        courses[i]=new char[strlen(temp)+1];
        strcpy(courses[i],temp);
    }

    cout<<"\nRegistered Courses:\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<". "<<courses[i]<<"\n";
    }

    for(int i=0;i<n;i++){
        delete[] courses[i];
    }
    delete[] courses;

    return 0;
}
