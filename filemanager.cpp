#include "filemanager.h"
#include"word.h"
#include<QFile>
#include<QString>
#include<QIODevice>
#include<QTextStream>
#include <QStringList>
Filemanager::Filemanager()
{

}
vector<Word> Filemanager::ReadFromDictionary(QString path)
{
    vector<Word>w;
    int i=0;

   // ifstream file(path);
    QString clue;
    QString word;
    QFile file(path);
    QStringList list;
    //QString exePath = QCoreApplication::applicationDirPath();
    //QString shipsPath = exePath + QDir::separator() + path;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){

             list =stream.readLine().split(":");
             for(i;i<list.size();i+=2)
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



//   if(file.is_open()){
//       while(file >> clue>>word) {

//        Word *w1= new Word(clue,word );
//            w.push_back(*w1);



//       }
//       file.close();
//      }


