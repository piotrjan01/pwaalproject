//============================================================================
// Name        : SuffixTree.cpp
// Author      : Piotr Gwizda�a
// Version     :
// Copyright   : by Piotr Gwizda�a
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "SuffixTree.h"
#include "debug.h"

using namespace std;

int main() {
	cout << "Hello World!!!" << endl; // prints Hello World!!!
	//string phrase = "mississippimississippimissingsissippissssppimisssimiiiippssimis";
	string phrase = "bananas";
	PRN1("rozpocz�cie budowy drzewa suffix-owego");
	VAR1(phrase);
	SuffixTree st(phrase);

	return 0;
}
