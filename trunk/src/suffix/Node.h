/*
 * Node.h
 *
 * Reperezentuje w�ze� jawny w drzewie sufiksowym. W�ze� ten przechowuje
 * list� kraw�dzi kt�re z niego wychodz� poindeksowanych pierwszym znakiem
 * tekstu odpowiadaj�cego danej kraw�dzi. Opr�cz tego przechowuje wska�nik
 * na w�ze� odpowiadaj�cy nast�pnemu, kr�tszemu sufiksowi obecnemu w drzewie
 * do kt�rego nale�y si� uda� uaktualniaj�c drzewo.
 *
 * Klasa dodatkowo posiada proste metody kt�re umo�liwiaj� operacje na jej polach.
 *
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda�a
 */

#ifndef NODE_H_
#define NODE_H_

#include <map>
#include <string>
#include <sstream>
#include <list>
#include "SuffixTree.h"
#include "Edge.h"
#include "../Object.h"

using namespace std;

class Edge;
class SuffixTree;

class Node : public Object {
public:
	/**
	 * Wska�nik na drzewo sufiksowe. U�ywany jedynie do generowanie IDs
	 */
	//TODO: static!
	SuffixTree *tree;

	/**
	 * Unikalne id w�z�a u�ywane do reprezentowania go na wyj�ciu.
	 */
	int id;

	/**
	 * U�ywane do zliczania li�ci w poddrzewie danego w�z�a
	 */
	int leafCount;

	/**
	 * Mapa zawieraj�ca kraw�dzie wychodz�ce z tego w�z�a indeksowane pierwszym
	 * znakiem tekstu odpowiadaj�cego danej kraw�dzi. Przyspisza poruszanie si�
	 * po drzewie.
	 */
	//TODO: make it hashmap
	map<char, Edge*> nodeEdges;

	/**
	 * Wska�nik do w�z�a odpowiadaj�cego nast�pnemu kr�tszemu sufiksowi obecnemu w drzewie.
	 */
	Node *suffixNode;

	/**
	 * Konstruktor.
	 */
	Node(SuffixTree* st, Node* suffixNode);

	virtual ~Node();

	/**
	 * Dodaje kraw�d� do listy kraw�dzi wychodz�cych z tego w�z�a.
	 * charIndeks to indeks znaku kt�rym dodawana kraw�d� ma by� indeksowana.
	 */
	void addEdge(int charIndex, Edge* edge);

	/**
	 * Usuwa wskazan� kraw�d� (podaj�c indeks jej znaku w tek�cie wej�ciowym drzewa).
	 */
	void removeEdge(int charIndex);

	/**
	 * Zwraca kraw�d� odpowiadaj�c� podanemu znakowi, albo null.
	 */
	Edge* findEdge(char c);

	/**
	 * Zwraca znak pod wskazanym indeksem w tek�cie wej�ciowym drzewa.
	 */
	char getCharAt(int ind);

	/**
	 * U�ywane do prezentacji
	 */
	list<Node*> getAllNodes();

	/**
	 * U�ywane do prezentacji
	 */
	list<Edge*> getAllEdges();

	/**
	 * Zwraca true je�li dany w�ze� jest li�ciem
	 */
	bool isLeaf();

	/**
	 * Ustawia leafCount na odpowiedni� warto�� w ca�ym poddrzewie
	 */
	void updateLeafCount(int allBegin);

	string toString();

};

#endif /* NODE_H_ */
