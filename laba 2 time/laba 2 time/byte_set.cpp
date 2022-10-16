/*#include "byte_set.h"
#include <iostream>

int Set::tag = 1;
tag_list Set::t_list;
const int Set::max_len = 16;

const char Set::universum[] = "0123456789ABCDEF";

std::ofstream* Set::fout = nullptr;

void Set::set_fout(std::ofstream* file)
{
	fout = file;
}

Set::Set(const char str[]) :own_tag(tag++)
{


	array = new char[max_len + 1];
	int i, j;
	for (i = 0; universum[i] != 0; i++) {
		int go = 1;
		for (j = 0; str[j] != 0; j++) {
			if (str[j] == universum[i]) {
				array[i] = 1;
				go = 0;
				break;
			}
		}
		if (go) array[i] = 0;
	}

}

Set::Set() : own_tag(tag++)
{


	array = new char[max_len + 1];
	int i;
	for (i = 0; i <= max_len; i++) {
		array[i] = 0;
	}
}

Set::Set(const Set& other) : own_tag(tag++)
{

	array = new char[max_len + 1];
	int i;
	for (i = 0; i <= max_len; i++) {
		array[i] = other.array[i];
	}


}

Set::~Set()
{
	delete[] array;
}

void Set::show(std::ostream* file)
{
	int i;
	*file << "{";
	for (i = 0; universum[i] != 0; i++) {
		if (array[i]) *file << universum[i];
	}
	*file << "}";
}

Set& Set::operator |=(const Set& other)
{
	int i;
	for (i = 0; i <= max_len; i++) {
		if (array[i] | other.array[i]) array[i] = 1;
	}
	return *this;
}

Set& Set::operator &=(const Set& other)
{
	int i;
	for (i = 0; i <= max_len; i++) {
		if (array[i] & other.array[i]) array[i] = 1;
	}
	return *this;
}

Set& Set::operator =(const Set& other)
{
	int i;
	if (this != &other) {
		for (i = 0; i <= max_len; i++) {
			array[i] = other.array[i];
		}
	}
	return *this;
}

Set Set::operator|(const Set& other)
{
	Set ret(*this);
	return(ret |= other);
}

Set Set::operator&(const Set& other)
{
	Set ret(*this);
	return(ret &= other);
}
*/