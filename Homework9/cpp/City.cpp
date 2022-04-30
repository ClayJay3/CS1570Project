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
#include "../include/City.h"

using namespace std;
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
     *      Message: Randomly scatters 47 jewels across the city
     * 
     *      Parameters: Requires initialized City
     * 
     *      Returns: None
     * ***************************************************************************/
City::City()
{
    int jewelsRemaining = 47;
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            if(m_grid[i][j] != JEWEL){
                if((rand() % 2)){
                    if(jewelsRemaining > 0){
                        m_grid[i][j] = JEWEL;
                        jewelsRemaining--;
                    }
                    else{
                        m_grid[i][j] = '-';
                    }
                }
                else{
                    m_grid[i][j] = '-';
                }
            }
        }
    }
}
/******************************************************************************
    *      Message: Puts a Robber into an unoccupied location
    * 
    *      Parameters: Requires initialized City and Robber
    * 
    *      Returns: None
    * ***************************************************************************/
void City::setRobber(Robber<Jewel> & man){
    int i = rand() % 9;
    int j = rand() % 9;
    while(m_grid[i][j] == JEWEL){
        i = rand() % 9;
        j = rand() % 9;
    }
    m_grid[i][j] = ROBBER;
    man.setLocation(i,j);
}
/******************************************************************************
    *      Message: Puts a Police Officer into an unoccupied location
    * 
    *      Parameters: Requires initialized City and Police Officer
    * 
    *      Returns: None
    * ***************************************************************************/
void City::setPolice(Police & man){
    int i = rand() % 9;
    int j = rand() % 9;
    while(m_grid[i][j] == JEWEL){
        i = rand() % 9;
        j = rand() % 9;
    }
    m_grid[i][j] = POLICE;
    man.setLocation(i,j);
}
void City::printGrid(){
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            cout << m_grid[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
///////////////////////////////////////////////////////////////////////////////