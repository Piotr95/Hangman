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
//void Image:: SetNextHangmanImage()
//{
//    if(!over)
//    {
//        //ui->label_2->setPixmap(QString::fromStdString(":Hpic/normal_lvl/H"+to_string(max_attemps-attemps)+".png"));
//    }
//}
