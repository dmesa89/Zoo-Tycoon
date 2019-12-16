/******************************************************************************
** Project Name: Zoo Tycoon
** Author: Daniel Mesa
** Date: 10/27/19
** Descriptin:  This is a class named Zoo.
** It contains a default constructor that initializes data members.
** It also contains It contains functions that run the zoo game, and
** various methods to buy animals, feed animals, collect daily profit
** deduct daily expenses and set get methods to regulate
** changes in animal class.
******************************************************************************/

#include "Zoo.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>


using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::fixed;


/******************************************************************************
**Zoo::Zoo()
** It contains a default constructor that initializes data members.
******************************************************************************/
Zoo::Zoo()
{

    bank = 50000;
    dailyProfit = 0;
    tigerSize = 10;
    turtleSize = 10;
    penguinSize = 10;
    newSpeciesSize = 10;
    tigers = new Tiger[tigerSize];
    turtles = new Turtle[turtleSize];
    penguins = new Penguin[penguinSize];
    newSpecies = new NewSpecies[newSpeciesSize];
    newSpeciesChoice = false;
    dailyFoodDeduction = 0;
    

}


/******************************************************************************
**void Zoo::runZoo()
** This is a metho that runs the zoo. It cycles through the daily
** processes of feeding animals, collecting profits, deducting
** costs and changing states of animals.
******************************************************************************/
void Zoo::runZoo()
{
    base = 5;
    bool gameStatus = true;
    //initial buying of animals
    startZoo();
    
    while(isThereEnoughInBank() == true && gameStatus == true)
    {
        //choose feed type and change food cost for each animal
        differentFeedTypes();
        changeBaseCost(base);
        
        //feeding the animals
        cout << endl;
        
        feedingAnimals(tigers, tigerSize);
        feedingAnimals(turtles, turtleSize);
        feedingAnimals(penguins, penguinSize);
        if(newSpeciesChoice == true)
        {feedingAnimals(newSpecies, newSpeciesSize);}
        cout << "Total food deductions are ";
        cout <<fixed <<std::setprecision(2) << dailyFoodDeduction << endl;
        bank -= dailyFoodDeduction;
        cout << "Total in bank after deductions is " <<bank << endl;
        cout << endl;

        
        if(isThereEnoughInBank() == true)
        {
            cout << endl;
            //random event takes place
            randomEvent();
            
            cout << endl;
            //calculate profit for the day
            profitForTheDay(tigers, tigerSize);
            profitForTheDay(turtles, turtleSize);
            profitForTheDay(penguins, penguinSize);
            if(newSpeciesChoice == true)
            {profitForTheDay(newSpecies, newSpeciesSize); }
            
            cout << endl;
            cout << "The daily profit of ";
            cout << std::setprecision(2) << fixed  << dailyProfit;
            cout << " will be added to your bank of " << bank << endl;
            bank = bank + dailyProfit;
            cout << "You now have " << bank << " in the bank." << endl;
            
            //every animal is a day older
            aDayOlder(tigers, tigerSize);
            aDayOlder(turtles, turtleSize);
            aDayOlder(penguins, penguinSize);
            if(newSpeciesChoice==true)
            {aDayOlder(newSpecies, newSpeciesSize);}
            dailyProfit = 0;
            dailyFoodDeduction = 0;
        }
        
        //prompt user to play again or end game
        gameStatus = endOfDay();
        if(gameStatus == true)
        {buyAdultAnimal();}
    

    }
    
    if(isThereEnoughInBank() == false)
    { cout << "You have run out of money. Game Over" << endl;}
    
    //delete arrays if ending game
    if(gameStatus == false)
    {
        delete[] tigers;
        delete [] turtles;
        delete [] penguins;
        if(newSpeciesChoice == true)
        {delete [] newSpecies; }
    }


}


