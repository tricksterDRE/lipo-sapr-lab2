#include <string>
#include <iostream>
#include <pcrecpp.h>
#include <sstream>		/* std::stringstream */
#include <algorithm>    /* std::find */
#include <iterator>		/* std::vector::iterator */
#include <vector>		/* std::vector */
#include "MacrosFinder.h"

string MacrosFinder::FindMacros()
{
    string macrosName = "";
    string list = "";
    pcrecpp::RE macrosNameRegex = pcrecpp::RE("#define\\s(\\w+)\\s");
    
    vector<string>macrosArray;
    vector<string>::iterator macrosArrayIterator;
    vector<string>::iterator uniqueMacros;
    
    /*Check all stdin*/
    while (getline(cin, macrosName))
    {
        /*Check line*/
        pcrecpp::StringPiece input(macrosName);
        while (macrosNameRegex.FindAndConsume(&input, &macrosName))
        {
            /*The uniqueness here is if we already find them -- then skip*/
            uniqueMacros = find(macrosArray.begin(), macrosArray.end(), macrosName);
            if (uniqueMacros == macrosArray.end())
            {
                if (list == "")
                {
                    /*if line is first -- doesn't add CR to begin of line*/
                    list += macrosName; 
                }
                else 
                {
                    list += "\n" + macrosName;
                }
                macrosArray.push_back(macrosName);
            }
        }
    }
    /*Return list with unique macroses*/
    return list;
}