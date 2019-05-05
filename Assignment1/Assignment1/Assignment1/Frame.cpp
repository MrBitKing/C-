
/**********************************************************************
Filename:  Frame.cpp
Version:   1.0
Author:  Nana Ngassa Franck
Student No:   040 783 398
Course Name/Number: C++ CST 8219
Lab Sect:  011
Assignment #: 1
Assignment name: Animation Project In C++
Due Date:  February 24 2018
Submission Date: Feb 24 2018
Professor: Andrew Tyler
Purpose:   Handle each frame
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Frame.h"




/**********************************************************************
Function Name:  Frame constructor
Purpose:   Initialize each frame
In parameters:  frame name
Out parameters:  None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Frame::Frame(char *fileName) {

	frameName = new char[strlen(fileName) + 1];
	strcpy(frameName, fileName);
}

/**********************************************************************
Function Name:  frame destructor
Purpose:   destroy each frame
In parameters:  None
Out parameters:  None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Frame::~Frame() {

	//delete each frame and set to null
	delete frameName;

	//	frameName = nullptr;
}

/**********************************************************************
Function Name:  FindFileName
Purpose:   return true on file match
In parameters:  filename to edit
Out parameters:  None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

bool Frame::FindFileName(char *fileName)
{
	if (strcmp(frameName, fileName) == 0)
		return true;
	return false;
}

/**********************************************************************
Function Name:  ReplaceFrameName
Purpose:   Edit frame name
In parameters:  frame name to edit
Out parameters:  None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/
void Frame::ReplaceFrameName(char *fileName)
{
	delete frameName;
	frameName = new char[strlen(fileName) + 1];
	strcpy(frameName, fileName);
}

/**********************************************************************
Function Name:  Report
Purpose:   return frame name
In parameters:  None
Out parameters:  frame name
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/
char *Frame::Report()
{
	return frameName;
}

