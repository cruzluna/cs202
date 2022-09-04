/*
* Name: Cruz Luna, 2001582775, #6
* Description: use input and output to encrypt and decrypt text files
* Input: input 0 for decryption and 1 for encryption 
* Output:  decryption to output.txt or encryption to output2.txt
*/


/* 
* main: either encrypts or decrypts from text file
* parameters: input 0 for decryption and 1 for encryption 
* return value:  decryption to output.txt or encryption to output2.txt  
*/
/* 
* generateRandomString:generates random string
* 
* return value:  random string
*/


#include <iostream>
#include <string> 
#include <time.h> //For time RNG
#include <fstream> // file stream 
#include <stdlib.h> // atoi
using namespace std;

const int defaultMin = 4; //Default min length of random string
const int defaultMax = 16; //Default max length of random string
const int lowerOffset = 'a' - 'A'; //Distance between capital and lowercase letters
string generateRandomString(int min_length = defaultMin, int max_length = defaultMax);

int main(int argc, char** argv)
{
	srand(time(NULL));
	//cout << generateRandomString() << endl; //Example of how to get random string
	
	//******************* YOUR CODE HERE *******************
	
	cout << "FileStream Assignment 6" << endl;
	 if(argc != 2)// handles incorrect argument count
    {
        cout << "Incorrect usage. Program is used like ./a.out <filename>"<< endl;
        return 1; // error code
    }
	if( atoi(argv[1])== 0){
		
		// open file using filestreams
		ifstream infile;
		infile.open("input.txt"); // open input.txt
		ofstream outfile;
		outfile.open("output.txt");
		// variable declarations
		string testStr, throwaway;
		
		// read in file
		
		//infile >> testStr; // should read file up until space
		//cout <<"your test string is " << testStr << endl;

		// check when word is jarjar

		int i = 0;
		
		infile >> testStr;

		while(!infile.eof())
		{	
			i++;
			
			//cout << i << endl;
			
			//testStr.compare()
			if(testStr == "jarjar"){
				//decl var
				string var;
				infile>> var;
				cout << "" << var << " ";
				
			
				outfile  << "" << var << " " ; 
				
			} 
			infile >> testStr;
			
			// close file
			
		}
		infile.close();
		outfile.close();


	
	} else if( atoi(argv[1]) == 1)// ./a.out 1 encrypting message
	{	// open file using filestreams
		ifstream infile;
		infile.open("input2.txt"); // open input.txt
		ofstream outfile;
		outfile.open("output2.txt");
		// variable declarations
		string testStr;
		
		int i = 0;
		
		infile >> testStr;

		while(!infile.eof())// runs until end of file
		{	
			i++;
			
			//cout << i << endl;
			
			//testStr.compare()
			if(!testStr.empty())// runs when the testStr is not empty
			{
				//declare variable 
				string var;
				infile>> var;
				cout << "" << var << " ";// verify it works
				
			
				outfile  << generateRandomString() <<"jarajar" << var << generateRandomString(); //encrypts  
				
			} 
			infile >> testStr; // necessary to ensure no runtime error
			
			
			
		}
		// close files
		infile.close();
		outfile.close();


	}else
	{	
		cout << "Invalid Argument Given. Use ./a.out 0 or ./a.out 1"<< endl;// display message for error
		return 1; // error code
	}
	

}

//Generates a random string between the min and max length given. String will contain only
//alphabetic characters
string generateRandomString(int min_length, int max_length)
{
	//Start by generating how long the string will be
	int strLength = rand() % (max_length - min_length) + min_length;

	//Now, go and generate length many random characters
	/* On each iteration, this will randomly generate a letter from 'A' to 'Z', and then randomly
	* decide whether each should be a capital or a lowercase letter
	*/
	string retString = "";
	for (int i = 0; i < strLength; i++)
		retString += (rand() % 26) + 'A' + (rand() % 2 == 0 ? 0 : lowerOffset);

	return retString;
}