/*
 * Suffix.cpp
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
	//znajd� kraw�d� w kt�rej kierunku nale�y p�j�� i d�ugo�� jej tekstu
	Edge* edge = this->originNode->findEdge(originNode->getCharAt(this->startInd));
	int length = edge->getPhraseLength();
	//dop�ki tekst danej kraw�dzi jest kr�tszy od tekstu suffiksu (czyli suffiks nie ko�czy si� na kraw�dzi)
	while (length <= this->getPhraseLength()) {
		this->startInd += length +1; //skr�� sufiks o kraw�d� i 1 znak
		this->originNode = edge->endN; //przenie�� pocz�tek sufiksu na koniec kraw�dzi
		if (this->startInd <= this->endInd) { //je�li pozosta� jeszcze jaki� tekst sufiksu
			//We� nast�pn� kraw�d� i jej d�ugo��
			edge = edge->endN->findEdge(this->originNode->getCharAt(this->startInd));
			length = edge->getPhraseLength();
		}
	}
}

string Suffix::toString() {
	stringstream ss;
	ss<<"Suffix: startInd="<<this->startInd<<" endInd="<<this->endInd;
	return ss.str();
}











