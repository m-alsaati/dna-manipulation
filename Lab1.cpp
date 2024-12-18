/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lab1.cpp
 * Author: Molham Alsaati
 *
 *
 */

#include "Lab1.h"

//implement the function enterDNAString
string enterDNAString(){
    string userStr; //variable to store user's input
    cout << "Enter your DNA string: " << endl;
    cin >> userStr;
    return userStr;
}

//implement the function checkValidity
bool checkValidity(string s){
    int i;  //counter variable for loop
    int strLen; //holds length of user's input
    bool validity;  //keeps track of whether use input is valid DNA string
    strLen = s.size();
    
    validity = true;
    for (i = 0; i < strLen; i++){
        //check every character to see if they are valid DNA letter
        if (s.at(i) == 'A' || s.at(i) == 'a'){
            continue;
        }
        else if(s.at(i) == 'C' || s.at(i) == 'c'){
            continue;
        }
        else if(s.at(i) == 'G' || s.at(i) == 'g'){
            continue;
        }
        else if(s.at(i) == 'T' || s.at(i) == 't'){
            continue;
        }
        else{
            validity = false;
            break;
        }
    }
    return validity;
}

//implement the function compliment
void compliment(string s){
    int lenStr; //holds length of user input string
    int i;  //counter variable for loop
    
    lenStr = s.size();
    
    cout << " : compliment(";
    for (i = 0; i < lenStr; i++){
        //check every character, then print out appropriate complement
        if (s.at(i) == 'A'){
            cout << "T";
        }
        else if (s.at(i) == 'T'){
            cout << "A";
        }
        else if (s.at(i) == 'G'){
            cout << "C";
        }
        else if (s.at(i) == 'C'){
            cout << "G";
        }
        else if (s.at(i) == 'a'){
            cout << "t";
        }
        else if (s.at(i) == 't'){
            cout << "a";
        }
        else if (s.at(i) == 'c'){
            cout << "g";
        }
        else if (s.at(i) == 'g'){
            cout << "c";
        }
    }
    cout << ")" << endl;
}

int main() {
    while(true) {
        cout << "Please choose an option:" << endl;
        cout << "1. Enter DNA string, echo it" << endl;
        cout << "2. Enter DNA string, echo it, validate it" << endl;
        cout << "3. Enter DNA string, echo it, validate it, compliment it if valid"<< endl;
        cout << "4. Exit" << endl;
        
        int option;
        cout << ">> ";
        
        cin >> option;
        
        //Following "if" statement is to avoid problem with cin
        //if a non-numeric character is read by cin when
        //it is actually supposed to read an integer.
        if ( !cin )  {
            cin.clear();
            cin.ignore( INT_MAX, '\n' );
            cout << "Non-numeric option! Try again." << endl;
            continue;
        }
        if (1 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            cout << endl;
        }
        else if (2 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            bool b = checkValidity(str1);
            if(b == true){
                cout << " : VALID DNA";
            }
            else{
                cout << " : INVALID DNA";
            }
            cout << endl;
        }
        else if (3 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            bool b = checkValidity(str1);
            if(b == true){
                cout << " : VALID DNA";
                compliment(str1);
            }
            else {
                cout << " : INVALID DNA";
            }
            cout << endl;
        }
        else if (4 == option) {
            return 0;
        }
        else {
            cout << "Integer option, but incorrect! Try again." << endl;
        }
    }
    return 0;
} //end of main