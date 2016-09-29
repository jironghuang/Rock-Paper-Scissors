#include <iostream>
#include "Player.h"
#include <string>

using namespace std;

Player::Player(){
	
}

Player::Player(string m){
	move = m;
}

string Player::getmove(){
	return move;
}

void Player::setmove(string m){
	move = m;
}


void Player::performMove(){
	cout<<"Player, please enter any of these 3 moves - Rock, Paper, Scissors."<<endl;
	cin>>move;

}

