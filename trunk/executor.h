#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <QString>
#include <QTreeWidgetItem>
#include <QProgressBar>
#include "suffix/Node.h"

class Executor
{
public:
    Executor();

    static QString doSuffixTreeByPath(QString path);

    static QString doSuffixTreeByGivenWord(QString word, int k, QTreeWidgetItem **root);
    static QString doSuffixTreeByGivenWord(QString word, int k);

    static QString doSuffixTreeTesting(int alfaLength, int beginSize, int endSize, int step, int k, int reps, QProgressBar *status);

    static char validateChar(char c);

    static void buildTreeStructure(Node* n, QTreeWidgetItem *wi);

};

#endif // EXECUTOR_H
