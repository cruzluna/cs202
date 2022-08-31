/*
    Name: Cruz Luna, 2001582775, 1001, Assignment #3
    Description: tracks information for students, both 
    Input:none 
    Output: information from student and child classes
*/

//Child class to student class
#ifndef UNDERGRAD_H
#define UNDERGRAD_H

#include "student.h"

#include <string> 

using namespace std;


/*
* underGrad: derived class of student with tracking adviser & student state 
* constructors: 
    underGrad(string ="",string ="", 
    string ="",string ="",
    double =0.0, double =0.0, double =0.0,
    string ="", sStat=NONE)
* public functions: 
    string getAdvisor() const;
    sStat getStatus() const;
    void setAdvisor(string);
    void setStatus(sStat);
    void showStudent();
* static members: none
* (variables and function prototypes)
string advisor;
    sStat sStatus;
*/
enum sStat{PROBATION, GOOD, SPECIAL, NONE};
class underGrad: public student{

    //private by default
    string advisor;
    sStat sStatus;
public: 
    //----Constructor----
    underGrad(string ="",string ="",
     string ="",string ="",double =0.0, 
     double =0.0, double =0.0,
     string ="", sStat=NONE);

    string getAdvisor() const;
    sStat getStatus() const;
    void setAdvisor(string);
    void setStatus(sStat);
    void showStudent();

};

#endif