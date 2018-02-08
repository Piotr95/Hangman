#ifndef INIT_H
#define INIT_H
#include<game.h>
#include<QHBoxLayout>
#include<QTextEdit>
#include<decorate.h>
class Game;
class Decorate;
class Init
{
public:
    Init();
    Word choseword();
    QTextEdit** initfields( Decorate *DE,int size_off_word,QHBoxLayout* word_field);

private:

};

#endif // INIT_H
