#ifndef HARDLVL_H
#define HARDLVL_H
#include<ilvl.h>
class HardLvl: public ILvl
{
public:
    HardLvl();
    string virtual getName();
    int virtual getAttemps();
    int virtual getMaxAttemps();
};


#endif // HARDLVL_H
