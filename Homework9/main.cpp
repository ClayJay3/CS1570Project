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
    // Set random seed.
    srand(85);

    // Create game objects and variables.
    City metrocity;
    Police metroMan(42069);
    Robber<Jewel> halStewart(69, false);
    Robber<Jewel> damien(420, false);
    Robber<Jewel> megamind(8008135, true);
    Robber<Jewel> minion(2, true);
    Robber<Jewel> robbers[4] = {halStewart, damien, megamind, minion};
    
    // Initialize police and robber locations.
    // Create instance variables.
    int i = rand() % SIZE - 1;
    int j = rand() % SIZE - 1;

    // Continue getting random numbers until we land on an empty spot.
    while(metrocity.getLocation(i,j) == JEWEL || metrocity.getLocation(i,j) == ROBBER || metrocity.getLocation(i,j) == POLICE){
        i = rand() % SIZE - 1;
        j = rand() % SIZE - 1;
    }

    // Create new coordinate location at i and j.
    Coordinate location = {.x_coord = i, .y_coord = j};

    metrocity.setLocation(location, POLICE);
    metroMan.setLocation(i,j);
    // Robbers begin here.
    for (Robber<Jewel>& robber : robbers)
    {
        // Continue getting random numbers until we land on an empty spot.
        while(metrocity.getLocation(i,j) == JEWEL || metrocity.getLocation(i,j) == ROBBER || metrocity.getLocation(i,j) == POLICE){
            i = rand() % SIZE - 1;
            j = rand() % SIZE - 1;
        }

        // Create new coordinate location at i and j.
        Coordinate location = {.x_coord = i, .y_coord = j};

        metrocity.setLocation(location, ROBBER);
        robber.setLocation(i,j);
    }

    metrocity.printGrid();
    int rounds = 1;
    bool activeRobber = true;
    while((rounds <= ROUNDS) && (robbers[0].getTotalAmountStolen() < MAXROBBERLOOT) && activeRobber){
        cout << "Round " << rounds << ":" << endl;
        // Move police and robbers on city map.
        if(robbers[0].getIsActive()){
            robbers[0].move(metrocity);
        }
        if(robbers[1].getIsActive()){
            robbers[1].move(metrocity);
        }
        if(robbers[2].getIsActive()){
            robbers[2].move(metrocity);
        }
        if(robbers[3].getIsActive()){
            robbers[3].move(metrocity);
        }
        metroMan.move(metrocity);

        // Check if a police and robber occupy the same spot.
        for (Robber<Jewel> &robber : robbers)
        {
            // Check the police and robbers location.
            if ((robber.getLocation().x_coord == metroMan.getLocation().x_coord) && (robber.getLocation().y_coord == metroMan.getLocation().y_coord) && robber.getIsActive())
            {
                // Tell police to arrest robber.
                metroMan.arrest(robber);
                cout << "Robber number " << robber.getID() << " was arrested!" << endl;

                // Remove robber from the city.
                metrocity.setLocation(robber.getLocation(), POLICE);
            }
        }

        // Print grid and increment rounds.
        metrocity.printGrid();
        cout << "Total loot stolen: $" << robbers[0].getTotalAmountStolen() << endl;
        rounds++;
        activeRobber = false;
        for(Robber<Jewel>& robber : robbers)
        {
            if(robber.getIsActive())
            {
                activeRobber = true;
            }
        }
    }

    if(rounds > ROUNDS){
        cout << "Summary of the chase:" << endl;
        cout << "The robbers wins the chase because maximum turns (" << ROUNDS << ") have been reached." << endl;
    }
    else if(!activeRobber)
    {
        cout << "Summary of the chase:" << endl;
        cout << "The police win the chase because all of the robbers have been arrested." << endl;
    }
    else
    {
        cout << "Summary of the chase:" << endl;
        cout << "The robbers manage to bribe the police officer to set their friends free and walk away with nothing." << endl;
        metroMan.setLoot(robbers[0].getTotalAmountStolen());
        metroMan.setCaught(0);
        for(Robber<Jewel>& robber : robbers)
        {
            robber.setJewelsStolen(0);
        }
    }
    cout << "\t Police ID: " << metroMan.getID() << endl;
    cout << "\t\t Confiscated Jewels amount: $" << metroMan.getLoot() << endl;
    cout << "\t\t Final number of robbers caught: " << metroMan.getRobbersCaught() << endl;
    for (i = 0; i<4; i++)
    {   
        if(!robbers[i].getIsGreedy()){
            cout << "\t Ordinary Robber ID: " << robbers[i].getID() << endl;
        }
        else{
            cout << "\t Greedy Robber ID: " << robbers[i].getID() << endl;
        }
        cout << "\t\t Final number of jewels picked up: " << robbers[i].getNumberOfJewelsStolen() << endl;
        cout << "\t\t Total jewel worth: $" << robbers[i].getTotalValue() << endl;
    }

    // Report program exit status.
    return EXIT_SUCCESS;
}