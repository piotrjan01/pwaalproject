/*
 * Node.h
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
 */

#ifndef NODE_H_
#define NODE_H_

#include <map>
#include "SuffixTree.h"

using namespace std;

class Node {
public:
	Node *suffixNode;
	Node(SuffixTree* st, Node* suffixNode);
	virtual ~Node();

	void addEdge(int charIndex, Edge* edge);
	void removeEdge(int charIndex);
	Edge* findEdge(char c);

	char getCharAt(int ind);


private:
	map<char, Edge> nodeEdges;
	SuffixTree *st;
	int id;



};

#endif /* NODE_H_ */
