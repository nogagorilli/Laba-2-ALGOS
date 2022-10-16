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
	*fout << "CREATING A SET #" << own_tag << " FROM A STRING" << " ";
	t_list.append(tag - 1);
	t_list.show(fout);//adding a new tag
	*fout << std::endl;

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
	*fout << "Set #" << own_tag << ": ";
	show(fout);
	*fout << std::endl;
}

Set::Set() : own_tag(tag++)
{
	*fout << "CREATING A SET #" << own_tag;
	t_list.append(tag - 1);
	t_list.show(fout);//adding a new tag
	*fout << std::endl;

	array = new char[max_len + 1];
	int i;
	for (i = 0; i <= max_len; i++) {
		array[i] = 0;
	}
}

Set::Set(const Set& other) : own_tag(tag++)
{
	*fout << "CREATING A SET #" << own_tag << " BY COPYING FROM A SET #" << other.own_tag << " ";
	t_list.append(tag - 1);
	t_list.show(fout);//adding a new tag
	*fout << std::endl;

	array = new char[max_len + 1];
	int i;
	for (i = 0; i <= max_len; i++) {
		array[i] = other.array[i];
	}

	*fout << "Set #" << own_tag << ": ";
	show(fout);
	*fout << std::endl;
}

Set::~Set()
{
	*fout << "DELETING A SET #" << own_tag << " ";
	t_list.exclude(own_tag);
	t_list.show(fout);//deleting a tag
	*fout << std::endl;

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
	*fout << "EQUALS\n";
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
	*fout << "OR\n";
	Set ret(*this);
	return(ret |= other);
}

Set Set::operator&(const Set& other)
{
	*fout << "AND\n";
	Set ret(*this);
	return(ret &= other);
}
*/