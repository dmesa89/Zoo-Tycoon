/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class declaration of Tiger
** It contains public virtual function declaration and default
** constructor.
******************************************************************************/

#ifndef Tigers_hpp
#define Tigers_hpp

#include <stdio.h>
#include "Animal.hpp"

class Tiger : public Animal
{
    public:
    Tiger();
    void setBaseFoodCost(double base);


};

#endif /* Tigers_hpp */
