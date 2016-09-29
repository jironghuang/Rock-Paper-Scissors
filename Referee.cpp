//For referee consider just taking in the move and judge if it's correct
#include <iostream>
#include <string>
#include "Player.h"
#include "Referee.h"

using namespace std;

Referee::Referee(){

}


//Maybe just put string as paramter. In main program, after getting the string output, feed into function below
void Referee::announcevalidmove(string m){
 if(m == "Scissors"||m == "Paper"||m == "Rock"){
    cout<<" Valid move!";  //change this to boolean
}else{
	cout<<" Invalid move!";
}
}

//Create a function to return boolean?
bool Referee::judgevalidmove(string m){
 if(m == "Scissors"||m == "Paper"||m == "Rock"){
    return true;  //change this to boolean
}else{
	return false;
}
}

//Create a function to determine winner and lose
void Referee::announcewinner(string h_move, string c_move){
	if((h_move == "Scissors") && (c_move == "Paper")){
		cout<<"Human wins!"<<endl;
	}else if((h_move == "Scissors") && (c_move == "Rock")){
		cout<<"Computer wins!"<<endl;
	}else if((h_move == "Scissors") && (c_move == "Scissors")){
		cout<<"Draw!"<<endl;
    }else if((h_move == "Paper") && (c_move == "Scissors")){
		cout<<"Computer wins!"<<endl;
	}else if((h_move == "Paper") && (c_move == "Paper")){
		cout<<"Draw!"<<endl;
	}else if((h_move == "Paper") && (c_move == "Rock")){
		cout<<"Human wins!"<<endl;
    }else if((h_move == "Rock") && (c_move == "Scissors")){
		cout<<"Human wins!"<<endl;
	}else if((h_move == "Rock") && (c_move == "Paper")){
		cout<<"Computer wins!"<<endl;
	}else if((h_move == "Rock") && (c_move == "Rock")){
		cout<<"Draw!"<<endl;
    }else{
    	cout<<"Invalid inputs"<<endl;    	
	}
}//for function




