/******************************************************************************
    PProgrammer: Clayton Cowen (crcqdc)
                Will Weidler (wawq97)
    Student ID: 12578792
                12578421
    Section: 307
    Date: 04-30-22
    File Robber.h
    Purpose: Defines the Robber.cpp class.
******************************************************************************/
#ifndef Robber_h
#define Robber_h

#include "Jewel.h"

#include <iostream>

using namespace std;

// Declare constants.
const char JEWEL = 'J';
const char POLICE = 'p';
const char ROBBER = 'r';
const int MAX_BAG_CAP = 17;
const int SIZE = 10;
///////////////////////////////////////////////////////////////////////////////


/******************************************************************************
 *      Description: Robber template class definition.
 *      Derived from: Nothing
 * ***************************************************************************/
template<class T>
class Robber
{
public:
    /******************************************************************************
     *      Description: Robber class constructor.
     * 
     *      Arguments: INT - the robber ID, BOOL - is the roobber greedy.
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    Robber(const int ID, bool greedy);
    /******************************************************************************
     *      Description: Robber class destructor.
     * 
     *      Arguments: None
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    ~Robber();
    /******************************************************************************
     *      Description: Put the given loot into the robbers bag if not full.
     * 
     *      Parameters: JEWEL - the jewel to insert into the bag.
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    void pickUpLoot(T loot);
    /******************************************************************************
     *      Description: This functions adjusts the robbers coordinate 1 step in 
     *                  a random direction.
     *      Parameters: CHAR[][] - the city map
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    char* move(char *map);
    /**************************************************************************
     *      Description: Sets the location of the Jewel.
     * 
     *      Parameters: INT - the i pos, INT - the j pos.
     * 
     *      Returns: Nothing
     * ***********************************************************************/
    void setLocation(const int x, const int y);

    int getJewelValue(const int index);
    /******************************************************************************
     *      Description: Get the total value of all jewels for a given robber.
     * 
     *      Parameters: An initialized robber
     * 
     *      Returns: A value corresponding to the total number of jewels in the robber's bag
     * ***************************************************************************/  
    int getTotalValue();
    


    // One-line methods.
     /**************************************************************************
     *      Description: Getters for greedy
     * ***********************************************************************/
    bool getID() { return robberID; };
    /**************************************************************************
     *      Description: Getters for numberOfJewels
     * ***********************************************************************/
    bool getNumberOfJewelsStolen() { return numberOfJewelsStolen; };
    /**************************************************************************
     *      Description: Getters for totalNumberOfJewels
     * ***********************************************************************/
    bool getTotalNumberOfJewelsStolen() { return robbersTotalAmountStolen; };
    /**************************************************************************
     *      Description: Getters for active
     * ***********************************************************************/
    bool getIsActive() { return active; };
    /**************************************************************************
     *      Description: Getters for greedy
     * ***********************************************************************/
    bool getIsGreedy() { return isGreedy; };
    /**************************************************************************
     *      Description: Getters for location
     * ***********************************************************************/
    Coordinate getLoction() { return coordinate; };
private:
    // Define class member variables.
    int                 robberID;
    int                 numberOfJewelsStolen;
    static int          robbersTotalAmountStolen;
    bool                active;
    bool                isGreedy;
    Jewel               bag[MAX_BAG_CAP] = {};
    Coordinate          coordinate = {};
};

/******************************************************************************
 *      Description: Robber class constructor.
 * 
 *      Arguments: None
 * 
 *      Returns: Nothing
 * ***************************************************************************/
template<class T>
Robber<T>::Robber(const int ID, bool greedy)
{
    // Initialize member variables.
    robberID = ID;
    numberOfJewelsStolen = 0;
    int robbersTotalAmountStolen = 0;
    active = true;
    isGreedy = greedy;
}

/******************************************************************************
 *      Description: Robber class destructor.
 * 
 *      Arguments: None
 * 
 *      Returns: Nothing
 * ***************************************************************************/
template<class T>
Robber<T>::~Robber()
{
    // Nothing to do.
}

/******************************************************************************
 *      Description: This functions adjusts the robbers coordinate 1 step in 
 *                  a random direction. WITH BONUS!!!
 *      Parameters: None
 * 
 *      Returns: Nothing
 * ***************************************************************************/
