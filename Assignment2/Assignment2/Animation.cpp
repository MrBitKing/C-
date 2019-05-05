
#pragma once

using namespace std;
#include <ostream>

#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include "Display.h"
#include "Frame.h"
#include "Animation.h"


Animation::Animation()
{
	animationName = nullptr;
}

Animation::~Animation()
{
	DeleteFrames();
}

void Animation::InsertFrame()
{
	string frameName;
	char resolution[256];
	vector<Display> Display1;

	cout << "Enter frame name LOLA" << endl;
	cin.clear();
	cin >> frameName;
	unsigned int i = 0;

	while (i < frames.size()) {

		if (frames[i]->GetFrameName() == frameName) {
			cout << "Frame already exist " << endl;
			return;
		}
		++i;
	}

	cout << "How many displays are in this Frame ? ";
	int displayNum = 0;

	while (!(cin >> displayNum)) {
		cout << "Only numbers please " << endl;
		cout << "How many displays are in this Frame ? ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	int z = 0;
	while (z < displayNum) {
		cout << "please enter the screen resolution of the next display :";
		cin >> resolution;
		Display display(resolution);
		//Display1.operator=(resolution);
		Display1.push_back(display);
		++z;
	}

	Frame* frame = new Frame(frameName, Display1);
	frames.push_back(frame);
}

void Animation::EditFrame()
{
	string oldF;
	string newF;

	int input;
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

			cin.clear();
			cin >> input;

			if (input == 1) {    //switch(input)

				cout << "What is the replacement name ? ";
				cin.clear();
				cin >> newF;

				unsigned int y = 0;
				while (y < frames.size()) {
					if (frames[y]->GetFrameName() == newF) {
						cout << "Frame already exist " << endl;
						return;
					}
					++y;

				}//		w	e are at the end of the loop, we did not find it
				frames[i]->GetFrameName() = newF;
				return;
			}
			else if (input == 2)
			{
				cout << "maxDisplayIndex =  " << frames.at(i)->size() - 1 << endl;
				int position;
				//
				cout << "What is the index of the resolution you want to modify : ";
				cin >> position;

				while ((position < 0 || (position) >= frames.at(i)->size()) == 0) {
					if (position < 0 || (position) >= frames.at(i)->size()) {
						cout << "What is the index of the resolution you want to modify : ";
						cin.clear();
						cin >> position;
					}
				}
				cout << "Enter the new resolution ";
				Display display(newRes);
				//	frames[i]->operator[](position) = display;
				frames.at(i)->operator[](position) = Display(display);
			}
			else
			{
				return;
			}
		}
		if ((i + 1 == frames.size()) && (frames[i]->GetFrameName() != oldF)) {
			cout << "Frame not found " << endl;
			return;
		}
		++i;
	}
}

void Animation::DeleteFrames()
{
	unsigned i = 0;

	if (frames.size() == 0) {
		cout << "No frame to erase " << endl;
		return;
	}
	while (i < frames.size()) {
		cout << "Erasing frame(s) " << i << endl;
		delete frames[i++];
	}
	frames.clear();
}

void Animation::RunFrames()
{
	unsigned int counter = 0;
	time_t startsec, oldsec, newsec;
	startsec = oldsec = time(nullptr);

	if (frames.empty())
	{
		cout << "No frames in the animation" << endl;
		return;
	}

	cout << "Run the Animation " << endl;
	cout << "Animation name is ";
	cout << animationName << endl;


	while (counter < frames.size()) {

		newsec = time(nullptr);
		if (newsec > oldsec)
		{
			cout << "Frame #" << counter << ", time = " << newsec - startsec << endl;
			cout << "FrameName " << frames[counter]->GetFrameName() << endl; //frames[counter]->GetFrameName() << endl;

			if (counter == 0) {
				cout << "this is the first frame in the deque" << endl;
			}
			int counter2 = 0;

			while (counter2 < frames[counter]->size()) {
				cout << "\tDisplay # " << counter2 << frames[counter]->operator[](counter2);
				++counter2;
			}
			++counter;
			oldsec = newsec;

		}
	}



}
ostream & operator<<(ostream &os, Animation &RS)
{
	// TODO: insert return statement here
	//	os << RS.animationName << endl;  // RS.animationName 
	unsigned i = 0;
	while (i < RS.frames.size())
		os << "Frame # lolalal " << i << " FrameName " << RS.frames[i] << endl;
	return os;
}


