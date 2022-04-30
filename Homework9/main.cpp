/******************************************************************************
    Programmer: Clayton Cowen
    Student ID: 12578792
    Section: 307
    Date: 04-27-22
    File main.cpp
    Purpose: Implement calculator functions.
******************************************************************************/

#include "include/City.h"
#include "include/Police.h"
#include "include/Robber.h"
#include <iostream>

using namespace std;
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
        Main method.
******************************************************************************/
int main()
{
    srand(85);
    City metrocity;
    Police metroMan;
    Robber<Jewel> halStewart(69, false);
    Robber<Jewel> damien(420, false);
    Robber<Jewel> megamind(8008135, true);
    Robber<Jewel> minion(1, true);
    metrocity.printGrid();
    int rounds = 1;
    while(rounds <= 30){}

    // Report program exit status.
    return EXIT_SUCCESS;
}