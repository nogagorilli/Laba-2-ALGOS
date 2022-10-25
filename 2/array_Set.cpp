/*#include "array_Set.h"

const char Set::universum[] = "0123456789ABCDEF";
const int Set::max_len = 16;
int Set::tag = 1;
tag_list Set::t_list;
std::ofstream* Set::fout = NULL;



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

Set& Set::operator|=(const Set& other)
{
	int go,i,j;
	int counter = 0;
	char buffer[max_len + 1];
	for (i = 0; universum[i] != 0; i++) {
		go = 1;
		for (j = 0; go && elements[j] != 0; j++) {
			if (elements[j] == universum[i]) {
				buffer[counter++] = universum[i];
				go = 0;
			}
		}
		for (j = 0; go && other.elements[j] != 0; j++) {
			if (other.elements[j] == universum[i]) {
				buffer[counter++] = universum[i];
				go = 0;
			}
		}
	}
	buffer[counter] = 0;
	delete[] elements;
	elements = new char[strlen(buffer) + 1];
	strcpy(elements, buffer);
	return *this;
}

Set& Set::operator=(const Set& other)
{

	if (this != &other) {
		delete[] elements;
		elements = new char[strlen(other.elements) + 1];
		strcpy(elements, other.elements);
	}
	return *this;
}

Set& Set::operator &=(const Set& other)
{
	char buffer[max_len + 1];
	int counter = 0;
	int i, j;
	for (i = 0; other.elements[i] != 0; i++) {
		for (j = 0; elements[j] != 0; j++) {
			if (other.elements[i] == elements[j]) {
				buffer[counter++] = other.elements[i];
				break;
			}
		}
	}
	buffer[counter] = 0;
	delete[] elements;
	elements = new char[strlen(buffer)+1];
	strcpy(elements, buffer);
	return *this;
}

void Set::show(std::ostream* file)
{
	*file << "{" << elements << "}";
}


void Set::set_fout(std::ofstream* file)
{
	fout = file;
}

Set::Set(const char str[]) :own_tag(tag++)
{
	int counter;
	int i, j;
	counter = 0;
	for (i = 0; universum[i] != 0; i++) {
		for (j = 0; str[j] != 0; j++) {
			if (str[j] == universum[i]) {
				counter++;
				break;
			}
		}
	}
	elements = new char[counter + 2];
	counter = 0;
	for (i = 0; universum[i] != 0; i++) {
		for (j = 0; str[j] != 0; j++) {
			if (str[j] == universum[i]) {
				elements[counter++] = universum[i];
				break;
			}
		}
	}
	elements[counter] = 0;


}


Set::Set() :own_tag(tag++)
{
	elements = new char[1];
	elements[0] = 0;
}


Set::Set(const Set& other) :own_tag(tag++)
{


	elements = new char[strlen(other.elements)+1];
	strcpy(elements,other.elements);


}

Set::~Set()
{
	delete[] elements;
}*/
