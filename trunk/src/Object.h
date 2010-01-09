/*
 * Object.h
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
