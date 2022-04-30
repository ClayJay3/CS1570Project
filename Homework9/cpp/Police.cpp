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
#include "../include/Police.h"

using namespace std;
/******************************************************************************
    *      Message: Increments robbersCaught and updates lootConfiscated according to the robber's data
    * 
    *      Parameters: Requires initialized City, Police, and Robber
    * 
    *      Returns: None
    * ***************************************************************************/
void Police::arrest()
{
    m_lootConfiscated += 0; // Robber's stolen loot here
    m_robbersCaught++;
}
/******************************************************************************
    *      Message: Changes Police location based on where the closest Robber is
    * 
    *      Parameters: Requires initialized City, Police, and Robber
    * 
    *      Returns: None
    * ***************************************************************************/
void Police::move()
{
    /*Integrate move function
    if(m_coordinates == robber.m_coordinates){
        arrest();
    }
    else if(m_coordinates == jewel.m_coordinates){
        //Remove from city grid
        m_lootConfiscated++;
    }*/
}
void Police::setLocation(const int x, const int y)
{
    // Set coordinates.
    m_location.x_coord = x;
    m_location.y_coord = y;
}
///////////////////////////////////////////////////////////////////////////////
