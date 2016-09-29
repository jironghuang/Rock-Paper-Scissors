#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

//Write the class definition and defintion of Players
class Player{
	
private:
	//string name;
	string move;	

public:
	//Constructor
	Player();
	Player(string m);
	
	string getmove();
	void setmove(string);    //without cin
	void performMove();  //with cin

};

#endif
