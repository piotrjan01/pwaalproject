/*
 * Object.h
 *
 * Klasa 'abstrakcyjna'. Przeznaczona jest do tego by dziedziczy³y po niej
 * inne klasy, co umo¿liwia uogólnienie ka¿dego obiektu i skorzystanie ze
 * zdefiniowanych tutaj metod (np. toString).
 *
 *  Created on: 2010-01-09
 *      Author: Piotr Gwizda³a
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>

class Object {
public:
	Object() {};
	virtual ~Object() {};

	virtual std::string toString() {
		return "Not implemented!";
	}

};

#endif /* OBJECT_H_ */