/******************************************************************************
**void Zoo::runZoo()
** This is a method that allows for initial buying of animals
** by sorting out which animals to send as parameters to
** initialbuy function of the zoo.
******************************************************************************/
void Zoo::startZoo()
{
    if(isThereEnoughInBank() == true)
    {
        
        cout << "Welcome to Zoo Tycoon!" << endl;
        char choice;
        cout << "Before we begin, Would you like to add a new animal class to the zoo? ";
        choice = inputValidationChar();
        while(choice != 'y' && choice != 'n')
        {
            cout << "Please enter valid [y/n] lower case letter: ";
            choice = inputValidationChar();
        }
        
        if(choice == 'y')
        {addNewSpecies();}
        
        cout << "Now back to your zoo!" <<endl;
        cout << "You have " << bank << " in the bank!" << endl;
        cout << "Lets start off by adding animals to your zoo." << endl;

        //prompt user to buy tigers and validate
        cout << "Would you like to buy tigers? ";
        choice = inputValidationChar();
        
        while(choice != 'y' && choice != 'n')
        {
            cout << "Please enter valid [y/n] lower case letter: ";
            choice = inputValidationChar();
        }
        
        if(choice == 'y')
        {initialBuy(tigers);}
        
        //prompt user to buy turtles and validate
        cout << "Would you like to buy turtles? ";
        choice = inputValidationChar();
        
        while(choice != 'y' && choice != 'n')
        {
            cout << "Please enter valid [y/n] lower case letter: ";
            choice = inputValidationChar();
        }
        
        if(choice == 'y')
        {initialBuy(turtles);}
        
        //prompt user to buy penguins and validate
        cout << "Would you like to buy penguins? ";
        choice = inputValidationChar();
        
        while(choice != 'y' && choice != 'n')
        {
            cout << "Please enter valid [y/n] lower case letter: ";
            choice = inputValidationChar();
        }
        
        if(choice == 'y')
        {initialBuy(penguins);}
        

        if(newSpeciesChoice == true)
        {
            cout << "Would you like to buy " << newSpecies->getName() <<"? ";
            choice = inputValidationChar();
            while(choice != 'y' && choice != 'n')
            {
                cout << "Please enter valid [y/n] lower case letter: ";
                choice = inputValidationChar();
            }
            if(choice == 'y')
            {initialBuy(newSpecies);}
        }

            
    }

}


/******************************************************************************
**void Zoo::initialBuy(Animal* animal)
** This is a method that allows for initial buying of animals
** it takes in an animal pointer and prompts the user
** for number of animals to purchase and deducts the cost
** and sets variables. There is no return.
******************************************************************************/
void Zoo::initialBuy(Animal* animal)
{
    //prompt user for amount of animal to buy and validate
    int amount = 0;
    cout << "How many would you like to buy [1/2]? ";
    amount = inputValidation();
    while(amount != 1 && amount != 2)
    {
        cout << "Please choose [1/2]. ";
        amount = inputValidation();
    }
    cout << endl;

    //set that many animals as existing in zoo
    for(int i = 0; i < amount; i++)
    {
        (animal+i)->setInZoo(true);
        double cost = (animal+i)->getCost();
        cout << cost << " has been deducted from your bank." << endl;
        bank = (bank - cost);
        isThereEnoughInBank();
    }
    if(isThereEnoughInBank())
    { cout << "You now have " <<bank <<" left in the bank." << endl;}
    cout << endl;
}

/******************************************************************************
**void Zoo::initialBuy(Animal* animal)
** This is a method that allows for feeding of animals
** it takes in an animal pointer  and size and deducts the daily
**basefoodcost for each of animals in the zoo.
******************************************************************************/

void Zoo::feedingAnimals(Animal *animal, int size)
{
    double totalCost = 0;
    int numOfAnimals = 0;
    
    for(int i = 0; i < size; i++)
    {
        if((animal+i)->getInZoo() == true)
        {
            numOfAnimals++;
            totalCost += (animal+i)->getBaseFoodCost();
            
        }
    }
    
    if(numOfAnimals > 0)
    {
        cout << "Total food cost deductions for your " <<numOfAnimals;
        cout << " " <<(animal)->getName() <<" is " <<totalCost << endl;
    }

    dailyFoodDeduction += totalCost;
}

/******************************************************************************
**void Zoo::randomEvent()
** This is a method that randomizes one of four events, and calls
** animal sickness, baby born, attendance boom or nothing.
** it has no parameters and returns nothing.
******************************************************************************/

