#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "executor.h"
#include "timer.h"
#include "QDebug"
#include "wordgenerator.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_startPath_clicked()
{
    qDebug()<<ui->pathInput->text();
    Timer t;
    QString time;
    t.start();
    QString result = "Œcie¿ka pliku: "+ui->pathInput->text()+"\n"+Executor::doSuffixTreeByPath(ui->pathInput->text());
    time.setNum(t.stop());
    result += "\nCzas wykonania: "+time;
    ui->tb->setText(result);
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Otwórz plik z danymi"), "./", tr("All Files (*)"));
    ui->pathInput->setText(fileName);
}


void MainWindow::on_startOwn_clicked()
{
    QTreeWidgetItem *r = NULL;

    Timer t;
    bool ok;
    int k = ui->kInput2->text().toInt(&ok);
    if (!ok) {
        ui->tb->setText("B³¹d przy próbie wczytania parametru k.");
        return;
    }
    QString time;
    t.start();
    QString result = Executor::doSuffixTreeByGivenWord(ui->userTextInput->text(), k, &r);
    time.setNum(t.stop());
    result += "\nCzas wykonania: "+time;
    ui->tb->setText(result);
    ui->treeWidget->clear();
    ui->treeWidget->addTopLevelItem(r);
    ui->treeWidget->expandAll();
}

void MainWindow::on_startGen_clicked()
{
    bool ok, oka = true;
    int as = ui->alfabetSize4Gen->text().toInt(&ok);
    oka = ok && oka;
    int s = ui->wordLength4Gen->text().toInt(&ok);
    oka = ok && oka;
    int k = ui->k4Gen->text().toInt(&ok);
    oka = ok && oka;
    if (!oka) {
        ui->tb->setText("B³¹d przy próbie wczytania parametrów.");
        return;
    }
    QString word = WordGenerator::generateWord(as, s);
    QString res;// = "Wygenerowany text: "+word+"\nk: "+QString().setNum(k)+"\n";

    Timer t;
    QString time;
    t.start();
    res += Executor::doSuffixTreeByGivenWord(word, k);
    time.setNum(t.stop());
    res += "\nCzas wykonania: "+time;
    ui->tb->setText(res);
}

void MainWindow::on_startComp_clicked()
{

    bool ok, oka = true;
    int as = ui->alfabetSizeInput->text().toInt(&ok);
    oka = ok && oka;
    int bl = ui->dataBeginInput->text().toInt(&ok);
    oka = ok && oka;
    int el = ui->dataEndInput->text().toInt(&ok);
    oka = ok && oka;
    int ls = ui->dataStepInput->text().toInt(&ok);
    oka = ok && oka;
    int reps = ui->repsInput->text().toInt(&ok);
    oka = ok && oka;
    int k = ui->kInput1->text().toInt(&ok);
    oka = ok && oka;
    if (!oka) {
        ui->tb->setText("B³¹d przy próbie wczytania parametrów.");
        return;
    }

    Timer t;
    QString time;
    QString res;
    t.start();
    res += Executor::doSuffixTreeTesting(as, bl, el, ls, k, reps, ui->progressBar);
    time.setNum(t.stop());
    res += "\nCzas wykonania: "+time;
    ui->tb->setText(res);

}
