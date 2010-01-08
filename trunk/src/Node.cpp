/*
 * Node.cpp
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
 */

#include "Node.h"
#include <pair.h>

Node::Node(SuffixTree* st, Node* suffixNode) {
	this->st = st;
	this->id = st->getNextId();
	this->suffixNode = suffixNode;
}

char Node::getCharAt(int ind) {
	string s = this->st->getText();
	return s[ind];
}

void Node::addEdge(int charIndex, Edge* edge) {
	this->nodeEdges.insert(pair<char, Edge*>(this->getCharAt(charIndex), edge));
}
void Node::removeEdge(int charIndex) {
	this->nodeEdges.erase(this->getCharAt(charIndex));
}

Edge* Node::findEdge(char c) {
	return this->nodeEdges[c];
}


Node::~Node() {
}