void Zoo::randomEvent()
{
    srand(time(0));
    
    int min;
    
    // if cheap feed sickness occurs at 50%
    if(base == 1)
    {min = 0;}
    
    //if regular feed sickness occurs at 25%
    else if(base == 2)
    { min = 25;}
    
    //if best feed sickness occurs at 12.6%
    else
    { min = 37;}
    
    int choice = rand()% (125 - min) + min;
        
    if(choice <= 50)
    {
        sendText("Oh no! an animal is sick!");
        cout << "Oh no! an animal is sick!" <<endl;
        bool removed = animalSick();
        if(removed == false)
        {cout << "The animal is better now!" << endl << endl;}
        
    }
    else if(choice > 50 && choice <= 75)
    {
        attendanceBoom();
    }
    else if(choice >75 && choice <= 100)
    {
        babyBorn();
    }
    else
    {
        sendText("Today is a normal day!");
        cout << "Today is a normal day!\n"  << endl;
    }
    
    
    //else if 101-125 nothing happens.
        

}

/******************************************************************************
**bool Zoo::animalSick()
** This is a method that randomly chooses an animal class to
** become sick and die. It sets the animals existence in the zoo
** to false. It returns a bool based on if there is an animal in the
** class to remove.
*******************************************************************************/
bool Zoo::animalSick()
{
    int max;
    if(newSpeciesChoice == true)
    { max = 4; }
    else
    { max = 3; }
    
    //choose random int
    int animal = rand()% max + 1;
    bool removed = false;
    
    //remove animal corresponding to number
    if(animal == 1)
    {
        removed = removeAnimal(tigers, tigerSize);
        if(removed == true)
        {cout << "A tiger has died." << endl; }
    }
    else if (animal == 2)
    {
        removed = removeAnimal(turtles, turtleSize);
        if(removed == true)
        { cout << "A turtle has died." << endl;}
    }
    else if(animal == 3)
    {
        removed = removeAnimal(penguins, penguinSize);
        if(removed == true)
        { cout << "A penguin has died." << endl;}
    }
    else if (animal == 4)
    {
        removed = removeAnimal(newSpecies, newSpeciesSize);
        if(removed == true)
        { cout << "A " << newSpecies->getName() <<" has died." << endl;}
    }
    
    return removed;
}

/******************************************************************************
**void Zoo::attendanceBoom()
** This is a method randomly chooses an armound from 250-500
** to add to the zoo bank for every tiger that exists in the zoo.
** There is no parameter and returns nothing.
*******************************************************************************/
void Zoo::attendanceBoom()
{
    int bonus = rand()% (500 + 1 - 250) + 250;
    
    for(int i = 0; i < tigerSize; i++)
    {
        if((tigers+i)->getInZoo() == 1)
        {
            dailyProfit += bonus;
        }
    }
    
    cout << "It's Tiger day! You have won " << bonus;
    cout << " for every tiger you own! " << endl;
    cout << " Your daily profit is now " << dailyProfit << endl;

    string fileName = "file.txt";
    
    
    std::ofstream ofs;
    ofs.open(fileName.c_str());
    
    ofs << "It's Tiger day! You have won " << bonus;
    ofs << " for every tiger you own! " << endl;
    ofs << " Your daily profit is now " << dailyProfit << endl;

    
    ofs.close();
    
}

