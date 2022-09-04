// conditionals
/* Program will play rock, paper, scissors; choosing from the variabel at the top for its play*/

#include <iostream>
using namespace std;

// Constants for the computer choices so the code is readable
/*const int ROCK = 0;
const int PAPER = 1;
const int SCISS = 2;
*/
enum RPS { ROCK, PAPER, SCISSORS}; // Quickly numbers 

int main(){
   /* int computerChoice = ROCK; // COMPUTER will always choose rock
    char playerChoice;
    
    cout << " Please pick rock (r), paper (p), or scissors (s)"<< endl;
    cin >> playerChoice;
    cout << "You chose  " << playerChoice << "\n\n" ;
    
    if(playerChoice == 'r')
    {
        cout << "You chose rock!" << endl;
    }*/

    switch(playerChoice ) // equivalent of else if
    {
        case 'r': 
            cout << "You chose rock" << endl;
            break;
        case 'p':
           cout << "You chose paper" << endl;
           break;
        case 's': 
            cout << "You chose scissors" << endl;
            break;
        default: //if  not r,p, or s
            break;
    }
}


