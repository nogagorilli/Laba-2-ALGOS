#pragma once
#include <fstream>
#include <iostream>
class tag_list
{
private:
	struct El
	{
		El* next;
		El* prev;
		int value;
		El(int);
	};
	El* first;
	El* last;
public:
	void append(int);
	void exclude(int);
	void show(std::ostream*);
	tag_list();
	~tag_list();
};
