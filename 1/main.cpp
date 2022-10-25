#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "rand_set.h"

//#include "array_Set.h"
//#include "byte_set.h"
//#include "word_set.h"
#include "list_set.h"

using namespace std;
const int max_len = 16;

int main()
{
	char str[80];
	char* buffer;
	int gen = 0;
	ofstream fout("OUTPUT.txt");
	Set::set_fout(&fout);
	srand(time(0));


	cout << "1 - Enter sets\n2 - generate sets\nYOUR answer: ";
	cin >> gen;


	if (gen == 1) {
		cout << "Enter set A: ";
		cin >> str;
		buffer = new char[strlen(str) + 1];
		
		strcpy(buffer,str);
	}
	else buffer = random_set();

	Set a(buffer);

	cout << endl;
	delete[] buffer;

	if (gen == 1) {
		cout << "Enter set B: ";
		cin >> str;
		buffer = new char[strlen(str) + 1];
		strcpy(buffer,str);
	}
	else buffer = random_set();
	Set b(buffer);

	cout << endl;
	delete[] buffer;

	if (gen == 1) {
		cout << "Enter set C: ";
		cin >> str;
		buffer = new char[strlen(str) + 1];
		strcpy(buffer,str);
	}
	else buffer = random_set();
	Set c(buffer);

	cout << endl;
	delete[] buffer;

	if (gen == 1) {
		cout << "Enter set D: ";
		cin >> str;
		buffer = new char[strlen(str) + 1];
		strcpy(buffer,str);
	}
	else buffer = random_set();
	Set d(buffer);

	cout << endl;
	delete[] buffer;

	Set e;
	e = a | b | c | d;
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
	cout << "Resulting set:";
	e.show(&cout);
	cout << "\n";

	return 0;
}
