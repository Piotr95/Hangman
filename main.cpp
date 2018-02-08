#include "game.h"
#include <QApplication>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    Game g;
    g.show();


    return a.exec();
}
