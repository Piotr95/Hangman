#include "Game.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <map>
#include <iterator>
#include <QtCore>
#include"word.h"
#include"filemanager.h"
#include <vector>
#include<QDebug>
#include<cstdlib>
#include<QPixmap>
#include <QProgressBar>
#include<easylvl.h>
#include<normallvl.h>
#include<hardlvl.h>


Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect ( ui->Bq, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bw, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Be, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Br, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bt, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->By, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bu, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bi, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bo, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bp, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );

    connect ( ui->Ba, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bs, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bd, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bf, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bg, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bh, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bj, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bk, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bl, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );

    connect ( ui->Bz, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bx, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bc, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bv, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bb, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bn, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bm, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );

    connect ( ui->B0, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->B1, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->B2, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->B3, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->B4, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->B5, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->B6, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->B7, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->B8, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->B9, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );

    connect ( ui->Bspace, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Benter, SIGNAL( clicked()), this, SLOT( Benter_clicked() ) );
    connect ( ui->Bclear, SIGNAL( clicked()), this, SLOT( Bclear_clicked() ) );
    connect ( ui->BNew, SIGNAL( clicked()), this, SLOT( NewGame_clicked() ) );
    Game::setWindowTitle("Hangman created by Piotr Szczepaniak");
    ui->Lvl->addItem("Easy");
    ui->Lvl->addItem("Normal");
    ui->Lvl->addItem("Hard");

    outputText = "";
    ui->line->setFocus();
    NewGame();
}

void Game::random_word()
{
   this->currentword=new Word( IT->choseword());
}


Word* Game::Getword()
{
 return this->currentword;
}

void Game::keyboardHandler(){
    QPushButton *B = (QPushButton *)sender();
    QString inputText = B->text();
    if (inputText == "Space"){
        outputText += " ";
    }else if(inputText == "Enter"){
        outputText += "";
    }else{
        outputText += inputText;
    }
    ui->line->setText(outputText);
}
void Game::Bclear_clicked()
{
    outputText="";
    ui->line->setText(outputText);
}


void Game::Benter_clicked()
{
    if(outputText.size()>0 && (!win)&&(!over))
    {
        ui->Text_Board->append("You entered :  \n"+outputText);
        guess(outputText);
        outputText="";
    }
}

void Game::Bback_clicked()
{
    outputText.remove(outputText.length()-1,outputText.length());
    ui->line->setText(outputText);
}




//QTextEdit** Game::initfields( int size_off_word)
//{
//     QTextEdit** words = new QTextEdit*[size_off_word];
//     for( int i=0;i<size_off_word;i++)
//     {
//        words[i]=new QTextEdit();
//        DE->decorateLetter(words[i]);
//        words[i]->show();
//        ui->word_field->addWidget(words[i]);
//     }
//     return words;
//}


void::Game::SetWordFields(QTextEdit** words)
{
    this->words=words;
}


QTextEdit**::Game::GetWordFields()
{
    return this->words;
}


//Word Game::choseword()
//{
//    Filemanager *f= new Filemanager();
//    vector<Word>w=f->ReadFromDictionary();
//    int randomizer=rand()%w.size();
//    return w[randomizer];
//}


 void Game:: addLetters()
{
    QTextEdit** temp_word_fields =IT->initfields(DE,currentword->GetWord().size(),ui->word_field);
    SetWordFields(temp_word_fields);
    ui->label->setText( currentword->GetClue() ) ;
 }


