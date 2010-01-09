/*
 * Edge.cpp
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda�a
 */

#include "Edge.h"
#include "debug.h"
#include <sstream>

Edge::Edge(int startIndex, int endIndex, Node *startNode) {
	this->startInd = startIndex;
	this->endInd = endIndex;
	this->startN = startNode;
	this->endN = new Node(startNode->st, NULL);
}

Edge::~Edge() {}


Node* Edge::split(Suffix *s) {
	//usuni�cie kraw�dzi z w�z�a-ojca
	this->remove();
	//TODO: ?
	//utworzenie nowej kraw�dzi zgodnie z dodawanym sufiksem
	Edge* ne = new Edge(this->startInd, this->startInd + s->getPhraseLength(), s->originNode);
	//dodanie nowej kraw�dzi do jej w�z�a-ojca
	ne->insert();
	//TODO: ?
	ne->endN->suffixNode = s->originNode;
	//wyd�u�enie zasi�gu tej kraw�dzi o now� liter�
	this->startInd += s->getPhraseLength() + 1;
	//podpi�cie tej kraw�dzi do nowopowsta�ej kraw�dzi
	this->startN = ne->endN;
	this->insert();
	return ne->endN;
}


void Edge::insert() {
	//PRN2("Inserting the edge to its parent node");
	this->startN->addEdge(this->startInd, this);
}


void Edge::remove() {
	this->startN->removeEdge(this->startInd);
}

int Edge::getPhraseLength() {
	return this->endInd - this->startInd;
}

string Edge::toString() {
	stringstream ss;
	ss<<"Edge: startInd="<<this->startInd<<" endInd="<<this->endInd;
	return ss.str();
}






