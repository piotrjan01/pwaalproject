/*
 * Edge.h
 *
 * Reprezentuje krawêdŸ w drzewie sufiksowym. Ka¿da krawêdŸ odpowiada pewnemu
 * fragmentowi tekstu wejœciowego. W tej implementacji przechowujemy indeksy
 * pocz¹tku i koñca odpowiedniego fragmentu. Oprócz tego krawêdŸ przchowuje
 * swój wêze³ pocz¹tkowy i wêze³ koñcowy.
 *
 * Klasa ta równie¿ posiada niezbêdn¹ metodê split(), która pozwala na podzia³
 * krawêdzi i dodanie dodatkowego wêz³a w przypadku gdy dodawany sufiks koñczy
 * siê w tzw. wêŸle niejawnym.
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
 */

#ifndef EDGE_H_
#define EDGE_H_

#include "Node.h"
#include "Suffix.h"
#include "../Object.h"
#include <string>

class Node;
class Suffix;

using namespace std;

class Edge : public Object{
public:

	/**
	 * index poczatkowy tekstu krawêdzi
	 */
	int startInd;

	/**
	 * index koñcowy tekstu krawêdzi
	 */
	int endInd;

	/**
	 * indeks pocz¹tkowy ca³ego tekstu od korzenia do tej krawêdzi. u¿ywany
	 * przy znajdywaniu najd³u¿szego tekstu wystêpuj¹cego k-krotnie.
	 */
	int allStart;


	Node* startN;
	Node* endN;



	/**
	 * Konstruuje i inicjalizuje now¹ krawêdŸ
	 */
	Edge(int startIndex, int endIndex, Node* startNode);

	virtual ~Edge();

	/**
	 * Kiedy dodawany suffix koñczy siê na wêŸle niejawnym, dodanie nowego znaku
	 * oznacza koniecznoœæ podzia³u krawêdzi, w wyniku czego powstaje nowy wêze³.
	 */
	Node* split(Suffix *s);

	/**
	 * Zwraca d³ugoœæ tekstu odpowiadaj¹cego tej krawêdzi.
	 */
	int getPhraseLength();

	/**
	 * Zwraca fragment tekstu przy krawêdzi
	 */
	string getEdgeFullText();

	string toString();

private:

	/**
	 * Dodaje tê krawêdŸ do listy krawêdzi wêz³a na który wskazuje jej pocz¹tek (startN).
	 * U¿ywane w metodzie split().
	 */
	void insertToParentEdgeList();

	/**
	 * Usuwa tê krawêdŸ z listy krawêdzi wêz³a w którym siê zaczyna. U¿ywane w metodzie split().
	 */
	void removeFromParentEdgeList();


};

#endif /* EDGE_H_ */
