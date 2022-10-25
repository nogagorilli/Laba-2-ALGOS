#include "tag_list.h"
#include <iostream>
#include "list_set.h"

void tag_list::append(int i)
{
	El* cur = NULL;
	cur = new El(i);
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

void tag_list::exclude(int val)
{
	El* cur = NULL;
	for (cur = first; cur != NULL; cur = cur->next) {
		if (cur->value == val) {
			if (cur->next == NULL) {
				last = cur->prev;
			}
			else {
				cur->next->prev = cur->prev;
			}
			if (cur->prev == NULL) {
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
	El* cur = NULL;
	*file << "tag list:{";
	for (cur = first; cur != NULL; cur = cur->next) *file << cur->value << " ";
	*file << "}";
}

tag_list::tag_list()
{
	first = NULL;
	last = NULL;
}

tag_list::~tag_list()
{
	El* a;
	El* cur = NULL;
	for (cur = first; cur != NULL;) {
		a = cur->next;
		delete cur;
		cur = a;
	}
}

tag_list::El::El(int i)
{
	next = NULL;
	prev = NULL;
	value = i;
}

