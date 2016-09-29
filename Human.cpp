//Human can probably inherit everythign from Player.h. Can refer to sphere example

#include <iostream>
#include "Player.h"
#include "Human.h"

using namespace std;

Human::Human(string m, string hn):Player(m){
	humname = hn;
	
}

string Human::gethumname(){
	return humname;
}

void Human::sethumname(string hn){
	humname = hn;
}
