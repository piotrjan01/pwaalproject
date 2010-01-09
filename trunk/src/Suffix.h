/*
 * Suffix.h
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda³a
 */

#ifndef SUFFIX_H_
#define SUFFIX_H_

#include "Node.h"
#include "Object.h"
#include <string>
//FIXME: przeportowaæ to do koñca (metody)

class Node;

class Suffix : public Object {
public:
	Suffix(Node* originNode, int startIndex, int endIndex);
	virtual ~Suffix();

	int getPhraseLength();

	Node* originNode;

	int startInd;

	int endInd;

	bool isExplicit();

	bool isImplicit();

	//TODO: ?
	void canonize();


	std::string toString();

};

#endif /* SUFFIX_H_ */
