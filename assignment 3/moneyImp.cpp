/*
    Name: Cruz Luna, 2001582775, 1001, Assignment #3
    Description: tracks information for students, both 
    Input: none
    Output: information from student and child classes
*/


#include <iostream>
#include <string> 
#include "money.h"

using namespace std;

money::money(double charges,double financialAid)
{   
    
    //Error checking
    setCharges(charges,financialAid);

    //Balance class variable initialization
    balance = charges - financialAid;
    
}

//Money function definitions

/*
* getCharges: get charges and pass by reference.
* parameters: double charges, double financial aid
* return value: n/a
*/
void money::getCharges(double &charges_, double &financialAid_) const
{
    //return student charges
    charges_ = charges;
    //return financial aid
    financialAid_ = financialAid;
    
}

/*
* getBalance: get balance of student.
* parameters: 
* return value: return balance
*/
double money::getBalance() const {return balance;}

/*
* setCharges: sets charges of student.
* parameters: double charges, double financialaid
* return value: none
*/
void money::setCharges(double charges_,double financialAid_)
{   
    //Error checking
    if(charges_ <= MAX_CHARGES && charges_ >= 0.0)
    {   //valid case
        //set charges variable  
        charges = charges_;
        

    }else{
        //invalid case
        cout << "Error, invalid charges amount." << endl;
        charges = 0.0;
        return;//does not print finaid if charges are invalid
    }
    
    if(financialAid_ <= charges_ && financialAid_ >= 0.0)
    {   //set financialAid variable
        financialAid = financialAid_;
    }else{
        //invalid case
        cout << "Error, invalid financial aid amount." << endl;
        financialAid = 0.0;
        
    }
    
    balance = charges - financialAid;

}