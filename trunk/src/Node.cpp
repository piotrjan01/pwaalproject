/*
 * Node.cpp
 *
 * Implementacja klasy opisanej w pliku nag³ówkowym
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

vector<Node*> Node::getAllNodes() {
	vector<Node*> ret;
	ret.push_back(this);
	map<char, Edge*>::iterator it;
	for (it = nodeEdges.begin(); it != nodeEdges.end(); it++) {
		vector<Node*> ret2 = it->second->endN->getAllNodes();
		for (unsigned int i=0; i<ret2.size(); i++) {
			ret.push_back(ret2.at(i));
		}
	}
	return ret;
}

vector<Edge*> Node::getAllEdges() {
	vector<Edge*> ret;
	map<char, Edge*>::iterator it;
	for (it = nodeEdges.begin(); it != nodeEdges.end(); it++) {
		ret.push_back(it->second);
		vector<Edge*> ret2 = it->second->endN->getAllEdges();
		for (unsigned int i=0; i<ret2.size(); i++) {
			ret.push_back(ret2.at(i));
		}
	}
	return ret;
}