/******************************************************************************
**vvoid Zoo::babyBorn()
** This is a method randomly choose an animal class to give
** birth to a baby but first checking if there is at least one animal
** present in the class that can give birth. It has no parameters
** and returns nothing.
*******************************************************************************/
void Zoo::babyBorn()
{
    int max;
    if(newSpeciesChoice == true)
    { max = 4; }
    else
    { max = 3; }
    
    //choose random int
    int animal = rand()% max + 1;
    bool adult = false;
    bool space = false;
    int baby = 0;
    cout << " Uh oh! Is there a baby coming? " << endl;
    sendText(" Uh oh! Is there a baby coming? ");
    
    //choose corresponding animal to give birth and check
    // if there is an animal old enough
    if(animal == 1)
    {
        adult = adultPresent(tigers, tigerSize);
        if (adult == true)
        {
            int numberOfBabies = tigers->getBabies();
            for(int i = 0; i < numberOfBabies ;i++)
            {
                //check if there is space for animal
                space = roomForAnimal(tigers, tigerSize);
                if (space == false)
                {
                    //if not, make larger array and then add animal
                    cout << "We need a bigger cage to house this baby tiger!";
                    cout << endl;
                    largerSize(tigers);
                }
                addAnimal(tigers, baby);
            }

        }
        else
        { cout << "False alarm! " << endl; }
        //cout << "There is no adult tiger." << endl;}
        
    }
    else if(animal == 2)
    {
        adult = adultPresent(turtles, turtleSize);
        if(adult == true)
        {
            int numberOfBabies = turtles->getBabies();
            for(int i = 0; i < numberOfBabies ; i++)
            {
                space = roomForAnimal(turtles, turtleSize);
                if(space == false)
                {
                    cout << "We need a bigger cage to house this baby turtle!";
                    cout << endl;
                    largerSize(turtles);
                }
                addAnimal(turtles, baby);
            }

        }
        else
        { cout << "False alarm! " << endl; }
        //cout << "There is no adult turtle." << endl; }
        
    }
    else if(animal == 3)
    {
        adult =adultPresent(penguins, penguinSize);
        if(adult == true)
        {
            int numberOfBabies = penguins->getBabies();
            for(int i = 0; i < numberOfBabies ; i++)
            {
                space = roomForAnimal(penguins, penguinSize);
                if(space == false)
                {
                    cout << "We need a bigger cage to house this baby penguin!";
                    cout << endl;
                    largerSize(penguins);
                }
                addAnimal(penguins, baby);
            }

        }
        else
        { cout << "False alarm! " << endl; }
        //{ cout << "There is no adult penguin." << endl; }
        
    }
    else if (animal == 4)
    {
        adult =adultPresent(newSpecies, newSpeciesSize);
        if(adult == true)
        {
            int numberOfBabies = newSpecies->getBabies();
            for(int i = 0; i < numberOfBabies ; i++)
            {
                space = roomForAnimal(newSpecies, newSpeciesSize);
                if(space == false)
                {
                    cout << "We need a bigger cage to house this baby " << newSpecies->getName();
                    cout << " !" << endl;
                    largerSize(newSpecies);
                }
                addAnimal(newSpecies, baby);
            }

        }
        else
        { cout << "False alarm! " << endl; }
        //{ cout << "There is no adult " <<newSpecies->getName() << endl; }
    }
    
}

/******************************************************************************
**bool Zoo::removeAnimal(Animal* animal, int size)
** This is a method takes in an animal class and its size
** and removes the animal from the array by setting its existence
** data member to zero.
*******************************************************************************/
bool Zoo::removeAnimal(Animal* animal, int size)
{
    bool removed = false;
    int i = 0;
    
    while(removed == false && i < size)
    {
        if((animal+i)->getInZoo() == 1)
        {
            (animal+i)->setInZoo(0);
            removed = true;
        }
        
        i++;
    }
    
    return removed;

}

/******************************************************************************
**bool Zoo::adultPresent(Animal *animal, int size)
** This is a method takes in an animal class and its size
** and checks if there is an adult present in the animal class.
** it returns a bool; true if adult is present, false if not.
*******************************************************************************/
bool Zoo::adultPresent(Animal *animal, int size)
{
    bool adult = false;
    int i = 0;
    
    while(adult == false && i < size)
    {
        if((animal+i)->getInZoo() == 1 && ((animal+i)->getAge()) >= 3 )
        {
            adult = true;
        }
        i++;
    }
    
    return adult;
}


/******************************************************************************
**bool Zoo::adultPresent(Animal *animal, int size)
** This is a method takes in an animal class and its size
** and checks if there is room in the array for another animal.
** If returns false if there is not room, true if there is.
*******************************************************************************/
bool Zoo::roomForAnimal(Animal *animal, int size)
{
    bool room = false;
    int i = 0;
    while(room == false && i < size)
    {
        if((animal+i)->getInZoo() == 0)
        {
            //cout << "There is room for an animal!" << endl;
            room = true;
        }
        i++;
    }
    
    return room;
}

