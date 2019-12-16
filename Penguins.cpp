/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class of Penguin
** It contains public virtual function and default constructor.
******************************************************************************/

#include "Penguins.hpp"

Penguin::Penguin()
{
    setName("Penguins");
    setAge(1);
    setCost(1000);
    setBabies(5);
    setBaseFoodCost(0);
    setPayOff(1000 *.10);
    setInZoo(0);
};

void Penguin::setBaseFoodCost(double base)
{
    Animal::setBaseFoodCost(base);
}