void Game:: guess(QString Text)
{
    QTextEdit** temp_word_fields=GetWordFields();
    Word* W=Getword();
    QString current_guess_word=W->GetWord().toLower();
    if(Text.length()>1)
    {
        temporary_word=Text;
        if(current_guess_word==temporary_word )
        {
            for(int i=0;i<current_guess_word.length();i++)
            {
                if(i==0)
                {
                    temp_word_fields[i]->setText(Text.at(i).toUpper());
                }
                else
                {
                    temp_word_fields[i]->setText(Text.at(i));
                }
            }

            CheckGameWin();

        }
        else
            failed_attempt();
            ui->Text_Board->append("Ii is diffrent  word try again :) \n");
            CheckGameOver();
    }
    else
    {
        if(current_guess_word.contains(Text.at(0)))
        {
            for(int i=0;i<current_guess_word.length();i++)
            {
                if(current_guess_word.at(i).toLower()==(Text.at(0)))
                {
                    if(i==0)
                    {
                        temp_word_fields[i]->setText(Text.toUpper());
                        temporary_word[i]=Text.at(0).toUpper();
                    }
                    else
                    {
                        temp_word_fields[i]->setText(Text);
                        temporary_word[i]=Text.at(0);
                    }
                }
            }

            CheckGameWin();


        }
        else
        {
            failed_attempt();
            ui->Text_Board->append(" Word don't contains this letters try again :)  \n");
            CheckGameOver();
        }
    }
}


void Game::NewGame()
{

    Clear_Word_field();
    Reset_Text_Board();
    Clear_ProgressBar();
    random_word();
    addLetters();
    SetLvl();
    attemps=IL->getAttemps();
    max_attemps=IL->getMaxAttemps();

    win=false;
    over=false;
    //Normal_lvl();
    initProgressbar();
    ui->label_2->setPixmap(QString::fromStdString(":Hpic/normal_lvl/H"+to_string(max_attemps-attemps)+".png"));


}


void Game:: SetNextHangmanImage()
{
    if(!over)
    {
        ui->label_2->setPixmap(QString::fromStdString(":Hpic/"+IL->getName()+"/H"+to_string(max_attemps-attemps)+".png"));
    }
}


void Game::Clear_Word_field()
{
    if (ui->word_field) {
        while(ui->word_field->count() > 0){
            QLayoutItem *item = ui->word_field->takeAt(0);
            QWidget* widget = item->widget();
            if(widget)
                delete widget;
            delete item;
        }
    }
}
void Game::Clear_ProgressBar()
{
    if (ui->PB) {
        while(ui->PB->count() > 0){
            QLayoutItem *item = ui->PB->takeAt(0);
            QWidget* widget = item->widget();
            if(widget)
                delete widget;
            delete item;
        }
    }
}


void Game::Reset_Text_Board()
{
    ui->Text_Board->setText("");
    QString initial_Text="Enter your guess letter:";
    ui->Text_Board->setText(initial_Text);
    DE->decorateTextBoard(ui->Text_Board);

}


Game::~Game()
{
    delete ui;
}







void Game::NewGame_clicked()
{
    NewGame();
}


//void Game:: Normal_lvl()
//{
//    QPixmap *temp[8];
//    QString s;
//    max_attemps=7;
//    attemps=7;


//}




void Game:: InitTemporary()
{
    int size= currentword->GetWord().size();
    for (int i=0;i<size;i++)
    {
        temporary_word[i]='_';
    }
}


void Game:: CheckGameWin()
{
    qDebug()<<currentword->GetWord();
    qDebug()<<temporary_word;
    if(currentword->GetWord().toLower()==temporary_word.toLower())
    {
        win=true;
        WinGame();
    }
}

void Game:: WinGame()
{
     ui->Text_Board->append("You Win :)  \n");
}


void Game::failed_attempt()
{
    attemps-=1;
    SetNextHangmanImage();
    decrProgressbar();
}


void Game:: CheckGameOver()
{

    if(attemps==0)
    {

      GameOver();
      over=true;

    }

}


void Game::GameOver()
{
    ui->Text_Board->append("Game Over :(  \n");
}


void Game::initProgressbar()
{
    health_points=new QProgressBar;

     DE->decoreteProgressBar(health_points,attemps);
     ui->PB->insertWidget(0,health_points);
}

void Game::decrProgressbar()
{

 health_points->setValue(attemps);


}
   void Game:: setTemporary(QString text)
   {
       this->temporary_word=text;
   }
void Game::SetWord( Word *word)
   {
       this->currentword=word;
   }
void Game::SetLvl()
{
 if(ui->Lvl->currentText()=="Easy")
 {
     IL=new EasyLvl();
 }
 else
 {
     if(ui->Lvl->currentText()=="Normal")
     {
         IL=new NormalLvl();
     }
     else {
         IL=new HardLvl();
     }

 }


}

