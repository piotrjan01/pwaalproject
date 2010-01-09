/*
 * Edge.h
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
 */

#ifndef EDGE_H_
#define EDGE_H_

#include "Node.h"
#include "Suffix.h"
#include "Object.h"
#include <string>

class Node;
class Suffix;

using namespace std;

class Edge : public Object{
public:

	int startInd;
	int endInd;
	Node* startN;
	Node* endN;

	/**
	 * Konstruuje i inicjalizuje now¹ krawêdŸ
	 */
	Edge(int startIndex, int endIndex, Node* startNode);

	virtual ~Edge();

	/**
	 * Kiedy suffix koñczy siê na wêŸle ukrytym, dodanie nowego znaku
	 * oznacza koniecznoœæ podzia³u krawêdzi, w wyniku czego powstaje
	 * nowy wêze³.
	 */
	Node* split(Suffix *s);


	/**
	 * Dodaje tê krawêdŸ do wêz³a na który wskazuje jej pocz¹tek (startN)
	 */
	void insert();

	/**
	 * Usuwa tê krawêdŸ z wêz³a w którym siê zaczyna
	 */
	void remove();

	int getPhraseLength();

	string toString();

};

#endif /* EDGE_H_ */
