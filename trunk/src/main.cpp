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
#include "SuffixTree.h"
#include "debug.h"

#define BUFFSIZE 5

using namespace std;

string readAllTextAndMakeTree(bool output, int k);
string readLinesOfTextAndMakeTree(bool output, int k);
void test();
char validateChar(char c);
void printUsage();

int main(int argc, char** argv) {

	map<string, bool> argFlags;
	argFlags["--help"] = argFlags["-h"] = argFlags["-pt"] = argFlags["-lbl"] = false;

	if ((argc < 2) || (argFlags["--help"] == true) || (argFlags["-h"] == true)) {
		printUsage();
		return 0;
	}

	int k = atoi(argv[1]);

	for (int i=2; i<argc; i++) {
		string s(argv[i]);
		if (argFlags.count(s) == 0) {
			argFlags["-h"] = true;
			break;
		}
		argFlags[s] = true;
	}


	bool print;
	if (argFlags["-pt"] == true) print = true;
	else print = false;

	string s;
	if (argFlags["-lbl"] == true)
		s = readLinesOfTextAndMakeTree(print, k);
	else s = readAllTextAndMakeTree(print, k);

	cout<<s<<endl;

	return 0;
}

void printUsage() {
	cout<<"This program finds the longest string with at least k repetitions in input text. "<<endl;
	cout<<"After calling the program, it waits for an input. The input depends on options."<<endl<<endl;
	cout<<"Usage: SuffixTree k [-h | --help] [-no] [-lbl]"<<endl;
	cout<<"Options: "<<endl;
	cout<<"\t -h, --help \t Prints this help message."<<endl;
	cout<<"\t -pt \t\t Print tree. Builds the tree and prints it out on screen in reusable form."<<endl;
	cout<<"\t -lbl \t\t Line by line input mode. The input is read line by line until given EOF or empty line."<<endl;
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
	string s;
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




