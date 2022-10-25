#pragma once
#include "tag_list.h"
#include <iostream>
#include <fstream>

class Set
{
private:
	class El {
	private:
		static const int maxmup;
		static El memory[];
		static int mup;
		static int mup0;
	public:
		El* next;
		El* prev;
		char value;
		El(char);
		El();
		~El();

		static void* operator new(size_t);
		static void operator delete(void*, size_t);
		static void mark();
		static void release();
		static void clear();
		void mem_out();
	};

	El* first;
	El* last;
	const int own_tag;
	static int tag;
	static const char universum[];
	void exclude(El*);
	void clear();
	static std::ofstream* fout;
public:
	static void set_fout(std::ofstream*);
	void append(char);
	void show(std::ostream*);
	Set(const char str[]);
	Set(const Set&);
	Set();
	~Set();
	
	Set operator |(const Set&);
	Set operator &(const Set&);
	Set& operator |=(const Set&);
	Set& operator &=(const Set&);
	Set& operator = (const Set&);
	static tag_list t_list;
};

