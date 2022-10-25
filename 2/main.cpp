#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "rand_set.h"

#define LIST

#ifdef LIST
#include "array_Set.h"
#endif

#ifdef BYTE 
#include "byte_set.h"
#endif

#ifdef WORD 
#include "word_set.h"
#endif

#ifdef LIST 
#include "list_set.h"
#endif
using namespace std;
const int max_len = 16;

int main()
{
	int iter;
	char str[80];
	char* buffer;
	int gen = 0;
	int i;
	time_t t1,t2;
	ofstream fout("OUTPUT.txt");
	Set::set_fout(&fout);
	srand(time(0));


	cout << "1 - Enter sets\n2 - generate sets\nYOUR answer: ";
	cin >> gen;


	if (gen == 1) {
		cout << "Enter set A: ";
		cin >> str;
		buffer = new char[strlen(str) + 1];
		strcpy(buffer, str);
	}
	else buffer = random_set();

	Set a(buffer);

	cout << endl;
	delete[] buffer;

	if (gen == 1) {
		cout << "Enter set B: ";
		cin >> str;
		buffer = new char[strlen(str) + 1];
		strcpy(buffer, str);
	}
	else buffer = random_set();
	Set b(buffer);

	cout << endl;
	delete[] buffer;

	if (gen == 1) {
		cout << "Enter set C: ";
		cin >> str;
		buffer = new char[strlen(str) + 1];
		strcpy(buffer, str);
	}
	else buffer = random_set();
	Set c(buffer);

	cout << endl;
	delete[] buffer;

	if (gen == 1) {
		cout << "Enter set D: ";
		cin >> str;
		buffer = new char[strlen(str) + 1];
		strcpy(buffer, str);
	}
	else buffer = random_set();
	Set d(buffer);

	cout << endl;
	delete[] buffer;

	

	

	cout << "Set A: ";
	a.show(&std::cout);
	cout << "\n";
	cout << "Set B: ";
	b.show(&cout);
	cout << "\n";
	cout << "Set C: ";
	c.show(&cout);
	cout << "\n";
	cout << "Set D: ";
	d.show(&cout);
	cout << "\n";

	cout << "Number of iterations: ";
	cin >> iter;
	if (iter <= 0) iter = 1;
	
	Set e;
	t1 = clock();
	#ifdef LIST
		Set::mark();
	#endif
	for (i = 0; i < iter; i++) { 
		e = a | b | c | d; 
	#ifdef LIST
		Set::release();
	#endif
	}
	t2 = clock();

	cout << "Resulting set:";
	e.show(&cout);
	cout << "\n";

	cout << "Program has spent " << t2-t1 << " ticks doing " << iter << " iterations\n";

	return 0;
}
