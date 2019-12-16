/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class declaration of Turtle
** It contains public virtual function declaration and default
** constructor.
******************************************************************************/

//include guards
#ifndef Turtles_hpp
#define Turtles_hpp

#include <stdio.h>
#include "Animal.hpp"

class Turtle : public Animal
{
    public:
        Turtle();
        void setBaseFoodCost(double base);
};


#endif /* Turtles_hpp */
