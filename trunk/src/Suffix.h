/*
 * Suffix.h
 *
 * Klasa Suffix reprezentuje sufiks tekstu wejœciowego. Obiekt klasy Suffix posiada fragment
 * tekstu wejœciowego i wêze³ w którym sufiks powinien siê zaczynaæ. Korzystaj¹c ze
 * sprowadzania sufiksu do formy kanonicznej, mo¿na znaleŸæ wêze³ (jawny lub niejawny) w którym
 * dany sufiks siê koñczy. Umo¿liwia to lokalizacjê miejsca w drzewie, które nale¿y zmodyfikowaæ.
 *
 * Po wywo³aniu metody canonize() mo¿na sprawdziæ czy sufiks koñczy siê w wêŸle jawnym czy
 * niejawnym korzystaj¹c z metod isExplicit() i isImplicit(). Jeœli kanoniczny sufiks koñczy
 * siê w wêŸle jawnym, oznacza to ¿e tekst przypisany do sufiksu jest pusty. Oznacza siê
 * to przez stan w którym startInd jest wiêkszy od endInd.
 *
 *  Created on: 2010-01-08
 *      Author: Piotr Gwizda³a
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
	 * Wêze³, w którym sufiks siê zaczyna
	 */
	Node* originNode;

	/**
	 * Indeks pocz¹tku tekstu sufiksu w tekœcie wejœciowym drzewa
	 */
	int startInd;

	/**
	 * Indeks koñca tekstu sufiksu w tekœcie wejœciowym drzewa
	 */
	int endInd;

	Suffix(Node* originNode, int startIndex, int endIndex);

	virtual ~Suffix();

	/**
	 * Zwraca d³ugoœæ tekstu sufiksu
	 */
	int getPhraseLength();

	/**
	 * Sprawdza czy sufiks koñczy siê w jawnym wêŸle. Musi byæ kanoniczny!
	 */
	bool isExplicit();

	/**
	 * Sprawdza czy sufiks koñczy siê w niejawnym wêŸle. Musi byæ kanoniczny!
	 */
	bool isImplicit();

	/**
	 * Konweruje sufiks do postaci kanonicznej. W postaci kanonicznej originNode jest najbli¿szym
	 * (id¹c w górê drzewa) jawnym wêz³em w stosunku do wêz³a w którym koñczy siê sufiks.
	 */
	void canonize();

	std::string toString();

};

#endif /* SUFFIX_H_ */
