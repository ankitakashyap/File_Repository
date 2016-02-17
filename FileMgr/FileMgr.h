#ifndef FILEMGR_H
#define FILEMGR_H

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FileMgr.h - Saves filename and path in datastore, adds patterns and         //
// performs search operations                                                                        //
// Object Oriented Design, Spring 2015                                                        //
// ver 2.2                                                                                                      //
// Language:    Visual C++ 11, Visual Studio 2013                                       //                       
// Platform:    MAC OSX,Core i5, Windows 7                                               //                                                                                                             
// Author:      Jim Fawcett, CST 4-187, Syracuse University                        //
//              (315) 443-3948, jfawcett@twcny.rr.com                                     //
// Modified by: Ankita Kashyap , Syracuse University                                //
//                   (315) 436-7059, ankashya@syr.edu                                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* Module Operations :
*== == == == == == == == ==
This  file contains the following class : FIleMgr - Performs search operations, manages all the filenames and corrsponding paths in the datastore module.
Useful for adding the patterns.There are various methods defined in this class for performing these operations


Public Interface:
=================
public:
FileMgr(const std::string&, DataStore&);
using iterator = DataStore::iterator;
using patterns = std::vector<std::string>;
void find(std::string&);
void addPattern(const std::string&);
void findnonrecursive(std::string&);
void searchnonrecursive();
void search();
int filecountr = 0, directorycount = 1, counter = 1;
std::string path_;
DataStore& store_;
patterns patterns_;





Required Files:
===============
DataStore.h, FileMgr.cpp,FIleSystem.h,FileMgr.h

Build Command:
==============
cl /EHa /TEST_FILEMANAGER FileMgr.cpp


Maintenance History:
====================
ver 2.2 : 5 Feb 15
Created test stubs, added comments and added prologues. Created a fully functional FileMgr package
ver 2.1 : 2 Feb15
- Integrated the modules with each other.
- Cleared the link errors
- Created functionality for recursive and non-recursive search opertions
- Mde changes to the functionality of the methods accoriding to the requirements
- Did modifications to display the requirements in different ways 
ver 1.1 : 25 Jan 15
-  Created functionality for adding the patterns into a vector
ver 1.0 : 23 Jan 15
- first release
*/




#include "FileSystem.h"
#include "../DataStore/DataStore.h"
class FileMgr
{
public:
	FileMgr(const std::string&, DataStore&);
  using iterator = DataStore::iterator;
  using patterns = std::vector<std::string>;
  void find(std::string&);
  void addPattern(const std::string&); 
  void findnonrecursive(std::string&);
  void searchnonrecursive();
  void search();
 int filecountr = 0, directorycount = 1, counter = 1;
	std::string path_;
	DataStore& store_;
	patterns patterns_;
};

#endif
