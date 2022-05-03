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

#include "Jewel.h"

#include <iostream>

using namespace std;

// Declare constants.
const int ROUNDS = 30;
const int MAXJEWELS = 47;
const int SIZE = 10;
const int MAXROBBERLOOT = 438;
const char JEWEL = 'J';
const char POLICE = 'p';
const char ROBBER = 'r';
const char ROBBERS = 'R';
const char VOID = '-';
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
     *      Description: Print the city map.
     * 
     *      Parameters: None
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    void printGrid();
    /******************************************************************************
     *      Description: Given the x and y location, get the map char value.
     * 
     *      Parameters: CONST INT - the x val, CONST INT - the y val.
     * 
     *      Returns: CHAR - the map val at the location.
     * ***************************************************************************/
    char getLocation(const int x, const int y);
    /******************************************************************************
     *      Description: Sets the char value at the given location.
     * 
     *      Parameters: CONST COORDINATE - the coordinate to set, CONST CHAR - the
     *              value to set.
     *      Returns: Nothing
     * ***************************************************************************/
    void setLocation(const Coordinate index, const char character);
private:
    char m_grid[SIZE][SIZE];
    int m_NumOfJewels;    
};
///////////////////////////////////////////////////////////////////////////////
#endif