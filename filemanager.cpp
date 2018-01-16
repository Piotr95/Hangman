#include "filemanager.h"
#include"word.h"
#include<QFile>
#include<QString>
#include<QIODevice>
#include<QTextStream>
#include <QStringList>
#include <QDebug>
Filemanager::Filemanager()
{

}
vector<Word> Filemanager::ReadFromDictionary()
{
    vector<Word>w;



    QString clue;
    QString word;
    QFile file(":Words/Dictionary.txt");
    QStringList list;
    QTextStream TS;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){

             list =stream.readLine().split(":");
             for(int i=0;i<list.size();i+=2)
             {
             clue=list.at(i);
             word=list.at(i+1);
               Word *w1= new Word(clue,word );
               w.push_back(*w1);
              }
             list.clear();


                  }
               file.close();
            }
    else
       {
           Word *w1= new Word("clue","word" );
               w.push_back(*w1);
       }

       return w;


    }




