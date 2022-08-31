/*
    Name: Cruz Luna, 2001582775, 1001, Assignment #3
    Description: tracks information for students, both 
    Input: none
    Output: information from student and child classes
*/

#ifndef GRAD_H
#define GRAD_H

#include "student.h"
#include "underGrad.h"
#include <string>
using namespace std;

/*
* grad: provide the same basic capabilities
     of underGrad with extra functionality
    with tracking graduate fees & graduate 
    assistantship status
* constructors: 
    grad(string ="",string ="", string ="",
    string ="",double =0.0, 
    double =0.0, double =0.0,string ="", 
    sStat=NONE, bool=false, double=0.0)
* public functions: 
    bool getGAstatus() const;
    double getGradFees() const;
    void setGAstatus(bool);
    void setGradFees(double);
    void showStudent();
* static members: static constexpr double MAX_FEES = 5000.0
* (variables and function prototypes)
    bool isGA;
    double gradFees
*/
class grad: public underGrad{

    //private by default
    bool isGA;
    double gradFees;
    static constexpr double MAX_FEES = 5000.0;

public:
    //----Constructor----
    grad(string ="",string ="", string ="",
    string ="",double =0.0, double =0.0, 
    double =0.0,string ="", sStat=NONE, 
    bool=false, double=0.0);

    bool getGAstatus() const;
    double getGradFees() const;
    void setGAstatus(bool);
    void setGradFees(double);
    void showStudent();
};

#endif
