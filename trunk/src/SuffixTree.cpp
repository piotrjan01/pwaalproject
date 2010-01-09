/*
 * SuffixTree.cpp
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda�a
 */

#include "SuffixTree.h"
#include "debug.h"

using namespace std;

SuffixTree::SuffixTree(string text) {
	this->nodeCount = 0;
	this->text = text;
	this->root = new Node(this, NULL);
	PRN2("tworzenie suffixu jako pierwszego punktu aktywnego");
	Suffix* activePoint = new Suffix(this->root, 0, -1);
	for (unsigned int i=0; i<text.length(); i++) {
		PRN2("dodawanie prefix�w: ");
		VAR2(text.substr(0, i+1));
		this->addPrefix(activePoint, i);
	}
}

SuffixTree::~SuffixTree() {
	delete this->root;
}

void SuffixTree::addPrefix(Suffix* activePoint, int endIndex) {
	PRN2("in addPrefix");
	Node* lastParent = NULL;
	Node* parent = NULL;
	Edge* edge;
	Edge* newEdge;

	while(true) {
		PRN2("\n\nstarting the while loop");


		parent = activePoint->originNode;

		//Najpierw pr�bujemy znale�� kraw�d� pasuj�c� ju� do zadanego w�z�a
		//Je�li istnieje, mo�emy ju� zako�czy� dodawanie kraw�dzi.
		VAR2(activePoint->startInd);
		VAR2(activePoint->endInd);
		if (activePoint->isExplicit()) {
			PRN2("active point is explicit");
			VAR2(this->text[endIndex]);
			edge = activePoint->originNode->findEdge(this->text[endIndex]);
			if (edge != NULL) {
				PRN2("break bo edge!=null");
//				CHKSUM("s");
				CHKSUM(edge->startInd);
				break;
			}
		}
		else { //punkt aktywny to w�ze� jawny
			PRN2("active point not explicit");
			edge = activePoint->originNode->findEdge(this->text[activePoint->startInd]);
			int length = activePoint->getPhraseLength();
			if ( text[edge->startInd + length + 1] == text[endIndex]) {
				PRN2("break bo znaki w tekst sie zgadzaja");
//				CHKSUM("e");
				CHKSUM(edge->endInd);
				break;
			}
			parent = edge->split(activePoint);
		}

		/**
		 * Je�lni nie znale�li�my odpowiedniej kraw�dzi ju� w drzewie, to musimy
		 * stworzy� now� i doda� j� do drzewa pod w�z�em-ojcem i doda� do hash-tablicy.
		 * Kiedy tworzymy nowy w�ze� oznacza to r�wnie�, ze musimy stworzy� nowy suffix-link
		 * do nowego w�z�a od starego w�z�a kt�ry odwiedzili�my.
		 */

		PRN2("continuing with no good edge found");

		newEdge = new Edge(endIndex, this->text.length() - 1, parent);
//		newEdge->insert();
		this->updateSuffixNode(lastParent, parent);
		lastParent = parent;

		//W ostatnim kroku przesuwamy si� do nast�pnego najmniejszego suffiksu:
		if (activePoint->originNode == this->root)
			activePoint->startInd = activePoint->startInd + 1;
		else activePoint->originNode = activePoint->originNode->suffixNode;
		activePoint->canonize();
	} //while

	PRN2("WYJSCIE z while");
	this->updateSuffixNode(lastParent, parent);
	activePoint->endInd = activePoint->endInd + 1; //teraz punktem ko�cowym jest nast�pny punkt aktywny.
	VAR2(activePoint);
	activePoint->canonize();
	VAR2(activePoint);
}

void SuffixTree::updateSuffixNode(Node* node, Node* suffixNode) {
	if ((node != NULL) && (node != root))
		node->suffixNode = suffixNode;
}

int SuffixTree::getNextId() {
	return nodeCount++;
}

string SuffixTree::toString() {
	stringstream ss;
	//ss<<"Suffix: startInd="<<this->startInd<<" endInd="<<this->endInd;
	return ss.str();
}










