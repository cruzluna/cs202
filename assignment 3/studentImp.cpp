/*
    Name: Cruz Luna, 2001582775, 1001, Assignment #4
    Description: tracks information for students, both 
    Input: none
    Output: information of students
*/

#include <iostream> 
#include <string>
#include <iomanip> //setprecision

#include "student.h"
#include "money.h"


using namespace std;

student::student(string lastName, string firstName, 
string studentID, string major,double gpa, 
double ch, double fn)
{   
        //setting class variables
        this->lastName = lastName;
        this->firstName = firstName;
        
        //Call the money constructor function with charges & finaid values
        
        finances = money(ch,fn);

        //student major code error checking
        if(!checkID(studentID)){
            this->studentID="";
            cout<<"Error, invalid student ID." << endl;
        }else{
            setID(studentID);
        }
        
        if(!(gpa>= 0.0 && gpa <= MAX_GPA))
        {
            cout << "Error, invalid GPA." << endl;
            this->gpa = 0.0;
        }else{
            setGPA(gpa);
            
        }
        
    
        //open majors file
        ifstream infile; 
        infile.open("majorsList.txt");
        
        //read majors list into majorCodes[]
        majorCodesCount=0;
        while(getline(infile,majorCodes[majorCodesCount]))
        {   if(infile.eof())
            {// fixes extra line
            break;
            }
            
            majorCodesCount++;//count
            
        }
        
        setMajor(major);
    }


//Student function definitions

/*
* getLastName: gets the last name of student.
* parameters: n/a
* return value: returns string lastName of student
*/
string student::getLastName() const {return lastName;}

/*
* getFirstName: gets the first name of student.
* parameters: n/a
* return value: return string firstName of student
*/
string student::getFirstName() const {return firstName;}

/*
* getID: gets the student ID.
* parameters: n/a
* return value: return string studentID of student
*/
string student::getID() const {return studentID;}

/*
* getMajor: gets the major of student.
* parameters: n/a
* return value: returns string major
*/
string student::getMajor() const {return major;}

/*
* getGPA: gets the gpa of student.
* parameters: n/a
* return value: return double gpa
*/
double student::getGPA() const {return gpa; }

/*
* checkID: checks the format of studentID.
* parameters: string studentID
* return value: return boolean 
*/
bool student::checkID(string studentID) const
{  
    //cout << "sanity check " << studentID << endl;
    if(studentID.empty()){
        
        return false;
    }
    //cout << "length: " << studentID.length() << endl;
    if(studentID.length() != 10)
    {   //string must equal 10 char
        return false;
    }

    //first character in string == "" 
    ///&& length of string = 10 
    //&& no alpha in digit
    if(studentID[0]=='L')
    {   
        for(int i = 1; i <= 9 ; i++)
        {   
            if(isalpha(studentID[i])) //checks if last nine char are integers
            {
                return false;
            }

            
        }
        return true;
    }
    
    return false;
}

/*
* expandMajorCode:expands major code into full string from txt file .
* parameters: string majorSearch
* return value: string major 
*/
string student::expandMajorCode(string majorSearch)
{   
    //from code to full name
    //takes in 2-4 character string 
    //ex:NUE
    //return: NUE- Nuclear engineering
    if(majorSearch.empty())
    {
        return "Error";
    }
    if(majorSearch.length() <= 4)
    {
        for(int i =0; i < majorCodesCount; i++)
        {   
            if(majorCodes[i].find(majorSearch) == 0 )
            {    
            
            return majorCodes[i];
            
            }

        }  

    }

    
    return "Error" ; 
}

/*
* setName: sets the first name and last name of student.
* parameters: string lastName, string firstName
* return value: none
*/
void student::setName(string lastName_,string firstName_)
{
   lastName = lastName_;
   firstName = firstName_;
   
}

/*
* setID: set student ID.
* parameters: string studentID
* return value: 
*/
void student::setID(string studentID_)
{   
    if(!checkID(studentID_))
    {   
        //cout << "ID:" << studentID_ << "Name: "<< firstName << endl;
        cout << "Error, invalid student ID." << endl;
        studentID = "";
    }else{
        studentID = studentID_;
    }
    
    
}

/*
* setMajor: set the student major.
* parameters: string major
* return value: 
*/
void student::setMajor(string major_)
{   
    major = expandMajorCode(major_);
    //cout << "major : " << major << endl;
    if (major == "Error")
    {   
        //leave as error
        cout << "Error, invalid student major." << endl;
    }
}

/*
* setGPA: set the student GPA.
* parameters: double gpa
* return value: 
*/
void student::setGPA(double gpa_)
{
    if(!(gpa_>= 0.0 && gpa_ <= MAX_GPA))
    {
        cout << "Error, invalid GPA." << endl;
        //gpa = 0.0;
    }else{
        gpa = gpa_;
    }
   
}

/*
* showStudent: display a student summary .
* parameters: 
* return value: 
*/
void student::showStudent()
{   
    double ch,fn;
    finances.getCharges(ch,fn);

    string indent(5, ' ');
    string bars;
    bars.append(70, '-');
    cout << endl << bars << endl;
    cout << "Student Summary" << endl;
    cout << indent << "   Name: " << lastName << ", " <<firstName << endl;
    cout << indent << "     ID: " << studentID << endl;
    cout << indent << "  Major: " << major << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << indent << "    GPA: " << setw(8) << gpa << endl;
    cout << indent << "Charges: " << setw(8) << ch << indent << indent << indent << "Financial Aid: "<< setw(8) << fn << endl;
    cout << indent << "Balance: " << setw(8) << finances.getBalance() << endl;

}

/*
* setCharges: sets the student charges with the composition.
* parameters: double charges, double financialAid
* return value: 
*/
void student::setCharges(double ch,double fn)
{   //calling money 
    finances.setCharges(ch,fn);
    
}

/*
* getCharges: gets charges with composition.
* parameters: double charges, double financial aid; pass by reference
* return value: 
*/
void student::getCharges(double &ch, double &fn) const
{
    finances.getCharges(ch,fn);

}

/*
* getBalance: gets balance with composition.
* parameters: n/a
* return value: balance
*/
double student::getBalance() const{return finances.getBalance();}