/******************************************************************************
    Programmer: Clayton Cowen (crcqdc)
                Will Weidler (wawq97)
    Student ID: 12578792
                12578421
    Section: 307
    Date: 04-30-22
    File Robber.cpp
    Purpose: Implements the Robber.cpp class.
******************************************************************************/
#include "../include/Robber.h"
#include "../include/City.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////

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
void Robber<T>::move()
{
    // Create instance variables.

    // Generate random number for determining movement direction.
    int randomMoveNum = (rand() % 8);

    // Check if robber is greedy.
    if (!isGreedy)
    {
        // Change position based on random number if robber is not greedy.
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
        // If robber is greedy, move in a random direction that has a jewel in its path.
        
    }

    // After moving to the new spot determine what to do.

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
///////////////////////////////////////////////////////////////////////////////