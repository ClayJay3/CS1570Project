/******************************************************************************
    Programmer: Clayton Cowen (crcqdc)
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
#include "City.h"

#include <iostream>

using namespace std;

// Declare constants.
const int MAX_BAG_CAP = 17; // 17
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
    Robber(const int id = 0, bool greedy = false);
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
    void move(City &city);
    /**************************************************************************
     *      Description: Sets the location of the Jewel.
     * 
     *      Parameters: INT - the i pos, INT - the j pos.
     * 
     *      Returns: Nothing
     * ***********************************************************************/
    void setLocation(const int x, const int y);
    /**************************************************************************
     *      Description: Gets the value of the jewel
     * 
     *      Parameters: INT - the index in a robbers bag
     *
     *      Returns: An int corresponding to the monetary value of the jewel
     * ***********************************************************************/
    int getJewelValue(const int index);
    /******************************************************************************
     *      Description: Get the total value of all jewels for a given robber.
     * 
     *      Parameters: An initialized robber
     * 
     *      Returns: A value corresponding to the total number of jewels in the robber's bag
     * ***************************************************************************/  
    int getTotalValue();
    /*************************************************************************
     *      Description: Setters for Active
     * 
     *      Parameters: BOOL - the toggle.
     * 
     *      Returns: Nothing
     * **********************************************************************/
    void setIsActive(bool isActive);
    /*************************************************************************
     *      Description: Setters for JewelsStolen
     * 
     *      Parameters: INT - the value to set.
     * 
     *      Returns: Nothing
     * **********************************************************************/
    void setJewelsStolen(const int value);
    
    // One-line methods.
    /*************************************************************************
    *      Description: Getters for ID
    * ***********************************************************************/
    int getID() { return robberID; };
    /**************************************************************************
     *      Description: Getters for numberOfJewels
     * ***********************************************************************/
    int getNumberOfJewelsStolen() { return numberOfJewelsStolen; };
    /**************************************************************************
     *      Description: Getters for totalNumberOfJewels
     * ***********************************************************************/
    int getTotalAmountStolen() { return robbersTotalAmountStolen; };
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
    Coordinate getLocation() { return coordinate; };
private:
    // Define class member variables.
    int                 robberID;
    int                 numberOfJewelsStolen;
    static int          robbersTotalAmountStolen;
    bool                replaceOldLocationWithJewel;
    bool                active;
    bool                isGreedy;
    Jewel               bag[MAX_BAG_CAP] = {};
    Coordinate          coordinate = {};
};

// Why was I created this way.
template<class T>
int Robber<T>::robbersTotalAmountStolen = 0;

/******************************************************************************
 *      Description: Robber class constructor.
 * 
 *      Arguments: None
 * 
 *      Returns: Nothing
 * ***************************************************************************/
