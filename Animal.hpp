/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class declaration of Animals
** It contains public functions, virtual funcitons, and accesor
** and mutator function declarations.
******************************************************************************/

#ifndef Animal_hpp
#define Animal_hpp

#include <stdio.h>
#include <string>

using std::string;

class Animal
{
    //private data members
    private:
    
        string stage;
        int age;
        int cost;
        int babies;
        int base;
        double baseFoodCost;
        int population;
        double payOff;
        bool inZoo;
        string name;
    
    //public function declarations
    public:
        Animal();               //default constructor
        
        
        //accessor and setter declarations
        void setAge(int age);
        int getAge();
        void addAge(int day);
        
        void setCost(int startCost);
        int getCost();
        
        void setBabies(int babies);
        int getBabies();
        void addBabies(int newBabies);
        
        virtual void setBaseFoodCost(double num);
        double getBaseFoodCost();
        
        virtual void setPayOff(double num);
        virtual double getPayOff();
    
        void setInZoo(bool num);
        bool getInZoo();
    
        void setName(string aName);
        string getName();

    
};

#endif /* Animal_hpp */