template<class T>
char* Robber<T>::move(char *map)
{
    // Get the current location of the robber.
    int x = coordinate.x_coord;
    int y = coordinate.y_coord;
    // Reset old location to '-'
    // map[x][y] = '-';
    *map = '-';
    cout << *map << endl;
    // // Generate random number for determining movement direction.
    // int randomMoveNum = (rand() % 8);

    // // Change position based on random number if robber is not greedy.
    // if (!isGreedy) // Bonus!
    // {
    //     switch(randomMoveNum)
    //     {
    //         // Move NW
    //         case 0:
    //             // Check if coordinate is valid.
    //             if (coordinate.x_coord > 0)
    //             {
    //                 coordinate.x_coord -= 1;
    //             }
    //             if (coordinate.y_coord > 0)
    //             {
    //                 coordinate.y_coord -= 1;
    //             }
    //             break;
            
    //         // Move N
    //         case 1:
    //             // Check if coordinate is valid.
    //             if (coordinate.x_coord > 0)
    //             {
    //                 coordinate.x_coord -= 1;
    //             }
    //             break;

    //         // Move NE
    //         case 2:
    //             // Check if coordinate is valid.
    //             if (coordinate.x_coord > 0)
    //             {
    //                 coordinate.x_coord -= 1;
    //             }
    //             if (coordinate.y_coord < SIZE - 1)
    //             {
    //                 coordinate.y_coord += 1;
    //             }
    //             break;

    //         // Move W
    //         case 3:
    //             // Check if coordinate is valid.
    //             if (coordinate.y_coord > 0)
    //             {
    //                 coordinate.y_coord -= 1;
    //             }
    //             break;

    //         // Move E
    //         case 4:
    //             // Check if coordinate is valid.
    //             if (coordinate.y_coord < SIZE - 1)
    //             {
    //                 coordinate.y_coord += 1;
    //             }
    //             break;

    //         // Move SW
    //         case 5:
    //             // Check if coordinate is valid.
    //             if (coordinate.x_coord > 0)
    //             {
    //                 coordinate.x_coord -= 1;
    //             }
    //             if (coordinate.y_coord > 0)
    //             {
    //                 coordinate.y_coord -= 1;
    //             }
    //             break;

    //         // Move S
    //         case 6:
    //             // Check if coordinate is valid.
    //             if (coordinate.x_coord < SIZE - 1)
    //             {
    //                 coordinate.x_coord += 1;
    //             }
    //             break;

    //         // Move SE
    //         case 7:
    //             // Check if coordinate is valid.
    //             if (coordinate.x_coord < SIZE - 1)
    //             {
    //                 coordinate.x_coord += 1;
    //             }
    //             if (coordinate.y_coord < SIZE - 1)
    //             {
    //                 coordinate.y_coord += 1;
    //             }
    //             break;
    //     }
    // }
    // else
    // {
    //     // Create instance variables.
    //     bool jewelDirections[8] = {};

    //     // Search each direction to see if it contains a jewel.
    //     for (int i = 0; i < SIZE; i++)
    //     {
    //         // Check NW.
    //         // Check if within bounds.
    //         if ((x - i) > 0 && (y - i) > 0)
    //         {
    //             // Subtract index from X and Y coords, check each iteration for a jewel.
    //             char gridVal = map[x - i][y - i];
    //             // If jewel found at index, set boolean toggle for this direction.
    //             if (gridVal == JEWEL)
    //             {
    //                 jewelDirections[0] = true;   
    //             } 
    //         }

    //         // Check N.
    //         // Check if within bounds.
    //         if ((x - i) > 0)
    //         {
    //             // Subtract index from X, check each iteration for a jewel.
    //             char gridVal = map[x - i][y];
    //             // If jewel found at index, set boolean toggle for this direction.
    //             if (gridVal == JEWEL)
    //             {
    //                 jewelDirections[1] = true;
    //             }
    //         }

    //         // Check NE.
    //         // Check if within bounds.
    //         if ((x - i) > 0 && (y + i) < SIZE - 1)
    //         {
    //             // Sub to X and add to Y, check each iteration for a jewel.
    //             char gridVal = map[x - i][y + i];
    //             // If jewel found at index, set boolean toggle for this direction.
    //             if (gridVal == JEWEL)
    //             {
    //                 jewelDirections[2] = true;
    //             }
    //         }

    //         // Check W.
    //         // Check if within bounds.
    //         if ((y - i) > 0)
    //         {
    //             // Subtract index from Y, check each iteration for a jewel.
    //             char gridVal = map[x][y - i];
    //             // If jewel found at index, set boolean toggle for this direction.
    //             if (gridVal == JEWEL)
    //             {
    //                 jewelDirections[3] = true;
    //             }
    //         }

    //         // Check E.
    //         // Check if within bounds.
    //         if ((y + i) < SIZE - 1)
    //         {
    //             // Add index to Y, check each iteration for a jewel.
    //             char gridVal = map[x][y + i];
    //             // If jewel found at index, set boolean toggle for this direction.
    //             if (gridVal == JEWEL)
    //             {
    //                 jewelDirections[4] = true;
    //             }
    //         }

    //         // Check SW.
    //         // Check if within bounds.
    //         if ((x + i) < SIZE - 1 && (y - i) < 0)
    //         {
    //             // Add index to X subtract to Y, check each iteration for a jewel.
    //             char gridVal = map[x + i][y - i];
    //             // If jewel found at index, set boolean toggle for this direction.
    //             if (gridVal == JEWEL)
    //             {
    //                 jewelDirections[5] = true;
    //             }
    //         }

    //         // Check S.
    //         // Check if within bounds.
    //         if ((x + i) < SIZE - 1)
    //         {
    //             // Add index to X, check each iteration for a jewel.
    //             char gridVal = map[x + i][y];
    //             // If jewel found at index, set boolean toggle for this direction.
    //             if (gridVal == JEWEL)
    //             {
    //                 jewelDirections[6] = true;
    //             }
    //         }

    //         // Check SE.
    //         // Check if within bounds.
    //         if ((x + i) < SIZE - 1 && (y + i) < SIZE - 1)
    //         {
    //             // Add index to X and Y, check each iteration for a jewel.
    //             char gridVal = map[x + i][y + i];
    //             // If jewel found at index, set boolean toggle for this direction.
    //             if (gridVal == JEWEL)
    //             {
    //                 jewelDirections[7] = true;
    //             }
    //         }
    //     }

    //     // After getting valid movement directions for the greedy robber, generat a random number and move.

    // }

    // // After moving to the new spot determine what to do.
    // if(map[coordinate.x_coord][coordinate.y_coord] == POLICE){
        
    // }
    // else if(map[coordinate.x_coord][coordinate.y_coord] == JEWEL){}
    // else if(map[coordinate.x_coord][coordinate.y_coord] == ROBBER){}
    // else{
        
    // }

    return reinterpret_cast<char*>(map);
}