/******************************************************************************
**bool Zoo::adultPresent(Tiger *animal)
** This is a method takes in a Tiger class and creates an array
** twice the size of the last, and loops the information of existing
** animal class to the new array, deleting the temporary array.
*******************************************************************************/
void Zoo::largerSize(Tiger* animal)
{

        tigerSize *= 2;
        Tiger* tempArray = new Tiger[tigerSize];
    

    
        for(int i = 0; i < (tigerSize/2); i ++)
        {
            (tempArray+i)->setName((animal+i)->getName());
            (tempArray+i)->setAge((animal+i)->getAge());
            (tempArray+i)->setCost((animal+i)->getCost());
            (tempArray+i)->setInZoo((animal+i)->getInZoo());
            (tempArray+i)->setBabies((animal+i)->getBabies());
            (tempArray+i)->setPayOff((animal+i)->getPayOff());
            (tempArray+i)->setBaseFoodCost((animal+i)->getBaseFoodCost());
            
        }
        for(int i = (tigerSize/2); i < tigerSize; i++)
        {
            (tempArray+i)->setName((animal)->getName());
            (tempArray+i)->setAge(0);
            (tempArray+i)->setCost((animal)->getCost());
            (tempArray+i)->setInZoo(0);
            (tempArray+i)->setBabies((animal)->getBabies());
            (tempArray+i)->setPayOff((animal)->getPayOff());
            (tempArray+i)->setBaseFoodCost((animal)->getBaseFoodCost());
        
        }
        
        delete [] tigers;
        tigers = tempArray;

    cout << "We just made a larger cage for the tigers!" << endl;
}

/******************************************************************************
**bool Zoo::adultPresent(Turtle *animal)
** This is a method takes in a Turtleclass and creates an array
** twice the size of the last, and loops the information of existing
** animal class to the new array, deleting the temporary array.
*******************************************************************************/
void Zoo::largerSize(Turtle *animal)
{

        turtleSize *= 2;
        Turtle* tempArray = new Turtle[turtleSize];
        for(int i = 0; i < (turtleSize/2); i ++)
        {
            (tempArray+i)->setName((animal+i)->getName());
            (tempArray+i)->setAge((animal+i)->getAge());
            (tempArray+i)->setCost((animal+i)->getCost());
            (tempArray+i)->setInZoo((animal+i)->getInZoo());
            (tempArray+i)->setBabies((animal+i)->getBabies());
            (tempArray+i)->setPayOff((animal+i)->getPayOff());
            (tempArray+i)->setBaseFoodCost((animal+i)->getBaseFoodCost());
        }

        for(int i = (turtleSize/2); i < turtleSize; i++)
        {
            (tempArray+i)->setName((animal)->getName());
            (tempArray+i)->setAge(0);
            (tempArray+i)->setCost((animal)->getCost());
            (tempArray+i)->setInZoo(0);
            (tempArray+i)->setBabies((animal)->getBabies());
            (tempArray+i)->setPayOff((animal)->getPayOff());
            (tempArray+i)->setBaseFoodCost((animal)->getBaseFoodCost());
        
        }
        
        delete [] turtles;
        turtles = tempArray;
    

    cout << "We just made a larger cage for the turtles!" << endl;
}

/******************************************************************************
**bool Zoo::adultPresent(Penguin animal)
** This is a method takes in a Penguin class and creates an array
** twice the size of the last, and loops the information of existing
** animal class to the new array, deleting the temporary array.
*******************************************************************************/
void Zoo::largerSize(Penguin *animal)
{
        penguinSize *= 2;
        Penguin* tempArray = new Penguin[penguinSize];
        for(int i = 0; i < (penguinSize/2); i ++)
        {
            (tempArray+i)->setName((animal+i)->getName());
            (tempArray+i)->setAge((animal+i)->getAge());
            (tempArray+i)->setCost((animal+i)->getCost());
            (tempArray+i)->setInZoo((animal+i)->getInZoo());
            (tempArray+i)->setBabies((animal+i)->getBabies());
            (tempArray+i)->setPayOff((animal+i)->getPayOff());
            (tempArray+i)->setBaseFoodCost((animal+i)->getBaseFoodCost());
            
        }

        for(int i = (penguinSize/2); i < penguinSize; i++)
        {
            (tempArray+i)->setName((animal)->getName());
            (tempArray+i)->setAge(0);
            (tempArray+i)->setCost((animal)->getCost());
            (tempArray+i)->setInZoo(0);
            (tempArray+i)->setBabies((animal)->getBabies());
            (tempArray+i)->setPayOff((animal)->getPayOff());
            (tempArray+i)->setBaseFoodCost((animal)->getBaseFoodCost());
        
        }
        
        delete [] penguins;
        penguins = tempArray;

    

    cout << "We just made a larger cage for the penguins!" << endl;
}

