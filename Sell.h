#ifndef SELL_H
#define SELL_H
//#include "Coin.h"
#include <iostream>
#include "Buy.h"
class Sell
{
//The sell functions are declared publically
public:
  Sell();
  Sell(Coin &c, int addCoin);
  void display();
  int getAdd();
    std::string getCoin();

//These values do not need to be accessed by the user, so they are private
private:
  Coin m_c;
  int m_addCoin;
  int myFront;
  int myBack;
};
#endif //SELL_H
