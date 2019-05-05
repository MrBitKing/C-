//Animation.h
#include "Frame.h"
#pragma once

class Animation {
	static const int BLOCK_SIZE = 64;
	char* animationName;
	unsigned int numFrames;
	Frame** frames;
public:
	Animation(char*);
	~Animation();
	void InsertFrame();
	void EditFrame();
	void DeleteFrames();
	void RunFrames();
};
