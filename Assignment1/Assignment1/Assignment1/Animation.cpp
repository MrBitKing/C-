
/**********************************************************************
Filename:  Animation.cpp
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
Purpose:   Until the user quits with option 5,
adds frames to Animations from keyboard with option 1,
edit frame with option 2 and delete all frames  with option 3.
Then display the frames at 1 second interval with option 4
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <crtdbg.h> 
#include "Frame.h"
#include <time.h>
#include <iostream>
#include <string>
#include "Animation.h"

using namespace std;

/**********************************************************************
Function Name:  Animation constructor
Purpose:   Initialize the animation
In parameters:  the name of the Animation
Out parameters:  None
Version:   1.0
Author:   Nana Ngassa Franck
**********************************************************************/


	Animation::Animation(char* fileName) {

		// Initialise animation
		animationName = new char[strlen(fileName) + 1];
		strcpy(animationName, fileName);
		numFrames = 0;
		frames = nullptr;
	}

	/**********************************************************************
	Function Name:  Animation destructor
	Purpose:   Destroy the animation and each frame it contains
	In parameters: None
	Out parameters:  None
	Version:   1.0
	Author:   Nana Ngassa Franck
	**********************************************************************/

	Animation::~Animation() {

		delete animationName;
		DeleteFrames();
	}

	/**********************************************************************
	Function Name:  InsertFrame
	Purpose:   Insert each frame, inc frames by 64 if full
	In parameters:  the name of the Animation
	Out parameters:  None
	Version:   1.0
	Author:   Nana Ngassa Franck
	**********************************************************************/

	void Animation::InsertFrame()
	{
		cout << "Insert a Frame In the Animation" << endl;
		cout << "Please enter the frame name: ";
		char frameName[256];

		cin >> frameName;

		//loops trough all frames in animation, print a error 
		//and exit if the frame to be added will result in a duplicate 
		unsigned int i = 0;

		while (i < numFrames) {

			if (strcmp(frames[i]->Report(), frameName) == 0) {
				//if (frames[i++]->FindFileName(frameName)) {
				cout << "Frame name already exist !" << endl;
				return;
			}
			i++;
		}
		//Animation starts with the number of frames to 64
		if (numFrames == 0) {
			frames = new Frame*[BLOCK_SIZE];
		}

		//Increment animation capacity when full of frames.
		else if ((numFrames) % BLOCK_SIZE == 0) {

			// Temp pointer to transfer data over
			Frame **temp = frames;
			unsigned int y = 0;
			//Copy bytes of data to the larger temp

			while (y < numFrames) {
				temp[y++] = frames[y++];//can't use strcpy
			}
			delete[] temp; //delete old pointer
		}





		//Keeps track of the number of blocks
		unsigned int blockcount = (numFrames / BLOCK_SIZE) + 1;
		cout << "Number of blocks " << blockcount << endl;

		//Allocated memory for the frame name 
		frames[numFrames++] = new Frame(frameName);
		//	frames[numFrames++]->ReplaceFrameName(frameName);
			//delete frames[numFrames-1];


	}

	/**********************************************************************
	Function Name:  EditFrame
	Purpose:   Initialize the animation
	In parameters:  the name of the Animation
	Out parameters:  None
	Version:   1.0
	Author:   Nana Ngassa Franck
	**********************************************************************/

	void Animation::EditFrame()
	{
		char oldframe[256];
		char newFrame[256];

		cout << "Enter the Frame filename to edit" << endl;
		cin >> oldframe;
		bool found = false;
		unsigned int i = 0;
		while (i < numFrames) {

			if (frames[i]->FindFileName(oldframe) == true) { //found file name to edit ?

				cout << "What is the replacement name ?";//<< endl;
				cin >> newFrame;

				frames[i]->ReplaceFrameName(newFrame);// Replace with new frame
				found = true; // set true if match was ever found
			}
			i++;
		}
		if (found == false) { // inc i before looping back
			cout << "Frame not found !" << endl;
			return;
		}
	}
	/**********************************************************************
	Function Name:  DeleteFrames
	Purpose:   calls the destroyer
	In parameters:  None
	Out parameters:  None
	Version:   1.0
	Author:   Nana Ngassa Franck
	**********************************************************************/

	void Animation::DeleteFrames()
	{

		cout << "In destructor - ";
		//	if (numFrames > 0) {
		cout << "Deleting all Frame(s) in the Animation \n" << endl;
		for (unsigned int i = 0; i < numFrames; i++) {
			delete frames[i];
		}

		//Free our animation
		delete[] frames;
		numFrames = 0;
		frames = nullptr;
	}
	//	if (numFrames == 0) { // Something to free ?
	//		cout << "Nothing to Free " << endl;
	//	}

	//}

	/**********************************************************************
	Function Name:  RunFrames
	Purpose:   Run each frames in order
	In parameters:  None
	Out parameters:  None
	Version:   1.0
	Author:   Nana Ngassa Franck
	**********************************************************************/

	void Animation::RunFrames()
	{
		unsigned int counter = 0;
		time_t startsec, oldsec, newsec;

		if (numFrames == 0)
		{
			cout << "No frames in the animation" << endl;
			return;
		}
		cout << "Run the Animation " << endl;
		cout << "Animation name is ";
		cout << animationName << endl;

		startsec = oldsec = time(nullptr);

		while (counter < (numFrames))
		{
			newsec = time(nullptr);
			if (newsec > oldsec)
			{
				cout << "Frame #" << counter << ",time = " << newsec - startsec << endl;
				cout << "Image file name " << frames[counter++]->Report() << endl;
				oldsec = newsec;
				//	cout << newsec << endl;
				//	cout << startsec << endl;

			}
		}
	}

