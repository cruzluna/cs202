/*
    Name: Cruz Luna, 2001582775, 1001, Assignment #3
    Description: tracks information for students, both 
    Input: none
    Output: information from student and child classes
*/

#include <iostream>
#include <iomanip> 

#include "student.h"
#include "underGrad.h"
#include "grad.h"
#include "money.h"



using namespace std;

grad::grad(string lastName, string firstName, 
string studentID, string major,double gpa, double ch, double fn, string advisor,
sStat sStatus, bool isGA, double gradFees):
underGrad(lastName,  firstName,  studentID,  major, gpa,  ch, fn,advisor,sStatus)
{
    //grad constructor
    this->isGA=isGA;
    this->gradFees=gradFees;

}
/*
* getGAstatus: returns the graduate assistance flag.
* parameters: none
* return value: bool isGA
*/
bool grad::getGAstatus() const{return isGA;}

/*
* getGradFees: returns the graduate student fees.
* parameters: none
* return value: double gradFees
*/
double grad::getGradFees() const{return gradFees;}

/*
* setGAstatus: sets the graduate student status.
* parameters: bool isGA
* return value: none
*/
void grad::setGAstatus(bool isGA_)
{
    isGA = isGA_;
}

/*
* setGradFees: sets the graduate student fees to the pass parameter.
* parameters: double gradFees
* return value: none
*/
void grad::setGradFees(double gradFees_)
{
    if(gradFees_ >= 0.0 && gradFees_<= MAX_FEES){
        gradFees = gradFees_;
    }else{
        cout << "Error, invalid graduate fees.";
        gradFees = 0.0;
    }
    
}

/*
* showStudent: display a student using the base class function.
* parameters: none
* return value: none
*/
void grad::showStudent()
{   
    //base class function
    underGrad::showStudent();

    //additional functionality 
    string indent(5, ' ');
    cout << "   Grad Fees: " << fixed << setprecision(2) << gradFees << indent;
    cout << indent << indent << "    Graduate Assistant: ";
    //Ga status
    if(isGA)
    {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}