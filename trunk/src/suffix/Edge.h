/*
 * Edge.h
 *
 * Reprezentuje kraw�d� w drzewie sufiksowym. Ka�da kraw�d� odpowiada pewnemu
 * fragmentowi tekstu wej�ciowego. W tej implementacji przechowujemy indeksy
 * pocz�tku i ko�ca odpowiedniego fragmentu. Opr�cz tego kraw�d� przchowuje
 * sw�j w�ze� pocz�tkowy i w�ze� ko�cowy.
 *
 * Klasa ta r�wnie� posiada niezb�dn� metod� split(), kt�ra pozwala na podzia�
 * kraw�dzi i dodanie dodatkowego w�z�a w przypadku gdy dodawany sufiks ko�czy
 * si� w tzw. w�le niejawnym.
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda�a
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
	 * index poczatkowy tekstu kraw�dzi
	 */
	int startInd;

	/**
	 * index ko�cowy tekstu kraw�dzi
	 */
	int endInd;

	/**
	 * indeks pocz�tkowy ca�ego tekstu od korzenia do tej kraw�dzi. u�ywany
	 * przy znajdywaniu najd�u�szego tekstu wyst�puj�cego k-krotnie.
	 */
	int allStart;


	Node* startN;
	Node* endN;



	/**
	 * Konstruuje i inicjalizuje now� kraw�d�
	 */
	Edge(int startIndex, int endIndex, Node* startNode);

	virtual ~Edge();

	/**
	 * Kiedy dodawany suffix ko�czy si� na w�le niejawnym, dodanie nowego znaku
	 * oznacza konieczno�� podzia�u kraw�dzi, w wyniku czego powstaje nowy w�ze�.
	 */
	Node* split(Suffix *s);

	/**
	 * Zwraca d�ugo�� tekstu odpowiadaj�cego tej kraw�dzi.
	 */
	int getPhraseLength();

	/**
	 * Zwraca fragment tekstu przy kraw�dzi
	 */
	string getEdgeFullText();

	string toString();

private:

	/**
	 * Dodaje t� kraw�d� do listy kraw�dzi w�z�a na kt�ry wskazuje jej pocz�tek (startN).
	 * U�ywane w metodzie split().
	 */
	void insertToParentEdgeList();

	/**
	 * Usuwa t� kraw�d� z listy kraw�dzi w�z�a w kt�rym si� zaczyna. U�ywane w metodzie split().
	 */
	void removeFromParentEdgeList();


};

#endif /* EDGE_H_ */