template<class T>
Robber<T>::Robber(const int id, bool greedy)
{
    // Initialize member variables.
    robberID = id;
    numberOfJewelsStolen = 0;
    replaceOldLocationWithJewel = false;
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
void Robber<T>::move(City &city)
{
    // Create variables.
    int currentNumberOfTurns = 0;
    bool moveAgain;

    // Check if the robber is active.
    if (getIsActive() && getTotalAmountStolen() <= MAXROBBERLOOT)
    {
        // Do-while loop for multiple turns of a greedy robber.
        do
        {
            // Set move again toggle
            moveAgain = false;

            // Get the current location of the robber.
            int x = coordinate.x_coord;
            int y = coordinate.y_coord;

            // Generate random number for determining movement direction.
            int randomMoveNum = (rand() % 8);

            // Change position based on random number if robber is not greedy.
            if (!isGreedy)
            {

                switch(randomMoveNum)
                {
                    // Move NW
                    case 0:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord > 0)
                        {
                            coordinate.x_coord -= 1;
                        }
                        if (coordinate.y_coord > 0)
                        {
                            coordinate.y_coord -= 1;
                        }
                        break;
                    
                    // Move N
                    case 1:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord > 0)
                        {
                            coordinate.x_coord -= 1;
                        }
                        break;

                    // Move NE
                    case 2:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord > 0)
                        {
                            coordinate.x_coord -= 1;
                        }
                        if (coordinate.y_coord < SIZE - 1)
                        {
                            coordinate.y_coord += 1;
                        }
                        break;

                    // Move W
                    case 3:
                        // Check if coordinate is valid.
                        if (coordinate.y_coord > 0)
                        {
                            coordinate.y_coord -= 1;
                        }
                        break;

                    // Move E
                    case 4:
                        // Check if coordinate is valid.
                        if (coordinate.y_coord < SIZE - 1)
                        {
                            coordinate.y_coord += 1;
                        }
                        break;

                    // Move SW
                    case 5:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord > 0)
                        {
                            coordinate.x_coord -= 1;
                        }
                        if (coordinate.y_coord > 0)
                        {
                            coordinate.y_coord -= 1;
                        }
                        break;

                    // Move S
                    case 6:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord < SIZE - 1)
                        {
                            coordinate.x_coord += 1;
                        }
                        break;

                    // Move SE
                    case 7:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord < SIZE - 1)
                        {
                            coordinate.x_coord += 1;
                        }
                        if (coordinate.y_coord < SIZE - 1)
                        {
                            coordinate.y_coord += 1;
                        }
                        break;
                }
            }
            else
            {
                /**********************************************************************************
                 * BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS 
                 * BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS 
                 * BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS 
                 * BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS 
                 * BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS 
                 * BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS BONUS 
                 * ********************************************************************************/
                // Create instance variables.
                bool jewelDirections[8] = {};

                // Search each direction to see if it contains a jewel.
                for (int i = 0; i < SIZE; i++)
                {
                    // Check NW.
                    // Check if within bounds.
                    if ((x - i) >= 0 && (y - i) >= 0)
                    {
                        // Subtract index from X and Y coords, check each iteration for a jewel.
                        char gridVal = city.getLocation(x - i, y - i);
                        // If jewel found at index, set boolean toggle for this direction.
                        if (gridVal == JEWEL)
                        {
                            jewelDirections[0] = true;   
                        } 
                    }

                    // Check N.
                    // Check if within bounds.
                    if ((x - i) >= 0)
                    {
                        // Subtract index from X, check each iteration for a jewel.
                        char gridVal = city.getLocation(x - i, y);
                        // If jewel found at index, set boolean toggle for this direction.
                        if (gridVal == JEWEL)
                        {
                            jewelDirections[1] = true;
                        }
                    }

                    // Check NE.
                    // Check if within bounds.
                    if ((x - i) >= 0 && (y + i) < SIZE)
                    {
                        // Sub to X and add to Y, check each iteration for a jewel.
                        char gridVal = city.getLocation(x - i, y + i);
                        // If jewel found at index, set boolean toggle for this direction.
                        if (gridVal == JEWEL)
                        {
                            jewelDirections[2] = true;
                        }
                    }

                    // Check W.
                    // Check if within bounds.
                    if ((y - i) >= 0)
                    {
                        // Subtract index from Y, check each iteration for a jewel.
                        char gridVal = city.getLocation(x, y - i);
                        // If jewel found at index, set boolean toggle for this direction.
                        if (gridVal == JEWEL)
                        {
                            jewelDirections[3] = true;
                        }
                    }

                    // Check E.
                    // Check if within bounds.
                    if (((y + i) < SIZE))
                    {
                        // Add index to Y, check each iteration for a jewel.
                        char gridVal = city.getLocation(x, y + i);
                        // If jewel found at index, set boolean toggle for this direction.
                        if (gridVal == JEWEL)
                        {
                            jewelDirections[4] = true;
                        }
                    }

                    // Check SW.
                    // Check if within bounds.
                    if ((x + i < SIZE) && (y - i >= 0))
                    {
                        // Add index to X subtract to Y, check each iteration for a jewel.
                        char gridVal = city.getLocation(x + i, y - i);
                        // If jewel found at index, set boolean toggle for this direction.
                        if (gridVal == JEWEL)
                        {
                            jewelDirections[5] = true;
                        }
                    }

                    // Check S.
                    // Check if within bounds.
                    if ((x + i) < SIZE)
                    {
                        // Add index to X, check each iteration for a jewel.
                        char gridVal = city.getLocation(x + i, y);
                        // If jewel found at index, set boolean toggle for this direction.
                        if (gridVal == JEWEL)
                        {
                            jewelDirections[6] = true;
                        }
                    }

                    // Check SE.
                    // Check if within bounds.
                    if ((x + i) < SIZE && (y + i) < SIZE)
                    {
                        // Add index to X and Y, check each iteration for a jewel.
                        char gridVal = city.getLocation(x + i,y + i);
                        // If jewel found at index, set boolean toggle for this direction.
                        if (gridVal == JEWEL)
                        {
                            jewelDirections[7] = true;
                        }
                    }
                }

                // After getting valid movement directions for the greedy robber, generate a random number and move.
                bool isDirectionWithJewel = false;
                int direction = 0;
                int counter = 0;
                while (!isDirectionWithJewel)
                {
                    // Generate new random number.
                    direction = rand() % 8;

                    // Check if direction is valid.
                    if (jewelDirections[direction])
                    {
                        isDirectionWithJewel = true;
                    }

                    // Check bool at array location.
                    if (jewelDirections[counter] == true)
                    {
                        doWeEvenHaveAGoodFrickenVal = true;
                    }

                    // Check if counter has overrun.
                    if (counter > 7)
                    {
                        isDirectionWithJewel = true;
                    }

                    // Increment counter.
                    counter++;
                }

                // Actually move.
                switch(direction)
                {
                    // Move NW
                    case 0:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord > 0)
                        {
                            coordinate.x_coord -= 1;
                        }
                        if (coordinate.y_coord > 0)
                        {
                            coordinate.y_coord -= 1;
                        }
                        break;
                    
                    // Move N
                    case 1:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord > 0)
                        {
                            coordinate.x_coord -= 1;
                        }
                        break;

                    // Move NE
                    case 2:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord > 0)
                        {
                            coordinate.x_coord -= 1;
                        }
                        if (coordinate.y_coord < SIZE - 1)
                        {
                            coordinate.y_coord += 1;
                        }
                        break;

                    // Move W
                    case 3:
                        // Check if coordinate is valid.
                        if (coordinate.y_coord > 0)
                        {
                            coordinate.y_coord -= 1;
                        }
                        break;

                    // Move E
                    case 4:
                        // Check if coordinate is valid.
                        if (coordinate.y_coord < SIZE - 1)
                        {
                            coordinate.y_coord += 1;
                        }
                        break;

                    // Move SW
                    case 5:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord > 0)
                        {
                            coordinate.x_coord -= 1;
                        }
                        if (coordinate.y_coord > 0)
                        {
                            coordinate.y_coord -= 1;
                        }
                        break;

                    // Move S
                    case 6:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord < SIZE - 1)
                        {
                            coordinate.x_coord += 1;
                        }
                        break;

                    // Move SE
                    case 7:
                        // Check if coordinate is valid.
                        if (coordinate.x_coord < SIZE - 1)
                        {
                            coordinate.x_coord += 1;
                        }
                        if (coordinate.y_coord < SIZE - 1)
                        {
                            coordinate.y_coord += 1;
                        }
                        break;
                }
            }

            // Set old location.
            Coordinate oldLocation;
            oldLocation.x_coord = x;
            oldLocation.y_coord = y;

            // If robbers bag is full, replace old spot with a jewel.
            if (replaceOldLocationWithJewel)
            {
                city.setLocation(oldLocation, JEWEL);
            }
            else
            {
                city.setLocation(oldLocation, VOID);
                // Decrement jewels count.
                city.decrementJewels();
            }

            // Make new easy to use coordinate.
            Coordinate newLocation = {coordinate.x_coord, coordinate.y_coord};

            // Store the current map value.
            char oldNextMapData = city.getLocation(newLocation.x_coord, newLocation.y_coord);

            // Set new location to robber.
            city.setLocation(newLocation, ROBBER);

            // If the old map value of the location we are currently at was a jewel, then add the jewel to our bag.
            if (oldNextMapData == JEWEL)
            {
                // Create a new jewel.
                Jewel newJewel;
                newJewel.setLocation(newLocation);

                // Attempt to pickup the loot.
                pickUpLoot(newJewel);
                
                // Check if the jewel value is even and robber is greedy, if so then the robber gets to move again.
                if (isGreedy && newJewel.getJewelValue() % 2 == 0)
                {
                    // Set the move again toggle.
                    moveAgain = true;
                }
            }
            // If new location involves running into a robber
            else if (oldNextMapData == ROBBER)
            {
                // initialize jewels to drop
                int jewelsToDrop = 0;

                city.setLocation(newLocation, ROBBERS);
                if(isGreedy)
                {
                    int jewelsDropped = (numberOfJewelsStolen/2);
                    if(!(numberOfJewelsStolen % 2))
                    {
                        jewelsToDrop = jewelsDropped;
                    }
                    else
                    {
                        jewelsToDrop = jewelsDropped + 1;
                    }
                    int tempJewelsStolen = numberOfJewelsStolen;
                    for(int i = jewelsToDrop; i < tempJewelsStolen; i++)
                    {
                        robbersTotalAmountStolen -= bag[i].getJewelValue();
                        if(city.getLocation(bag[i].getLocation().x_coord, bag[i].getLocation().y_coord) != VOID)
                        {
                            city.setLocation(bag[i].getLocation(), JEWEL);
                        }
                        else
                        {
                            city.setLocation(bag[i].getLocation(), JEWEL);
                        }
                        numberOfJewelsStolen--;
                    }
                    if(jewelsDropped != 0)
                    {
                        cout << "The greedy robber number " << robberID << " got too excited and dropped " << jewelsDropped;
                        if (jewelsDropped == 1)
                        {
                            cout << "jewel!" << endl;
                        }
                        else
                        {
                            cout << " jewels!" << endl;
                        }
                    }
                }
            }            
            // Increment turn counter.
            currentNumberOfTurns++; 
        } while (moveAgain && currentNumberOfTurns < 3);
    }
    return;
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
        robbersTotalAmountStolen += loot.getJewelValue();
    }
    else
    {
        replaceOldLocationWithJewel = true;
    }
}
/**************************************************************************
    *      Description: Gets the value of the jewel
    * 
    *      Parameters: INT - the index in a robbers bag
    *
    *      Returns: An int corresponding to the monetary value of the jewel
    * ***********************************************************************/
