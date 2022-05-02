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
    int i = rand() % 9;
    int j = rand() % 9;

    // Continue getting random numbers until we land on an empty spot.
    while(metrocity.getLocation(i,j) == JEWEL || metrocity.getLocation(i,j) == ROBBER || metrocity.getLocation(i,j) == POLICE){
        i = rand() % 9;
        j = rand() % 9;
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
            i = rand() % 9;
            j = rand() % 9;
        }

        // Create new coordinate location at i and j.
        Coordinate location = {.x_coord = i, .y_coord = j};

        metrocity.setLocation(location, ROBBER);
        robber.setLocation(i,j);
    }


    metrocity.printGrid();
    int rounds = 1;
    while(rounds <= 3){

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
        metroMan.move();
        cout << "Round " << rounds << ":" << endl;
        metrocity.printGrid();
        rounds++;
    }
    if(rounds == 31){
        cout << "Summary of the chase:" << endl;
        cout << "The robbers wins the chase because maximum turns (30) have been reached." << endl;
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