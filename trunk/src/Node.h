/*
 * Node.h
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
 */

#ifndef NODE_H_
#define NODE_H_

#include <map>
#include <string>
#include <sstream>
#include "SuffixTree.h"
#include "Edge.h"
#include "Object.h"
#include "debug.h"

using namespace std;

class Edge;
class SuffixTree;

class Node : public Object {
public:

	map<char, Edge*> nodeEdges;
	SuffixTree *st;
	int id;

	Node *suffixNode;
	Node(SuffixTree* st, Node* suffixNode);
	virtual ~Node();

	void addEdge(int charIndex, Edge* edge);
	void removeEdge(int charIndex);
	Edge* findEdge(char c);

	char getCharAt(int ind);

	string toString() {
		PRN("in toString");
		stringstream ss;
		ss<<"Node: id="<<this->id<<" suffixNode="<<this->suffixNode;
		map<char, Edge*>::iterator it;
		int i=0;
		for (it = this->nodeEdges.begin(); it != nodeEdges.end(); it++) {
			ss << "\t edge "<<++i<<": " << it->first << " => " ;//<< ((Object *)it->second)->toString();
		}
		return ss.str();
	}





};

#endif /* NODE_H_ */
