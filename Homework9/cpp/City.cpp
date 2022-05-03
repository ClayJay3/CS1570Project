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
    int jewelsRemaining = MAXJEWELS;
    m_NumOfJewels = MAXJEWELS;
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            if(m_grid[i][j] != JEWEL){
                if((rand() % 2)){
                    if(jewelsRemaining > 0){
                        m_grid[i][j] = JEWEL;
                        jewelsRemaining--;
                    }
                    else{
                        m_grid[i][j] = VOID;
                    }
                }
                else{
                    m_grid[i][j] = VOID;
                }
            }
        }
    }
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
char City::getLocation(const int x, const int y){
    return m_grid[x][y];
}
void City::setLocation(const Coordinate index, const char character){
    m_grid[index.x_coord][index.y_coord] = character;
    return;
}
///////////////////////////////////////////////////////////////////////////////