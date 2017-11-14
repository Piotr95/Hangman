#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    TE->setPlaceholderText(" _ ");
    TE->setFontPointSize(8);
    TE->setFontFamily("MS Shell Dlg 2");
}
void MainWindow::addLetters( int size_off_word)
{
    QTextEdit* letter = new QTextEdit;
     decorate(letter);
  ;
    int i=0;
          QTextEdit** word = new QTextEdit*[size_off_word];
     for(i;i<size_off_word;i++)
     {
        word[i]=new QTextEdit();
        decorate(word[i]);

        word[i]->show();
          ui->HorizontalLayout->addWidget(word[i]);
     }
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Wybierz_clicked()
{
    addLetters(4);
}


