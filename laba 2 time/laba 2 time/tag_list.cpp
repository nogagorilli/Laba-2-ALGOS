#include "tag_list.h"
#include <iostream>
#include "list_set.h"

void tag_list::append(int i)
{
	El* cur = nullptr;
	cur = new El(i);
	if (first == nullptr) {
		first = cur;
		last = cur;
	}
	else {
		last->next = cur;
		cur->prev = last;
		last = cur;
	}
}

void tag_list::exclude(int val)
{
	El* cur = nullptr;
	for (cur = first; cur != nullptr; cur = cur->next) {
		if (cur->value == val) {
			if (cur->next == nullptr) {
				last = cur->prev;
			}
			else {
				cur->next->prev = cur->prev;
			}
			if (cur->prev == nullptr) {
				first = cur->next;
			}
			else {
				cur->prev->next = cur->next;
			}
			delete cur;
			break;
		}
	}
}

void tag_list::show(std::ostream* file)
{
	El* cur = nullptr;
	*file << "tag list:{";
	for (cur = first; cur != nullptr; cur = cur->next) *file << cur->value << " ";
	*file << "}";
}

tag_list::tag_list()
{
	first = nullptr;
	last = nullptr;
}

tag_list::~tag_list()
{
	El* a;
	El* cur = nullptr;
	for (cur = first; cur != nullptr;) {
		a = cur->next;
		delete cur;
		cur = a;
	}
}

tag_list::El::El(int i)
{
	next = nullptr;
	prev = nullptr;
	value = i;
}

