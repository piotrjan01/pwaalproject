/*
 * Edge.cpp
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
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
	//usuniêcie krawêdzi z wêz³a-ojca
	this->remove();
	//TODO: ?
	//utworzenie nowej krawêdzi zgodnie z dodawanym sufiksem
	Edge* ne = new Edge(this->startInd, this->startInd + s->getPhraseLength(), s->originNode);
	//dodanie nowej krawêdzi do jej wêz³a-ojca
	ne->insert();
	//TODO: ?
	ne->endN->suffixNode = s->originNode;
	//wyd³u¿enie zasiêgu tej krawêdzi o now¹ literê
	this->startInd += s->getPhraseLength() + 1;
	//podpiêcie tej krawêdzi do nowopowsta³ej krawêdzi
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






