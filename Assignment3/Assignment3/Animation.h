//Animation.h
#pragma once

using namespace std;


class Animation {
	string animationName;
	deque<Frame*> frames;
public:
	Animation(string name) :animationName(name) {}
	~Animation();
	void InsertFrame();
	void EditFrame();
	void DeleteFrames();
	void CompressReport()
	{
	for (unsigned int i = 0; i < frames.size(); i++)
			frames[i]->Compress();
	}
	void RunFrames();
	friend ostream& operator<<(ostream&, Animation&);
};