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
	// TODO Auto-generated destructor stub
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
	if (isImplicit()) {
		Edge* edge = this->originNode->findEdge(originNode->getCharAt(this->startInd));
		int length = edge->getPhraseLength();
		while (length <= this->getPhraseLength()) {
			this->startInd += length +1;
			this->originNode = edge->endN;
			//is implicit?
			if (this->startInd <= this->endInd) {
				edge = edge->endN->findEdge(this->originNode->getCharAt(this->startInd));
				length = edge->getPhraseLength();
			}
		}
	}
}

string Suffix::toString() {
	stringstream ss;
	ss<<"Suffix: startInd="<<this->startInd<<" endInd="<<this->endInd;
	return ss.str();
}
