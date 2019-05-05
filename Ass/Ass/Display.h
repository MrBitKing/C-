
//Display.h
#pragma once

class Display
{
	char* resolution;
public:
	Display(char*);
	Display(const Display&);
	Display& operator=(Display&);
	~Display();
	friend ostream& operator<<(ostream&, Display&);
};
