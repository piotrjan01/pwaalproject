/*
 * SuffixTree.h
 *
 * G��wna klasa drzewa sufiksowego. Przechowuje dane takie jak tekst wej�ciowy czy wska�nik
 * na korze� drzewa. Dost�pne s� 2 konstruktory. Jeden od razu buduje drzewo sufiksowe z
 * podanego tekstu (gdy znamy ca�y tekst). Drugi za� twozy puste drzewo i czeka na podawanie
 * kolejnych znak�w tekstu do dodania.
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda�a
 */

#ifndef SUFFIXTREE_H_
#define SUFFIXTREE_H_

#include <string>
#include <vector>
#include "Node.h"
#include "Suffix.h"
#include "Object.h"

class Node;
class Suffix;

using namespace std;


class SuffixTree : public Object {
public:

	/**
	 * Tekst wej�ciowy drzewa sufiksowego
	 */
	string text;

	/**
	 * Tworzy drzewo sufiksowe i dodaje do niego podany tekst
	 */
	SuffixTree(string text);

	/**
	 * Tworzy puste drzewo sufiksowe
	 */
	SuffixTree();

	virtual ~SuffixTree();

	/**
	 * Dodaje podany tekst do drzewa sufiksowego
	 */
	void appendText(string t);

	/**
	 * Generuje nowe ID dla w�z��w jawnych
	 */
	int getNextId();

	std::string toString();

	Node* getRoot() { return root; }

private:
	/**
	 * Korze� drzewa
	 */
	Node* root;

	/**
	 * Ilo�� w�z��w jawnych w drzewie. U�ywane do przydzielania unikalnych ID w�z�om jawnym.
	 */
	int nodeCount;

	/**
	 * suffiks odpowiadaj�cy punktowi aktywnemu
	 */
	Suffix* activePoint;

	/**
	 * Dodaje prefix z tekstu wej�ciowego korzystaj�c z punktu aktywnego.
	 */
	void addPrefix(int endIndex);

	/**
	 * Ustawia wska�nik na nast�pny kr�tszy sufiks danemu w�z�owi pod warunkiem, �e node nie jest
	 * korzeniem ani NULL.
	 */
	void updateSuffixNode(Node* node, Node* suffixNode);




};

#endif /* SUFFIXTREE_H_ */
