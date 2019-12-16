/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class Zoo. It contain a default
** constructor and virtual functions
******************************************************************************/

#include "NewSpecies.hpp"

/******************************************************************************
**NewSpecies::NewSpecies()
** This is the default constructor that initializes data members.
******************************************************************************/
NewSpecies::NewSpecies()
{
    setName(" ");
    setAge(0);
    setCost(0);
    setBabies(0);
    setBaseFoodCost(0);
    setPayOff(0);
    setInZoo(0);

}



/******************************************************************************
**void NewSpecies::setBaseFoodCost(double aBaseFoodCost)
** This is a virtual function that sets the basefoodcost. It
** takes in a double.
******************************************************************************/
void NewSpecies::setBaseFoodCost(double aBaseFoodCost)
{
    Animal::setBaseFoodCost(aBaseFoodCost);
}

/******************************************************************************
**void NewSpecies::setPayOff(double aPayOff)
** This is a virtual function that sets the payOff. It
** takes in a double.
******************************************************************************/
void NewSpecies::setPayOff(double aPayOff)
{
    Animal::setPayOff(aPayOff);
}


