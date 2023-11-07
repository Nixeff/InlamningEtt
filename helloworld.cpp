#include <iostream>

using namespace std;

int money;

int handleMoney(){
    int option;
    while(true){
        system("CLS");
        cout << "What do you want to do? (1: Load money 2: Take money 3: Go Back To Main Menu)"<<endl;
        cin.clear();
        cin >> option;
        switch(option){
            case(1):
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


int main(){
    string anwser;
    int option;

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
        cout << "What do you want to do? (1: Handle Money 2: Play 3: Exit)"<<endl;
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

