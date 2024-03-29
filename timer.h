/*
 * timer.h
 *
 * Prosta klasa umożliwiająca pomiar czasu wykonania.
 *
 *  Created on: 2010-01-10
 *      Author: Piotr Gwizdała
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <time.h>

class Timer {
	clock_t t;
public:
	void start() {
		t=clock();
	}
	double stop() {
		t=clock()-t;
		return (double)(t / (double)CLOCKS_PER_SEC);
	}
};

#endif /* TIMER_H_ */
