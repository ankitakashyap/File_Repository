////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FileMgr.cpp - Saves filename and path in datastore, adds patterns and      //
// performs search operations                                                                        //
// Object Oriented Design, Spring 2015                                                        //
// ver 2.2                                                                                                      //
// Language:    Visual C++ 11, Visual Studio 2013                                       //                       
// Platform:    MAC OSX,Core i5, Windows 7                                               //                                                                                                             
// Author:      Jim Fawcett, CST 4-187, Syracuse University                         //
//                  (315) 443-3948, jfawcett@twcny.rr.com                                  //
// Modified by: Ankita Kashyap , Syracuse University                                 //
//                   (315) 436-7059, ankashya@syr.edu                                     //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "FileSystem.h"
#include"FileMgr.h"

//<---------------------<Copy Constructor>-------------------

FileMgr::FileMgr(const std::string& path, DataStore& ds) : path_(path), store_(ds)
{
	patterns_.push_back("*.*");
}

//<---------------------<Searches for the path and stores it in the datastore>-------------------
void FileMgr::find(std::string& path)
{

	std::vector<std::string> drts = FileSystem::Directory::getDirectories(path);
	for (auto dt : drts)
	{
		if (dt != "."&&dt != ".."&& drts.size()>2)                // In case there are directories present in the current path, control will go here
		{
			for (auto patt : patterns_)
			{
				std::vector<std::string> subfiles = FileSystem::Directory::getFiles(path, patt);
				for (auto sbf : subfiles)
				{
					store_.save(sbf, path);
				}
			}
			std::string nm = FileSystem::Path::fileSpec(path, dt);
			find(nm);
		}
		else                                                                      // In case no directories are present, then this condition will be evaluated
		{
			if (dt != "..")
			{
				for (auto patt : patterns_)
				{
					std::vector<std::string> subfiles = FileSystem::Directory::getFiles(path, patt);
					for (auto sbf : subfiles)
					{
						store_.save(sbf, path);
					}
				}
			}
		}
	}
}

//<---------------------<Searches for  the files in the current directory>-------------------
void FileMgr::findnonrecursive(std::string& path)
{
	for (auto patt : patterns_)
		{
			std::vector<std::string> subfiles = FileSystem::Directory::getFiles(path, patt);
			for (auto sbf : subfiles)
			{
				store_.save(sbf, path);
			}
		}
}





//<---------------------<Adds pattern into a vector>----------------------------------------------
void FileMgr::addPattern(const std::string& patt)
{
	if (patterns_.size() == 1 && patterns_[0] == "*.*")
		patterns_.pop_back();
	patterns_.push_back(patt);
}


//<---------------------<Searches for  the files in the current directory>-------------------
void FileMgr::searchnonrecursive()
{
	findnonrecursive(path_);
}





//<---------------------<Searches for the files in the current directory and sub-directories i.e. it performs recursive search >-------------------
void FileMgr::search()
{
	find(path_);
}



//<---------------------<Test Stub for File Manager>-------------------------------

#ifdef TEST_FILEMANAGER
#include"../DataStore/DataStore.h"
#include"../Display/Display.h"
int main()
{
	Display disp;
	string path = "./TestCheck";
	DataStore ds;
	FileMgr fmg1(path, ds);
	fmg1.find(path);
	fmg1.findnonrecursive(path);
	fmg1.addPattern("*.*");
	fmg1.search();
	fmg1.searchnonrecursive();
	disp.display(ds);
	
}
#endif