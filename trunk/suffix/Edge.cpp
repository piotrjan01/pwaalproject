/*
 * Edge.cpp
 *
 * Implementacja klasy opisanej w pliku nag³ówkowym
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
 */

#include "Edge.h"
#include <sstream>

Edge::Edge(int startIndex, int endIndex, Node *startNode) {
	this->startInd = startIndex;
	this->endInd = endIndex;
	this->startN = startNode;
	this->endN = new Node(startNode->tree, NULL, this);
	this->insertToParentEdgeList();
}

Edge::~Edge() {

}


Node* Edge::split(Suffix *s) {
	//usuniêcie tej krawêdzi z wêz³a-ojca
	this->removeFromParentEdgeList();
	//utworzenie nowej krawêdzi zgodnie z dodawanym sufiksem (niejawnie powstaje nowy wêze³ - liœæ)
        Edge* ne = new Edge(this->startInd, this->startInd + s->getPhraseLength(), s->originNode);
	//ustawienie wskaŸnika na nastêpny mniejszy sufiks w drzewie
	ne->endN->suffixNode = s->originNode;
	//wyciêcie starego pocz¹tku tekstu (teraz jest on na nowej krawêdzi) i dodanie nowego znaku
	this->startInd += s->getPhraseLength() + 1;
	//podpiêcie tej krawêdzi na koniec nowopowsta³ej krawêdzi
	this->startN = ne->endN;
	this->insertToParentEdgeList();
	//Zwracany jest nowy wêze³
	return ne->endN;
}


void Edge::insertToParentEdgeList() {
	this->startN->addEdge(this->startInd, this);
}

void Edge::removeFromParentEdgeList() {
	this->startN->removeEdge(this->startInd);
}

int Edge::getPhraseLength() {
	return this->endInd - this->startInd;
}

int Edge::getFullSuffixLength() {
    int mtl = startN->tree->text.length();

    int realEnd = (this->endInd < 0 ? mtl : this->endInd);
    if (realEnd > mtl) realEnd = mtl-1;

    int tt = realEnd - startInd+1;
    int pt = 0;
    if (startN->parentEdge != NULL) pt = startN->parentEdge->getFullSuffixLength();
    return pt+tt;
}

string Edge::getEdgeText() {
        string text = startN->tree->text;
        int realEnd = (this->endInd < 0 ? text.length() : this->endInd);
        if (realEnd > (int)text.length()) realEnd = text.length()-1;
        text = text.substr(this->startInd, realEnd - this->startInd +1);
        return text;
}


string Edge::getEdgeFullText() {
    string tt = getEdgeText();
    string pt;
    if (startN->parentEdge != NULL) pt = startN->parentEdge->getEdgeFullText();
    return pt+tt;
}

string Edge::toString() {
	stringstream ss;
	string text = startN->tree->text;
	int realEnd = (this->endInd < 0 ? text.length() : this->endInd);
	if (realEnd > (int)text.length()) realEnd = text.length()-1;
	text = text.substr(this->startInd, realEnd - this->startInd +1);
	ss<<startInd<<"\t"<<realEnd<<"\t";
	ss<<this->startN->toString()<<"\t"<<this->endN->toString()<<"\t"<<text;
	return ss.str();
}






