#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include "Player.h"

using std::string;

class Human:public Player{
	private:
	 string humname;
		
	public:
	 Human(string m, string hn);
	 
	 string gethumname();
	 void sethumname(string);
	 
};
#endif
