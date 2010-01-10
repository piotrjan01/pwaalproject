/*
 * Node.cpp
 *
 * Implementacja klasy opisanej w pliku nag³ówkowym
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
 */

#include "Node.h"
#include "../debug.h"
#include <utility>

Node::Node(SuffixTree* st, Node* suffixNode) {
	this->tree = st;
	this->id = st->getNextId();
	this->suffixNode = suffixNode;
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
	this->nodeEdges.erase(this->getCharAt(charIndex));
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
	map<char, Edge*>::iterator it;
	for (it = nodeEdges.begin(); it != nodeEdges.end(); it++) {
		if (it->second->endN->isLeaf()) leafCount++;
		else {
			it->second->endN->updateLeafCount();
			leafCount += it->second->endN->leafCount;
		}
	}
}

list<Node*> Node::getAllNodes() {
	list<Node*> ret;
	ret.push_back(this);
	map<char, Edge*>::iterator it;
	for (it = nodeEdges.begin(); it != nodeEdges.end(); it++) {
		list<Node*> ret2 = it->second->endN->getAllNodes();
		ret.splice(ret.end(), ret2);
	}
	return ret;
}

list<Edge*> Node::getAllEdges() {
	list<Edge*> ret;
	map<char, Edge*>::iterator it;
	for (it = nodeEdges.begin(); it != nodeEdges.end(); it++) {
		ret.push_back(it->second);
		list<Edge*> ret2 = it->second->endN->getAllEdges();
		ret.splice(ret.end(), ret2);
	}
	return ret;
}

