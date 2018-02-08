#include "init.h"
#include<filemanager.h>
#include<QHBoxLayout>
#include<QTextEdit>
Init::Init()
{

}
Word Init::choseword()
{
    Filemanager *f= new Filemanager();
    vector<Word>w=f->ReadFromDictionary();
    int randomizer=rand()%w.size();
    return w[randomizer];
}
QTextEdit** Init::initfields( Decorate *DE ,int size_off_word,QHBoxLayout* word_field)
{
     QTextEdit** words = new QTextEdit*[size_off_word];
     for( int i=0;i<size_off_word;i++)
     {
        words[i]=new QTextEdit();
        DE->decorateLetter(words[i]);
        words[i]->show();
       word_field->addWidget(words[i]);
     }
     return words;
}
