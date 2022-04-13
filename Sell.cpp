#include "Sell.h"
#include <iostream>

Sell::Sell():myFront(0), myBack(0){}

//The Sell function is initialized with c and addCoin
Sell::Sell(Coin &c, int addCoin)
{
m_c = c;
m_addCoin = addCoin;
}

//The getCoin, getAdd, and display functions are defined
std::string Sell::getCoin() {
return m_c.getName();
}

int Sell::getAdd() {
return m_addCoin;
}

void Sell::display() {

std::cout<<"Coin: "<<getCoin()<<" Amount Sold: "<<getAdd()<<std::endl;

}



