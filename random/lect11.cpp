/* how to use iterations (FOR, WHILE loops
    takes in a single user input, n, and calculates the sum of numbers from 0 to n
    ex: n= 4 ... answer= 0+1+2+3+4=10*/

#include <iostream>
using namespace std;


int main(){
    
    int n;
    cout << "enter a number: " << endl;
    cin >> n;

    int sum = 0;
    int i = 0;
    
    while(i <= n){
    
    cout << i << endl;
    sum += i; // equiv to sum = sum + i; short form 
   
    //++i; Pre increment operator 
    // i--; Goes down by 1
   //These 3 lines of code all count by 1
    i++; // increment operator, same as i+=1 or i = i +1
    // i +=1
    // i = i +1

    }
    
    cout << "The sum is = " << sum << endl;

}

// for (statement 1; statement 2; statement 3)
// statement 1-- executed one time before the execution of the code block; optional variable declaration
// statement 2-- defines the condition for executing the code block; condition to check
// statement 3-- executed EVERY time after the code block has been executed

cout << "\n\nStarting FOR Loop "<< endl; 
sum = 0;
for(int j = 0; j <= n; j++ )
{
    cout << j << endl;
    sum += j ;

} 
    cout << "The sum is = " << sum << endl;
////////////////////////////////////////////////////////////
do 
{
    // runs once at minimum before checking condition
}while( i <= n ;)

int sumAlt = (n*(n+1))/2; //adds up to one