#include <iostream>
#include <ctime>

using namespace std;


int money = 0;          //Hur mycket pengar du har 
int winnings = 0;       //Hur mycket pengar du har kännat/förlorat
bool running = true;    //Används för att se om programmet ska köras
bool playing;

//Definerar mina funktioner 
void areYouOfAge();
int loadMoney();
int takeMoney();
int handleMoney();
int play();
int howMuchDoYouWantToBet();
int rollDie();


int main(){
    system("CLS");      //Varje gång system("CLS") körs är det för att cleara terminalen för att skapa effekten av att det inte är en massa nya rader som skrivs
    areYouOfAge();      
    while(running){
        system("CLS");
        char option;
        cout << "Your Balance: " << money<<"kr" << endl << "What do you want to do? (1: Handle Money 2: Play 3: Exit)"<<endl;
        cin.clear();
        cin >> option;  
        switch(option){
            case('1'):
                handleMoney();
                break;
            case('2'):
                play();
                break;
            case('3'):
                cout << "Bye Bye!";
                running = false;
                break;
            default:
                break;
        }
    }
    return 0;
}


/*  areYouOfAge
    Frågar om du är över 18 om inte så kommer den att sätta running till falskt vilket betyder att spelet inte kommer starta. Om du är över 18
    så kommer den att inte göra någonting.

    Ger inte ut ett svar
*/
void areYouOfAge(){
    while(true){
        char anwser;
        cout << "Are you over the age of 18?(y/n)"<< endl;
        cin >> anwser;
        if (anwser== 'y'){
            cout << "Awesome! Lets gamble";
            break;
        } else if (anwser == 'n'){
            cout << "You have to be over the age of 18 to gamble kid!";
            running = false;
            break;
        } else {
            cout << "That is not a valid anwser"<< endl;
        }
    }
}

/*  loadMoney 
    Låter användaren ge en input(integer) som ska vara emmellan 1-5000 och "laddar" det till kontot

    Ger alltid ut 0 som svar
*/
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

/*  takeMoney
    Låter användaren ge en input(integer) som ska vara emmellan 1-hur mycket pengar som finns på kontot.
    Sen så tar den bort de pengarna ifrån kontot

    Ger alltid ut 0 som svar
*/
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

/*  handleMoney
    Tar användaren till en meny där de kan välja vilken pengar funktion de vill använda eller om de vill gå till baka till huvudmenyn(Se main)
    
    Ger alltid ut 0 som savar*/
int handleMoney(){
    while(true){
        char option;
        system("CLS");
        cout << "You have: "<< money << "kr"<<endl << "What do you want to do? (1: Load money 2: Take money 3: Go Back To Main Menu)"<<endl;
        cin.clear();
        cin >> option;
        switch(option){
            case('1'):
                loadMoney();
                break;
            case('2'):
                takeMoney();
                break;
            case('3'):
                return 0;
                break;
            default:
                cout << "Not a valid input"<<endl;
                break;
        }
    }
    return 0;
}
/*  getDiceSeed
    Skapar ett typ av lista med "slump" tal med hjälp av den totala tiden ifrån idag till 1970/1/1
    
    Ger alldrig ut något svar
*/
void getDiceSeed(){
    srand(time(0));
}

/*  rollDie
    Slumpar ett tal emmelan 1-6
    
    Ger ut ett slump tal emmelan 1-6(integer)
*/
int rollDie(){
    return rand() % 6 + 1;
}

/*  howMuchDoYouWantToBet
    Låter spelaren välja hur mycket de vill satsa
    
    retunerar anntingen 0,100,300,500(integer)*/
int howMuchDoYouWantToBet(){
    while(true){
        char option;
        system("CLS");
        cout << "You have: "<< money << "kr"<<endl << "How much do you want to bet? (1: 100 2: 300 3: 500 0: exit to main menu)"<< endl;
        cin >> option;
        switch(option) {
            case '0':
                playing = false;
                return 0;
                break;
            case '1':
                if(money>=100){
                    money-=100;
                    return 100;
                }else{
                    cout<<"You don't have that much money!"<<endl;
                }
                break;
            case '2':
                if(money>=300){
                    money-=300;
                    return 300;
                }else{
                    cout<<"You don't have that much money!"<<endl;
                }
                break;
            case '3':
                if(money>=500){
                    money-=500;
                    return 500;
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
}

/*  play
    Här är själva spelet. Det börjar med att använda howMuchDoYouWantToBet() för att få reda på hur mycket spelaren vill satsa.
    Sedan börjar spelet (Om spelaren hade pengar att satsa). Först rullas tärningarna sedan gemförs summorna och om någon får mer
    vinner dem och om de blir lika spelas omgången om tills det att någon fått 2 vinnster. 
    
    returnerar alltid 0
*/
int play(){
    int bet;
    int playerDice[2] = {1,1};
    int computerDice[2] = {1,1};
    int playerResult;
    int computerResult;
    int playerScore = 0;
    int computerScore = 0;
    playing = true;
    bet = howMuchDoYouWantToBet();
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

