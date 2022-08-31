/*
    Name: Cruz Luna, 2001582775, 1001, Assignment #3
    Description: tracks information for students, both 
    Input: none
    Output: information from student and child classes
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "money.h"
#include <string>
#include <iostream> //cout
#include <fstream>

using namespace std;

/*
* student: 
    track student information and 
    provide standard support functions for all students. 
* constructors: 
    student()
* public functions: 
    string getLastName() const;
    string getFirstName() const;
    string getID() const;
    string getMajor() const;
    double getGPA() const;
    void setName(string,string);
    void setID(string);
    void setMajor(string);
    void setGPA(double);
    void showStudent();
    double getBalance() const;
    void getCharges(double &, double &) const;
    void setCharges(double,double);
* static members: 
    static constexpr int MAX_MAJORS = 250;
    static constexpr double MAX_GPA = 4.0;
* variables and function prototypes
    string lastName;
    string firstName;
    string studentID;
    string major;
    double gpa;
    money finances;//composition
    ifstream majorsFile; 
    int majorCodesCount;
    string majorCodes[MAX_MAJORS];
*/
class student{
    //private by default
    string lastName;
    string firstName;
    string studentID;
    string major;
    double gpa;
    
    money finances;//composition
    
    ifstream majorsFile; 
    int majorCodesCount;
    static constexpr int MAX_MAJORS = 250;

    string majorCodes[MAX_MAJORS];
    
    static constexpr double MAX_GPA = 4.0;

    //private functions
    bool checkID(string) const;
    string expandMajorCode(string);
    
    


public:
    //----Constructors-----
    student(string="",string="", string="",string="",double=0.0, double=0.0, double=0.0);
    //----Destructor----
    ~student()
    {   ifstream infile;
        infile.close();//close file
    }
    //----Get----
    string getLastName() const;
    string getFirstName() const;
    string getID() const;
    string getMajor() const;
    double getGPA() const;
    //----Set----
    void setName(string,string);
    void setID(string);
    void setMajor(string);
    void setGPA(double);
    
    void showStudent();
    

    double getBalance() const;
    void getCharges(double &, double &) const;
    void setCharges(double,double);


    
    




};


#endif