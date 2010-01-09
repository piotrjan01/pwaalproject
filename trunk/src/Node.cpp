/*
 * Node.cpp
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
 */

#include "Node.h"
#include "debug.h"
#include <utility>

Node::Node(SuffixTree* st, Node* suffixNode) {
	this->tree = st;
	this->id = st->getNextId();
	this->suffixNode = suffixNode;
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
	this->nodeEdges.erase(this->getCharAt(charIndex));
}

Edge* Node::findEdge(char c) {
	return this->nodeEdges[c];
}

string Node::toString()  {
	stringstream ss;
	ss<<this->id;
	return ss.str();
}

Node::~Node() {
	delete this->suffixNode;
}
