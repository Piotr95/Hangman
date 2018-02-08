#ifndef DECORATE_H
#define DECORATE_H
#include<QTextEdit>
#include<QTextBrowser>
#include<QProgressBar>

class Decorate
{
public:
    Decorate();
    void decorateLetter(QTextEdit* TE);
    void decorateTextBoard(QTextBrowser *TB);
    void decoreteProgressBar(QProgressBar* health_points,int failed_attemps);


};

#endif // DECORATE_H
