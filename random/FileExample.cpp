// This program shows an example of how to read files, error check the input, and 
// output text to a file. This example is specifically for the input_example.txt
// file on Canvas and demonstrates how to open files we know the structure of.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Usage of program:
// ./a.out <filename>

//Example:
// ./a.out example_input.txt
int main(int argc, char** argv)
{
    //Make sure the user is using our program correctly
    if (argc != 2)
    {
        cout << "Incorrect usage. Program is used like ./a.out <filename>" << endl;
        return 1;
    }

    //Open a file using ifstream.
    string filename = argv[1];
    ifstream infile;
    infile.open(filename); //Open the file with the given filename

    //Variable declarations
    string name, address;
    string throwAway;
    int age;

    //Read in the info from out file
    getline(infile, name); //Gets the first line of infile  and stores in name
    infile >> age; //Read in the age
    getline(infile, throwAway); //Linefeed after age, which we don't need, so put it in garbage
    getline(infile, address); //Last, read the address

    infile.close(); //Close the file when we're done with it

    //Write the results to an output file called "example_output"
    ofstream outfile;
    outfile.open("example_output"); //If file doesn't exist, system will create it

    outfile << "Name: " << name << endl;
    outfile << "Age: " << age << endl;
    outfile << "Address: " << address << endl;

    outfile.close(); //Close the output file

    return 0;
}