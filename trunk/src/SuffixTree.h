/*
 * SuffixTree.h
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda³a
 */

#ifndef SUFFIXTREE_H_
#define SUFFIXTREE_H_

#include <string>
#include "Node.h"
#include "Suffix.h"

class Node;
class Suffix;

using namespace std;

//FIXME: przeportowaæ to do koñca

class SuffixTree {
public:

	string text;
	Node* root;
	int nodeCount;

	SuffixTree(string text);
	virtual ~SuffixTree();

	int getNextId();

	string getText();

	void addPrefix(Suffix* active, int endIndex);

	void updateSuffixNode(Node* node, Node* suffixNode);

};

#endif /* SUFFIXTREE_H_ */
