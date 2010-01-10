/*
 * SuffixTree.h
 *
 * G³ówna klasa drzewa sufiksowego. Przechowuje dane takie jak tekst wejœciowy czy wskaŸnik
 * na korzeñ drzewa. Dostêpne s¹ 2 konstruktory. Jeden od razu buduje drzewo sufiksowe z
 * podanego tekstu (gdy znamy ca³y tekst). Drugi zaœ twozy puste drzewo i czeka na podawanie
 * kolejnych znaków tekstu do dodania.
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda³a
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
	 * Tekst wejœciowy drzewa sufiksowego
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
	 * Generuje nowe ID dla wêz³ów jawnych
	 */
	int getNextId();

	std::string toString();

	Node* getRoot() { return root; }

private:
	/**
	 * Korzeñ drzewa
	 */
	Node* root;

	/**
	 * Iloœæ wêz³ów jawnych w drzewie. U¿ywane do przydzielania unikalnych ID wêz³om jawnym.
	 */
	int nodeCount;

	/**
	 * suffiks odpowiadaj¹cy punktowi aktywnemu
	 */
	Suffix* activePoint;

	/**
	 * Dodaje prefix z tekstu wejœciowego korzystaj¹c z punktu aktywnego.
	 */
	void addPrefix(int endIndex);

	/**
	 * Ustawia wskaŸnik na nastêpny krótszy sufiks danemu wêz³owi pod warunkiem, ¿e node nie jest
	 * korzeniem ani NULL.
	 */
	void updateSuffixNode(Node* node, Node* suffixNode);




};

#endif /* SUFFIXTREE_H_ */
