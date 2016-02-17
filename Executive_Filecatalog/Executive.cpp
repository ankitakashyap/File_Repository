/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Executive.cpp - Interacts with the Command Line and is the main point of       // 
// control for the program.Manages complete flow of execution for the program  //
// Object Oriented Design, Spring 2015                                                             //
// ver 2.2                                                                                                           //
// Language:    Visual C++ 11, Visual Studio 2013                                             //                       
// Platform:    MAC OSX,Core i5, Windows 7                                                     //                                                                                                             
// Author:  Ankita Kashyap , Syracuse University                                               //
//              (315) 436-7059, ankashya@syr.edu                                                 //
// Source - Jim Fawcett                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "../FileMgr/FileMgr.h"
#include "../DataStore/DataStore.h"
#include <iostream>
#include"../Display/Display.h"
#include<vector>
#include<string>
#ifdef TEST_EXECUTIVE

//<---------------------<Controls flow of execution for the application>-------------------
int main(int argc, char* argv[])
{


	if (argc == 1)                                                                        // When there is no input on command line
	{
		std::string dir = FileSystem::Directory::getCurrentDirectory();
		std::vector<std::string> currentdirfiles = FileSystem::Directory::getFiles(dir, "*.*");
		cout << "There are " << currentdirfiles.size() << " files in 1 directory";
	}
	else if (argc == 2)                                                                  // Used for whenever path is given
	{
		DataStore ds;
		Display disp;
		FileMgr fm(argv[1], ds);
		cout << "The files contained in  the directory are as follows : \n";
		std::vector<std::string> currentdirfiles = FileSystem::Directory::getFiles(argv[1], "*.*");
		for (auto f1 : currentdirfiles)
		 cout<< f1<<"\n";
		fm.addPattern("*.*");
		fm.searchnonrecursive();
		while (1)                                                                             // For repeated user input 
		{
			string userpattern, usertext;
			cout << "\nEnter the pattern using the format: .<pattern> (Eg: .cpp )  you want to search from the existing data  \n otherwise type Exit to move to the next requirement\n";
			cin >> userpattern;
			if (userpattern == "exit" || userpattern == "Exit" || userpattern == "EXIT")
				break;
			cout << "Enter the  text search you want to search from the existing data  \n otherwise type Exit to move to the next requirement\n";
			cin >> usertext;
			if (usertext == "exit" || usertext == "Exit" || usertext == "EXIT")
				break;
			std::vector<std::string> tmpforfilename;
			tmpforfilename = ds.userfilenamesforsearchtext(usertext, userpattern);
			disp.displayfilesforusersearch(tmpforfilename);
		}
	}
	else                                                                                      // All options are given as input argument
	{
		DataStore ds;
		Display disp;
		FileMgr fm(argv[1], ds);
		int checkerforpath = 0, checkerforpattern = 0, checkerforswitches = 0;
		std::vector<std::string> CopyArgumentsintoVector;
		CopyArgumentsintoVector.assign(argv + 1, argv + argc);
		for (auto tr : CopyArgumentsintoVector)
		{
			if ((tr.find("../") != string::npos) || (tr.find("./") != string::npos) || (tr.find("\\") != string::npos))
			{
				checkerforpath++;
			}
		}
		for (auto tr : CopyArgumentsintoVector)
		{
			if ((tr.find("*.") != string::npos))
			{
				checkerforpattern++;
				fm.addPattern(tr);
				fm.searchnonrecursive();
			}
		}
		if (checkerforpattern == 0)
		{
			fm.addPattern("*.*");
		}
		else if (checkerforpattern>0)
		{
			int fs = 0;
			for (auto tr1 : CopyArgumentsintoVector)
			{
				if ((tr1.find("/s") != string::npos))
				{
					fs++;
				}
			}
			if (fs==0)
			disp.display(ds);
		}
		int checkfors = 0;
		for (auto tr1 : CopyArgumentsintoVector)
		{
			int l = 0; // check for both /s and /d
			if ((tr1.find("/s") != string::npos))
			{
				checkfors++; // incremented when /s is present
				for (auto tr1 : CopyArgumentsintoVector)
				{
					if (tr1.find("/d") != string::npos)
					{
						l++; // incremented when /s and /d are found
					}
				}
				if (l != 0)
				{
					fm.search();
					disp.displayonlyduplicate(ds);
				}
				else
				{
					fm.search();
					disp.display(ds);
				}
			}
			
			if ((tr1.find("/f") != string::npos))
			{
				std::vector<std::string> tmp;
				int x = (tr1.find("/f") != string::npos) + 1;
				string textstring;
				textstring = tr1.substr(x);
				tmp = ds.searchtext(textstring);
				disp.filesearchfortext(tmp);
			}
		}
		for (auto tr1 : CopyArgumentsintoVector)
		{
			if ((tr1.find("/d") != string::npos) && checkfors == 0)
			{
				cout << "No duplicates found in current directory \n";
			}

		}
		while (1)
		{
			string userpattern, usertext;
			cout <<"\nEnter the pattern using the format: .<pattern> (Eg: .cpp )  you want to search from the existing data  \n otherwise type Exit to move to the next requirement\n\n";
			cin >> userpattern;
			if (userpattern == "exit" || userpattern == "Exit" || userpattern == "EXIT")
				break;
			cout << "Enter the  text search you want to search from the existing data  \n otherwise type Exit to move to the next requirement\n\n";
			cin >> usertext;
			if (usertext == "exit" || usertext == "Exit" || usertext == "EXIT")
				break;
			std::vector<std::string> tmpforfilename;
			tmpforfilename = ds.userfilenamesforsearchtext(usertext, userpattern);
			disp.displayfilesforusersearch(tmpforfilename);
		}
	}
	return 0;
}
#endif