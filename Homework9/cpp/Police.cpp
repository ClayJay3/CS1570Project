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

Police::Police(const int id)
{
    m_id = id; 
    m_lootConfiscated = 0; 
    m_robbersCaught = 0;
}
/******************************************************************************
    *      Message: Increments robbersCaught and updates lootConfiscated according to the robber's data
    * 
    *      Parameters: Requires initialized City, Police, and Robber
    * 
    *      Returns: None
    * ***************************************************************************/
void Police::arrest(Robber<Jewel> &robber)
{
    m_lootConfiscated += robber.getTotalValue(); // Robber's stolen loot here
    m_robbersCaught++;
    robber.setJewelsStolen(0);
    robber.setIsActive(false);
}
/******************************************************************************
    *      Message: Changes Police location based on where the closest Robber is
    * 
    *      Parameters: Requires initialized City, Police, and Robber
    * 
    *      Returns: None
    * ***************************************************************************/
void Police::move(City &city)
{
    // Get the current location of the police.
    int x = m_location.x_coord;
    int y = m_location.y_coord;

    // Generate random number for determining movement direction.
    int randomMoveNum = (rand() % 8);

    // Change position based on random number if robber is not greedy.
    switch(randomMoveNum)
    {
        // Move NW
        case 0:
            // Check if coordinate is valid.
            if (m_location.x_coord > 0)
            {
                m_location.x_coord -= 1;
            }
            if (m_location.y_coord > 0)
            {
                m_location.y_coord -= 1;
            }
            break;
        
        // Move N
        case 1:
            // Check if coordinate is valid.
            if (m_location.x_coord > 0)
            {
                m_location.x_coord -= 1;
            }
            break;

        // Move NE
        case 2:
            // Check if coordinate is valid.
            if (m_location.x_coord > 0)
            {
                m_location.x_coord -= 1;
            }
            if (m_location.y_coord < SIZE - 1)
            {
                m_location.y_coord += 1;
            }
            break;

        // Move W
        case 3:
            // Check if coordinate is valid.
            if (m_location.y_coord > 0)
            {
                m_location.y_coord -= 1;
            }
            break;

        // Move E
        case 4:
            // Check if coordinate is valid.
            if (m_location.y_coord < SIZE - 1)
            {
                m_location.y_coord += 1;
            }
            break;

        // Move SW
        case 5:
            // Check if coordinate is valid.
            if (m_location.x_coord > 0)
            {
                m_location.x_coord -= 1;
            }
            if (m_location.y_coord > 0)
            {
                m_location.y_coord -= 1;
            }
            break;

        // Move S
        case 6:
            // Check if coordinate is valid.
            if (m_location.x_coord < SIZE - 1)
            {
                m_location.x_coord += 1;
            }
            break;

        // Move SE
        case 7:
            // Check if coordinate is valid.
            if (m_location.x_coord < SIZE - 1)
            {
                m_location.x_coord += 1;
            }
            if (m_location.y_coord < SIZE - 1)
            {
                m_location.y_coord += 1;
            }
            break;
    }

    // Store old location and city map value.
    Coordinate oldLocation = {.x_coord = x, .y_coord = y};
    char oldNextMapData = city.getLocation(oldLocation.x_coord, oldLocation.y_coord);
    // Set old location to a dash.
    city.setLocation(oldLocation, VOID);

    // Set new location on city map.
    city.setLocation(m_location, POLICE);

    // Check if we have found a jewel at the new spot.
    if (oldNextMapData == JEWEL)
    {
        // Create a new jewel at location.
        Jewel newJewel;
        newJewel.setLocation(m_location);

        // Add jewel value to cops nums.
        m_lootConfiscated += newJewel.getJewelValue();
    }

}


void Police::setLocation(const int x, const int y)
{
    // Set coordinates.
    m_location.x_coord = x;
    m_location.y_coord = y;
}
///////////////////////////////////////////////////////////////////////////////
