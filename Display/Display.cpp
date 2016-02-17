/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Display.cpp - Displays the functionality of the requirements for the project  //
// Object Oriented Design, Spring 2015                                                         //
// ver 2.2                                                                                                       //
// Language:    Visual C++ 11, Visual Studio 2013                                        //                       
// Platform:    MAC OSX,Core i5, Windows 7                                                //                                                                                                             
// Author:  Ankita Kashyap , Syracuse University                                         //
//              (315) 436-7059, ankashya@syr.edu                                           //
// Source - Jim Fawcett                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include"Display.h"
#include<map>


//<---------------------<Searches for contents of a file based on a specified text>-------------------

void Display::filesearchfortext(std::vector<std::string> tmp)
{
	for (auto t1 : tmp)
	{
		cout << t1;
		if (t1.find(".") != string::npos)
			cout << " -> ";
		else
			cout << "\n";
	}
}


//<---------------------<For displaying the names of files and the paths from the current directory and any sub-directories present>-------------------
void Display::display(DataStore& ds)
{
	cout << "The output is: \n\n";
	for (ds.itr = ds.store.begin(); ds.itr != ds.store.end(); ++ds.itr)
	{
		std::cout << "FileName: \t" << ds.itr->first << "\n";
		for (ds.litr = ds.itr->second.begin(); ds.litr != ds.itr->second.end(); ds.litr++)
			std::cout << "Path: \t" << **(ds.litr) << "\n";
	}
}



//<---------------------<For displaying the duplicate files along with path in current directory as well as sub-directories>-------------------

void Display::displayonlyduplicate(DataStore& ds)
{
	cout << "The duplicate files along with paths which are present in current directory and sub-directories are as follows: \n\n";
	for (ds.itr = ds.store.begin(); ds.itr != ds.store.end(); ++(ds.itr))
	{
		int listchecker = 0;
		for (ds.litr = ds.itr->second.begin(); ds.litr != ds.itr->second.end(); (ds.litr)++)
		{
			listchecker++;
		}
		if (listchecker > 1)
		{
			std::cout << "FileName: \t" << ds.itr->first << "\n";
			for (ds.litr = ds.itr->second.begin(); ds.litr != ds.itr->second.end(); (ds.litr)++)
				std::cout << "Path: \t" << **(ds.litr) << "\n";
		}
	}
	cout << "\n";
}


//<---------------------<Searches for contents of a file based on a specified text and on input given by the user from the console>-------------------

void Display::displayfilesforusersearch(std::vector<std::string> tmp)
{
	for (auto t1 : tmp)
	{
		cout << t1;
		if (t1.find(".") != string::npos)
			cout << " -> ";
		else
			cout << "\n";
	}
}


//<---------------------<Test stub for display module>-------------------

#ifdef TEST_DISPLAY
int main()
{
	DataStore ds;
	ds.save("Filename.h", "./TestCheck");
	Display disp;
	disp.display(ds);
	disp.displayduplicateonly(ds);
	std::vector<std::string> test_vector;
	test_vector.push_back("Filename.h");
	test_vector.push_back("Path1");
	test_vector.push_back("Filename1.h");
	test_vector.push_back("Path2");
	disp.displayfilesforusersearch(test_vector);
	disp.filesearchfortext(test_vector);
}
#endif