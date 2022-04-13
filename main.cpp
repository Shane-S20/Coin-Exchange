//#include <iostream>
//#include <string>
#include<fstream>
using namespace std;
#include "Queue.h"
#include "Sell.h"
#include "Buy.h"
Queue<Buy> buyQ;
Queue<Sell> sellQ;

//Calls all of our startup functions necessary
int coinCount();
const int N = coinCount();
HashTable<int,Coin> coinTbl(N);
void load();
void save();
void tableDisplay();
void mainProgram();


int main () {
	load();
	tableDisplay();
	cout<<"Welcome to the exchange."<<"\n"<<endl;
	mainProgram();
	cout<<"Thank you for visiting the coin exchange."<<endl;
	save();

    return 0;
}

int coinCount() {

int counter = 0;
string line;
ifstream inFile;
inFile.open("Coins.txt");
while(!inFile.eof()){
getline(inFile,line,'\n');
counter++;
}
inFile.close();
return counter - 2;
}



void tableDisplay(){
	for(int i = 0; i < 10; i++)
	cout<<endl;
	for(int i = 0; i < N; i++)
	coinTbl[i].display();
	cout<<endl;
	buyQ.display(cout);
	sellQ.display(cout);
}

void mainProgram() {
	char input;
   	int n;
  	int amtOfCoins=0;
	const int runTime = 2;
	srand(time(NULL));
	time_t simulationTime = 0;
    for( ; ; )
    {
    cout<<"Please let us know how we can help you."<<endl;
    cout<<"Press B for Buy, S for Sell, P to pass to next day, or Q to end."<<endl;
    cin>>input;
        cout<<endl;
        if(input == 'Q' || input == 'q'){
        break;}
        else if(input == 'b' || input == 'B') {
        cout<<"Which coin would you like to exchange? 1, 2, ... up to "<<N<<endl;
        for(int i = 0; i<N; i++)
        cout<<i+1<<": "<<coinTbl[i].getName()<<" ";
        cout<<endl;
        cin>>n;
        n = n - 1;
        cout<<"Now, how much?"<<endl;
        cin>>amtOfCoins;
       //The buy function is called
        Buy b(coinTbl[n], amtOfCoins);
        buyQ.enqueue(b);
        coinTbl[n].removeCoin(amtOfCoins);
        coinTbl[n].setValue((float)coinTbl[n].getIssuedCoins()/(float)coinTbl[n].getOutstandingCoins()*10.0);

        } else if(input=='S' || input == 's'){
        cout<<"Which coin would you like to exchange? 1, 2, ... up to "<<N<<endl;
        for(int i = 0; i<N; i++)
        cout<<i+1<<": "<<coinTbl[i].getName()<<" ";
        cout<<endl;
        cin>>n;
        n = n - 1;
        cout<<"Now, how much?"<<endl;
        cin>>amtOfCoins;
	//The sell function is called
        Sell s(coinTbl[n], amtOfCoins);
        sellQ.enqueue(s);
        coinTbl[n].addCoin(amtOfCoins);
        coinTbl[n].setValue((float)coinTbl[n].getIssuedCoins()/(float)coinTbl[n].getOutstandingCoins()*10.0);

        } else if(input == 'P' || 'p'){
        //Using random values, the coin exchange simulation runs
        srand(time(NULL));
        time_t simulationTime = runTime;
        time_t beginTime = time(NULL);
        time_t passedTime = 0;
                do{
                int n = rand() % N;
                int chance = rand () % 300;
                int randCoin = rand() % 2500;
                        if(chance == 1){
                        Buy b(coinTbl[n], randCoin);
                        buyQ.enqueue(b);
                        coinTbl[n].removeCoin(randCoin);
                        coinTbl[n].setValue((float)coinTbl[n].getIssuedCoins()/(float)coinTbl[n].getOutstandingCoins()*10.0);
                        }else if(chance == 2) {
                        Sell s(coinTbl[n], randCoin);
                        sellQ.enqueue(s);
                        coinTbl[n].addCoin(randCoin);
                        coinTbl[n].setValue((float)coinTbl[n].getIssuedCoins()/(float)coinTbl[n].getOutstandingCoins()*10.0);
                        }
                                if(coinTbl[n].getOutstandingCoins()>coinTbl[n].getIssuedCoins())
                                coinTbl[n].setOutstandingCoins(0);
                time_t currentTime = time(NULL);
                passedTime = currentTime - beginTime;
                }while(passedTime<simulationTime);
                }

        tableDisplay();
        }

}

//Loading from the Coins.txt file
void load() {
string name;
float value;
float outstandingCoins;
float issuedCoins;
string line;
ifstream inFile;
inFile.open("Coins.txt");
for(int i = 0; i< N; i++){
getline(inFile,line,'\n');
        inFile>> name >> value >> outstandingCoins >> issuedCoins;
        coinTbl[i] = Coin(value, name, outstandingCoins, issuedCoins);
}
inFile.close();
}

//Saving the new values from the simulation into the Coins.txt file
void save() {
ofstream outFile;
outFile.open("Coins.txt");
string thisName;
float thisValue;
int thisOutstanding;
int thisIssued;
outFile<<"---------"<<'\n';
for(int i = 0; i< N; i++){
	thisName = coinTbl[i].getName();
	thisValue = coinTbl[i].getValue();
	thisOutstanding = coinTbl[i].getOutstandingCoins();
	thisIssued = coinTbl[i].getIssuedCoins();
        outFile << thisName<<" "<<thisValue<<" "<<thisOutstanding<<" "<<thisIssued<<'\n';
 }
}
