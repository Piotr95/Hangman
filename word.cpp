#include "Word.h"
#include<vector>
#include<string>
#include <fstream>
using namespace std;
Word::Word(string clue,string word)
{
this->clue=clue;
this->word=word;
}
string Word::GetWord()
{
  return this-> word;
}
string Word:: GetClue()
{
  return this-> clue;
}
