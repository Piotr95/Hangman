#ifndef IMAGE_H
#define IMAGE_H
#include<QPixmap>
#include<QString>
#include<game.h>
class MainWindow;
class Image
{
public:
    Image();
   ~Image();
    QPixmap* load_Pic(QString path);


};

#endif // IMAGE_H