/******************************************************************************
**bool Zoo::adultPresent(fNewSpecies animal)
** This is a method takes in a New Species class and creates an array
** twice the size of the last, and loops the information of existing
** animal class to the new array, deleting the temporary array.
*******************************************************************************/
void Zoo::largerSize(NewSpecies *animal)
{
        newSpeciesSize *= 2;
        NewSpecies* tempArray = new NewSpecies[newSpeciesSize];
        for(int i = 0; i < (newSpeciesSize/2); i++)
        {
            (tempArray+i)->setName((animal+i)->getName());
            (tempArray+i)->setAge((animal+i)->getAge());
            (tempArray+i)->setCost((animal+i)->getCost());
            (tempArray+i)->setInZoo((animal+i)->getInZoo());
            (tempArray+i)->setBabies((animal+i)->getBabies());
            (tempArray+i)->setPayOff((animal+i)->getPayOff());
            (tempArray+i)->setBaseFoodCost((animal+i)->getBaseFoodCost());
                
        }
    
        for(int i = (newSpeciesSize/2); i < newSpeciesSize; i++)
        {   (tempArray+i)->setName(animal->getName());
            (tempArray+i)->setAge(0);
            (tempArray+i)->setCost((animal)->getCost());
            (tempArray+i)->setInZoo(0);
            (tempArray+i)->setBabies((animal)->getBabies());
            (tempArray+i)->setPayOff((animal)->getPayOff());
            (tempArray+i)->setBaseFoodCost((animal)->getBaseFoodCost());
        
        }
        
        delete [] newSpecies;
        newSpecies = tempArray;
        
        cout << "We just made a larger cage for the " <<newSpecies->getName() <<" !" << endl;

}

/******************************************************************************
**void Zoo::profitForTheDay(Animal *animal, int size)
** This is a method takes in an animal class and its size and
** loops through the existing animals to claculate the profit for
** the day.
*******************************************************************************/
void Zoo::profitForTheDay(Animal *animal, int size)
{
    int numOfAnimals = 0;
    double totalPayOff = 0;
    for(int i = 0; i < size; i++)
    {
       // if((animal+i)->getInZoo() == true)
       // { dailyProfit += (animal+i)->getPayOff();}
        if((animal+i)->getInZoo() == true)
        {
            numOfAnimals++;
            totalPayOff += (animal+i)->getPayOff();
            
        }
    }
    
    dailyProfit += totalPayOff;
    
    if(numOfAnimals > 0)
    {
        cout << "Your total payoff for " << numOfAnimals <<" " ;
        cout <<(animal)->getName() << " is "  << totalPayOff << endl;
    }
    
}


/******************************************************************************
**void Zoo::buyAdultAnimal()
** This is a method that prompts the user to buy an animal at the
** end of the day and checks if a larger array of that class is needed.
*******************************************************************************/

