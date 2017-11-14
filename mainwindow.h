#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void addLetters(int size_off_word);
     void decorate(QTextEdit* TE);
private slots:
    void on_Wybierz_clicked();




private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
