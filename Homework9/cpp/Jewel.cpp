/******************************************************************************
    Programmer: Clayton Cowen (crcqdc)
                Will Weidler (wawq97)
    Student ID: 12578792
                12578421
    Section: 307
    Date: 04-30-22
    File Jewel.cpp
    Purpose: Implements the Jewel.cpp class.
******************************************************************************/
#include "../include/Jewel.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
 *      Description: Jewel class constructor.
 * 
 *      Arguments: None
 * 
 *      Returns: Nothing
 * ***************************************************************************/
Jewel::Jewel()
{
    // Initialize class member vaiables.
    jewelValue = 0;
    coordinate = {};
}

/******************************************************************************
 *      Description: Jewel class destructor.
 * 
 *      Arguments: None
 * 
 *      Returns: Nothing
 * ***************************************************************************/
Jewel::~Jewel()
{
    // Nothing to freaking obliterate.
}

/**************************************************************************
 *      Description: Sets the location of the Jewel.
 * 
 *      Parameters: INT - the i pos, INT - the j pos.
 * 
 *      Returns: Nothing
 * ***********************************************************************/
void Jewel::setLocation(const int x, const int y)
{
    // Set coordinates.
    coordinate.x_coord = x;
    coordinate.y_coord = y;

    // Set Jewel value.
    jewelValue = x * y;
}
///////////////////////////////////////////////////////////////////////////////