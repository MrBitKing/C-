// ass1.cpp

/**********************************************************************
Filename:  Assignment1.c
Version:   1.0
Author:  Nana Ngassa Franck
Student No:   040 783 398
Course Name/Number: C++ CST 8219
Lab Sect:  011
Assignment #: 1
Assignment name: Animatiom Project In C
Due Date:  February 24 2018
Submission Date: September 3 2018**
Professor: Andrew Tyler
Purpose:   Until the user quits with option 4, adds frames to Animations from keyboard with option 1
and delete all frames  with option 2. Then display the frames at 1 second interval with option 3
*********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "Frame.h"
#include "Animation.h"

using namespace std;

int main(void)
{
	char response;
	bool RUNNING = true;
	Animation A("Animation#1");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	while (RUNNING)
	{
		cout << "MENU\n 1. Insert a Frame\n 2. Edit a Frame\n 3. Delete all the Frames\n 4. Run the Animation\n 5. Quit\n";
		cin >> response;
		switch (response)
		{
		case '1':A.InsertFrame(); break;
		case '2':A.EditFrame(); break;
		case '3':A.DeleteFrames(); break;
		case '4':A.RunFrames(); break;
		case '5':RUNNING = false; break;
		default:cout << "Please enter a valid option" << sizeof(double) << endl;
		}
	}
	return 0;
}
