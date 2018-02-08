#ifndef Game_H
#define Game_H

#include <QMainWindow>
#include <QTextEdit>
#include"word.h"
#include<QLineEdit>
#include<QPixmap>
#include<QProgressBar>
#include "image.h"
#include "decorate.h"
#include "init.h"
#include "ilvl.h"
namespace Ui {
class MainWindow;
}
class Image;
class Decorate;
class Init;
class ILvl;

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

    //init game
     void SetLvl();
     void InitTemporary();
     void SetWordFields(QTextEdit** words);
     QTextEdit** GetWordFields();
     void random_word();
     Word* Getword();
     void SetWord(Word* word);
     void Clear_Word_field();
     void Reset_Text_Board();
     void initProgressbar();
     void Clear_ProgressBar();
     void decrProgressbar();
    //game

    void guess(QString Text);
    void addLetters();
    void failed_attempt();
    int*Find_letters(QString k);
    void FillTemporary();
    void CheckGameWin();
    void WinGame();
    void CheckGameOver();
    void NewGame();
    void GameOver();
    void setTemporary(QString text);
   //Image
   void SetNextHangmanImage();



    //Lvl
    void Normal_lvl();
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
    QString temporary_word;
    QProgressBar* health_points;
    int max_attemps;
    int attemps;
    Init*IT;
    Image* IM;
    Decorate* DE;
    ILvl* IL;

    bool win;
    bool over;

};

#endif
