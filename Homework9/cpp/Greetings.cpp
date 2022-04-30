/******************************************************************************
    Programmer: Clayton Cowen
    Student ID: 12578792
    Section: 307
    Date: 02-28-22
    File Greetings.cpp
    Purpose: Implements the Greetings.cpp class.
******************************************************************************/
#include "../include/Greetings.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
 *      Description: Greetings class constructor.
 * 
 *      Arguments: None
 * 
 *      Returns: Nothing
 * ***************************************************************************/
Greetings::Greetings()
{
    // Nothing to construct.
}

/******************************************************************************
 *      Description: Greetings class destructor.
 * 
 *      Arguments: None
 * 
 *      Returns: Nothing
 * ***************************************************************************/
Greetings::~Greetings()
{
    // Nothing to freaking obliterate.
}

/******************************************************************************
 *      Description: Print greeting message to the user through the console.
 * 
 *      Parameters: STRING message (the message to print to console)
 * 
 *      Returns: Nothing
 * ***************************************************************************/
void Greetings::greeting(string message)
{
    // Print to console.
    cout << message << endl;
}

/******************************************************************************
 *      Message: Print goodbye message to the user through the console.
 * 
 *      Parameters: STRING message (the message to print to console)
 * 
 *      Returns: Nothing
 * ***************************************************************************/
void Greetings::goodbye(string message)
{
    // Print to console.
    cout << message << endl;
}
///////////////////////////////////////////////////////////////////////////////