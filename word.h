#ifndef WORD_H
#define WORD_H
#include<string>
#include<vector>
using namespace std;

class Word
{
public:
  string clue;
  string word;


public:
    Word(string clue, string word);
    string GetWord();
    string GetClue();


};

#endif // WORD_H
