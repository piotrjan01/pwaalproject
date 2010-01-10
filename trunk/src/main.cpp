//============================================================================
// Name        : SuffixTree.cpp
// Author      : Piotr Gwizda³a
// Version     :
// Copyright   : by Piotr Gwizda³a
// Description : Suffix tree implementation using Ukkonen's online algorithm
//============================================================================

/**
 * This is a main file of a program and it handles all the command-line functionality.
 */

//TODO: Command line obs³uga
//TODO: Reprezentacja graficzna
//TODO: Testy masowe
//TODO: Dokumentacja
//TODO: Z³o¿onoœæ
//TODO: Porównanie testu z teori¹

#include <iostream>
#include <string>
#include <vector>
#include "SuffixTree.h"
#include "debug.h"

using namespace std;

int main() {
	cout << "Hello World!!!" << endl; // prints Hello World!!!
	//string phrase = "mississippimississippimissingsissippissssppimisssimiiiippssimis";
	string phrase = "bananas";
	PRN1("rozpoczêcie budowy drzewa suffix-owego");
	VAR1(phrase);

	SuffixTree st;
	for (unsigned int i=0; i<phrase.length(); i++) st.appendText(phrase.substr(i, 1));

	vector<Node*> v = st.getRoot()->getAllNodes();
	cout<<endl;
	for (unsigned int i=0; i<v.size(); i++) {
		cout<<v[i]->toString()<<endl;
	}

	vector<Edge*> v2 = st.getRoot()->getAllEdges();
	cout<<endl;
	for (unsigned int i=0; i<v2.size(); i++) {
		cout<<v2[i]->toString()<<endl;
	}

	return 0;
}
