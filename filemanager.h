#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include<string>
#include<vector>
#include"word.h"
#include<fstream>

using namespace std;

class Filemanager
{
public:
    Filemanager();
    vector<Word>ReadFromDictionary(QString path);
};

#endif // FILEMANAGER_H
