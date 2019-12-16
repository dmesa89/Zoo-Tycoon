/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is the class declaration of Zoo.
** It contains private data members and function declarations.
******************************************************************************/
#ifndef Zoo_hpp
#define Zoo_hpp

#include <stdio.h>
#include "Tigers.hpp"
#include "Turtles.hpp"
#include "Penguins.hpp"
#include "Animal.hpp"
#include "NewSpecies.hpp"
#include "InputValidation.hpp"


class Zoo
{
    //private data members
    private:
        Tiger* tigers;
        Turtle* turtles;
        Penguin* penguins;
        NewSpecies* newSpecies;
        double bank;
        double dailyProfit;
        int tigerSize, penguinSize, turtleSize, newSpeciesSize;
        double base;
        double newBase;
        int dailyFeedType;
        bool newSpeciesChoice = false;
        int days;
        int newFoodMultiplier;
        double dailyFoodDeduction;
    
    public:
    
        
        Zoo();                      //default constructor
        void runZoo();               
        void startZoo();
        void initialBuy(Animal* animal);
        void feedingAnimals(Animal* animal, int size);
        void randomEvent();
        void profitForTheDay(Animal* animal, int size);
        bool animalSick();
        void attendanceBoom();
        void babyBorn();
        bool adultPresent(Animal* animal, int size);
        bool roomForAnimal(Animal* animal, int size);
        bool removeAnimal(Animal* animal, int size);
        void largerSize(Tiger* animal);
        void largerSize(Penguin* animal);
        void largerSize(Turtle* animal);
        void largerSize(NewSpecies* animal);
        void buyAdultAnimal();
        bool endOfDay();
        void changeBaseCost(double base);
        void addAnimal(Animal* animal, int age);
        void addNewSpecies();
        void differentFeedTypes();
        void aDayOlder(Animal* animal, int size);
        void sendText(string inputString);
        bool isThereEnoughInBank();
    

    
    
    

    
    
};

#endif /* Zoo_hpp */
