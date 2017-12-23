#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include"word.h"
#include<QLineEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
       QTextEdit** initfields(int size_off_word);
     void decorate(QTextEdit* TE);
     void addLetters();
     Word choseword(QString path);
     void setLine(QLineEdit * Line);
private slots:
    void on_Wybierz_clicked();
    void keyboardHandler();
    void on_clear_clicked();
    void on_Benter_clicked();
    void on_Bback_clicked();




private:
    Ui::MainWindow *ui;
    QString outputText;
    QLineEdit *Line;

};

#endif // MAINWINDOW_H
