
/**********************************************************************
Filename:  Display.cpp
Version:   1.0
Author:  Nana Ngassa Franck
Student No:   040 783 398
Course Name/Number: C++ CST 8219
Lab Sect:  011
Assignment #: 2
Assignment name: Animatiom Project In C
Due Date:  March 24 2018
Submission Date: March 24 2018
Professor: Andrew Tyler
Purpose:   Handles each resolutions: Overloaded constructors
*********************************************************************/

#pragma once

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#include <iostream>
#include "Display.h"


/*********************************************************************
Function Name:  Animation
Purpose: constructor
In parameters:	char *resolution
Out parameters:	None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/


Display::Display(char *resolution)
{
	this->resolution = new char[strlen(resolution) + 1];
	strcpy(this->resolution, resolution);

}


	/********************************************************************
	Function Name:  Animation
	Purpose: copy constructor
	In parameters:	&RS
	Out parameters:	None
	Version:   1.0
	Author:   Nana Ngassa Franck
	**********************************************************************/


Display::Display(const Display &RS)
{

	resolution = new char[strlen(RS.resolution) + 1];
	strcpy(resolution, RS.resolution);
}


/********************************************************************
Function Name:  operator=
Purpose:   Assignment operator
In parameters:	&RS
Out parameters:	*this
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Display & Display::operator=(Display &RS)
{

	//Avoid self-assignment
	if (this == &RS)
		return *this;

	if (strlen(RS.resolution) > strlen(resolution)) { 
	delete[] resolution;
	resolution = new char[strlen(RS.resolution) + 1];

	}
	strcpy(resolution, RS.resolution);
	return *this;
}


/********************************************************************
Function Name:  ~Display
Purpose:   Destroyer for each resolution
In parameters:	None
Out parameters:	None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Display::~Display()
{
	if (resolution)
		delete[]resolution;
}



/********************************************************************
Function Name:  operator<<
Purpose:   Output operator
In parameters:	None
Out parameters:	None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

ostream & operator<<(ostream &os, Display &RS)
{
	os << " Resolution " << RS.resolution;
	return os;
}