void Zoo::buyAdultAnimal()
{
    int adult = 3;
    int choice;
    bool room = false;
    cout << "Would you like to buy a: " << endl;
    cout << "1. tiger:   $10000" << endl;
    cout << "2. turtle:  $100"<< endl;
    cout << "3. penguin: $1000" << endl;
    if(newSpeciesChoice == true)
    {cout << "4. " <<newSpecies->getName() <<":  $" <<(newSpecies)->getCost() << endl;}
    cout << "Please enter the number choice of the animal " << endl;
    cout << "you would like to buy. ";
    choice = inputValidation();
    if(newSpeciesChoice == true)
    {
        while(choice > 4 && choice < 1)
        {
            cout << "Please choose a number [1-4]: ";
            choice = inputValidation();
        }
    }
    else
    {
        while(choice > 3 && choice < 1)
        {
            cout << "Please choose a number [1-3]: ";
            choice = inputValidation();
        }
    }
    
    
    
    if(choice == 1)
    {
        //check if there is room for animal
        room = roomForAnimal(tigers, tigerSize);
        if(room == false)
        {
            //if not add larger array
            cout << "We need a larger cage!" <<endl;
            largerSize(tigers);
        }
        //add animal
        addAnimal(tigers, adult);
    }
    else if(choice == 2)
    {
        room = roomForAnimal(turtles, turtleSize);
        if(room == false)
        {
            cout << "We need a larger cage!" <<endl;
            largerSize(turtles);
        }
        addAnimal(turtles, adult);
    }
    else if(choice == 3)
    {
        room = roomForAnimal(penguins, penguinSize);
        if(room == false)
        {
            cout << "We need a larger cage!" <<endl;
            largerSize(penguins);
        }
        addAnimal(penguins, adult);
    }
    else if( choice == 4 && newSpeciesChoice == true )
    {
        
        room = roomForAnimal(newSpecies, newSpeciesSize);
        if(room == false)
        {
            cout << "We need a larger cage!" <<endl;
            largerSize(newSpecies);
        }
        addAnimal(newSpecies, adult);
    }
}

/******************************************************************************
**bool Zoo::endOfDay()
** This is a method that prompts the user to keep playing
** it returns a bool, true if they want to keep playing and have
** money in the bank, false if not.
*******************************************************************************/
bool Zoo::endOfDay()
{
    char choice = true;
    if(bank > 0)
    {
        cout << "Would you like to keep playing. ";
        choice = inputValidationChar();
        while(choice != 'y' && choice != 'n')
        {
            cout << "Please enter valid [y/n] lower case letter: ";
            choice = inputValidationChar();
        }
        if(choice == 'n')
        {choice = false; }

        
    }
    else
    {
        cout << "You have no more money in the bank. " << endl;
        cout << "Game over." << endl;
        choice = false;
    }
    
    return choice;
}


/******************************************************************************
**void Zoo::changeBaseCost(double base)
** This is a method that loops through each animal class and
** sets the base food cost. It takes in a double int and returns
** nothing.
*******************************************************************************/
void Zoo::changeBaseCost(double base)
{
    for(int i = 0; i < 10; i++)
    {
        (tigers+i)->setBaseFoodCost(newBase);
        (turtles+i)->setBaseFoodCost(newBase);
        (penguins+i)->setBaseFoodCost(newBase);
        if(newSpeciesChoice == true)
        {(newSpecies+i)->setBaseFoodCost(newBase*newFoodMultiplier);}
        
    }
}


/******************************************************************************
**void Zoo::addAnimal(Animal *animal, int age)
** This is a method takes in an animal class and its age to
** add an animal and set the age of that animal. It returns
** nothing.
*******************************************************************************/
void Zoo::addAnimal(Animal *animal, int age)
{
    bool added = false;
    int i = 0;
    int cost = 0;
    while(added == false)
    {
        if((animal+i)->getInZoo() == 0)
        {
            (animal+i)->setAge(age);
            (animal+i)->setInZoo(true);
            if(age == 0)
            {cout << "We added a baby " <<(animal)->getName() <<endl;}
            added = true;
            if (age == 3)
            {
                cost = (animal+i)->getCost();
                bank -= cost;
                isThereEnoughInBank();
                if(isThereEnoughInBank())
                {
                    cout << "We added an adult " <<(animal)->getName() << endl;
                    cout << "We deducted " << cost << " from your bank." << endl;
                    cout << "You now have " << bank << " in the bank." << endl;
                }

              }
        }
        
        i++;
    }
}

/******************************************************************************
**void Zoo::aDayOlder(Animal* animal, int size)
** This is a method takes in an animal class and its size
** to add a day to all the animals ages. It returns nothing.
*******************************************************************************/
void Zoo::aDayOlder(Animal* animal, int size)
{
    int age;
    
    for(int i = 0; i < size; i++)
    {
        age = (animal+i)->getAge();
        age++;
        (animal+i)->setAge(age);
    }
}


