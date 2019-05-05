
//Frame.h
#pragma once

class Frame {
	string frameName;
	vector<Display> displays;
public:
	Frame(string f, vector<Display> d) :frameName(f), displays(d) {}
	string& GetFrameName() { return frameName; }
	Display& operator[](int);
	int size() { return displays.size(); }
	friend ostream& operator<<(ostream&, Frame&);
};
