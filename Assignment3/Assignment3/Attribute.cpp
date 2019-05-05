#define _CRT_SECURE_NO_WARNINGS 


/*
* File Name: ImageFrame.cc
* Version: 1
* Compiler: MS Visual Studio 2015
* Author: Nana Ngassa Franck, 040 783 398
* Course: CST 8219 –C++ Section 301
* Assignment: 3
* Date: April 21, 2017
* Professor: Andrew Tyler
* Methods: Attribute(char *RS)
*	operator=(Attribute &RS)
*	Attribute(const Attribute &RS)
*	Attribute::~Attribute()
*	operator<<(ostream &, Attribute &)
*/

#include <deque>
#include <iomanip>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#include "Attribute.h"
#include "Frame.h"
#include "ImageFrame.h"
#include"AudioFrame.h"
#include "Animation.h"


/*********************************************************************
Function Name:   operator<<
Purpose:  overloaded  Output operator
In parameters:  os, RS
Out parameters: os
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Attribute::Attribute(char *RS)
{
	attributeString = new char[strlen(RS) + 1];
	strcpy(attributeString, RS);
}


/*********************************************************************
Function Name:   operator<<
Purpose:  overloaded  Output operator
In parameters:  os, RS
Out parameters: os
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Attribute::Attribute(const Attribute &RS)
{
	attributeString = new char[strlen(RS.attributeString) + 1];
	strcpy(attributeString, RS.attributeString);
}


/*********************************************************************
Function Name:   operator=(Attribute &RS)
Purpose:  overloaded  assignment operator operator
In parameters:  os, RS
Out parameters: os
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Attribute & Attribute::operator=(Attribute &RS)
{
	if (&RS == this)
		return *this;

	delete[]attributeString;
	attributeString = new char[strlen(RS.attributeString) + 1];
	strcpy(attributeString, RS.attributeString);
	return *this;
}


/*********************************************************************
Function Name:   ~Attribute()
Purpose:  delete attribute
In parameters:  os, RS
Out parameters: os
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Attribute::~Attribute()
{
	delete[] attributeString;
}


/**********************************************************************
Function Name:   operator<<
Purpose:  overloaded  Output operator
In parameters:  os, RS
Out parameters: os
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

ostream & operator<<(ostream &os, Attribute &RS)
{
	os << RS.attributeString;
	return os;
}
