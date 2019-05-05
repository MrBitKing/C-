//Animation.cpp

/*
* File Name: Frame.cpp.cc
* Version: 1
* Compiler: MS Visual Studio 2015
* Author: Nana Ngassa Franck, 040 783 398
* Course: CST 8219 –C++ Section 301
* Assignment: 3
* Date: April 21, 2018
* Professor: Andrew Tyler
* Methods: ~Animation()
*	InsertFrame()
*   EditFrame()
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



/***************************************************************************
Function Name:  ~Animation()
Purpose:   Calls the destroyer
In parameters:  None
Out parameters: None
Version:   1.0
Author:   Nana Ngassa Franck
****************************************************************************/

Animation::~Animation()
{
	DeleteFrames();
}

/***************************************************************************
Function Name:  InsertFrames()
Purpose:   Into the deque, Insert each frame child and their resolutions
In parameters:  None
Out parameters: None
Version:   1.0
Author:   Nana Ngassa Franck
**************************************************************************/

void Animation::InsertFrame()
{
	string frameName;	       /*FrameName*/
	char resolution[256];      /*Resolution*/
	vector <Attribute> Attributes;  /*vector of resolution(s) for each frame */
	unsigned frameType;
	Frame* frame;

	cout << "Insert a frame in the animation " << endl << "Please Enter frame name ";
	cin >> frameName;
	unsigned int i = 0;

	/* Check if frameName already exist */
	while (i < frames.size()) {	

		if (frames[i]->GetFrameName() == frameName) {
			cout << "Frame already exist " << endl;
			return;
		}
		++i;
	}

	cout << "Please enter the filesize in MB ";
	double size = 0;

	while (!(cin >> size)) {

		cout << "Only numbers please " << endl;
		cout << "Please enter the filesize in MB ? ";
		cin.clear();
		cin.ignore(128, '\n');
	}


	cout << "What type of Frame is it ? Audio Frame(1) or GIF Image Frame(2) ? ";
	cin >> frameType;

	while (frameType != 1 && frameType != 2) {
	
		cout << "Wrong type, 1 and 2 Only. Try Again\n";
		cout << "What type of Frame is it ? Audio Frame(1) or GIF Image Frame(2) ? ";
		cin >> frameType;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}//valid frame type is being inserted ?? 


	if (frameType == 1)
		cout << "How many frequency ranges are associated with this audio Frame ? ";
	else
		cout << "How many screen resolutions are associated with this GIF image Frame? ";

	int displayNum = 0;
	while (!(cin >> displayNum)) {

		cout << "Only numbers please, try again " << endl;
		if (frameType == 1)
			cout << "How many frequency ranges are associated with this audio Frame ? ";
		else
			cout << "How many screen resolutions are associated with this GIF image Frame? ";
		cin.clear();
		cin.ignore(128, '\n');
		/*cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
	}

	int next = 0;
	while (next < displayNum) { // Enter resolutions
		cout << "Please enter the next screen resolution : ";
		cin >> resolution;
		Attribute attribute(resolution);
		Attributes.push_back(attribute);
		++next;
	}

	/*Initialize frame childs and their reolution(s)*/
	if (frameType == 1)
		frame = new AudioFrame(frameName, size, Attributes);
	else
		frame = new ImageFrame(frameName, size, Attributes);
	
	/* First frame in the deque ?*/
	if (frames.size() == 0) {
		frames.push_back(frame);
		cout << "This is the first frame in the deque " << endl;
	}

	else {

		if (frames.size() == 1) {
			cout << "There is 1 Frame in the deque " << endl;
			cout << "Which index do you wish to insert at ? 0 or 1 ";
		}
		else
		{
			/*More then 1 frame in the animation ?*/
			cout << "There are " << frames.size() << " Frame(s) in the dequeue " << endl;
			cout << "Which index do you wish to insert at ? " << "0 and " << frames.size() << " inclusive? ";
		}

		unsigned insertPosition = 0;
		cin >> insertPosition;

		/*Get valid position number to insert frame at */
		while (insertPosition < 0 || insertPosition > frames.size()) {

			cout << "Invalid position, prevent Assertion failure(non-digits) and deque insert iterator outside of range " << endl;
			cout << "Which index do you wish to insert at ? " << "0 to " << frames.size() << "?";
			cin.clear();
			//	cin.ignore(128, '\n');
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> insertPosition;
		}//insertPosition validated
		
		/*Create frames iterator and insert resolution in valid position*/
		deque <Frame*>::iterator iterator = frames.begin();
		frames.insert(iterator + insertPosition, frame);
	}
}


/*********************************************************************
Function Name: EditFrame()
Purpose:   edit each frame child and/or their resoultion 
In parameters:  None
Out parameters: None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void Animation::EditFrame()
{

	string oldF; /*Old frame*/
	string newF; /*New frame*/

	bool found = false;
	int choice;
	char newRes[256];

	cout << "Please enter the name of the frame to edit : ";
	cin >> oldF;

	unsigned i = 0;
	while (i < frames.size()) {

		//find what to edit first
		if (frames[i]->GetFrameName() == oldF) {

			cout << "Found at index " << i << endl;
			cout << "Menu\n";
			cout << " 1. Edit the FrameName \n";
			cout << " 2. Edit an Attribute \n";

			/* Get option from user */
			cin >> choice;

			/*Replace an existing frame*/
			if (choice == 1) {

				cout << "What is the replacement name ? ";
				cin.clear();
				cin >> newF;  /* Get new frameName */

				unsigned int y = 0;

				/*Check if frame already exist*/
				while (y < frames.size()) {
					if (frames[y]->GetFrameName() == newF) {
						cout << "Frame already exist " << endl;
						return;
					}
					++y;

				}//we are at the end of the loop, we did not find duplicate -> edit
				frames[i]->GetFrameName() = newF;
				return;
			}

			/*Replace a resolution at a valid position*/
			else if (choice == 2)
			{
				cout << "maxDisplayIndex =  " << frames.at(i)->size() - 1 << endl;

				int position = 0;
				cout << "What is the attribute index you want to modify ? ";
				cin >> position;

				/*Keep asking for position while not in range*/
				while ((position < 0 || position >= frames.at(i)->size())) {

					cout << "Retry, What is the display index you want to modify : ";

					/*Clear invalid input in buffer and ignore non digits*/
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cin >> position;   /* Get input again */

					
				}//position validated
				cout << "Please give the new attribute value  : " << endl;
				cin >> newRes;				/*If valid get new resolution*/
				Attribute attribute(newRes);	/*initialize the resolution*/
				frames[i]->operator[](position) = attribute;		/*Set the new resolution*/
			}
			else
			{
				return;
			}

		}// End of first if

		 /*At the end of frames and no match found ? */
		if ((i + 1 == frames.size()) && (frames[i]->GetFrameName() != oldF)) {
			cout << "Frame not found " << endl;
			return;
		}
		++i;
	}//End of loop

}//end of edit frames


