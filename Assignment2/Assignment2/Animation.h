
//Animation.h
#pragma once

class Animation {
	string animationName;
	deque<Frame*> frames;
public:
	Animation(string name) :animationName(name) {}
	Animation();
	~Animation();
	void InsertFrame();
	void EditFrame();
	void DeleteFrames();
	void RunFrames();
	friend ostream& operator<<(ostream&, Animation&);
};
