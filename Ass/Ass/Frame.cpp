
/**********************************************************************
Filename:  Frame.cpp
Version:   1.0
Author:  Nana Ngassa Franck
Student No:   040 783 398
Course Name/Number: C++ CST 8219
Lab Sect:  011
Assignment #: 2
Assignment name: Animatiom Project In C
Due Date:  March 24 2018
Submission Date:	March 24 2018
Professor: Andrew Tyler
Purpose:   Handles each frame:subscripts and output operators 
*********************************************************************/

#pragma once

using namespace std;

#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include "Display.h"
#include "Frame.h"


/********************************************************************
Function Name:  operator[]
Purpose:   Array subscript operator
In parameters:	n
Out parameters:	None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Display& Frame::operator[](int position)
{
	return displays[position];
}


/********************************************************************
Function Name:  operator<<
Purpose:   Extraction operator
In parameters:	None
Out parameters:	None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

ostream & operator<<(ostream &os, Frame &RS)
{
	/*Extract frameName*/
	os << "FrameName = " << RS.frameName << endl;

	/*Output each resolution*/
	for (unsigned i = 0; i < RS.displays.size(); i++) {
		os << setw(17) << "Display #" << i << " Resolution = " << RS.displays[i]<< endl;
	}
	return os;
}