/*********************************************************************
Function Name:  DeleteFrames()
Purpose:   Destroy the animation
In parameters:  None
Out parameters: None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void Animation::DeleteFrames()
{
	unsigned i = 0;

	if (frames.empty())
	{
		cout << "No frame(s) in the animation " << endl;
		return;
	}

	while (i < frames.size())
		delete frames[i++];

	frames.clear();
	cout << "Delete all the Frames from the Animation" << endl;
}

/*********************************************************************
Function Name:  RunFrames()
Purpose:   Calls the output operator
In parameters:  None
Out parameters:  Animation pointer, *this
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void Animation::RunFrames() {

	cout << *this;
}

/*********************************************************************
Function Name:  operator<<
Purpose:   Output Operator
In parameters:  os, RS
Out parameters: os
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

ostream & operator<<(ostream &os, Animation &RS)

{
	unsigned int counter = 0;
	time_t startsec, oldsec, newsec;
	startsec = oldsec = time(nullptr);

	if (RS.frames.empty())
	{
		os << "No frame(s) to run in the animation" << endl;
	}

	else {

		os << "Run the Animation " << endl << "Animation name is " << RS.animationName << endl;

		while (counter < RS.frames.size()) {

			newsec = time(nullptr);
			if (newsec > oldsec)
			{
				os << "Frame #" << counter << "; time = " << newsec - startsec << ";" << endl;
				os << *(RS.frames[counter++]) << endl;
				oldsec = newsec;
			}
		}
	}
	return os;
}
