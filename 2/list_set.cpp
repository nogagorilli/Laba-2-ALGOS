#include "list_set.h"
const char Set::universum[] = "0123456789ABCDEF";
int Set::tag = 1;
tag_list Set::t_list;
const int Set::El::maxmup = 10000;
Set::El Set::El::memory[maxmup];
int Set::El::mup = 0;
int Set::El::mup0 = 0;
std::ofstream* Set::fout = NULL;

Set::El::El(char val) {
	prev = NULL;
	next = NULL;
	value = val;
}

Set::El::El() :next(NULL), prev(NULL), value('!')
{
}

Set::El::~El() {

}

void* Set::El::operator new(size_t)
{

	void* ret = NULL;
	if (mup < maxmup) {
		ret = &memory[mup++];
	}

	return ret;
}

void Set::El::operator delete(void*, size_t)
{
}

void Set::El::mark()
{
	mup0 = mup;
}

void Set::El::release()
{
	mup = mup0;
}

void Set::El::clear()
{
	mup = 0;
}

void Set::El::mem_out()
{
	std::cout << "Current memory: " << mup << std::endl;
}

void Set::set_fout(std::ofstream* file)
{
	fout = file;
}

void Set::append(char value)
{
	El* cur;
	cur = new El(value);
	if (first == NULL) {
		first = cur;
		last = cur;
	}
	else {
		last->next = cur;
		cur->prev = last;
		last = cur;
	}

}

void Set::show(std::ostream* file)
{
	int i;
	El* cur;
	*file << "{";
	for (i = 0; universum[i] != 0; i++) {
		for (cur = first; cur != NULL; cur = cur->next) {
			if (universum[i] == cur->value) {
				*file << universum[i];
				break;
			}
		}
	}
	*file << "}";
}

void Set::exclude(El* elem)
{
	if (elem->next == NULL) {
		last = elem->prev;
	}
	else {
		elem->next->prev = elem->prev;
	}
	if (elem->prev == NULL) {
		first = elem->next;
	}
	else {
		elem->prev->next = elem->next;
	}

	delete elem;
}

void Set::clear()
{
	El* oth;
	El* cur;
	for (cur = first; cur != NULL;) {
		oth = cur->next;
		delete cur;
		cur = oth;
	}
	first = NULL;
	last = NULL;
}

void Set::mark()
{
	Set::El::mark();
}

void Set::release()
{
	Set::El::release();
}

Set::Set(const char str[]) :own_tag(tag++)
{

	El* cur;
	first = NULL;
	last = NULL;
	cur = NULL;
	int i;
	int j;
	for (i = 0; universum[i] != 0; i++) {
		for (j = 0; str[j] != 0; j++) {
			if (universum[i] == str[j]) {
				append(universum[i]);
				break;
			}
		}
	}

}

Set::Set(const Set& other) :own_tag(tag++)
{
	El* cur;
	first = NULL;
	last = NULL;
	for (cur = other.first; cur != NULL; cur = cur->next) {
		append(cur->value);
	}
}

Set::Set() :own_tag(tag++)
{

	first = NULL;
	last = NULL;
}

Set::~Set()
{

	El* cur;
	for (; first != NULL;) {
		cur = first->next;
		delete first;
		first = cur;
	}
	first = NULL;
	last = NULL;
}

Set Set::operator|(const Set& other)
{
	Set ret(*this);

	ret |= other;

	return ret;
}

Set Set::operator&(const Set& other)
{
	Set ret(*this);
	ret &= other;
	return ret;
}

Set& Set::operator|=(const Set& other)
{
	El* cur;
	El* oth;
	int go = 1;
	if (this != &other) {
		for (oth = other.first; oth != NULL; oth = oth->next) {
			go = 1;
			for (cur = first; cur != NULL; cur = cur->next) {
				if (oth->value == cur->value) {
					go = 0;
					break;
				}
			}
			if (go) append(oth->value);
		}
	}
	return *this;

}

Set& Set::operator&=(const Set& other)
{
	int go;
	El* cur;
	El* oth;
	if (this != &other) {
		for (cur = first; cur != NULL;) {
			go = 1;
			for (oth = other.first; oth != NULL; oth = oth->next) {
				if (oth->value == cur->value) {
					go = 0;
					break;
				}
			}
			oth = cur->next;
			if (go) exclude(cur);
			cur = oth;
		}
	}
	return *this;
}

Set& Set::operator=(const Set& other)
{
	El* oth;
	if (this != &other) {
		clear();
		for (oth = other.first; oth != NULL; oth = oth->next) {
			append(oth->value);
		}
	}
	return *this;
}

