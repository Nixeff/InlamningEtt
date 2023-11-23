#include <iostream>
#include <ctime>

using namespace std;

int money = 0;
char dummy;
bool playing;



int loadMoney();
int takeMoney();
int handleMoney();
int play();
int rollDie();

int main(){
    string anwser;
    int option;

    system("CLS");

    while(true){
        cout << "Are you over the age of 18?"<< endl;
        cin >> anwser;

        if (anwser== "y"){
            cout << "Awesome! Lets gamble";
            break;
        } else if (anwser == "n"){
            cout << "You have to be over the age of 18 to gamble kid!";
            return 0;
        } else {
            cout << "That is not a valid anwser"<< endl;
        }
    }

    while(true){
        system("CLS");
        cout << "Your Balance: $" << money << endl << "What do you want to do? (1: Handle Money 2: Play 3: Exit)"<<endl;
        cin.clear();
        cin >> option;
        switch(option){
            case(1):
                cout << "Oki!";
                handleMoney();
                break;
            case(2):
                play();
                break;
            case(3):
                cout << "Bye Bye!";
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}

int loadMoney(){
    int amount;
    cout << "How much do you want to load? (Not over $5000)" <<endl;
    cin.clear();
    cin >> amount;
    if((amount+money)<=5000 && amount > 0){
        money=money+amount;
        cout << "Your new balance is: $"<<money<<endl;
    } else{
        cout << "You cant add $"<< amount << " to your account!";
    }
    system("pause");
    return 0;
}

int takeMoney(){
    int amount;
    cout << "How much do you want to take out?" <<endl;
    cin.clear();
    cin >> amount;
    if(amount<=money && amount > 0){
        money=money-amount;
        cout << "Your new balance is: $"<<money<<endl;
    } else{
        cout << "You cant take money you dont have!";
    }
    system("pause");
    return 0;
}

int handleMoney(){
    int option;
    while(true){
        system("CLS");
        cout << "What do you want to do? (1: Load money 2: Take money 3: Go Back To Main Menu)"<<endl;
        cin.clear();
        cin >> option;
        switch(option){
            case(1):
                loadMoney();
                break;
            case(2):
                takeMoney();
                break;
            case(3):
                return 0;
                break;
            default:
                cout << "Not a valid input"<<endl;
                break;
        }
    }
    return 0;
}

void getDiceSeed(){
    srand(time(0));
}

int rollDie(){
    return rand() % 6 + 1;
}



int play(){
    int amount;
    int playerDice[2] = {1,1};
    int computerDice[2] = {1,1};;
    int playerScore;
    int computerScore;
    playing = true;
    while(playing){
        system("CLS");
        playerScore = 0;
        computerScore = 0;
        cout << "How much do you want to bet? (Write '0' to exit to main menu)"<< endl;
        cin >> amount;
        if(amount == 0){
            playing = false;
            break;
        } else if(amount > 0){
            getDiceSeed();
            playerDice[0]=rollDie();
            playerDice[1]=rollDie();
            computerDice[0]=rollDie();
            computerDice[1]=rollDie();
            cout << "You rolled : " << playerDice[0] << " + "<<playerDice[1]<<" ,The Computer rolled : " << computerDice[0] << " + "<<computerDice[1]<<endl;
            /*if (playerDie>computerDie){
                playerScore++;
                cout << "You won this round! You have "<<playerScore<<" Points! And The computer has "<<computerScore<<" Points!" <<endl;
            } else if (computerDie>playerDie){
                playerScore++;
                cout << "The computer won this round! You have "<<playerScore<<" Points! And The computer has "<<computerScore<<" Points!" <<endl;
            } else {
                
            }*/
            system("pause");
        }

    }
    
    return 0;
}