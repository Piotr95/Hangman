#ifndef EASYLVL_H
#define EASYLVL_H
#include<ilvl.h>
#include<string>

class EasyLvl: public ILvl
{
public:
    EasyLvl();
    string virtual getName();
    int virtual getAttemps();
    int virtual getMaxAttemps();
};

#endif // EASYLVL_H
