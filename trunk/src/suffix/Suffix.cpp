/*
 * Suffix.cpp
 *
 * Implementacja klasy opisanej w pliku nag��wkowym
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda�a
 */

#include "Suffix.h"
#include <sstream>

Suffix::Suffix(Node* originNode, int startIndex, int endIndex) {
	this->originNode = originNode;
	this->startInd = startIndex;
	this->endInd = endIndex;
}

Suffix::~Suffix() {
	delete this->originNode;
}

int Suffix::getPhraseLength() {
	return this->endInd - this->startInd;
}

bool Suffix::isExplicit() {
	return (this->startInd > this->endInd);
}

bool Suffix::isImplicit() {
	return !isExplicit();
}

void Suffix::canonize() {
	if (this->isExplicit()) return; //gdy ju� jest skanonizowany - wychodzimy
	PRN2("\n\nin canonize");
	//znajd� kraw�d� w kt�rej kierunku nale�y p�j�� i d�ugo�� jej tekstu
	VAR2(this->startInd);
	VAR2(originNode->getCharAt(this->startInd));
	Edge* edge = this->originNode->findEdge(originNode->getCharAt(this->startInd));
	VAR2(edge);
	VAR2((int)edge);
	VAR2((int)this->originNode);
	VAR2((int)this->originNode->nodeEdges.size());
	int length = edge->getPhraseLength();
	//dop�ki tekst danej kraw�dzi jest kr�tszy od tekstu suffiksu (czyli suffiks nie ko�czy si� na kraw�dzi)
	VAR2(length);
	while (length <= this->getPhraseLength()) {
		this->startInd += length +1; //skr�� sufiks o kraw�d� i 1 znak
		VAR2(this->startInd);
		this->originNode = edge->endN; //przenie�� pocz�tek sufiksu na koniec kraw�dzi
		if (this->startInd <= this->endInd) { //je�li pozosta� jeszcze jaki� tekst sufiksu
			//We� nast�pn� kraw�d� i jej d�ugo��
			edge = edge->endN->findEdge(this->originNode->getCharAt(this->startInd));
			length = edge->getPhraseLength();
			PRN2("new length");
			VAR2(length);
		}
	}
	PRN2("END canonize\n");
}

string Suffix::toString() {
	stringstream ss;
	ss<<"Suffix: startInd="<<this->startInd<<" endInd="<<this->endInd;
	return ss.str();
}











