/*
 * Suffix.h
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda³a
 */

#ifndef SUFFIX_H_
#define SUFFIX_H_

//FIXME: przeportowaæ to do koñca

class Suffix {
public:
	Suffix();
	virtual ~Suffix();

	int getPhraseLength();

	Node *originNode;

};

#endif /* SUFFIX_H_ */
