/*
 * Edge.h
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda�a
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
	 * Konstruuje i inicjalizuje now� kraw�d�
	 */
	Edge(int startIndex, int endIndex, Node* startNode);

	virtual ~Edge();

	/**
	 * Kiedy suffix ko�czy si� na w�le ukrytym, dodanie nowego znaku
	 * oznacza konieczno�� podzia�u kraw�dzi, w wyniku czego powstaje
	 * nowy w�ze�.
	 */
	Node* split(Suffix *s);


	/**
	 * Dodaje t� kraw�d� do w�z�a na kt�ry wskazuje jej pocz�tek (startN)
	 */
	void insert();

	/**
	 * Usuwa t� kraw�d� z w�z�a w kt�rym si� zaczyna
	 */
	void remove();

	int getPhraseLength();

	string toString();

};

#endif /* EDGE_H_ */
