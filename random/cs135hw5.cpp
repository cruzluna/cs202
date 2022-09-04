/*
* Name: Cruz Luna, 2001582775, #5
* Description:outputs results of three mini games-- Gues a number, Repeat a word, & Power calculation
* Input: integer between 1-10, a word (string) to repeat, and three more integers  
* Output:  results of three games--
*/


/* 
* guessAnumber: guess a number between 1-10. Prompts user to keep guessing until they are correct.
* parameters: rand & guess 
* return value:  a string that returns the result (Correct or incorrect)   
*/
/* 
* repeatWord:ask for a word to repeat and how many times and print it
* parameters: words & repeats
* return value:  the word entered the amount of times prompted by the user
*/

/*
* mypow: implementation of the power function from cmath using for loops
* parameters: base & exponent 
* return value:  a power calculation 
*/

#include <iostream>
#include <string>
#include <time.h>    //For Time
#include <stdlib.h>  //For srand
//Not allowed to use cmath or any absolute value function.
using namespace std;

void guessAnumber(int s){
    int random = rand() % s + 1; //random number in range [1 to s] (including s)
    int guess;
    bool done = false; // assume prediction is false until proven otherwise
    cout << "Guess a Number between 1 and "<< s << endl; // prompt user to enter number
    //Your Code Here
    int count = 0; //current count 
    
    // use a while loop
    //Count through all of the numbers [1 to s] 
    while(!done)//keep iterating while false (until bool done = true)
    {   //cout << count << "\n";
        cin >> guess;
        // check guess
        if(random != guess){
            cout << "The force is not with you. Try Again! " << endl; 
            count++; //keep counting  
        }else{
            cout << "The Force is strong with this one! You win!" << endl;
            done = true; // Quit the loop
        }
    }
}

void repeatWord(){
    int repeats;
    string word;
    cout << "Enter a Single word to repeat: ";
    cin >> word;
    cout << "\nEnter How many times to repeat: ";
    cin >> repeats;
    //Your Code Here
    //for loop
    for(int countt = 1; countt <= repeats; countt++ ){
        cout << word << endl; // prints repeated word
    }

    cout << "Done repeating word " << repeats << " times!" << endl; //display
}

void mypow(){ //Note, instead of return 0 or 1, simply type return.
    //Use floats! You must use a loop!
    float base;
    int exponent;
    float answer;
    cout << "My Power Function!\n";
    //Your Code Here
    
    cout << "Enter base number: "; // prompt user for base 
    cin >> base; 

    cout << "Enter exponent: ^"; // prompt user for exponent
    cin >> exponent;

    int result = 1; // initializes loop 
    // anything multiplied by one is itself
    
    //following if takes care of negative exp and postitive base
    if(exponent < 0 && base > 0){
        exponent= exponent*-1; 
        for(int i = 1; i <= exponent; i++){
            result *= base;// equiv to result = result * base
            ///1* base* base * n....
        }
        cout << "The Answer is: 1/" << result<< endl; // display
        return; 
        
    }
    // following if takes care of negative exp and negative base
     if(exponent < 0 && base < 0){
        exponent= exponent*-1;
        for(int i = 1; i <= exponent; i++){
            result *= base;
            
        }
        cout << "The Answer is: -1/" << result*-1<< endl;
        return; 
        
    }


    
    for(int i = 1; i <= exponent;i++)// cant be i=0 because that would give use x^n+1
    { 
        result *= base; // equiv to result = result * base
    }
    cout << "The Answer is: " << result << endl;

}

//Don't touch Main
int main(int argc, char *argv[]){
	//Normally we seed on time, but for now let's just seed with a constant for consistency
    //srand(time(NULL)); 
	srand(argc == 2 ? atoi(argv[1]) : 11037);
    guessAnumber(10);
    repeatWord();
    mypow();
    cout << "Thanks for playing, Goodbye!" << endl;
    return 0;
}
