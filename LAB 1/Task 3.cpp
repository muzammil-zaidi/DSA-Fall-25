#include<iostream>
#include<cstring>
using namespace std;

class Playlist{
private:
    char **songs;
    int size;

public:
    Playlist(int n) : size(n){
        songs=new char*[size];
        for(int i=0;i<size;i++){
            songs[i]=nullptr;
        }
    }

    Playlist(const Playlist& other) : size(other.size){
        songs=new char*[size];
        for(int i=0;i<size;i++){
            if(other.songs[i]){
                songs[i]=new char[strlen(other.songs[i])+1];
                strcpy(songs[i],other.songs[i]);
            }
            else{
                songs[i]=nullptr;
            }
        }
    }

    Playlist& operator=(const Playlist& other){
        if(this==&other)
            return *this;

        for(int i=0;i<size;i++){
            delete[] songs[i];
        }
        delete[] songs;

        size=other.size;
        songs=new char*[size];
        for(int i=0;i<size;i++){
            if(other.songs[i]){
                songs[i]=new char[strlen(other.songs[i])+1];
                strcpy(songs[i],other.songs[i]);
            }
            else{
                songs[i]=nullptr;
            }
        }
        return *this;
    }

    ~Playlist(){
        for(int i=0;i<size;i++){
            delete[] songs[i];
        }
        delete[] songs;
    }

    void setSong(int index,const char* name){
        if(index>=0 && index<size){
            delete[] songs[index];
            songs[index]=new char[strlen(name)+1];
            strcpy(songs[index],name);
        }
    }

    void display() const{
        for(int i=0;i<size;i++){
            if(songs[i]){
                cout<<i+1<<". "<<songs[i]<<endl;
            }
            else{
                cout<<i+1<<". [empty]"<<endl;
            }
        }
    }
};

int main(){
    Playlist playlist1(3);
    playlist1.setSong(0,"Song A");
    playlist1.setSong(1,"Song B");
    playlist1.setSong(2,"Song C");

    cout<<"Playlist 1:"<<endl;
    playlist1.display();

    Playlist playlist2=playlist1;

    cout<<"\nPlaylist 2 (after copy):"<<endl;
    playlist2.display();

    playlist2.setSong(0,"Song X");

    cout<<"\nPlaylist 2 (after modification):"<<endl;
    playlist2.display();

    cout<<"\nPlaylist 1 (should be unchanged):"<<endl;
    playlist1.display();

    return 0;
}
