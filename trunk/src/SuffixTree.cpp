/*
 * SuffixTree.cpp
 *
 * Implementacja klasy opisanej w pliku nag³ówkowym
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda³a
 */

#include "SuffixTree.h"
#include "debug.h"

using namespace std;

SuffixTree::SuffixTree(string text) {
	SuffixTree();
	this->appendText(text);
}

SuffixTree::SuffixTree() {
	this->text = "";
	this->nodeCount = 0;
	this->root = new Node(this, NULL);
	this->activePoint = new Suffix(this->root, 0, -1);
}

SuffixTree::~SuffixTree() {
	delete this->root;
}


void SuffixTree::appendText(string t) {
	if (t == "") return;
	int oldTextLength = this->text.length();
	this->text = this->text + t;
	for (unsigned int i=0; i<t.length(); i++) {
			this->addPrefix(oldTextLength+i);
	}
}

void SuffixTree::addPrefix(int endIndex) {
	Node* lastParent = NULL;
	Node* parent = NULL;
	Edge* edge;
	Edge* newEdge;

	while(true) {
		parent = activePoint->originNode;

		if (parent != NULL) CHKSUM(parent->id);

		if (activePoint->isExplicit()) { //jeœli dodawany sufiks koñczy siê na wêŸle jawnym
			//spróbuj znaleŸæ krawêdŸ odpowiadaj¹c¹ nowemu znakowi
			edge = activePoint->originNode->findEdge(this->text[endIndex]);
			//jeœli znaleziona, to wychodzimy z pêtli
			if (edge != NULL) {
				CHKSUM(edge->startInd);
				break;
			}
		}
		else { //punkt aktywny to wêze³ niejawny, czyli sufiks koñczy siê gdzieœ w krawêdzi
			//znajdŸ krawêdŸ, w której siê koñczy
			edge = activePoint->originNode->findEdge(this->text[activePoint->startInd]);
			int length = activePoint->getPhraseLength();
			//jeœli dodajemy znak na koniec krawêdzi, to wyjdŸ z while
			if ( text[edge->startInd + length + 1] == text[endIndex]) {
				CHKSUM(edge->startInd);
				break;
			}
			//jeœli nie, to trzeba podzieliæ krawêdŸ
			parent = edge->split(activePoint);
		}
		//nie znaleziono odpowiedniej krawêdzi, wiêc tworzymy w³asn¹
		newEdge = new Edge(endIndex, INT_MAX, parent);
		//uaktualniamy wskaŸnik na nastêpny krótszy sufiks
		this->updateSuffixNode(lastParent, parent);
		//zapamiêtujemy ostatniego ojca punktu aktywnego
		lastParent = parent;

		//jeœli punkt aktywny jest bezpoœrednio pod korzeniem
		if (activePoint->originNode == this->root)
			activePoint->startInd = activePoint->startInd + 1; //jedynie przesuwamy tekst punktu aktywnego
		//w p.p. idziemy dalej pod¹¿aj¹c za wskaŸnikiem na nastêpny krótszy sufiks
		else activePoint->originNode = activePoint->originNode->suffixNode;
		activePoint->canonize();
	} //while

	//uaktualniamy wskaŸnik na nastêpny krótszy sufiks
	this->updateSuffixNode(lastParent, parent);
	//przesuwamy koniec tekstu punktu aktywnego do przodu
	//(tak na prawdê tego znaku mo¿emy jeszcze nie znaæ).
	activePoint->endInd = activePoint->endInd + 1;
	activePoint->canonize(); //kanonizujemy
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










