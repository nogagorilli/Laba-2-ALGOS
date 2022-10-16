#pragma once
#include "tag_list.h"
#include <fstream>


class Set
{
private:
	static const char universum[];
	static const int max_len;
	static int tag;
	const int own_tag;
	int i, j, counter;
	unsigned int word;
	static std::ofstream* fout;
public:
	static tag_list t_list;

	static void set_fout(std::ofstream*);

	Set(const char str[]);
	Set();
	Set(const Set&);
	~Set();

	void show(std::ostream*);
	Set operator|(const Set&);
	Set operator&(const Set&);
	Set& operator |=(const Set&);
	Set& operator &=(const Set&);
	Set& operator =(const Set&);
};
