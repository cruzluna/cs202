#include <iostream>
#include <iomanip> //setfill() setw()
using namespace std;

/* 
Draws a line to the terminal
Input: number of lines
Output: line of length 40 on terminal
Return: None
*/

void draw_line(int number, int length, char line_character); // function protype
// tells compiler that function exists

/* */ /* 
Draws 2 lines to the terminal
Input: None
Output: 2 lines of length 40 on terminal
Return: None
*/
void draw_2lines(); // Function prototype
int main(){
    draw_line(1,20,'='); // function call with an input
    cout << "My cool program \n";
    draw_line(2,15,'+'); // funciton call
    cout << "Now draw three lines\n";
    draw_line(3,45, '*');

}

//Function defintion
//  what does this function do??
void draw_line(int number, int length, char line_character){
    for(int n=1; n <= number; n++){
        for(int i = 0; i < length; i++){
        cout << line_character;
        }
        cout << endl;
    }
    

}