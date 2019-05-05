
//Frame.cpp
#pragma once

using namespace std;

#include <vector>
#include <iostream>
#include <string>
#include "Display.h"
#include "Frame.h"

//class Display {

	//string frameName;
//	vector<Display> displays;

//public:

	//Display(string frameNames = "") :frameName(frameNames) { cout << "Display::Display(string):" << frameName << endl; }

//	Display(const Display& RS) : frameName(RS.frameName) { cout << "D" }
	Display& Frame::operator[](int n)
	{
		// TODO: insert return statement here

	/*	if (n<0 || n >(signed) displays.size()) {
			cout << "\nIndex value of";
			cout << n << "is-out-of-bounds.\n ";
			exit(1);
		}*/
		return displays[n]; //displays.at(n); 
	}

	 ostream & operator<<(ostream &os, Frame &RS)
	{
		// TODO: insert return statement here
		os << RS.GetFrameName() << endl;  //\n ?//getframename
	//	os << RS.displays << endl;  //\n ?//getframename
		return os;
	}
//};