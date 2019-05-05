//ImageFrame.cpp

/*
* File Name: ImageFrame.cc
* Version: 1
* Compiler: MS Visual Studio 2015
* Author: Nana Ngassa Franck, 040 783 398
* Course: CST 8219 –C++ Section 301
* Assignment: 3
* Date: April 21, 2017
* Professor: Andrew Tyler
* Methods: void ImageFrame::Compress()
*	ostream & operator<<(ostream &, ImageFrame &)
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
Purpose:   Compress each Image frame 
In parameters:  None
Out parameters: None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void ImageFrame::Compress()
{
	double compressedSizes[BITS];

	for (int i = 0; i < BITS; i++) {
		compressedSizes[i] = fileSize / (COMPRESSION_RATIO * BITDEPTH_FACTOR[i]);
	}

	cout << "Name = " << this->GetFrameName() << endl;
	cout << "Lempel-Ziv-Welch Lossless Compression " << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "colors: " << setw(11);
	for (int i = 0; i < BITS; i++) {

		if (i == 0 || i == 1 || i == 2) {
			cout << "| " << setprecision(0) << fixed << pow(2, i + 1) << setw(8);
		}
		else
			if (i == 3 || i == 4 || i == 5 || i == 7 || (i == 8))
				cout << "| " << setprecision(0) << fixed << pow(2, i + 1) << setw(7);
			else
				if (i == 6)
					cout << "| "<< setprecision(0) << fixed << pow(2, i + 1) << setw(6);

	}
	cout << endl;
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "file size (MB): " << setw(3);
	for (int i = 0; i < BITS; i++) {
		cout << setprecision(3) << fixed;
		cout << "| " << compressedSizes[i] << setw(4);
	}
	cout << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
}

/*********************************************************************
Function Name:   operator<<
Purpose:  overloaded  Output operator
In parameters:  os, RS
Out parameters: os
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

ostream & operator<<(ostream &os, ImageFrame &RS)
{
	return os;
}

