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
#ifndef CITY_H
#define CITY_H

#include "Robber.h"
#include "Police.h"
#include <iostream>

using namespace std;

// Declare constants.

///////////////////////////////////////////////////////////////////////////////


/******************************************************************************
 *      Description: Greetings class definition.
 *      Derived from: Nothing
 * ***************************************************************************/
class City
{
public:
    /******************************************************************************
     *      Message: Randomly scatters 47 jewels across the city
     * 
     *      Parameters: Requires initialized City
     * 
     *      Returns: None
     * ***************************************************************************/
    City();
    /******************************************************************************
     *      Message: Gets the current number of Jewels in the City map
     * 
     *      Parameters: Requires initialized City
     * 
     *      Returns: An int corresponding to the number of Jewels in the city
     * ***************************************************************************/
    int getNumOfJewels(){return m_NumOfJewels;}
    /******************************************************************************
     *      Message: Puts a Robber into an unoccupied location
     * 
     *      Parameters: Requires initialized City and Robber
     * 
     *      Returns: None
     * ***************************************************************************/
    void setRobber(Robber<Jewel> & man);
    /******************************************************************************
     *      Message: Puts a Police Officer into an unoccupied location
     * 
     *      Parameters: Requires initialized City and Police Officer
     * 
     *      Returns: None
     * ***************************************************************************/
    void setPolice(Police & man);
    char* getGrid() { return reinterpret_cast<char*>(m_grid); };
    void printGrid();
    void setLocation(const coordinates index, const char character);
    friend class Robber<Jewel>;
private:
    char m_grid[SIZE][SIZE];
    int m_NumOfJewels = 47;    
};
///////////////////////////////////////////////////////////////////////////////
#endif