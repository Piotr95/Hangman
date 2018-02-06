#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include"word.h"
#include<QLineEdit>
#include<QPixmap>
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
    void SetNextHangmanImage();
    void failed_attempt();
    void decorate(QTextEdit* TE);
    void addLetters();
    void SetWordFields(QTextEdit** words);
    QTextEdit** GetWordFields();
    Word choseword();
    void guess(QString Text);
    void random_word();
    Word* Getword();
    int*Find_letters(QString k);
    void GameOver();
    void NewGame();
    void Clear_Word_field();
    void Reset_Text_Board();
    void Decorate_Text_Box();
    void Normal_lvl();
    void SetHangmanSteps(QPixmap **steps);
    QPixmap* load_Pic(QString path);
    void InitTemporary();
    void FillTemporary();
    void CheckGameWin();
    void WinGame();
    void CheckGameOver();
private slots:
    void keyboardHandler();
    void Bclear_clicked();
    void Benter_clicked();
    void Bback_clicked();
    void NewGame_clicked();

private:
    Word *currentword;
    Ui::MainWindow *ui;
    QString outputText;
    QLineEdit *line;
    QTextEdit** words;
    QPixmap **hangman_steps;
    QString temporary_word;
    int failed_attemps;

    bool win;
    bool over;

};

#endif // MAINWINDOW_H
