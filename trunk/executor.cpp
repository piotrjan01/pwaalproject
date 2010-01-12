#include "executor.h"
#include <fstream>
#include <string>
#include <sstream>
#include "suffix/SuffixTree.h"
#include "timer.h"
#include "wordgenerator.h"

Executor::Executor()
{
}

QString Executor::doSuffixTreeByPath(QString path) {
    string line;
    ifstream myfile (path.toStdString().c_str());
    QString ret;

    if (myfile.is_open()) {
        stringstream ss;
        char c;
        string ks;
        int k;
        bool ok;
        myfile>>ks;
        QString qks(ks.c_str());
        k = qks.toInt(&ok, 10);
        if ( ! ok ) {
            ret = "Nieprawid³owy format pliku wejœciowego: "+path+"\n";
            return ret;
        }

        while (! myfile.eof() && myfile>>c) {
            c = validateChar(c);
            if (c != 0) ss<<c;
        }
        ss<<"$";
        ret = "Plik wejœciowy: \n";
        ret += QString().setNum(k);
        ret += "\n";
        ret += ss.str().c_str();
        ret += "\n\n";
        SuffixTree st(ss.str().c_str());
        ret += "Wynik operacji:\n";
        ret += st.getLongestSubstringWithKRepetitions(k).c_str();


    }
    else {
            ret = "Nie mo¿na otworzyæ pliku: "+path+"\n";
    }
    return ret;

}

QString Executor::doSuffixTreeByGivenWord(QString word, int k, QTreeWidgetItem **root) {
    string s = word.toStdString();
    stringstream ss;
    char c;
    for (unsigned int i=0; i<s.length(); i++) {
        c = validateChar(s[i]);
        if (c) ss<<c;
    }
    ss<<"$";
    SuffixTree st(ss.str());
    QString ret;
    ret = st.getLongestSubstringWithKRepetitions(k).c_str();
    word = word.replace(ret, "<font color=#f00>"+ret+"</font>");
    ret = "S³owo wejœciowe: "+word+"<br>k: "+QString().setNum(k)+"<br>Wynik operacji:<br>" + ret+"<br>";
    *root = new QTreeWidgetItem(QStringList(QString("root")));
    buildTreeStructure(st.getRoot(), *root);
    return ret;
}

QString Executor::doSuffixTreeByGivenWord(QString word, int k) {
    string s = word.toStdString();
    stringstream ss;
    char c;
    for (unsigned int i=0; i<s.length(); i++) {
        c = validateChar(s[i]);
        if (c) ss<<c;
    }
    ss<<"$";
    SuffixTree st(ss.str());
    QString ret(st.getLongestSubstringWithKRepetitions(k).c_str());
    word = word.replace(ret, "<font color=#f00>"+ret+"</font>");
    ret = "S³owo wejœciowe: "+word+"<br>k: "+QString().setNum(k)+"<br>Wynik operacji:<br>" + ret+"<br>";
    return ret;
}


QString Executor::doSuffixTreeTesting(int alfaLength, int beginSize, int endSize, int step, int k, int reps, QProgressBar *stat) {
    QString ret = "Proces testowanie czasu wykonania dla ró¿nych rozmiarów problemu\n";
    ret += "Dane wejœciowe:\nRozmiar alfabetu: "+QString().setNum(alfaLength);
    ret += "\nPocz¹tkowy rozmiar problemu: "+QString().setNum(beginSize);
    ret += "\nKoñcowy rozmiar problemu: "+QString().setNum(endSize);
    ret += "\nKwant wzrostu rozmiaru problemu: "+QString().setNum(step);
    ret += "\nParametr K: "+QString().setNum(k);
    ret += "\nIloœæ powtórzeñ testu dla ka¿dego kroku (oblicza siê œredni czas): "+QString().setNum(reps);
    ret += "\n\nWyniki:\n";
    ret += "Rozmiar \t Czas wykonania\t q\n";

    QVector<double> data;
    stat->setMinimum(beginSize);
    stat->setMaximum(endSize);
    stat->setValue(beginSize);

    Timer t;
    for (int i=beginSize; i<=endSize; i+=step) {
        string res;
        double time=0;

        SuffixTree *st;

        for (int r=0; r<reps; r++) {
            QString qw = WordGenerator::generateWord(alfaLength, i);
            string w = qw.toStdString();
            w+="$";

            t.start();
            st = new SuffixTree(w);
            res = st->getLongestSubstringWithKRepetitions(k);
            time += t.stop();

            delete st;
            w = "";
            qw = "";

        }

        time = time/reps;
        data.push_back(time);
        double comp;
        comp = (i - beginSize)/(endSize - beginSize);

        stat->setValue(i);
    }

    int mediana = (int)(data.size() / 2.0);
    double c = data.at(mediana) / (beginSize+mediana*step);
    //make table
    for (int i=0; i<data.size(); i++) {
        int n = (beginSize+i*step);
        ret += QString().setNum(n)+"\t"+QString().setNum(data.at(i))+"\t"+QString().setNum(data.at(i)/(c*n))+"\n";
    }

    return ret;
}



void Executor::buildTreeStructure(Node* n, QTreeWidgetItem *wi) {
    QHash<char, Edge*>::iterator it;
    for (it = n->nodeEdges.begin(); it != n->nodeEdges.end(); it++) {
        QTreeWidgetItem *ni = new QTreeWidgetItem(wi, QStringList(QString(it.value()->getEdgeText().c_str())));
        buildTreeStructure(it.value()->endN, ni);
    }
}

char Executor::validateChar(char c) {
        if ((int)c >= 65 && (int)c <= 90) c = (char)((int)c + 32);
        if ((int)c < 97 || (int)c > 122) return 0;
        return c;
}
