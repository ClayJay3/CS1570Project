/******************************************************************************
    Programmer: Clayton Cowen (crcqdc)
                Will Weidler (wawq97)
    Student ID: 12578792
                12578421
    Section: 307
    Date: 04-30-22
    File Greetings.h
    Purpose: Defines the Greetings.cpp class.
******************************************************************************/
#ifndef POLICE_H
#define POLICE_H

#include "City.h"
#include "Robber.h"

#include <iostream>

using namespace std;

// Declare constants.

///////////////////////////////////////////////////////////////////////////////


/******************************************************************************
 *      Description: Greetings class definition.
 *      Derived from: Nothing
 * ***************************************************************************/
class Police
{
public:
    /**************************************************************************
     *      Description: Police constructor.
     * 
     *      Parameters: CONST INT ID - the police id number.
     * 
     *      Returns: Nothing
     * ***********************************************************************/
    Police(const int id);
    /******************************************************************************
     *      Message: Increments robbersCaught and updates lootConfiscated according to the robber's data
     * 
     *      Parameters: Requires initialized City, Police, and Robber
     * 
     *      Returns: None
     * ***************************************************************************/
    void arrest(Robber<Jewel> &robber);
    /******************************************************************************
     *      Message: Increments robbersCaught and updates lootConfiscated according to the robber's data
     * 
     *      Parameters: Requires initialized City, Police, and Robber
     * 
     *      Returns: None
     * ***************************************************************************/
    void move(City &city);
    /******************************************************************************
     *      Message: returns the Police object's id
     * 
     *      Parameters: Requires initialized Police
     * 
     *      Returns: An int corresponding to the Police object's id
     * ***************************************************************************/
    int getID(){return m_id;}
    /******************************************************************************
     *      Message: returns Police object's current loot confiscated from the city and robbers
     * 
     *      Parameters: Requires initialized Police object
     * 
     *      Returns: An int corresponding to the value of the jewels confiscated
     * ***************************************************************************/
    int getLoot(){return m_lootConfiscated;}
    /******************************************************************************
     *      Message: Sets the loot value.
     * 
     *      Parameters: CONST INT - the value to set the loot var to.
     * 
     *      Returns: None
     * ***************************************************************************/
    void setLoot(const int value) {m_lootConfiscated = value; }
    /******************************************************************************
     *      Message: Get number of robbers caught.
     * 
     *      Parameters: None
     * 
     *      Returns: INT - the number of robbers caught
     * ***************************************************************************/
    int getRobbersCaught() { return m_robbersCaught; }      
    /******************************************************************************
     *      Description: Sets the number of robbers that the police has caught.
     * 
     *      Parameters: Requires initialized City, Police, and Robber
     * 
     *      Returns: None
     * ***************************************************************************/
    void setCaught(const int value) { m_robbersCaught = value; }
    /******************************************************************************
     *      Message: Gets the current location of the robber.
     * 
     *      Parameters: None
     * 
     *      Returns: COORDINATE - the coordinate struct containing the location of the police.
     * ***************************************************************************/
    Coordinate getLocation() { return m_location; }
    /******************************************************************************
     *      Message: Sets the Police object on a loction in the city grid
     * 
     *      Parameters: Requires initialized City and Police
     * 
     *      Returns: None
     * ***************************************************************************/
    void setLocation(const int x, const int y);
private:
    int m_id;
    Coordinate m_location;
    int m_lootConfiscated;
    int m_robbersCaught;    
};
///////////////////////////////////////////////////////////////////////////////
#endif