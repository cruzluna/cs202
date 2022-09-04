/* command line arguments from the user. 
Two command line args , both ints, and then print the sum and product of those two #s*/

#include <iostream>
#include <cstdlib> //includes atoi

using namespace std;

int main(int argc, char ** argv){
    
    cout << "The argument count is: " << argc; //

    string firstNumberStr = argv[1]; // Index 1
    string secondNumberStr = argv[2];// index 2 (0 1 2 3 .... n+1)

    // convert string to int
    int firstNumber = atoi(argv[1]); // string to an integer with atoi--> array to int?
    int secondNumber = atoi(argv[2]);

    cout << firstNumber << " + " << secondNumber << " = " << firstNumber + secondNumber << endl;
    cout << firstNumber << " * " << secondNumber << " = " << firstNumber * secondNumber << endl;
}