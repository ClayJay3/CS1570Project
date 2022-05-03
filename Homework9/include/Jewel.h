/******************************************************************************
    PProgrammer: Clayton Cowen (crcqdc)
                 Will Weidler (wawq97)
    Student ID: 12578792
                12578421
    Section: 307
    Date: 04-30-22
    File Greetings.h
    Purpose: Defines the Greetings.cpp class.
******************************************************************************/
#ifndef Jewel_h
#define Jewel_h

#include <iostream>

using namespace std;

// Define class structs.
struct Coordinate
{
    int x_coord = 0;
    int y_coord = 0;
};

// Declare constants.

///////////////////////////////////////////////////////////////////////////////


/******************************************************************************
 *      Description: Jewel class definition.
 *      Derived from: Nothing
 * ***************************************************************************/
class Jewel
{
public:
    /******************************************************************************
     *      Description: Jewel class constructor.
     * 
     *      Arguments: None
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    Jewel();
    /******************************************************************************
     *      Description: Jewel class destructor.
     * 
     *      Arguments: None
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    ~Jewel();

    // One-line methods.
    /**************************************************************************
     *      Description: Getter for jewel value.
     *      Parameters: None
     *      Returns: INT - the value of the jewel.
     * ***********************************************************************/
    int getJewelValue() { return jewelValue; };
    /**************************************************************************
     *      Description: Setter for jewel value.
     *      Parameters: int value
     *      Returns: Nothing
     * ***********************************************************************/
    void setJewelValue(const int value) { jewelValue = value; };
    /**************************************************************************
     *      Description: Sets the location of the Jewel.
     *      Parameters: COORDINATE - the location
     *      Returns: Nothing
     * ***********************************************************************/
    void setLocation(Coordinate coords);
    /**************************************************************************
     *      Description: Gets the location of the Jewel.
     *      Parameters: None
     *      Returns: Coordinate
     * ***********************************************************************/
    Coordinate getLocation() { return coordinate; };
private:
    // Declare class member variables.
    int jewelValue;
    Coordinate coordinate;
};
///////////////////////////////////////////////////////////////////////////////
#endif