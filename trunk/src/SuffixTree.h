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
#include "Object.h"

class Node;
class Suffix;

using namespace std;


class SuffixTree : public Object {
public:

	/**
	 * Tekst wejœciowy drzewa sufiksowego
	 */
	string text;

	/**
	 * Korzeñ drzewa
	 */
	Node* root;

	/**
	 * Iloœæ wêz³ów jawnych w drzewie. U¿ywane do przydzielania unikalnych ID wêz³om jawnym.
	 */
	int nodeCount;

	SuffixTree(string text);

	virtual ~SuffixTree();

	/**
	 * Generuje nowe ID dla wêz³ów jawnych
	 */
	int getNextId();

	/**
	 * Dodaje
	 */
	void addPrefix(Suffix* active, int endIndex);

	void updateSuffixNode(Node* node, Node* suffixNode);

	std::string toString();

	//zwraca text
	string getText();

};

#endif /* SUFFIXTREE_H_ */
