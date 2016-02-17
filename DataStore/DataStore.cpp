///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DataStore.cpp - Stores the filenames and the corresponding paths            //
// Object Oriented Design, Spring 2015                                                         //
// ver 2.2                                                                                                       //
// Language:    Visual C++ 11, Visual Studio 2013                                        //                       
// Platform:    MAC OSX,Core i5, Windows 7                                                //                                                                                                             
// Author:  Ankita Kashyap , Syracuse University                                         //
//              (315) 436-7059, ankashya@syr.edu                                           //
// Source - Jim Fawcett                                                                             //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "DataStore.h"
#include <iostream>

//<---------------------<Stores the filenames and paths into a map>-------------------

void DataStore::save(const std::string& filename, const std::string& path)
{
	it = paths.insert(path);
	iterator mapitr = store.find(filename);
	if (mapitr != store.end())                 // this is  for handling the case of  duplicates
	{
		ListOfIters::iterator lstitr = mapitr->second.begin();
		while (lstitr != mapitr->second.end())
		{
			if (**(lstitr) == path)
				return;
			else
				lstitr++;
		}
		mapitr->second.push_back(it.first);
	}

	else                                            // this for cases other than duplicates cases
	{
		ListOfIters ltr;
		
		ltr.push_back(it.first);
		store[filename] = ltr;
	}
}


//<---------------------<Searches the contents of a file for a specified text search  based on user input in the console >-------------------

std::vector<std::string> DataStore::userfilenamesforsearchtext(string searchtext, string userpattern)
{

	std::vector<std::string> uflnmvtr;
	
	std::string check; int cntr = 0;
	for (iterator st = store.begin(); st != store.end(); ++st)
	{
		if (st->first.find(userpattern) != string::npos)
		{
			cntr++;
			for (ListOfIters::iterator litr = st->second.begin(); litr != st->second.end(); litr++)
			{

				check = FileSystem::Path::fileSpec(**(litr), st->first);
			
				fstream flopn;
				
				size_t pos;    
				std::string line;
				flopn.open(check);
				if (!flopn)
				{
					cout << "Unable to open file" << endl;
					exit(1);
				}
				while (flopn.good())    // return true if none of the stream's error state flags  are set.
				{
					getline(flopn, line);     // reads  line by line  from file
					pos = line.find(searchtext); 
					if (pos != string::npos)       // string::npos is returned if string is not found
					{
					
						uflnmvtr.push_back(st->first);
						uflnmvtr.push_back(**(litr));
					
						break;
					}
				}
			}
		}
		
	}
	if (cntr == 0)
		cout << "Please give the existing pattern in data stored";
	else
	cout << "The  text search  for the user input < " << searchtext << " > is present in the following files along with path: \n";

	return uflnmvtr;
}





//<---------------------<Searches the contents of a file for a specified text search >-------------------
std::vector<std::string> DataStore::searchtext(string searchtext)
{
	std::vector<std::string> flnmvtr;

	std::string check;
	for (iterator st = store.begin(); st != store.end(); ++st)
	{
		for (ListOfIters::iterator litr = st->second.begin(); litr != st->second.end(); litr++)
		{

			check = FileSystem::Path::fileSpec(**(litr), st->first);

			fstream flopn;
			size_t pos;                              // npos is of type size_t
			std::string line;
			flopn.open(check);
			if (!flopn)
			{
				cout << "Cannot open file" << endl;
				exit(1);
			}
			while (flopn.good())               // returns true if none of the stream's error state flags are set.
			{
				getline(flopn, line);               // reads line by line from file
				pos = line.find(searchtext);          // search
				if (pos != string::npos)        // string::npos is returned if string is not found
				{

					flnmvtr.push_back(st->first);
					flnmvtr.push_back(**(litr));
					break;
				}
			}
		}
	}
	cout << "The text search < " << searchtext << " > is present in the following files along with  path: \n";
	return flnmvtr;
}




//<---------------------< Test Stub for DataStore >-------------------

#ifdef TEST_DATASTORE
#include"../Display/Display.h"
int main()
{
	DataStore ds;
	string filename = "Display.h", path = "../Display", searchstring = "class", user_pattern = ".h";
	ds.save(filename, path);
	ds.searchtext(searchstring);
	ds.userfilenamesforsearchtext(searchstring, user_pattern);
	Display disp;
	disp.display(ds);
}
#endif
