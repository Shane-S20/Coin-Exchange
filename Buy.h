#ifndef BUY_H
#define BUY_H
#include "Coin.h"
#include <iostream>
#include <string>

class Buy 
{
//All of the Buy functions are delcared publically
    public:
    Buy();
    Buy(Coin &c, int removeCoin);
    void display();
    int getRemove();
    std::string getCoin();
//These values are hidden to ensure protection from the user
    private:
    Coin m_c;
    int m_removeCoin;
    int myFront;
    int myBack;
 
};




#endif
//BUY_H
