/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class of Tiger
** It contains public virtual function and default
** constructor.
******************************************************************************/

#include "Tigers.hpp"

Tiger::Tiger()
{
    setName("Tigers");
    setAge(1);
    setCost(10000);
    setBabies(1);
    setBaseFoodCost(0);
    setPayOff(10000 *.20);
    setInZoo(0);
    
}

void Tiger::setBaseFoodCost(double base)
{
    Animal::setBaseFoodCost(5*base);
}


