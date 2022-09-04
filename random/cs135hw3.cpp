/*
* Name: Cruz Luna, 2001582775, #3
* Description:outputs calculation between two numbers or results of Anime quiz
* Input: single character input A or Q to either do a calcuation or run an Anime quiz
* Output: calculation results of two numbers OR quiz results
*/


/* main(): accepts char user input (A or Q) to do either a calculation or an Anime quiz.
Calculator includes the operations between two numbers:
    addition, subtraction, multiplication, division, power, comparison, & modulus
Anime quiz:
    a series of questions with three outcomes that decide if the user is allowed into the anime club
*/
#include <iostream>
#include <cmath> // include to use power operation
using namespace std;



int main(int argc, char ** argv){
    char userChoice; //user choise as a char
    int score = 0; // running score variable 

    //Prompt the user and read their choice
    cout << "Enter Which Program You Wish to Run:"<< endl;
    cout << "A: Calculator\n"<<"Q: Quiz"<<endl;
    cin >> userChoice;
    
    switch(userChoice)
    {
        case 'A':  // User selects calculator portion
            float firstNum, secNum; //user input 
            char calcOp; // calculator selection
            cout << "Running calculator"<< endl;
            cout << "Enter First Number: "<< endl;
            cin >> firstNum;
            cout << "Enter Second Number: " << endl;
            cin >> secNum;
        
            cout << "Enter operation to perform from list: "<< endl;
            cout << "A: Addition\n"<<"S: Subtraction\n"<<"M: Multiplication\n";
            cout << "D: Division\n"<< "P: Power\n"<< "C: Comparison\n" << "O: Modulus\n";
            cin >> calcOp; // (char) user input for calc operation 

                switch(calcOp)
                {
                    case 'A': // addition
                        cout << "The Answer to life is: " << firstNum + secNum << endl;
                        break;
                    case 'S': // subtraction
                        cout << "The Answer to life is: " << firstNum - secNum << endl;
                        break;
                    case 'M': // multiplication
                        cout << "The Answer to life is: " << firstNum * secNum << endl;
                        break;
                    case 'D': // division
                        if(secNum == 0)
                        {
                            cout << "Division by Zero detected. Aborting!"<<endl;
                            return -1;
                            break;
                        }
                        cout << "The Answer to life is: " << firstNum / secNum << endl;
                        break;
                    case 'P': // power
                         if((firstNum == 0)&&(secNum < 0 ))
                        {
                            cout << "Mathematically not possible. Aborting!"<<endl;
                            return -1 ;
                            break;
                        }
                        cout << "The Answer to life is: " << pow(firstNum, secNum) << endl;
                        break;
                    case 'C': // comparison
                        if(firstNum == secNum)
                        {
                            cout << firstNum << "  is equal to " << secNum << endl;
                        }else if (firstNum > secNum){
                            cout << firstNum << " is greater than " << secNum << endl; 
                        }else{
                            cout << firstNum << " is less than " << secNum << endl;
                        }
                        
                        break;
                    case 'O': // modulus
                        cout << "The Answer to life is: " << (int) firstNum % (int) secNum << endl;
                        // cast double as int 
                        break; 
                    default: // user types any other character than above
                    cout << firstNum * -1 << endl;  // inverse operation on first number
                }   
                break;
        case 'Q':// user selects anime quiz 
            
            char firstQ, secQ, thirdQ, fourthQ, fifthQ, sixthQ, seventhQ, eigthQ;
            // declaring question variables 

            cout << "Running Quiz"<< endl;
            cout << "Hello there, Welcome to the Automated Anime Club test,\n"<<endl;
            cout << "Please Answer each Question with a Y for Yes, and N for No."<< endl;
    
            cout << "Do you agree that Japanese animation are nothing more than cartoons?"<<endl;
            cin >> firstQ; // user input to first question
            if (firstQ== 'Y'){
                score = score - 5;
            } else if(firstQ = 'N'){
                score = score + 5;
            }else{
                score = score + 0;
            }

            cout << "Can you tell when people are speaking Japanese? "<< endl;
            cin >> secQ; // user input to second question

            if(secQ == 'Y'){
                score = score + 5;
            }else if (secQ == 'N'){
                score = score - 5;
            }else{
                score = score + 0;
            }
            
            cout << "Do you hate body pillows?"<< endl;
            cin >> thirdQ; // user input to third question
            if(thirdQ == 'Y'){
                score = score - 5;
            }else if (thirdQ == 'N'){
                score = score + 5;
            }else{
                score = score + 0;
            }
            cout << "Have you seen the toothbrush scene?"<< endl;
            cin >> fourthQ; // user input to 4th question
            if(fourthQ == 'Y'){
                score = score + 5;
            }else if (fourthQ == 'N'){
                score = score - 5;
            }else{
                score = score + 0;
            }

            cout << "Did you ever hear the tragedy of Darth Plagueis The Wise?"<< endl;
            cin >> fifthQ; // user input to 5th question
            if(fifthQ == 'Y'){
                score = score - 0;
            }else if (fifthQ == 'N'){
                score = score + 0;
            }else{
                score = score + 0;
            }
            //output paragraph
            cout << "I thought not. It's not a story the Jedi would tell you. It\'s a Sith legend. Darth Plagueis was a Dark"<< endl;
            cout <<"Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to"<<endl;
            cout <<"create life... He had such a knowledge of the dark side that he could even keep the ones he cared about"<<endl;
            cout <<"from dying. The dark side of the Force is a pathway to many abilities some consider to be unnatural."<<endl;
            cout <<"He became so powerful... the only thing he was afraid of was losing his power, which eventually, of "<<endl;
            cout <<"course, he did. Unfortunately, he taught his apprentice everything he knew, then his apprentice killed"<<endl;
            cout <<"him in his sleep. It's ironic he could save others from death, but not himself.\n"<<endl;


            cout << "Is it possible to learn this power?"<< endl;
            cin >> sixthQ; // user input 6th question
            if(sixthQ == 'Y'){
                score = score - 0;
            }else if (sixthQ == 'N'){
                score = score + 0;
            }else{
                score = score + 0;
            }
            cout << "Do you own anything imported from Japan excluding Cameras and watches?"<< endl;
            cin >> seventhQ; // user input 7th question
            if(seventhQ == 'Y'){
                score = score + 5;
            }else if (seventhQ == 'N'){
                score = score - 5;
            }else{
                score = score + 0;
            }

            cout << "Do you use bleach or watch \"bleach\"? Answer U for use, W for watch"<< endl;
            cin >> eigthQ; // user input 8th question
            if(eigthQ == 'U'){
                score = score - 5;
            }else if (eigthQ == 'W'){
                score = score + 5;
            }else{
                score = score + 0;
            }

            // check sum of score from quiz and determine results
            if (score>10){
                cout << "Oni Chan? You are hereby granted Club President!"<<endl;
            }else if(score<=0){
                cout << "You are a traitor and spy, begone !"<< endl;
            }else{
                cout << "Congratulations. You are in this council, but we don ot grant you the\n"<< "rank of master"<<endl;
            }

            break;
        default: // did not put A or Q (did not select quiz or calculator)
            cout << "Invalid Entry, Goodbye"<< endl;
            break;
            
    }



}