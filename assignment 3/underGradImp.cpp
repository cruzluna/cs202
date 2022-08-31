/*
    Name: Cruz Luna, 2001582775, 1001, Assignment #3
    Description: tracks information for students, both 
    Input: none
    Output: information from student and child classes
*/
#include <iostream>
#include <iomanip>

#include "underGrad.h"
#include "student.h"
#include "money.h"

using namespace std;

underGrad::underGrad(string lastName, string firstName, 
string studentID, string major,double gpa, double ch, double fn, string advisor, sStat sStatus ):
student( lastName,  firstName,  studentID,  major, gpa,  ch, fn)
{   //initialize advisor and sStatus
    this->advisor=advisor;
    this->sStatus=sStatus;
}

/*
* getAdvisor: gets the advisor .
* parameters: n/a
* return value: string advisor
*/
string underGrad::getAdvisor() const{return advisor;}

/*
* getStatus: gets and returns the status of the student.
* parameters: n/a
* return value: returns sStatus
*/
sStat underGrad::getStatus() const{return sStatus;}

/*
* setAdvisor: set the advisor of the student.
* parameters: string advisor
* return value: none
*/

void underGrad::setAdvisor(string advisor_)
{
    advisor = advisor_;
}

/*
* setStatus: sets the status of the student.
* parameters: sStat sStatus
* return value: what the function returns, if any
*/
void underGrad::setStatus(sStat sStatus_)
{
    sStatus = sStatus_;
}

/*
* showStudent: display student summary using the base class function.
* parameters: none
* return value: none
*/
void underGrad::showStudent()
{
    //uses base class function
    student::showStudent();
    //need it because it cant call itself
    //no base case to stop itself therefore it crashes
    
    //student status
    if(sStatus == NONE)
    {
        if(getGPA() <= 1.7)
        {
            sStatus = PROBATION;
        
        }else{
            sStatus = GOOD;
        }
    }
    
    
    string indent(5, ' ');
    cout << indent << "Advisor: " << left << setw(17) << advisor;
    cout << indent << " Status: " ;
    //switch
    switch(sStatus){
        case 0:
            cout << "PROBATION" << endl;
            break;

        case 1:
            cout << "GOOD"<< endl;
            break;
        case 2:
            cout << "SPECIAL"<< endl;
            break;
        case 3: 
            cout << "NONE"<< endl;
            break;
        default:
            break;
    }
}