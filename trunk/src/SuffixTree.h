/*
 * SuffixTree.h
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda³a
 */

#ifndef SUFFIXTREE_H_
#define SUFFIXTREE_H_

#include <string>

//FIXME: przeportowaæ to do koñca

class SuffixTree {
public:
	SuffixTree();
	virtual ~SuffixTree();
	int getNextId();

	string getText();

};

#endif /* SUFFIXTREE_H_ */
