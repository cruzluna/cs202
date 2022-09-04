//Prime Printer
//Given a number n, print all primes <= n
/* PrimePrinter.cpp : In this example, we will read in an integer from the user, 
n,and then print all prime numbers from 2 to n. We will use this to practice loops/iterationThis will 
use the naive approach, so we will go through all numbers from 2 to n, and thencheck if the number is prime.
Consider that a prime is any number that has no divisors besides itself and 1. So, one way wecan do this is 
to do the opposite, and NOT print any numbers that are NOT prime.That is, if a number has at least one 
non-trivial divisor, then it must be NOT prime.This is easier to do because finiding a single counter example 
is easier than checking all numbers.As a side note, this can be slightly optimized by only checking up to the 
square root of a numberfor divisors, since the smallest divisor is always <= the square root. 
We won't do it thisway for the sake of keeping things simple.*/
// ex n==13..2,3,5,7,11,13
#include <iostream> 
using namespace std;

int main(){

    int n;
    cout << "Please enter a number: " << endl;
    cin >> n;

    cout << "Primes from 2 to " << n << endl;

    bool isPrime; // check if number is prime

    //Print the Primes
    for(int i = 2; i <= n; i++)// counts from 2 to n
    {
        isPrime = true; //set number to prime until we prove otherwise (find counterexample)

        //Check if i is a prime number
        for(int j = 2; j < i; j++) // counts from 2 to i - 1
        {
            // Check if i is a prime number
            if ( i % j == 0)
            {
                isPrime = false; // counter example
             // If i has a divisior, it is nor prime
                break; // break out of loop and goes to the end
            }
            else
                continue; //skip back to the top of the loop
        }

        //by the end of this loop, we know if i is prime; by this line of code should know if i is prime

        if(isPrime){

         //same as if(isPrime == true); because it is a boolean it automatically treats as true false
            cout <<  i << ", " ;
        }    
    } 
    cout << endl;


}