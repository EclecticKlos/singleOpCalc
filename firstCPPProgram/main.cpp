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
    if(strncmp( &x, "*",1) == 0 || strncmp( &x, "/",1) == 0 || strncmp( &x, "+",1) == 0 || strncmp( &x, "-",1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

map<int,string> updateNumbersAndTheirLocations(vector<char> workingAlgo)
{
    map<int,string> workingNumsandLocations;
    
    for(int i=0; i<workingAlgo.size(); i++)
    {
        string thisNum = "";
        while(isdigit(workingAlgo[i]) != 0)
        {
            thisNum.push_back(workingAlgo[i]);
            i++;
        }
        if (thisNum != ""){
            workingNumsandLocations[i] = thisNum;
        }
    }
    
    for(auto elem : workingNumsandLocations)
    {
        cout << "elem: " << elem.first << " " << elem.second << "\n";
    }
    return workingNumsandLocations;
}

int main()
{
    cout << "Let's do some math! Tell me what you want to do without spaces. \n";
    string userInput = "";
    getline(cin, userInput);
    vector<char> workingAlgo;
    map<int,string> numbersAndTheirLocations;
    for(int i=0; i<userInput.length(); i++)
    {
        string thisNum = "";
        int tensPlaceLocation = i;
        while(isdigit(userInput[i]) != 0)
        {
            workingAlgo.push_back(userInput[i]);
            thisNum.push_back(userInput[i]);
            i++;
        }
        if (thisNum != ""){
            numbersAndTheirLocations[tensPlaceLocation] = thisNum;
        }
        else {
            workingAlgo.push_back(userInput[i]);
        }
    }
    
    for(int i=0; i<userInput.length(); i++){
        workingAlgo.push_back(userInput[i]);
    }
    
    for(int i=0; i<workingAlgo.size(); i++)
    {
        if(isOperator(workingAlgo[i]) != 0)
        {
            if (workingAlgo[i] == '*')
            {
                cout << "num1: " << numbersAndTheirLocations[i-1] << "\n";
                cout << "num2: " << numbersAndTheirLocations[i+1] << "\n";
//                cout << "num1: " << numbersAndTheirLocations.find(i-1)->second << "\n";
//                cout << "num2: " << numbersAndTheirLocations.find(i+1)->second << "\n";
                int num1 = stoi(numbersAndTheirLocations.find(i-1)->second);
                int num2 = stoi(numbersAndTheirLocations.find(i+1)->second);
                int product = num1 * num2;
                cout << "prod: " << product << "\n";
                
                if(product >= 0)
                {
                    cout << "before elem reassign: " << workingAlgo.at(i+1) << "\n";
                    workingAlgo.at(i+1) = product;
                    cout << "product elem: " << workingAlgo.at(i+1) << "\n";
                    workingAlgo.erase(workingAlgo.begin()+(i-1), workingAlgo.begin()+(i+1));
                    updateNumbersAndTheirLocations(workingAlgo);
                }
                else
                {
                    workingAlgo.push_back('-');
                    workingAlgo.push_back(product);
                    workingAlgo.erase(workingAlgo.begin()+(i-1), workingAlgo.begin()+(i+2));
                    updateNumbersAndTheirLocations(workingAlgo);
                }
            }
        }
    }
    cout << workingAlgo.at(0);
}

//////////////////////// NOTES ////////////////////////

//----------------
//Next Steps:
//Must chunk each portion of input, finding entire number
//Then must figure out how to place a larger element in a vector location in the place of smaller element
//----------------

//  Likely would be best to read directly from the stream and determine each character as either
//  string or num?

//  Should break each algorithm manipulation into separate function

//  Learn what "&" is actually doing
//  Learn diff between " and '

///////////////////////////////////////////////////////