/**************************************************************************
 *      Description: Sets the location of the Jewel.
 * 
 *      Parameters: INT - the i pos, INT - the j pos.
 * 
 *      Returns: Nothing
 * ***********************************************************************/
template <class T>
void Robber<T>::setLocation(const int x, const int y)
{
    // Set coordinates.
    coordinate.x_coord = x;
    coordinate.y_coord = y;
}

/******************************************************************************
 *      Description: Put the given loot into the robbers bag if not full.
 * 
 *      Parameters: JEWEL - the jewel to insert into the bag.
 * 
 *      Returns: Nothing
 * ***************************************************************************/
template<class T>
void Robber<T>::pickUpLoot(T loot)
{
    // Check if robbers bag is full.
    if (numberOfJewelsStolen < MAX_BAG_CAP)
    {
        // Add the loot to the bag.
        bag[numberOfJewelsStolen++] = loot;
    }
}

template<class T>
int Robber<T>::getJewelValue(const int index){
    int sum = 0;
    sum = (bag[index].getLocation().x_coord + bag[index].getLocation().y_coord);
    return sum;
}
template <class T>
int Robber<T>::getTotalValue(){
    int sum = 0;
    for(int i = 0; i<numberOfJewelsStolen; i++){
        sum += getJewelValue(i);
    }
    return sum;
}
///////////////////////////////////////////////////////////////////////////////
#include "Robber.h"
#endif