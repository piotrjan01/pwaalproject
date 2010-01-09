/*
 * debug.cpp
 *
 *  Created on: 2010-01-09
 *      Author: Piotr Gwizda�a
 */


#ifndef DEBUG_H_
#define DEBUG_H_

#define CHKSUM(X) if (Dbg::debugLevel >= 1) { Dbg::prn(X); }

#define PRN1(X) if (Dbg::debugLevel >= 1) { PRN(X) }
#define VAR1(X) if (Dbg::debugLevel >= 1) { VAR(X) }

#define PRN2(X) if (Dbg::debugLevel >= 2) { PRN(X) }
#define VAR2(X) if (Dbg::debugLevel >= 2) { VAR(X) }

#define PRN(X) Dbg::prn("msg: "); Dbg::prn(__FILE__); Dbg::prn("@"); Dbg::prn(__LINE__); \
		Dbg::prn(" "); Dbg::prn(X); Dbg::prn("\n");
#define VAR(X) Dbg::prn("var: "); Dbg::prn(#X); Dbg::prn(" = "); \
		Dbg::prn(X); Dbg::prn("\n");


#include <string>
#include <iostream>
#include <sstream>
#include "Object.h"

using namespace std;

class Dbg {
public:

	static const int debugLevel = 1;

	static void Dbg::prn(string s)  {
		cout<<s<<flush;
		return;
	}

	static void Dbg::prn(int s)  {
		stringstream ss;
		ss<<s;
		prn(ss.str());
	}

	static void Dbg::prn(char s)  {
			stringstream ss;
			ss<<s;
			prn(ss.str());
	}

	static void Dbg::prn(Object* s)  {
				prn(s->toString());
		}


};

#endif //DEBUG

