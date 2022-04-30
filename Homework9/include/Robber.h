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
#include "City.h"

#include <iostream>

using namespace std;

// Declare constants.
const int MAX_BAG_CAP = 17;
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
     *      Parameters: None
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    void move();
    /**************************************************************************
     *      Description: Sets the location of the Jewel.
     * 
     *      Parameters: INT - the i pos, INT - the j pos.
     * 
     *      Returns: Nothing
     * ***********************************************************************/
    void setLocation(const int x, const int y);
    friend class City;
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
///////////////////////////////////////////////////////////////////////////////
#include "Robber.h"
#endif