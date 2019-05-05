//Frame.h
#pragma once

class Frame {
	char* frameName;
public:
	Frame(char*);
	~Frame();
	bool FindFileName(char*);
	void ReplaceFrameName(char*);
	char* Report();
};