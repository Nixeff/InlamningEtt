#include <iostream>

using namespace std;

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
        cout << "What do you want to do?"<<endl;
        cin.clear();
        cin >> option;
        switch(option){
            case(1):
                cout << "Oki!";
                break;
            default:
                break;
        }
    }
    return 0;
}