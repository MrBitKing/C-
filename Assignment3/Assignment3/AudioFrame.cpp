

/*
* File Name: Frame.cpp.cc
* Version: 1
* Compiler: MS Visual Studio 2015
* Author: Nana Ngassa Franck, 040 783 398
* Course: CST 8219 –C++ Section 301
* Assignment: 3
* Date: April 21, 2018
* Professor: Andrew Tyler
* Methods: Compress()
*	operator<<(ostream &, Animation &)
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
Function Name:  compress()
Purpose:   Compress each Audio frame
In parameters:  None
Out parameters: None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void AudioFrame::Compress()
{

	double compressedSizes[RATES];

	for (int i = 0; i < RATES; i++) {
		compressedSizes[i] = fileSize / COMPRESSION_RATIO[i];
	}

	cout << "Name = " << this->GetFrameName() << endl;
	cout << "MP3 Lossy Compression" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "bitrate (kbits/s):\t";
	for (int i = 0; i < RATES; i++) {

		if (i == 0)
			cout << "| " << setprecision(0) << BITRATE[i] << setw(7);
		else
		if (i == 1)
			cout << "| " << setprecision(0) << BITRATE[i] << setw(7);
		else
		cout << "| " << setprecision(0) << BITRATE[i] ;
	}

	cout << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "file size (MB): \t";

	for (int i = 0; i < RATES; i++) {
		cout << setprecision(4) << fixed;
		cout << "| "<< compressedSizes[i] << setw(4);

	}
	cout << endl;
	cout << "----------------------------------------------------------" << endl;

}


/*********************************************************************
Function Name:   operator<<
Purpose:  overloaded  Output operator
In parameters:  os, RS
Out parameters: os
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

ostream & operator<<(ostream &os, AudioFrame &RS)
{
	return os;
}
	