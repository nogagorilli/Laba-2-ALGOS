#include "rand_set.h"
#include <cstdlib>
char universum[] = "0123456789ABCDEF";
const int max_len = 16;

char* random_set()
{
	int i = 0;
	int k = 0;
	char* buffer;
	buffer = new char[max_len + 1];
	for (i = 0; universum[i] != 0; i++) if (rand() % 5 == 0) buffer[k++] = universum[i];
	buffer[k] = 0;
	return buffer;
}
