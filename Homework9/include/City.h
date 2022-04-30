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
#define GITY_H

#include <iostream>

using namespace std;

// Declare constants.
const int SIZE = 10;

///////////////////////////////////////////////////////////////////////////////


/******************************************************************************
 *      Description: Greetings class definition.
 *      Derived from: Nothing
 * ***************************************************************************/
class City
{
public:
    /******************************************************************************
     *      Message: Gets the current number of Jewels in the City map
     * 
     *      Parameters: 
     * 
     *      Returns: 
     * ***************************************************************************/
    int getNumOfJewels();
private:
    char m_grid[SIZE][SIZE];
    int m_NumOfJewels;    
};
///////////////////////////////////////////////////////////////////////////////
#endif