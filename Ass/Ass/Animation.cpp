
/**********************************************************************
Filename:  Animation.cpp
Version:   1.0
Author:  Nana Ngassa Franck
Student No:   040 783 398
Course Name/Number: C++ CST 8219
Lab Sect:  011
Assignment #: 2
Assignment name: Animatiom Project In C++
Due Date:  March 24 2018
Submission Date: March 24 2018
Professor: Andrew Tyler
Purpose:  I9nsert, edit and run frames
*********************************************************************/

#pragma once


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
Function Name:  ~Animation()
Purpose:   Destroy the animation
In parameters:  None
Out parameters: None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/


Animation::~Animation()
{
	DeleteFrames();
}

/*********************************************************************
Function Name:  InsertFrame
Purpose:   Insert frame(s) in the deque and resolution(s) into vector
In parameters:  None
Out parameters:  void
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void Animation::InsertFrame()
{
	string frameName;	       /*FrameName*/
	char resolution[256];      /*Resolution*/
	vector<Display> displays;  /*vector of resolution(s) for each frame */

	cout <<"Insert a frame in the animation " << endl <<"Please Enter frame name ";
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

	cout << "How many displays are in this Frame ? ";

	int displayNum = 0;
	/* Valid digit entered ? Not rewuired for this assignment*/
	while (!(cin >> displayNum)) {

		cout << "Only numbers please " << endl;
		cout << "How many displays are in this Frame ? ";
		cin.clear();
		cin.ignore(128, '\n');
		/*cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
	}

	int next = 0;
	while (next < displayNum) {
		cout << "Please enter the screen resolution of the next display :";
		cin >> resolution;
		Display display(resolution);
		displays.push_back(display);
		++next;
	}

	/*Initialize each frame and their reolution(s)*/
	Frame* frame = new Frame(frameName, displays);

	/* First frame in the deque ?*/
	if (frames.size() == 0) {
		frames.push_back(frame);
		cout << "This is the first frame in the deque "<< endl;
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
			cout << "Which index do you wish to insert at ? " << "0 to " << frames.size() << "? ";
		}

		unsigned insertPosition = 0;
		cin >> insertPosition;

		/*Get valid position number to insert frame at */
		while (insertPosition < 0 || insertPosition > frames.size()) {

		//	if ((insertPosition < 0 || insertPosition > frames.size())) {
				cout << "Invalid position, prevent Assertion failure(non-digits) and deque insert iterator outside of range " << endl;
				cout << "Which index do you wish to insert at ? " << "0 to " << frames.size() << "?";
				cin.clear();
			//	cin.ignore(128, '\n');
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cin >> insertPosition;
		//	}
		}

		/*Create frames iterator and insert resolution in valid position*/
		deque <Frame*>::iterator iterator = frames.begin();
		frames.insert(iterator + insertPosition, frame);
	}
}

/*********************************************************************
Function Name:  EditFrame
Purpose:   Delete frame if found and or it's reslution
In parameters:  None
Out parameters:  void
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void Animation::EditFrame()
{
	string oldF; /*Old frame*/
	string newF; /*New frame*/

	int choice;
	char newRes[256];


	cout << "Please enter the name of the frame to edit : ";
	cin >> oldF;

	unsigned int i = 0;
	while (i < frames.size()) {

		if (frames[i]->GetFrameName() == oldF) {

			cout << "Found at index " << i << endl;
			cout << "Menu\n";
			cout << " 1. Enter frame to edit \n";
			cout << " 2. Edit a display resolution \n";

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
				cout << "What is the display index you want to modify ? ";
				cin >> position;

				/*Keep asking for position while not in range*/
				while ((position < 0 || position >= frames.at(i)->size())) {
				//	if ((position < 0 || position >= frames.at(i)->size())) {

						cout << "Retry, What is the display index you want to modify : ";

						/*Clear invalid input in buffer and ignore non digits*/
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						cin >> position;   /* Get input again */
				//	}

				}
				cout << "Please give the new resolution of the display : "<< endl;
				cin >> newRes;				/*If valid get new resolution*/
				Display display(newRes);	/*initialize the resolution*/
				frames[i]->operator[](position) = display;		/*Set the new resolution*/
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
	}//End of first loop;
}

/*********************************************************************
Function Name:  DeleteFrames
Purpose:   Delete each frame of the animation in order
In parameters:  None
Out parameters:  void
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void Animation::DeleteFrames()
{
	unsigned i = 0;

	if (frames.size() == 0) {
		cout << "No frame to erase " << endl;
		return;
	}
	while (i < frames.size()) {
		delete frames[i++];
	}
	cout << "Delete all the Frame(s) from the animation " << endl;
	frames.clear();
}

/*********************************************************************
Function Name:  RunFrames
Purpose:   Run each frames in order
In parameters:  A pointer to Animation
Out parameters:  void
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/

void Animation::RunFrames()
{
	cout << *this;
}


/*********************************************************************
Function Name:  operator<<
Purpose:   Extraction operator (Not used)
In parameters:  &os, &RS
Out parameters:  void
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
		os << "No frame(s) in the animation" << endl;
		//return o;
	}

	os << "Run the Animation " << endl << "Animation name is " << RS.animationName << endl;

	while (counter < RS.frames.size()) {

		newsec = time(nullptr);
		if (newsec > oldsec)
		{
			os << "Frame #" << counter << "; time = " << newsec - startsec << ";" << endl;
			os << (RS.frames[counter++]) << endl;
			oldsec = newsec;
		}
	}
	return os;

}


