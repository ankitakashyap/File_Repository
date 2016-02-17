#ifndef DATASTORE_H
#define DATASTORE_H

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DataStore.h - Stores the filenames and the corresponding paths              //
// Object Oriented Design, Spring 2015                                                       //
//ver 2.2                                                                                                      //
// Language:    Visual C++ 11, Visual Studio 2013                                       //                       
// Platform:    MAC OSX,Core i5, Windows 7                                               //                                                                                                             
// Author:  Ankita Kashyap , Syracuse University                                        //
//              (315) 436-7059, ankashya@syr.edu                                          //
// Source - Jim Fawcett                                                                             //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Module Operations :
*== == == == == == == == ==
 This  file contains the following class : DataStore - useful for storing the filename and path. It contains the declarations of the methods defined in DataStore.cpp
It has the following methods :

void save() -  This function takes the filename and the path and stores it in a map
std::vector<std::string> userfilenamesforsearchtext() -  It is used for searching text when user inputs command in the console
std::vector<std::string> searchtext() -  Finds the specified text in a file. It is displayed when /f is given in the commandline. Outputs the filename and path.


Public Interface:
=================
public:
using Path = std::string;
using Paths = std::set<Path>;
using PathIter = Paths::iterator;
using ListOfIters = std::list<PathIter>;
using File = std::string;
using Store = std::map<File, ListOfIters>;
using iterator = Store::iterator;
void save(const std::string&, const std::string&);
std::vector<std::string> userfilenamesforsearchtext(string, string);
std::vector<std::string> searchtext(string);
iterator itr;
std::pair<PathIter, bool> it;
Store store;
Paths paths;
PathIter pitr;
ListOfIters::iterator litr;

Required Files:
 ===============
 FileMgr.h, DataStore.cpp,FIleSystem.h,DataStore.h

 Build Command:
  ==============
  cl /EHa /TEST_DATASTORE DataStore.cpp


  Maintenance History:
  ====================
 ver 2.2 : 8 Feb 15
 Created test stubs, added comments and added prologues
 ver 2.1 : 2 Feb15
 - Integrated the modules with each other.
 - Cleared the link errors
 - Implemented functionality for text search.
 ver 1.1 : 25 Jan 15
-  Created functionality for datastore. Inserted filename and paths in the map
 ver 1.0 : 23 Jan 15
 - first release
  */

#include <vector>
#include<set>
#include<list>
#include<map>
#include<string>
#include<iostream>
#include <fstream>
#include"../FileMgr/FileSystem.h"
using namespace std;

class DataStore
{
public:
	using Path = std::string;
	using Paths = std::set<Path>;
	using PathIter = Paths::iterator;
	using ListOfIters = std::list<PathIter>;
	using File = std::string;
	using Store = std::map<File, ListOfIters>;
	using iterator = Store::iterator;
	void save(const std::string&, const std::string&);
	std::vector<std::string> userfilenamesforsearchtext(string, string);
	std::vector<std::string> searchtext(string);
	iterator itr;
	std::pair<PathIter, bool> it;
	Store store;
	Paths paths;
	PathIter pitr;
	ListOfIters::iterator litr;
};
#endif