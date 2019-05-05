
//Display.cpp
#pragma once

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#include <iostream>
#include "Display.h"


Display::Display(char *resolution)
{
	this->resolution = new char[strlen(resolution) + 1];
	strcpy(this->resolution, resolution);
}

Display::Display(const Display &RS)
{
	this->resolution = new char[strlen(RS.resolution) + 1];
	strcpy(resolution, RS.resolution);

	//string s(RS.resolution);
	//Display display1(RS.resolution);
	//strcpy(resolution, s);


}

Display & Display::operator=(Display &RS)
{

	// if target memory not big enough 
	//allocate new memory

/*	if (strlen(RS.resolution) > strlen(resolution)) {
		delete[] resolution; // 
		resolution = nullptr;
		resolution = new char[strlen(RS.resolution) + 1];
	}*/

	resolution = new char[strlen(RS.resolution) + 1];
	strcpy(resolution, RS.resolution);
	cout << resolution;  // no print ?
	return *this;
		//return RS;
}

Display::~Display()
{
	cout << "Freeing some displays p\n";
	if (resolution)
		delete[]resolution;
}

ostream & operator<<(ostream &os, Display &RS)
{
	// TODO: insert return statement here
	os << RS.resolution << endl;  //\n ? .resolution ??
//	os << &RS.operator= << endl;  //\n ? .resolution ??

	return os;
}
