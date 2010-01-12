#ifndef WORDGENERATOR_H
#define WORDGENERATOR_H

#include <QString>
#include <string>

using namespace std;

class WordGenerator
{
public:
    WordGenerator();

    static QString generateWord(int alfaSize, int length);


};


#endif // WORDGENERATOR_H
