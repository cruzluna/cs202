/*
* Name: Cruz Luna, 2001582775, #2
* Description:outputs excerpt from the Constitution and the Bill of Rights
* Input: beta (degrees) and slant distance (feet)
* Output: Radius in feet
*/

#include <iostream>  // existing iostream
#include <cmath>    // gives the program access to sin(), sqrt(), pow()
                    // will use sin() in this program
using namespace std;

const float PI = 3.14159; //Global constant

/*
* main(): calculates the radius of a sandworm 
* parameters: angle of the slant (beta) slant distance (slant_ft) 
* return value: radius in feet
*/


int main(int argc, char** argv){

    double alpha, radius, chordlenghth, beta; //declare variables
    int   slant_ft; //declares slant distance

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"; // print for terminal formatting
    cout << "Program to calculate a sandworm radius\n"; // print program purpose
    
    cout << "Enter beta in degrees:"; // retrieve slant angle
    cin >> beta; // user input beta (slant angle)
    
    cout << "Enter the slant distance(feet): "; // retrieve slant distance 
    cin >> slant_ft; // user input slant distance
    
    alpha = 90-(.5*beta); // angle needed for chord length calc(degrees)
    chordlenghth = slant_ft*((sin(beta*PI/180))/(sin(alpha*PI/180))); // calcualtes the chord length (radians)

    radius = chordlenghth*(sin((PI/2)-(alpha*PI/180)))/(sin((alpha*PI/180)*2));

    cout << ">>>>>>>>>>>>>>>>>>>>>\n"; // terminal formatting
    cout << "Sandworm calculations\n"; // describes output
    cout << "Beta: "<< beta << " degrees\n"; // outputs slant angle given by user (degrees)
    cout << "Slant distance: " << slant_ft << " feet\n"; //outputs slant distance given by user (feet)
    cout << "Radius: " << radius << " feet\n";   // Radius calculation (feet)
    return 0;

}
