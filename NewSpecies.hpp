/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class declaration of NewSpecies
** It contains private data members and function declarations.
******************************************************************************/

#ifndef NewSpecies_hpp
#define NewSpecies_hpp

#include <stdio.h>
#include <string>
#include "Animal.hpp"

using std::string;

class NewSpecies: public Animal
{

    
        
    
    public:
        //default constructor
        NewSpecies();
    
        //virtual function declaration
        void setBaseFoodCost(double aBaseFoodCost);
        void setPayOff(double aPayOff);
    

};

#endif /* NewSpecies_hpp */
