/*
 * Suffix.h
 *
 * Klasa Suffix reprezentuje sufiks tekstu wej�ciowego. Obiekt klasy Suffix posiada fragment
 * tekstu wej�ciowego i w�ze� w kt�rym sufiks powinien si� zaczyna�. Korzystaj�c ze
 * sprowadzania sufiksu do formy kanonicznej, mo�na znale�� w�ze� (jawny lub niejawny) w kt�rym
 * dany sufiks si� ko�czy. Umo�liwia to lokalizacj� miejsca w drzewie, kt�re nale�y zmodyfikowa�.
 *
 * Po wywo�aniu metody canonize() mo�na sprawdzi� czy sufiks ko�czy si� w w�le jawnym czy
 * niejawnym korzystaj�c z metod isExplicit() i isImplicit(). Je�li kanoniczny sufiks ko�czy
 * si� w w�le jawnym, oznacza to �e tekst przypisany do sufiksu jest pusty. Oznacza si�
 * to przez stan w kt�rym startInd jest wi�kszy od endInd.
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda�a
 */

#ifndef SUFFIX_H_
#define SUFFIX_H_

#include "Node.h"
#include "Object.h"
#include <string>

class Node;

class Suffix : public Object {
public:

	/**
	 * W�ze�, w kt�rym sufiks si� zaczyna
	 */
	Node* originNode;

	/**
	 * Indeks pocz�tku tekstu sufiksu w tek�cie wej�ciowym drzewa
	 */
	int startInd;

	/**
	 * Indeks ko�ca tekstu sufiksu w tek�cie wej�ciowym drzewa
	 */
	int endInd;

	Suffix(Node* originNode, int startIndex, int endIndex);

	virtual ~Suffix();

	/**
	 * Zwraca d�ugo�� tekstu sufiksu
	 */
	int getPhraseLength();

	/**
	 * Sprawdza czy sufiks ko�czy si� w jawnym w�le. Musi by� kanoniczny!
	 */
	bool isExplicit();

	/**
	 * Sprawdza czy sufiks ko�czy si� w niejawnym w�le. Musi by� kanoniczny!
	 */
	bool isImplicit();

	/**
	 * Konweruje sufiks do postaci kanonicznej. W postaci kanonicznej originNode jest najbli�szym
	 * (id�c w g�r� drzewa) jawnym w�z�em w stosunku do w�z�a w kt�rym ko�czy si� sufiks.
	 */
	void canonize();

	std::string toString();

};

#endif /* SUFFIX_H_ */
