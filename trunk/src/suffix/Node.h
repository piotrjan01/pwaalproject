/*
 * Node.h
 *
 * Reperezentuje wêze³ jawny w drzewie sufiksowym. Wêze³ ten przechowuje
 * listê krawêdzi które z niego wychodz¹ poindeksowanych pierwszym znakiem
 * tekstu odpowiadaj¹cego danej krawêdzi. Oprócz tego przechowuje wskaŸnik
 * na wêze³ odpowiadaj¹cy nastêpnemu, krótszemu sufiksowi obecnemu w drzewie
 * do którego nale¿y siê udaæ uaktualniaj¹c drzewo.
 *
 * Klasa dodatkowo posiada proste metody które umo¿liwiaj¹ operacje na jej polach.
 *
 *
 *  Created on: 2010-01-07
 *      Author: Piotr Gwizda³a
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
	 * WskaŸnik na drzewo sufiksowe. U¿ywany jedynie do generowanie IDs
	 */
	//TODO: static!
	SuffixTree *tree;

	/**
	 * Unikalne id wêz³a u¿ywane do reprezentowania go na wyjœciu.
	 */
	int id;

	/**
	 * U¿ywane do zliczania liœci w poddrzewie danego wêz³a
	 */
	int leafCount;

	/**
	 * Mapa zawieraj¹ca krawêdzie wychodz¹ce z tego wêz³a indeksowane pierwszym
	 * znakiem tekstu odpowiadaj¹cego danej krawêdzi. Przyspisza poruszanie siê
	 * po drzewie.
	 */
	//TODO: make it hashmap
	map<char, Edge*> nodeEdges;

	/**
	 * WskaŸnik do wêz³a odpowiadaj¹cego nastêpnemu krótszemu sufiksowi obecnemu w drzewie.
	 */
	Node *suffixNode;

	/**
	 * Konstruktor.
	 */
	Node(SuffixTree* st, Node* suffixNode);

	virtual ~Node();

	/**
	 * Dodaje krawêdŸ do listy krawêdzi wychodz¹cych z tego wêz³a.
	 * charIndeks to indeks znaku którym dodawana krawêdŸ ma byæ indeksowana.
	 */
	void addEdge(int charIndex, Edge* edge);

	/**
	 * Usuwa wskazan¹ krawêdŸ (podaj¹c indeks jej znaku w tekœcie wejœciowym drzewa).
	 */
	void removeEdge(int charIndex);

	/**
	 * Zwraca krawêdŸ odpowiadaj¹c¹ podanemu znakowi, albo null.
	 */
	Edge* findEdge(char c);

	/**
	 * Zwraca znak pod wskazanym indeksem w tekœcie wejœciowym drzewa.
	 */
	char getCharAt(int ind);

	/**
	 * U¿ywane do prezentacji
	 */
	list<Node*> getAllNodes();

	/**
	 * U¿ywane do prezentacji
	 */
	list<Edge*> getAllEdges();

	/**
	 * Zwraca true jeœli dany wêze³ jest liœciem
	 */
	bool isLeaf();

	/**
	 * Ustawia leafCount na odpowiedni¹ wartoœæ w ca³ym poddrzewie
	 */
	void updateLeafCount(int allBegin);

	string toString();

};

#endif /* NODE_H_ */
