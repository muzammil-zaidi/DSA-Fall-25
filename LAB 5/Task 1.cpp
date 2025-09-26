#include<iostream>
#include<cstdlib> 
#include<ctime>
using namespace std;

void guessNumber(int target,int playerTurn){
    int guess;
    cout<<"Player "<<playerTurn<<", enter your guess (1-100): ";
    cin>>guess;

    if(guess==target){
        cout<<"Congratulations! Player "<<playerTurn<<" wins!\n";
        return;
    }
    else if(guess<target){
        cout<<"Too low. ";
    }
    else{
        cout<<"Too high. ";
    }

    int nextPlayer;
    if(playerTurn==1){
        nextPlayer=2;
    }
    else{
        nextPlayer=1;
    }

    guessNumber(target,nextPlayer);
}

int main(){
    srand(time(0));
    int target=rand()%100+1;

    cout<<"Welcome to the Number Guessing Game!\n";
    cout<<"Players take turns to guess the number between 1 and 100.\n";

    guessNumber(target,1);

    return 0;
}
