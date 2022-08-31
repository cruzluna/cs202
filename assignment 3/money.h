/*
    Name: Cruz Luna, 2001582775, 1001, Assignment #3
    Description: tracks information for students, both 
    Input: none
    Output: information from student and child classes
*/

#ifndef MONEY_H
#define MONEY_H

#include <string> 


using namespace std;

/*
* money: brief description of the classcontains the student financial data & functions
* constructors: 
    money::money(double charges,double financialAid)
* public functions: 
    void getCharges(double &, double &) const;
    double getBalance() const;
    void setCharges(double,double);
* static members: 
    static constexpr double MAX_CHARGES = 10000.0;
* (variables and function prototypes)
    double charges;
    double financialAid;
    double balance;
*/
class money{
    //private by default
    double charges;
    double financialAid;
    double balance;
    static constexpr double MAX_CHARGES = 10000.0;

public:

//----Get----
void getCharges(double &, double &) const;
double getBalance() const;
//----Set----
void setCharges(double,double);
//----Constructor----
money(double=0.0,double=0.0);//set default in header file


};
#endif