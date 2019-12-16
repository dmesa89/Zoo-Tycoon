/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class Turtle. It contain a default
** constructor and virtual functions
******************************************************************************/
#include "Turtles.hpp"

/******************************************************************************
**Turtle::Turtle()
** This is the default constructor that initializes data members.
******************************************************************************/
Turtle::Turtle()
{
    setName("Turtles");
    setAge(1);
    setCost(100);
    setBabies(10);
    setBaseFoodCost(0);
    setPayOff(100 *.05);
    setInZoo(0);

}

/******************************************************************************
**void NewSpecies::setBaseFoodCost(double aBaseFoodCost)
** This is a virtual function that sets the basefoodcost. It
** takes in a double.
******************************************************************************/
void Turtle::setBaseFoodCost(double base)
{
    Animal::setBaseFoodCost(base/2); 
}
