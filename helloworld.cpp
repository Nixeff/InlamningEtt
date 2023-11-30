#include <iostream>
#include <ctime>

using namespace std;

int money = 0;
int winnings = 0;

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
        cout << "Are you over the age of 18?(y/n)"<< endl;
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
        cout << "Your Balance: " << money<<"kr" << endl << "What do you want to do? (1: Handle Money 2: Play 3: Exit)"<<endl;
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
    cout << "How much do you want to load? (Not over 5000kr)" <<endl;
    cin.clear();
    cin >> amount;
    if((amount+money)<=5000 && amount > 0){
        money=money+amount;
        cout << "Your new balance is: "<<money<<"kr"<<endl;
    } else{
        cout << "You cant add "<< amount << "kr to your account!";
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
        cout << "Your new balance is: "<<money<<"kr"<<endl;
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
        cout << "You have: "<< money << "kr"<<endl << "What do you want to do? (1: Load money 2: Take money 3: Go Back To Main Menu)"<<endl;
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
    int option;
    int bet;
    int playerDice[2] = {1,1};
    int computerDice[2] = {1,1};;
    int playerResult;
    int computerResult;
    int playerScore = 0;
    int computerScore = 0;
    bool playing = true;
    bool betting = true;
    while(betting){
        system("CLS");
        cout << "You have: "<< money << "kr"<<endl << "How much do you want to bet? (1: 100 2: 200 3: 500 0: exit to main menu)"<< endl;
        cin >> option;
        switch(option) {
            case 0:
                betting = false;
                playing = false;
                break;
            case 1:
                if(money>=100){
                    betting = false;
                    bet = 100;
                }else{
                    cout<<"You don't have that much money!"<<endl;
                }
                break;
            case 2:
                if(money>=200){
                    betting = false;
                    bet = 200;
                }else{
                    cout<<"You don't have that much money!"<<endl;
                }
                break;
            case 3:
                if(money>=500){
                    betting = false;
                    bet = 500;
                }else{
                    cout<<"You don't have that much money!"<<endl;
                }
                break;
            default:
                cout << "That was not a valid input!";
                break;
        }
        system("pause");
    }
    money-=bet;
    while(playing){
        system("CLS");
        if(playing){
            getDiceSeed();
            playerDice[0]=rollDie();
            playerDice[1]=rollDie();
            playerResult = playerDice[0]+playerDice[1];
            computerDice[0]=rollDie();
            computerDice[1]=rollDie();
            computerResult = computerDice[0]+computerDice[1];
            cout << "You rolled : " << playerDice[0] << " + "<<playerDice[1]<<" For a total of "<< playerResult<<" ,The Computer rolled : " << computerDice[0] << " + "<<computerDice[1]<<" For a total of "<< computerResult<<endl;
            if (playerResult>computerResult){
                playerScore++;
                cout << "You won this round! You have "<<playerScore<<" Points! And The computer has "<<computerScore<<" Points!" <<endl;
            } else if (computerResult>playerResult){
                computerScore++;
                cout << "The computer won this round! You have "<<playerScore<<" Points! And The computer has "<<computerScore<<" Points!" <<endl;
            } else {
                cout << "It was a Tie!"<<endl;
            }
            cout << "The score is "<<playerScore << " To the player and "<<computerScore<<" To the Computer!"<<endl;
            if(playerScore>= 2){
                money+=bet*2;
                winnings += bet;
                cout<<"You Win!"<<endl<<"You have earned "<<bet<<"kr"<<endl<<"Making your balance: "<<money<<"kr"<<endl<<"Your total winnings are: "<<winnings<<"kr"<<endl;
                playing = false;
            }else if (computerScore >= 2){
                winnings-= bet;
                cout<<"You lose!"<<endl<<"You lost your bet of "<<bet<<"kr"<<endl<<"Making your balance: "<<money<<"kr"<<endl<<"Your total winnings are: "<<winnings<<"kr"<<endl;
                playing = false;
            }
            system("pause");
        }

    }
    
    return 0;
}