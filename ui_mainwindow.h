/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 12. Jan 18:25:16 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *startPath;
    QLineEdit *pathInput;
    QLabel *label;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QLineEdit *alfabetSizeInput;
    QLabel *label_2;
    QLineEdit *dataBeginInput;
    QLabel *label_3;
    QLineEdit *dataEndInput;
    QLabel *label_4;
    QLineEdit *dataStepInput;
    QLabel *label_5;
    QPushButton *startComp;
    QLineEdit *kInput1;
    QLabel *label_7;
    QLineEdit *repsInput;
    QLabel *label_13;
    QGroupBox *groupBox_3;
    QLineEdit *userTextInput;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *kInput2;
    QPushButton *startOwn;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox_4;
    QLabel *label_9;
    QLineEdit *alfabetSize4Gen;
    QLabel *label_10;
    QPushButton *startGen;
    QLabel *label_11;
    QLineEdit *wordLength4Gen;
    QLineEdit *k4Gen;
    QTextBrowser *tb;
    QLabel *label_12;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(871, 581);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 271, 101));
        startPath = new QPushButton(groupBox);
        startPath->setObjectName(QString::fromUtf8("startPath"));
        startPath->setGeometry(QRect(180, 70, 75, 23));
        pathInput = new QLineEdit(groupBox);
        pathInput->setObjectName(QString::fromUtf8("pathInput"));
        pathInput->setGeometry(QRect(10, 40, 241, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 151, 16));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 70, 75, 23));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 70, 291, 231));
        alfabetSizeInput = new QLineEdit(groupBox_2);
        alfabetSizeInput->setObjectName(QString::fromUtf8("alfabetSizeInput"));
        alfabetSizeInput->setGeometry(QRect(10, 20, 41, 20));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 20, 91, 16));
        dataBeginInput = new QLineEdit(groupBox_2);
        dataBeginInput->setObjectName(QString::fromUtf8("dataBeginInput"));
        dataBeginInput->setGeometry(QRect(10, 50, 41, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 50, 141, 16));
        dataEndInput = new QLineEdit(groupBox_2);
        dataEndInput->setObjectName(QString::fromUtf8("dataEndInput"));
        dataEndInput->setGeometry(QRect(10, 80, 41, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 80, 141, 16));
        dataStepInput = new QLineEdit(groupBox_2);
        dataStepInput->setObjectName(QString::fromUtf8("dataStepInput"));
        dataStepInput->setGeometry(QRect(10, 110, 41, 20));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 110, 141, 16));
        startComp = new QPushButton(groupBox_2);
        startComp->setObjectName(QString::fromUtf8("startComp"));
        startComp->setGeometry(QRect(200, 200, 75, 23));
        kInput1 = new QLineEdit(groupBox_2);
        kInput1->setObjectName(QString::fromUtf8("kInput1"));
        kInput1->setGeometry(QRect(10, 140, 41, 20));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 140, 91, 16));
        repsInput = new QLineEdit(groupBox_2);
        repsInput->setObjectName(QString::fromUtf8("repsInput"));
        repsInput->setGeometry(QRect(10, 170, 41, 20));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(70, 170, 191, 16));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(590, 10, 271, 531));
        userTextInput = new QLineEdit(groupBox_3);
        userTextInput->setObjectName(QString::fromUtf8("userTextInput"));
        userTextInput->setGeometry(QRect(10, 40, 231, 20));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 20, 151, 16));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 70, 91, 16));
        kInput2 = new QLineEdit(groupBox_3);
        kInput2->setObjectName(QString::fromUtf8("kInput2"));
        kInput2->setGeometry(QRect(10, 70, 41, 20));
        startOwn = new QPushButton(groupBox_3);
        startOwn->setObjectName(QString::fromUtf8("startOwn"));
        startOwn->setGeometry(QRect(170, 70, 75, 23));
        treeWidget = new QTreeWidget(groupBox_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(10, 110, 251, 411));
        treeWidget->header()->setVisible(false);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 170, 271, 131));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(70, 60, 141, 16));
        alfabetSize4Gen = new QLineEdit(groupBox_4);
        alfabetSize4Gen->setObjectName(QString::fromUtf8("alfabetSize4Gen"));
        alfabetSize4Gen->setGeometry(QRect(10, 30, 41, 20));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(70, 90, 91, 16));
        startGen = new QPushButton(groupBox_4);
        startGen->setObjectName(QString::fromUtf8("startGen"));
        startGen->setGeometry(QRect(180, 90, 75, 23));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(70, 30, 91, 16));
        wordLength4Gen = new QLineEdit(groupBox_4);
        wordLength4Gen->setObjectName(QString::fromUtf8("wordLength4Gen"));
        wordLength4Gen->setGeometry(QRect(10, 60, 41, 20));
        k4Gen = new QLineEdit(groupBox_4);
        k4Gen->setObjectName(QString::fromUtf8("k4Gen"));
        k4Gen->setGeometry(QRect(10, 90, 41, 20));
        tb = new QTextBrowser(centralWidget);
        tb->setObjectName(QString::fromUtf8("tb"));
        tb->setGeometry(QRect(10, 310, 571, 231));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 0, 561, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_12->setWordWrap(true);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 553, 261, 20));
        progressBar->setValue(0);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AAL projekt - Piotr Gwizda\305\202a", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\305\232cie\305\274ka do pliku wej\305\233ciowego", 0, QApplication::UnicodeUTF8));
        startPath->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        pathInput->setText(QApplication::translate("MainWindow", "in1.txt", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Wpisz poni\305\274ej \305\233cie\305\274k\304\231 do pliku", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Przegl\304\205daj...", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Badanie z\305\202o\305\274ono\305\233ci obliczeniowej", 0, QApplication::UnicodeUTF8));
        alfabetSizeInput->setText(QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "D\305\202ugo\305\233\304\207 alfabetu", 0, QApplication::UnicodeUTF8));
        dataBeginInput->setText(QApplication::translate("MainWindow", "100", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Pocz\304\205tkowy rozmiar problemu", 0, QApplication::UnicodeUTF8));
        dataEndInput->setText(QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Ko\305\204cowy rozmiar problemu", 0, QApplication::UnicodeUTF8));
        dataStepInput->setText(QApplication::translate("MainWindow", "50", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Kwant wzrostu problemu", 0, QApplication::UnicodeUTF8));
        startComp->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        kInput1->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Parametr k", 0, QApplication::UnicodeUTF8));
        repsInput->setText(QApplication::translate("MainWindow", "100", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Ilo\305\233\304\207 powt\303\263rze\305\204 dla ka\305\274dego rozmiaru", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Tekst w\305\202asny z podgl\304\205dem drzewa", 0, QApplication::UnicodeUTF8));
        userTextInput->setText(QApplication::translate("MainWindow", "barbara", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Wpisz poni\305\274ej tekst w\305\202asny", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Parametr k", 0, QApplication::UnicodeUTF8));
        kInput2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        startOwn->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Dane wygenerowane", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Rozmiar problemu", 0, QApplication::UnicodeUTF8));
        alfabetSize4Gen->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Parametr k", 0, QApplication::UnicodeUTF8));
        startGen->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "D\305\202ugo\305\233\304\207 alfabetu", 0, QApplication::UnicodeUTF8));
        wordLength4Gen->setText(QApplication::translate("MainWindow", "32", 0, QApplication::UnicodeUTF8));
        k4Gen->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        tb->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Tutaj b\304\231d\304\205 wy\305\233wietlone rezultaty dzia\305\202ania programu.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Program ten umo\305\274liwia przetestowanie algorytmu znajdywania najd\305\202u\305\274szego tekstu powtarzaj\304\205cego si\304\231 co najmniej k razy w tek\305\233cie wej\305\233ciowym. Testowany algorytm opiera si\304\231 na drzewie sufiksowym konstruowanym algorytmem Ukkonen'a.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
