#include "Word.h"
#include<vector>
#include<string>
#include <fstream>
#include<QString>

using namespace std;

Word::Word(QString clue,QString word)
{
    this->clue=clue;
    this->word=word;
}


QString Word::GetWord()
{
    return this-> word;
}


QString Word:: GetClue()
{
    return this-> clue;
}
