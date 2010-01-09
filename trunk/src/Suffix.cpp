/*
 * Suffix.cpp
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda³a
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
	if (this->isExplicit()) return; //gdy ju¿ jest skanonizowany - wychodzimy
	//znajdŸ krawêdŸ w której kierunku nale¿y pójœæ i d³ugoœæ jej tekstu
	Edge* edge = this->originNode->findEdge(originNode->getCharAt(this->startInd));
	int length = edge->getPhraseLength();
	//dopóki tekst danej krawêdzi jest krótszy od tekstu suffiksu (czyli suffiks nie koñczy siê na krawêdzi)
	while (length <= this->getPhraseLength()) {
		this->startInd += length +1; //skróæ sufiks o krawêdŸ i 1 znak
		this->originNode = edge->endN; //przenieœæ pocz¹tek sufiksu na koniec krawêdzi
		if (this->startInd <= this->endInd) { //jeœli pozosta³ jeszcze jakiœ tekst sufiksu
			//WeŸ nastêpn¹ krawêdŸ i jej d³ugoœæ
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











