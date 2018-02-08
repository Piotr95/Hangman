#include "image.h"
#include<QPixmap>
Image::Image()
{

}
QPixmap* Image::load_Pic(QString path)
{
    QPixmap *tempPixmap = new QPixmap(path);
    if(tempPixmap->isNull())
    {
       exit(0);
    }
    return tempPixmap;
}

