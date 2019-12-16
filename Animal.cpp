/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is a class named Animal.
** It contains a default constructor that initializes data members.
** It also contains It contains accessor and mutator functions
******************************************************************************/

#include "Animal.hpp"

/******************************************************************************
** Animal::Animal()
** It contains a default constructor that initializes data members.
******************************************************************************/

Animal::Animal()
{
    name = " ";
    age = 0;
    cost = 0;
    babies = 0;
    baseFoodCost = 0.0;
    payOff = 0.0;
    inZoo = 0;
    
}

/******************************************************************************
** void Animal::setAge(int days)
**This method sets the age days. it take in an int.
******************************************************************************/
void Animal::setAge(int days)
{age = days;}

/******************************************************************************
** void Animal::addAge(int day)
 ** This method increments the age. It takes in an int.
******************************************************************************/
void Animal::addAge(int day)
{ age += age;}

/******************************************************************************
** int Animal::getAge()
 ** This method returns the age.
******************************************************************************/
int Animal::getAge()
{ return age;}

/******************************************************************************
** void Animal::addAge(int day)
 ** This method sets the cost. It takes in an int.
******************************************************************************/
void Animal::setCost(int startCost)
{ cost = startCost; }

/******************************************************************************
**int Animal::getCost()
 ** This method returns the cost.
******************************************************************************/
int Animal::getCost()
{ return cost; }

/******************************************************************************
** void Animal::setBabies(int startBabies)
** This method sets the babies. It takes in an int.
******************************************************************************/
void Animal::setBabies(int startBabies)
{ babies = startBabies;}

/******************************************************************************
**int Animal::getBabies()
** This method returns the babies.
******************************************************************************/
int Animal::getBabies()
{ return babies;}

/******************************************************************************
**void Animal::addBabies(int newBabies)
** This method increments the babies
******************************************************************************/
void Animal::addBabies(int newBabies)
{ babies += newBabies; }

/******************************************************************************
**void Animal::setBaseFoodCost(double startFoodCost)
** This method sets the BaseFoodCost. it takes in a double
******************************************************************************/
void Animal::setBaseFoodCost(double startFoodCost)
{ baseFoodCost = startFoodCost; }

/******************************************************************************
**double Animal::getBaseFoodCost()
** This method returns the BaseFoodCost.
******************************************************************************/
double Animal::getBaseFoodCost()
{ return baseFoodCost;}

/******************************************************************************
**void Animal::setPayOff(double startPayOff)
** This method sets the payOff. it takes in a double
******************************************************************************/
void Animal::setPayOff(double startPayOff)
{ payOff = startPayOff;}

/******************************************************************************
**double Animal::getPayOff()
** This method returns the payOff.
******************************************************************************/
double Animal::getPayOff()
{ return payOff;}


/******************************************************************************
*void Animal::setInZoo(bool num)
** This method sets the inZoo. it takes in a bool
******************************************************************************/
void Animal::setInZoo(bool num)
{ inZoo = num; }

/******************************************************************************
*bool Animal::getInZoo()
** This method returns the inZoo.
******************************************************************************/
bool Animal::getInZoo()
{ return inZoo; }

/******************************************************************************
*void Animal::setName(string aName)
** This method sets the name. It takes in a string
******************************************************************************/
void Animal::setName(string aName)
{
    name = aName;
}

/******************************************************************************
string Animal::getName()
** This method returns the name.
******************************************************************************/
string Animal::getName()
{
    return name;
}

