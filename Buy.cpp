#include "Buy.h"

Buy::Buy():myFront(0),myBack(0){}
//Initializes the buy constructor with c and RemoveCoin
Buy::Buy(Coin &c, int removeCoin) {
 m_c = c;
m_removeCoin = removeCoin;

}
//Function definitions for the getCoin,getRemove,
//and display functions
std::string Buy::getCoin() {
return m_c.getName();
}

int Buy::getRemove() {
return m_removeCoin;
}

void Buy::display() {

std::cout<<"Coin: "<<getCoin()<<" Amount Bought: "<<getRemove()<<std::endl;

}
