///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Display.h - Displays the functionality of the requirements for the project    //
// Object Oriented Design, Spring 2015                                                       //
// ver 2.2                                                                                                      //
// Language:    Visual C++ 11, Visual Studio 2013                                       //                       
// Platform:    MAC OSX,Core i5, Windows 7                                               //                                                                                                             
// Author:  Ankita Kashyap , Syracuse University                                        //
//              (315) 436-7059, ankashya@syr.edu                                          //
// Source - Jim Fawcett                                                                             //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Module Operations :
*== == == == == == == == ==
This  file contains the following class : Display- It outputs the functionality of requirements . It contains the declarations of the methods defined in Display.cpp
It has the following methods :
display() -  This function outputs the filename and the path , recursively and non-recursively.
displayduplicateonly() - Displays files for the duplicates present . Duplicate file names and paths are displayed .
filesearchfortext() - Displays output for searching text 
displayfilesforusersearch() - Searches text and emits result based on the user input from the console.


Public Interface:
=================
public:
void display(DataStore&);
void displayonlyduplicate(DataStore&);
void filesearchfortext(std::vector<std::string>);
void displayfilesforusersearch(std::vector<std::string>);



Required Files:
===============
DataStore.h, Display.cpp,FIleSystem.h,Display.h

Build Command:
==============
cl /EHa /TEST_DISPLAY Display.cpp


Maintenance History:
====================
ver 2.2 : 8 Feb 15
Created test stubs, added comments and added prologues
ver 2.1 : 2 Feb15
- Integrated the modules with each other.
- Cleared the link errors
- Created functionality for display of the duplicate filenames along with their paths
- Creates the functions for text search functions.
- Did modifications to display the filenames and path to be stored in a map
ver 1.1 : 25 Jan 15
-  Created functionality for displaying filename and paths
ver 1.0 : 23 Jan 15
- first release
*/



#include"../DataStore/DataStore.h"
class Display
{
public:
	void display(DataStore&);
	void displayonlyduplicate(DataStore&);
	void filesearchfortext(std::vector<std::string>);
	void displayfilesforusersearch(std::vector<std::string>);
};

