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
 *      Parameters: COORDINATE - the coordinate to set the jewel to.
 * 
 *      Returns: Nothing
 * ***********************************************************************/
void Jewel::setLocation(Coordinate coords)
{
    // Set coordinates.
    coordinate.x_coord = coords.x_coord;
    coordinate.y_coord = coords.y_coord;

    // Set Jewel value.
    jewelValue = coords.x_coord + coords.y_coord;
}
///////////////////////////////////////////////////////////////////////////////