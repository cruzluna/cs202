// Library functions to calculate and print
// The result of e^(i*theta) from a command line argument
//Theta is from user
//e(i^theta) = cos(theta)+i*sin(theta)
#include <iostream>
#include <cmath>
using namespace std;
/*int main(int argc, char** argv){
    cout<<"argc = "<< argc << endl;
    cout<<"argv[0] = "<<argv[0]<<endl;
    cout<< "argv[1] = " << argv[1] << endl;

}*/

int main(int argc, char** argv){
    
    float theta;

    cout << "Enter a theta" << endl;
    cin >> theta; 
    
    cout<<cos(theta)<<" + i" << sin(theta) << endl;

}
