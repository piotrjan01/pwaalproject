/*
 * Node.cpp
 *
 * Implementacja klasy opisanej w pliku nag³ówkowym
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
 */

#include "Node.h"
#include <utility>

Node::Node(SuffixTree* st, Node* suffixNode, Edge* parentEdge) {
	this->tree = st;
	this->id = st->getNextId();
	this->suffixNode = suffixNode;
	this->parentEdge = parentEdge;
	this->leafCount = 0;
}

char Node::getCharAt(int ind) {
	string s = this->tree->text;
	return s[ind];
}

void Node::addEdge(int charIndex, Edge* edge) {
	char c = this->getCharAt(charIndex);
	this->nodeEdges[c] = edge;
}
void Node::removeEdge(int charIndex) {
        //this->nodeEdges.erase(this->getCharAt(charIndex));
        this->nodeEdges.remove(this->getCharAt(charIndex));
}

Edge* Node::findEdge(char c) {
	return this->nodeEdges[c];
}

string Node::toString()  {
	stringstream ss;
	ss<<this->id;//<<"\t"<<leafCount;
	return ss.str();
}

bool Node::isLeaf() {
	return (nodeEdges.size() == 0);
}

Node::~Node() {
	delete this->suffixNode;
}

void Node::updateLeafCount() {
        QHash<char, Edge*>::iterator it;
	if (isLeaf()) {
		leafCount = 1;
		return;
	}
	for (it = nodeEdges.begin(); it != nodeEdges.end(); it++) {
                        it.value()->endN->updateLeafCount(); //kontynuujemy
                        leafCount += it.value()->endN->leafCount;
	}
}

list<Node*> Node::getAllNodes() {
	list<Node*> ret;
	ret.push_back(this);
        QHash<char, Edge*>::iterator it;
	for (it = nodeEdges.begin(); it != nodeEdges.end(); it++) {
                list<Node*> ret2 = it.value()->endN->getAllNodes();
		ret.splice(ret.end(), ret2);
	}
	return ret;
}

list<Edge*> Node::getAllEdges() {
	list<Edge*> ret;
        QHash<char, Edge*>::iterator it;
	for (it = nodeEdges.begin(); it != nodeEdges.end(); it++) {
                ret.push_back(it.value());
                list<Edge*> ret2 = it.value()->endN->getAllEdges();
		ret.splice(ret.end(), ret2);
	}
	return ret;
}

