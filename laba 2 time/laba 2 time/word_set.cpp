/*#include "word_set.h"
#include <iostream>

const char Set::universum[] = "0123456789ABCDEF";
int Set::tag = 1;
tag_list Set::t_list;
std::ofstream* Set::fout = nullptr;

void Set::set_fout(std::ofstream* file)
{
    fout = file;
}

Set::Set(const char str[]) :own_tag(tag++)
{


    word = 0;
    for (i = 0; universum[i] != 0; i++) {
        for (j = 0; str[j] != 0; j++) {
            if (str[j] == universum[i]) {
                word = word | (1 << i);
                break;
            }
        }
    }


}

Set::Set() : own_tag(tag++)
{

    word = 0;
}

Set::Set(const Set& other) : own_tag(tag++)
{

    word = other.word;
}

Set::~Set()
{
}

void Set::show(std::ostream* file)
{
    *file << "{";
    for (i = 0; universum[i] != 0; i++) {
        if ((word & (1 << i)) != 0) * file << universum[i];
    }
    *file << "}";
}

Set Set::operator|(const Set& other)
{

    Set ret(*this);
    return (ret |= other);
}

Set Set::operator&(const Set& other)
{

    Set ret(*this);
    return (ret&= other);
}

Set& Set::operator|=(const Set& other)
{
    word = word | other.word;
    return *this;
}

Set& Set::operator&=(const Set& other)
{
    word = word & other.word;
    return *this;
}

Set& Set::operator=(const Set& other)
{

    word = other.word;
    return *this;
}
*/