void Zoo::addNewSpecies()
{
    
    string newName;
    cout << "Please enter the animal you would like to introduce into the zoo. ";
    newName = inputValidationString();
    while(newName.size() > 20)
    {
        cout << "Please choose a name with less than 20 characters: ";
        newName = inputValidationString();
    }
    
    int newPrice;
    cout << "Please enter the price you would like each new ";
    cout << newName << " to cost. ";
    newPrice = inputValidation();
    while (newPrice > 50000 || newPrice < 1)
    {
        cout << "Please choose a positive integer [1- 50,000]: ";
        newPrice = inputValidation();
    }
    
    int newBabies;
    cout << "Please enter the number of babies you'd like this animal to ";
    cout << "have per litter from [1-15]: ";
    newBabies = inputValidation();
    while (newBabies > 15 || newBabies < 1)
    {
        cout << "Please choose a number from [1-15]: ";
        newBabies = inputValidation();
    }
    
    cout << "Please enter the number of times you'd like to multiply ";
    cout << "the base food cost by to calculate the per animal food cost from: ";
    newFoodMultiplier = inputValidation();
    while (newFoodMultiplier > 100 || newFoodMultiplier< 1)
    {
        cout << "Please choose an integer [1-100]: ";
        newFoodMultiplier = inputValidation();
    }
    
    double aBaseFoodCost = base * newFoodMultiplier;
    
    int newPercentMultiplier;
    cout << "Please enter the percent you would like to multiply the new ";
    cout << newName << " cost by to calculate the payoff per day. ";
    newPercentMultiplier = inputValidation();
    while (newPercentMultiplier > 100 || newFoodMultiplier < 1 )
    {
        cout << "Please choose a percent [1-100]: ";
        newPercentMultiplier = inputValidation();
    }
    
    double aPayOff = newPrice * (newPercentMultiplier/100.00);
    
    
    
    for(int i = 0; i < newSpeciesSize; i++)
    {
        (newSpecies+i)->setName(newName);
        (newSpecies+i)->setCost(newPrice);
        (newSpecies+i)->setBabies(newBabies);
        (newSpecies+i)->setBaseFoodCost(aBaseFoodCost);
        (newSpecies+i)->setPayOff(aPayOff);
        (newSpecies+i)->setAge(1);
        
    }
    
    newSpeciesChoice = true;
    
    cout << "Great, you've added the new " << newName << " class to your zoo!" <<endl;

    
}


/******************************************************************************
**void Zoo::differentFeedTypes()
** This is a method that prompts the user to choose a type of
** animal feed for the day that changes the chances of the animals
** becoming sick. 
*******************************************************************************/
void Zoo::differentFeedTypes()
{
    newBase = base;
    //prompt user for different type of feed and validate
    cout << "Please choose which type of feed you would like to purchase for the day. " << endl;
    cout << "1: Kenny's CheapO Kibbles" <<endl;
    cout << "2: Regular Kibbles" <<endl;
    cout << "3: Stacey's Organic Glutten Free Kibbles" <<endl;
    dailyFeedType = inputValidation();
    while (dailyFeedType < 1 || dailyFeedType > 3)
    {
        cout << "Please choose option [1-3]: ";
        dailyFeedType = inputValidation();
    }
    
    
    switch(dailyFeedType)
    {
        case 1: newBase = base/2.0;
            break;
        case 3: newBase = base * 2.0;
            break;
    }
    
}

/******************************************************************************
**bool Zoo::isThereEnoughInBank()
** This is a method that checks whether there is enough money
** in the bank. It returns a bool.
*******************************************************************************/
bool Zoo::isThereEnoughInBank()
{
    if(bank < 1)
    {
        return false;
    }
    else
    { return true;}
}

/******************************************************************************
**void Zoo::sendText(string inputString)
** This is a method that outputs the random message to
** a file called file.txt. It take a in a string.
*******************************************************************************/
void Zoo::sendText(string inputString)
{
    string fileName = "file.txt";
    
    
    std::ofstream ofs;
    ofs.open(fileName);
    
    ofs << inputString;

    
    ofs.close();
    
}
