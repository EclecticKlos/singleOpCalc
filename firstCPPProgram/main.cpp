//
//  main.cpp
//  firstCPPProgram
//
//  Created by Dan Klos on 6/1/16.
//  Copyright © 2016 Dan Klos. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stdio.h>


using namespace std;

bool isOperator(char x)
{
    if(strncmp( &x, "*",1) == 0 || strncmp( &x, "/",1) == 0 || strncmp( &x, "+",1) == 0 || strncmp( &x, "-",1) == 0){
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    
    
//////////////////////// NOTES ////////////////////////

//  Likely would be best to read directly from the stream and determine each character as either
//  string or num?

//  Should break each algorithm manipulation into separate function
    
//  Learn what "&" is actually doing
    
///////////////////////////////////////////////////////
    vector<string> numsInAlgo;
    vector<char> tempWorkingAlgo;
    
    cout << "Let's do some math! Tell me what you want to do without spaces. \n";
    string userInput = "";
    getline(cin, userInput);
    vector<char> usersAlgorithm;
    for(int i=0; i<userInput.length(); i++){
        if(isdigit(userInput[i])){
            
        }
        usersAlgorithm.push_back(userInput[i]);
    }
    
    // Must have two seperate data structures, one for nums one for operators
    
 
    
    
}
