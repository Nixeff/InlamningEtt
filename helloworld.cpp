#include <iostream>

using namespace std;

int money = 0;

int loadMoney(){
    int amount;
    cout << "How much do you want to load? (Not over $5000)" <<endl;
    cin >> amount;
    if((amount+money)<=5000){
        money=money+amount;
    } else{
        cout << "That is too much money!";
    }
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
                break;
            case(3):
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}

int play(){
    
    return 0;
}


int main(){
    string anwser;
    int option;

    system("CLS");
    cout << "Are you over the age of 18?";
    cin >> anwser;

    if (anwser== "y"){
        cout << "Awesome! Lets gamble";
    } else if (anwser == "n"){
        cout << "You have to be over the age of 18 to gamble kid!";
        return 0;
    } else {
        cout << "That is not a valid anwser";
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

