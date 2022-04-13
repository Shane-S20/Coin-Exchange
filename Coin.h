#ifndef COIN_H
#define COIN_h

#include "HashTable.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Buy.h"



class Coin 
{ 

public:

    Coin() { m_value = 0; m_name = " "; m_issuedCoins = 0; m_outstandingCoins=0; }
//Coin Constructor which takes the value, name, and outstanding coins
    Coin(float value, std::string name, unsigned long outstandingCoins, int issuedCoins)
    {
        m_value=value;
        m_name=name;
        m_issuedCoins = issuedCoins;
        m_outstandingCoins=outstandingCoins;
    }
//These are set and get functions which allows us to access the private data variables safely    
    void display()
    {std::cout<<"Coin: "<<getName()<<" CV: "<<getValue()
	<<" Inventory: "<<getOutstandingCoins()<<
	" Total Issued: "<<getIssuedCoins()<<std::endl;}

    void setValue(float value)
    {m_value = value; }
    
    float getValue()
    {return m_value; }
    
    void setName(std::string name)
    {m_name = name; }
    
    std::string getName()
    {return m_name; }
    
    void setOutstandingCoins(unsigned long outstandingCoins)
    {m_outstandingCoins = outstandingCoins; }
    
    unsigned long getOutstandingCoins()
    {return m_outstandingCoins; }
    
    void setIssuedCoins(unsigned long issuedCoins)
    {m_issuedCoins = issuedCoins;}

    int getIssuedCoins()
    {return m_issuedCoins;}

    void addCoin(unsigned long x)
        {setOutstandingCoins(getOutstandingCoins() + x);}
    void removeCoin(unsigned long x)
        {setOutstandingCoins(getOutstandingCoins() - x);}

//Private data that is accessed with the get and set functions above
private:
    unsigned long m_issuedCoins;
    float m_value;
    std::string m_name;
    unsigned long m_outstandingCoins;

};

#endif //COIN_H
