/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class declaration of Penguin
** It contains public virtual function declaration and constructor.
******************************************************************************/

#ifndef Penguins_hpp
#define Penguins_hpp

#include <stdio.h>
#include "Animal.hpp"

class Penguin : public Animal
{
public:
    Penguin();
    void setBaseFoodCost(double base);
};

#endif /* Penguins_hpp */