template<class T>
int Robber<T>::getJewelValue(const int index){
    int sum = 0;
    sum = (bag[index].getJewelValue());
    return sum;
}
/******************************************************************************
    *      Description: Get the total value of all jewels for a given robber.
    * 
    *      Parameters: An initialized robber
    * 
    *      Returns: A value corresponding to the total number of jewels in the robber's bag
    * ***************************************************************************/  
template <class T>
int Robber<T>::getTotalValue(){
    int sum = 0;
    for(int i = 0; i<numberOfJewelsStolen; i++){
        sum += getJewelValue(i);
    }
    return sum;
}
/*************************************************************************
    *      Description: Setters for Active
    * 
    *      Parameters: BOOL - the toggle.
    * 
    *      Returns: Nothing
    * **********************************************************************/
template <class T>
void Robber<T>::setIsActive(bool isActive) 
{ 
    active = isActive;
    robbersTotalAmountStolen -= getTotalValue();
    return;
}
/*************************************************************************
    *      Description: Setters for JewelsStolen
    * 
    *      Parameters: INT - the value to set.
    * 
    *      Returns: Nothing
    * **********************************************************************/
template <class T>
void Robber<T>::setJewelsStolen(const int value)
{
    numberOfJewelsStolen = value;
    return;
}
///////////////////////////////////////////////////////////////////////////////
#include "Robber.h"
#endif