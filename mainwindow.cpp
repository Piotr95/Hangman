#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <map>
#include <iterator>
#include <QtCore>
#include"word.h"
#include"filemanager.h"
#include <vector>

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


Word MainWindow::choseword(QString path)
{
    Filemanager *f= new Filemanager();
    vector<Word>w=f->ReadFromDictionary(path);
   //int randomizer=rand()%w.size();


    return w[w.size()-1];
}

void MainWindow:: addLetters()
{

     Word initWords=choseword("Dictionary.txt");
       QTextEdit** words =initfields(initWords.GetWord().size());





    ui->label->setText( initWords.GetClue() ) ;

     }







MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Wybierz_clicked()
{
  addLetters();
}


