/*#include "word_set.h"
#include <iostream>

const char Set::universum[] = "0123456789ABCDEF";
int Set::tag = 1;
tag_list Set::t_list;
std::ofstream* Set::fout = NULL;

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

    word = 0;
    for (i = 0; universum[i] != 0; i++) {
        for (j = 0; str[j] != 0; j++) {
            if (str[j] == universum[i]) {
                word = word | (1 << i);
                break;
            }
        }
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
    word = 0;
}

Set::Set(const Set& other) : own_tag(tag++)
{
    *fout << "CREATING A SET #" << own_tag << " BY COPYING FROM A SET #" << other.own_tag << " ";
    t_list.append(tag - 1);
    t_list.show(fout);//adding a new tag
    *fout << std::endl;
    word = other.word;
}

Set::~Set()
{
    *fout << "DELETING A SET #" << own_tag << " ";
    t_list.exclude(own_tag);
    t_list.show(fout);//deleting a tag
    *fout << std::endl;
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
    *fout << "OR\n";
    Set ret(*this);
    return (ret |= other);
}

Set Set::operator&(const Set& other)
{
    *fout << "AND\n";
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
    *fout << "EQUALS\n";
    word = other.word;
    return *this;
}
*/
