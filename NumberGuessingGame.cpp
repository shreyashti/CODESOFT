#include<iostream>
using namespace std;
#include<ctime>
#include<cstdlib>

int main(){
    srand(time(0)); // Here we have to seed the random number generator with the current time
    int HiddenNumber = rand() % 100 + 1; // Random number will be generated here between 1-100, if we take 200 in place of 100 than there will  number between 1-200
    int guess = 0;
    int attempts = 0;


cout<<"WELCOME TO THE NUMBER GUESSING GAME"<<endl;
cout<<"-----------------------------------"<<endl;
cout<<"WE HAVE SELECTED A NUMBER BETWEEN 1 TO 100"<<endl;
cout<<"---------CAN YOU GUESS WHAT IT IS...?-------"<<endl;

//Now this loop will iterate until the user guesses the correct number

while(guess != HiddenNumber){
    cout<<"Enter your guess: ";
    cin>>guess;
    attempts++;

    if(guess > HiddenNumber){
        cout<<"Too high! Try again......"<<endl;
    }
    else if(guess < HiddenNumber){
        cout<<"Too Low! Try again......."<<endl;
    }
    else{
        cout<<"WOOHOO! YOU GUESSED THE NUMBER...... "<<endl;
    }
}

return 0;
}