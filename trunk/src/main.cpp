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

//TODO: Reprezentacja graficzna
//TODO: Testy masowe
//TODO: Dokumentacja
//TODO: Z³o¿onoœæ
//TODO: Porównanie testu z teori¹

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "suffix/SuffixTree.h"
#include "debug.h"

#define BUFFSIZE 5

using namespace std;

string readAllTextAndMakeTree(bool output, int k);
string readLinesOfTextAndMakeTree(bool output, int k);
void test();
char validateChar(char c);
void printUsage();

int main(int argc, char** argv) {

	if ((argc != 2 && argc !=3) || (argc==3 && string(argv[2]) != "-pt")) {
		printUsage();
		return 1;
	}

	bool printTree = false;
	if (argc==3 && string(argv[2]) == "-pt") printTree = true;

	string line;
	ifstream myfile (argv[1]);

	if (myfile.is_open()) {
		stringstream ss;
		char c;
		int k;
		myfile>>k;
		while (! myfile.eof() && myfile>>c) {
				c = validateChar(c);
				if (c != 0) ss<<c;
		}
		SuffixTree st(ss.str());
		cout<<st.getLongestSubstringWithKRepetitions(k)<<endl;
		if (printTree) cout<<st.toString();
		myfile.close();
		return 0;
	}


	else {
		cout << "Unable to open file: "<<argv[1]<<endl;
		return 1;
	}

	return 0;
}

void printUsage() {
	cout<<"This program finds the longest string with at least k repetitions in input text. "<<endl;
	cout<<"\nUsage: SuffixTree <filename>"<<endl;
	cout<<"\nfilename \tName of the file from which the input will be read. The file should start \n"
			"\t\twith the single line with integer value - the k parameter. The rest of the file should\n"
			"\t\tbe the input text. "<<endl;
	cout<<"\nprogrammed by Piotr Gwizdala"<<endl;
}

string readLinesOfTextAndMakeTree(bool print, int k) {
	string s;
	char c;
	SuffixTree st;
	while (! cin.eof() && cin.get(c)) {
		if (c == '\n') {
			if (s.length() == 0) break;
			st.appendText(s);
			s = "";
		}
		else if ((c = validateChar(c)) != 0) s = s+c;
	}
	st.getLongestSubstringWithKRepetitions(2);
	if (print) return st.toString();
	else return st.getLongestSubstringWithKRepetitions(k);
}

string readAllTextAndMakeTree(bool print, int k) {
	stringstream ss;
	char c;
	while (! cin.eof() && cin>>c) {
		c = validateChar(c);
		if (c != 0) ss<<c;
	}
	SuffixTree st(ss.str());
	if (print) return st.toString();
	else return st.getLongestSubstringWithKRepetitions(k);
}

char validateChar(char c) {
	if ((int)c >= 65 && (int)c <= 90) c = (char)((int)c + 32);
	if ((int)c < 97 || (int)c > 122) return 0;
	return c;
}

void test() {
	cout << "Hello World!!!" << endl; // prints Hello World!!!
	//string phrase = "mississippimississippimissingsissippissssppimisssimiiiippssimis";
	//string phrase = "bananas";
	string phrase = "REMDummyfileforNTVDM";
	//string phrase = "abcxyzABCXYZ";
	PRN1("rozpoczêcie budowy drzewa suffix-owego");
	VAR1(phrase);

	SuffixTree st(phrase);
	//for (unsigned int i=0; i<phrase.length(); i++) st.appendText(phrase.substr(i, 1));

	list<Node*> v = st.getRoot()->getAllNodes();
	cout<<st.toString()<<endl;
}




