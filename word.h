#ifndef WORD_H
#define WORD_H
#include<string>
#include<QString>
using namespace std;

class Word
{
private:
  QString clue;
  QString word;


public:
    Word(QString clue, QString word);
    QString GetWord();
    QString GetClue();


};

#endif // WORD_H
