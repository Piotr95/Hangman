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
    connect ( ui->Benter, SIGNAL( clicked()), this, SLOT( keyboardHandler() ) );
    connect ( ui->Bclear, SIGNAL( clicked()), this, SLOT( on_clear_clicked() ) );
    outputText = "";
    ui->Line->setFocus();
    NewGame();







}

void MainWindow::random_word()
{
    this->currentword=new Word( choseword("Dictionary.txt"));
}

Word* MainWindow::Getword()
{
 return this->currentword;
}



void MainWindow::keyboardHandler()
{
    QPushButton *B = (QPushButton *)sender();


    QString inputText = B->text();

    if (inputText == "Space")
    {
        outputText += " ";
    }
    else if(inputText == "Enter")
    {

                outputText += "";


    }

    else
    {

            outputText += inputText;

    }


    ui->Line->setText(outputText);

}

void MainWindow::setLine(QLineEdit * Line)
{
    Line = Line;
}
void MainWindow::on_clear_clicked()
{
    outputText="";
    ui->Line->setText(outputText);
}



void MainWindow::on_Benter_clicked()
{
if(outputText.size()>0)
{

    ui->Text_Board->append("You entered :  \n"+outputText);
    guess(outputText);
    outputText="";


}
}




void MainWindow::on_Bback_clicked()
{
    outputText.remove(outputText.length()-1,outputText.length());
    ui->Line->setText(outputText);
}













void MainWindow::decorate(QTextEdit *TE)
{

 TE->setReadOnly(true);
 TE->setMaximumSize(31,42);
 TE->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 TE->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 TE->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">_</span></p></body></html>", Q_NULLPTR));
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
          ui->word_field->addWidget(words[i]);

     }
     return words;

}
void::MainWindow::Setwords(QTextEdit** words)
{
    this->words=words;
}

QTextEdit**::MainWindow::Getwords()
{
    return this->words;
}


Word MainWindow::choseword(QString path)
{

    Filemanager *f= new Filemanager();
    vector<Word>w=f->ReadFromDictionary();
   int randomizer=rand()%w.size();

    qDebug()<<randomizer;
    qDebug()<<w.size();
    return w[randomizer];
}

 QTextEdit** MainWindow:: addLetters()
{


       QTextEdit** temp_words =initfields(currentword->GetWord().size());
       Setwords(temp_words);





    ui->label->setText( currentword->GetClue() ) ;


 }
void MainWindow:: guess(QString Text)
{
 QTextEdit** temp_words=Getwords();
 Word* W=Getword();

   QString current_guess_word=W->GetWord().toLower();

   if(Text.length()>1)
   {
    if(current_guess_word==Text )
    {
        for(int i=0;i<current_guess_word.length();i++)
      {


            if(i==0)
            {
           temp_words[i]->setText(Text.at(i).toUpper());
            }
            else
            {
            temp_words[i]->setText(Text.at(i));
            }
              }

        ui->Text_Board->append("You Win :)  \n");

    }
    else
           ui->Text_Board->append("Ii is diffrent  word try again :) \n");
   }

   else
   {
     if(current_guess_word.contains(Text))
       {
          for(int i=0;i<current_guess_word.length();i++)
        {
            if(current_guess_word.at(i).toLower()==(Text.at(0)))
            {
             if(i==0)
             {
            temp_words[i]->setText(Text.toUpper());
             }
             else
             {
             temp_words[i]->setText(Text);
             }
            }
       }
     }
       else
       {
        ui->Text_Board->append(" Word don't contains this letters try again :)  \n");
       }



   }

}
void MainWindow::NewGame()
{
    Clear_Word_field();
    Reset_Text_Board();
    random_word();
    addLetters();
}
void MainWindow::EndGame()
{

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

void MainWindow::on_Wybierz_clicked()
{
 // addLetters();
// Clear_Word_field();
// Clear_Text_Board();
 NewGame();
}


