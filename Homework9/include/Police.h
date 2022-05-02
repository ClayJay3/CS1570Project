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
    Police(const int id);
    /******************************************************************************
     *      Message: Increments robbersCaught and updates lootConfiscated according to the robber's data
     * 
     *      Parameters: Requires initialized City, Police, and Robber
     * 
     *      Returns: None
     * ***************************************************************************/
    void arrest();
    /******************************************************************************
     *      Message: Increments robbersCaught and updates lootConfiscated according to the robber's data
     * 
     *      Parameters: Requires initialized City, Police, and Robber
     * 
     *      Returns: None
     * ***************************************************************************/
    void move();
    int getID(){return m_id;}
    int getLoot(){return m_lootConfiscated;}
    int getRobbersCaught(){return m_robbersCaught;}
    void setLocation(const int x, const int y);
private:
    int m_id;
    Coordinate m_location;
    int m_lootConfiscated;
    int m_robbersCaught;    
};
///////////////////////////////////////////////////////////////////////////////
#endif