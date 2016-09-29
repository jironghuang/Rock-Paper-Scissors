//intsead of inheritance, create Player object in private? Similar to Yahtzee
//Referee starts and end game? Also judge Player Computer validity and results
#ifndef REFEREE_H
#define REFEREE_H
#include <string>
#include "Player.h"

//Consider cashcard example?

using namespace std;

//Write class for referee

class Referee{
	
 private:
		
 public:
 	//Computer Input and Player Input	
 	Referee();	 	
	//Referee(string p);

    void announcevalidmove(string);   
	bool judgevalidmove(string); 
	
	void announcewinner(string,string);
	
}; 

#endif

