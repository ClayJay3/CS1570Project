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
    metrocity.setPolice(metroMan);
    metrocity.setRobber(halStewart);
    metrocity.setRobber(damien);
    metrocity.setRobber(megamind);
    metrocity.setRobber(minion);
    metrocity.printGrid();
    int rounds = 1;
    while(rounds <= 30){

        if(halStewart.getIsActive()){
            halStewart.move(metrocity.getGrid());
        }
        if(damien.getIsActive()){
            damien.move(metrocity.getGrid());
        }
        if(megamind.getIsActive()){
            megamind.move(metrocity.getGrid());
        }
        if(minion.getIsActive()){
            minion.move(metrocity.getGrid());
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
    cout << "\t Ordinary Robber ID: " << halStewart.getID() << endl;
    cout << "\t\t Final number of jewels picked up: " << halStewart.getNumberOfJewelsStolen() << endl;
    cout << "\t\t Total jewel worth: $" << halStewart.getTotalValue() << endl;
    cout << "\t Ordinary Robber ID: " << damien.getID() << endl;
    cout << "\t\t Final number of jewels picked up: " << damien.getNumberOfJewelsStolen() << endl;
    cout << "\t\t Total jewel worth: $" << damien.getTotalValue() << endl;
    cout << "\t Ordinary Robber ID: " << megamind.getID() << endl;
    cout << "\t\t Final number of jewels picked up: " << megamind.getNumberOfJewelsStolen() << endl;
    cout << "\t\t Total jewel worth: $" << megamind.getTotalValue() << endl;
    cout << "\t Ordinary Robber ID: " << minion.getID() << endl;
    cout << "\t\t Final number of jewels picked up: " << minion.getNumberOfJewelsStolen() << endl;
    cout << "\t\t Total jewel worth: $" << minion.getTotalValue() << endl;

    // Report program exit status.
    return EXIT_SUCCESS;
}