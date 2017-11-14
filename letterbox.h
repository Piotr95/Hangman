#ifndef LETTERBOX_H
#define LETTERBOX_H

#include <QMainWindow>

class LetterBox : public QTextEdit
{
QTextEdit *TE;
public:
LetterBox::LetterBox(QString symbol);

}

#endif // LETTERBOX_H
