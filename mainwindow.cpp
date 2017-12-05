#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <map>
#include <iterator>
#include <QtCore>
#include"word.h"
#include"filemanager.h"

#include<cstdlib>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::decorate(QTextEdit *TE)
{

    TE->setReadOnly(true);
    TE->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    TE->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    TE->setMaximumSize(31,42);
    TE->setMaximumSize(31,42);
    TE->setAlignment(Qt::AlignCenter| Qt::AlignBottom);
    TE->setPlaceholderText(" _ ");
    TE->setFontPointSize(8);
    TE->setFontFamily("MS Shell Dlg 2");
}
QTextEdit** MainWindow::initfields( int size_off_word)
{


    int i=0;
          QTextEdit** words = new QTextEdit*[size_off_word];
     for(i;i<size_off_word;i++)
     {
        words[i]=new QTextEdit();
        decorate(words[i]);

        words[i]->show();
          ui->HorizontalLayout->addWidget(words[i]);

     }
     return words;

}
void MainWindow:: addLetters()
{
    Word initWords=choseword("Dictionary.txt");


        //TE'
    int i=0;
    string currentword=initWords.GetWord();
    int size_off_word=currentword.size();

          QTextEdit** words =initfields(size_off_word);
     for(i;i<size_off_word;i++)
     {
        words[i]=new QTextEdit();
        words[i]->setPlaceholderText(QString(currentword.at(i)));

        words[i]->show();
          ui->HorizontalLayout->addWidget(words[i]);

     }

}

Word MainWindow::choseword(string path)
{
    Filemanager *f= new Filemanager();
    vector<Word>*w=f->ReadFromDictionary(path);
    int randomizer=rand()%w->size();

    Word *chosen= new Word (w->at(randomizer).GetClue(),w->at(randomizer).GetWord());

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Wybierz_clicked()
{
 //   addLetters();
}


