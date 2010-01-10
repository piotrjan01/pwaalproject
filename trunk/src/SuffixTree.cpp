/*
 * SuffixTree.cpp
 *
 * Implementacja klasy opisanej w pliku nag��wkowym
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda�a
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

		if (activePoint->isExplicit()) { //je�li dodawany sufiks ko�czy si� na w�le jawnym
			//spr�buj znale�� kraw�d� odpowiadaj�c� nowemu znakowi
			edge = activePoint->originNode->findEdge(this->text[endIndex]);
			//je�li znaleziona, to wychodzimy z p�tli
			if (edge != NULL) {
				CHKSUM(edge->startInd);
				break;
			}
		}
		else { //punkt aktywny to w�ze� niejawny, czyli sufiks ko�czy si� gdzie� w kraw�dzi
			//znajd� kraw�d�, w kt�rej si� ko�czy
			edge = activePoint->originNode->findEdge(this->text[activePoint->startInd]);
			int length = activePoint->getPhraseLength();
			//je�li dodajemy znak na koniec kraw�dzi, to wyjd� z while
			if ( text[edge->startInd + length + 1] == text[endIndex]) {
				CHKSUM(edge->startInd);
				break;
			}
			//je�li nie, to trzeba podzieli� kraw�d�
			parent = edge->split(activePoint);
		}
		//nie znaleziono odpowiedniej kraw�dzi, wi�c tworzymy w�asn�
		newEdge = new Edge(endIndex, INT_MAX, parent);
		//uaktualniamy wska�nik na nast�pny kr�tszy sufiks
		this->updateSuffixNode(lastParent, parent);
		//zapami�tujemy ostatniego ojca punktu aktywnego
		lastParent = parent;

		//je�li punkt aktywny jest bezpo�rednio pod korzeniem
		if (activePoint->originNode == this->root)
			activePoint->startInd = activePoint->startInd + 1; //jedynie przesuwamy tekst punktu aktywnego
		//w p.p. idziemy dalej pod��aj�c za wska�nikiem na nast�pny kr�tszy sufiks
		else activePoint->originNode = activePoint->originNode->suffixNode;
		activePoint->canonize();
	} //while

	//uaktualniamy wska�nik na nast�pny kr�tszy sufiks
	this->updateSuffixNode(lastParent, parent);
	//przesuwamy koniec tekstu punktu aktywnego do przodu
	//(tak na prawd� tego znaku mo�emy jeszcze nie zna�).
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










