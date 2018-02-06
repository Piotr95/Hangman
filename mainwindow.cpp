#include "mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent) :
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
    outputText = "";
    ui->line->setFocus();
    NewGame();
}

void MainWindow::random_word()
{
    this->currentword=new Word( choseword());
}


Word* MainWindow::Getword()
{
 return this->currentword;
}

void MainWindow::keyboardHandler(){
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
void MainWindow::Bclear_clicked()
{
    outputText="";
    ui->line->setText(outputText);
}


void MainWindow::Benter_clicked()
{
    if(outputText.size()>0 && (!win)&&(!over))
    {
        ui->Text_Board->append("You entered :  \n"+outputText);
        guess(outputText);
        outputText="";
    }
}

void MainWindow::Bback_clicked()
{
    outputText.remove(outputText.length()-1,outputText.length());
    ui->line->setText(outputText);
}


void MainWindow::decorate(QTextEdit *TE)
{
 TE->setReadOnly(true);
 TE->setMaximumSize(31,42);
 TE->setMinimumSize(31,42);
 TE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 TE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 TE->setGeometry(148,42,944,494);
 TE->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">_</span></p></body></html>", Q_NULLPTR));
}


QTextEdit** MainWindow::initfields( int size_off_word)
{
     QTextEdit** words = new QTextEdit*[size_off_word];
     for( int i=0;i<size_off_word;i++)
     {
        words[i]=new QTextEdit();
        decorate(words[i]);
        words[i]->show();
        ui->word_field->addWidget(words[i]);
     }
     return words;
}


void::MainWindow::SetWordFields(QTextEdit** words)
{
    this->words=words;
}


QTextEdit**::MainWindow::GetWordFields()
{
    return this->words;
}


Word MainWindow::choseword()
{
    Filemanager *f= new Filemanager();
    vector<Word>w=f->ReadFromDictionary();
    int randomizer=rand()%w.size();
    return w[randomizer];
}


 void MainWindow:: addLetters()
{
    QTextEdit** temp_word_fields =initfields(currentword->GetWord().size());
    SetWordFields(temp_word_fields);
    ui->label->setText( currentword->GetClue() ) ;
 }


void MainWindow:: guess(QString Text)
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


void MainWindow::NewGame()
{
    Clear_Word_field();
    Reset_Text_Board();
    Clear_ProgressBar();
    random_word();
    addLetters();

    win=false;
    over=false;
    Normal_lvl();
    initProgressbar();
    ui->label_2->setPixmap(QString::fromStdString(":Hpic/normal_lvl/H"+to_string(7-failed_attemps)+".png"));


}


void MainWindow:: SetNextHangmanImage()
{
    if(!over)
    {
        ui->label_2->setPixmap(QString::fromStdString(":Hpic/normal_lvl/H"+to_string(7-failed_attemps)+".png"));
    }
}


void MainWindow::Clear_Word_field()
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
void MainWindow::Clear_ProgressBar()
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


void MainWindow::Reset_Text_Board()
{
    ui->Text_Board->setText("");
    QString initial_Text="Enter your guess letter:";
    ui->Text_Board->setText(initial_Text);
    Decorate_Text_Box();

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Decorate_Text_Box()
{
    ui->Text_Board->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
    "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
    "p, li { white-space: pre-wrap; }\n"
    "</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
    "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
    "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Enter your guess letter:</span></p></body></html>", Q_NULLPTR));
}


void MainWindow::NewGame_clicked()
{
    NewGame();
}


void MainWindow:: Normal_lvl()
{
    QPixmap *temp[8];
    QString s;
    failed_attemps=7;
    int j=0;
    for(int i=7;i>=0;i--)
    {
        temp[j] = load_Pic(QString(":Hpic/normal_lvl/H"+s.setNum(i)+".png"));
        j++;
    }
    SetHangmanSteps(temp);
}


void MainWindow::SetHangmanSteps(QPixmap** steps)
{
    this->hangman_steps=steps;
}


QPixmap* MainWindow::load_Pic(QString path)
{
    QPixmap *tempPixmap = new QPixmap(path);
    if(tempPixmap->isNull())
    {
       exit(0);
    }
    return tempPixmap;
}


void MainWindow:: InitTemporary()
{
    int size= currentword->GetWord().size();
    for (int i=0;i<size;i++)
    {
        temporary_word[i]='_';
    }
}


void MainWindow:: CheckGameWin()
{
    qDebug()<<currentword->GetWord();
    qDebug()<<temporary_word;
    if(currentword->GetWord().toLower()==temporary_word.toLower())
    {
        win=true;
        WinGame();
    }
}

void MainWindow:: WinGame()
{
     ui->Text_Board->append("You Win :)  \n");
}


void MainWindow::failed_attempt()
{
    failed_attemps-=1;
    SetNextHangmanImage();
    decrProgressbar();
}


void MainWindow:: CheckGameOver()
{

    if(failed_attemps==0)
    {

      GameOver();
      over=true;

    }

}


void MainWindow::GameOver()
{
    ui->Text_Board->append("Game Over :(  \n");
}


void MainWindow::initProgressbar()
{
    health_points=new QProgressBar;

     health_points->setOrientation(Qt::Vertical);
     health_points->setTextDirection(QProgressBar::BottomToTop);
     qDebug()<<failed_attemps;
     health_points->setRange(0, failed_attemps);
     health_points->setValue(failed_attemps);
     health_points->setTextVisible(false);
     health_points->setStyleSheet("::chunk {""background-color: red}");
     ui->PB->insertWidget(0,health_points);
}

void MainWindow::decrProgressbar()
{

 health_points->setValue(failed_attemps);


}


