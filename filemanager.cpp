#include "filemanager.h"
#include"word.h"
Filemanager::Filemanager()
{

}
vector<Word>* Filemanager::ReadFromDictionary(string path )
{
   vector<Word>*w= new vector<Word>();

   ifstream file(path);
   string clue;
   string word;
   while(file >> clue>>word) {

    Word *w1= new Word(clue,word );
        w->push_back(*w1);



   }
   return w;
}

