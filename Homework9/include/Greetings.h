/******************************************************************************
    Programmer: Clayton Cowen (crcqdc)
                Will Weidler ()
    Student ID: 12578792
    Section: 307
    Date: 04-30-22
    File Greetings.h
    Purpose: Defines the Greetings.cpp class.
******************************************************************************/
#ifndef Greetings_h
#define Greetings_h

#include <iostream>

using namespace std;

// Declare constants.

///////////////////////////////////////////////////////////////////////////////


/******************************************************************************
 *      Description: Greetings class definition.
 *      Derived from: Nothing
 * ***************************************************************************/
class Greetings
{
public:
    /******************************************************************************
     *      Description: Greetings class constructor.
     * 
     *      Arguments: None
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    Greetings();
    /******************************************************************************
     *      Description: Greetings class destructor.
     * 
     *      Arguments: None
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    ~Greetings();
    /******************************************************************************
     *      Description: Print greeting message to the user through the console.
     * 
     *      Parameters: STRING message (the message to print to console)
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    void greeting(string message = greetMessage);
    /******************************************************************************
     *      Message: Print goodbye message to the user through the console.
     * 
     *      Parameters: STRING message (the message to print to console)
     * 
     *      Returns: Nothing
     * ***************************************************************************/
    void goodbye(string message = goodbyeMessage);
private:
    
};
///////////////////////////////////////////////////////////////////////////////
#endif