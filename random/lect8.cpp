// StringExample.cpp : This file contians the 'main' function. Program...
#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    str = "Hello World!!!"; // use this method to modify it before we print it

    string str2 = " is the printed string";
    //adding two strings
    // concatenation
    std::cout << str + str2 <<endl; // concatenate these two strings

    char c = 'D';//ASCII D= 68 (decimal)

    cout << str[1] << endl; // accessing character in string


}