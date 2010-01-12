#include "wordgenerator.h"
#include <ctime>
#include <cstdlib>
#include <sstream>

WordGenerator::WordGenerator()
{
}

QString WordGenerator::generateWord(int alfaSize, int length) {

    string alfabet = "abcdefghijklmnopqrstuvwxyz";
    stringstream ss;

    if (alfaSize > (int)alfabet.size()) alfaSize = alfabet.size();

    srand((unsigned)time(0));
    for (int i=0; i<length; i++) {
        ss<<alfabet[(rand() % alfaSize)];
    }

    return QString(ss.str().c_str());

}
