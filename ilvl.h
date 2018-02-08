#ifndef ILVL_H
#define ILVL_H
#include<string>
using namespace std;
class ILvl
{
public:
    ILvl();
     string virtual getName()=0;
    int virtual getAttemps()=0;
    int virtual getMaxAttemps()=0;
};

#endif // ILVL_H
