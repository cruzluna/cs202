#include <iostream> 
using namespace std;

int main(){
    
    bool flagT = true;
    bool flagF = false; 

    
    cout << "True OR False = " << (flagT || flagF) << endl;
    cout << "True AND False = " << (flagT && flagF) << endl;


    // Simulate EXOR
    /* It can only be true if one is true, but both cannot be true. If both false, its false...
    Either A is true, or b is true, but NOT Both
    */ 
   // F+F = F, F+T= T; T+F= T;T+T=F
   // !a&&b
    bool A = true;
    bool B  = false;
    
    cout << ((!A&&B) || (A&&!B)) << endl;
    
    /*  == --> comparison operator */

    // Check if a number is in the range (2,7] 

    double n = 10.4;

    cout << endl << "Is " <<  n << " in (2,7]? " << ((n > 2) && (n<=7))<< endl;
    return 0;
}