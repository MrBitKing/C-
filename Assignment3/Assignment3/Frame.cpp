//Frame.cpp

/*
* File Name: Frame.cpp.cc
* Version: 1
* Compiler: MS Visual Studio 2015
* Author: Nana Ngassa Franck, 040 783 398
* Course: CST 8219 –C++ Section 301
* Assignment: 3
* Date: April 214, 2017
* Professor: Andrew Tyler
* Methods: operator[] (int x)
*	ostream & operator<<(ostream &os, Frame &RS)
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
Function Name:  DeleteFrames()
Purpose:   Subspcripting operator
In parameters:  None
Out parameters: None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

Attribute& Frame::operator[] (int x)
{
	return attributes[x];
}

/*********************************************************************
Function Name:  operator<<
Purpose:   outputOperator
In parameters:  os, RS
Out parameters: os
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

ostream & operator<<(ostream &os, Frame &RS)
{
	AudioFrame* audio = dynamic_cast<AudioFrame*>(&RS);
	ImageFrame* image = dynamic_cast<ImageFrame*>(&RS);

	if (audio)
		cout << "AudioFrame" << endl;

	if (image)
		cout << "AudioFrame" << endl;

	os << "FrameName " << RS.GetFrameName() << endl;

	for (int i = 0; i < RS.size(); i++) {

		if (audio)
			os << "\tResolution #" << i << ": " << RS.attributes[i] << endl;

		if (image)
			os << "\tBandwith #" << i << ": " << RS.attributes[i] << endl;
	}
	
	return os;

}
