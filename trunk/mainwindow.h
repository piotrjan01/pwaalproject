#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    void on_startComp_clicked();
    void on_pushButton_clicked();
    void on_startGen_clicked();
    void on_startOwn_clicked();
    void on_startPath_clicked();
};

#endif // MAINWINDOW_H
