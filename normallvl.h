#ifndef NORMALLVL_H
#define NORMALLVL_H
#include<ilvl.h>
#include<string>

class NormalLvl: public ILvl
{
public:
    NormalLvl();
    string virtual getName();
    int virtual getAttemps();
    int virtual getMaxAttemps();
};

#endif // NORMALLVL_H
