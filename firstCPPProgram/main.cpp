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
#include <sstream>
#include <stdlib.h>


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

map<int,int> updateMap(map<int,int> workingMap){
    
    
    return workingMap;
}

int main()
{
    cout << "Let's do some math! Tell me what you want to do without spaces. \n";
    string userInput = "";
    getline(cin, userInput);
    vector<char> workingAlgo;
    map<int,int> numbersAndLocations;
    for(int i=0; i<userInput.length(); i++){
        if(isdigit(userInput[i]) != 0){
            numbersAndLocations[i] = atoi(&userInput.at(i));
        }
        workingAlgo.push_back(userInput[i]);
    }
    
    for(int i=0; i<workingAlgo.size(); i++){
        if(isOperator(workingAlgo[i]) != 0){
            if (workingAlgo[i] == '*') {
                int num1 = numbersAndLocations.find(i-1)->second;
                int num2 = numbersAndLocations.find(i+1)->second;
                int product = num1 * num2;
                
                if(product >= 0){
                    workingAlgo.at(i+1) = product;
                    cout << "algo " << workingAlgo.at(i+1);
                    workingAlgo.erase(workingAlgo.begin()+(i-1), workingAlgo.begin()+(i+1));
                }
                else {
                    workingAlgo.push_back('-');
                    workingAlgo.push_back(product);
                    workingAlgo.erase(workingAlgo.begin()+(i-1), workingAlgo.begin()+(i+2));
                }
            }
        }
    }
    cout << workingAlgo.at(0);
}

//////////////////////// NOTES ////////////////////////

//  Likely would be best to read directly from the stream and determine each character as either
//  string or num?

//  Should break each algorithm manipulation into separate function

//  Learn what "&" is actually doing
//  Learn diff between " and '

///////////////////////////////////////////////////////
