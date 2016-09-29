#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Computer.h"
#include "Player.h"

using std::string;
using namespace std;

Computer::Computer(string m, string cid, string pm):Player(m){
	compid = cid;
	player_move = pm;	
	
	rock_freq = 0;
	scissors_freq = 0;
	paper_freq = 0;
	
	rock_win_freq = 0;
	scissors_win_freq = 0;
	paper_win_freq = 0;
}

string Computer::getcid(){
	return compid;
}

void Computer::setcid(string cid){
	compid = cid;
}

string Computer::getplayermove(){
	return player_move;
}

void Computer::setplayermove(string pm){
	player_move = pm;
}


void Computer::randmove(){
	
	//srand(time(0));	//do this srand in main instead, if not won't work
	
	if((rand()%3)==0){
		Computer::setmove("Rock");			//Putting Computer or Player works because of inheritance
	}else if ((rand()%3)==1){
		Computer::setmove("Paper");
	}else{
		Computer::setmove("Scissors");
	}
	//memory_comp.push_back(Computer::getmove());     //this works, look at dicerool example where you're able to assign something to private varaible within a class function
}

//store computer move
void Computer::storecompmove(){
	memory_comp.push_back(Computer::getmove());
}

//Ask Computer to remember player's move through string
void Computer::storeplayermove(string pm){
	memory_player.push_back(pm);
}

//Display computer history
void Computer::display_comphist(){
	cout<<"Computer history."<<endl;
	for(int i = 0; i<memory_comp.size(); i++) {
		cout<<memory_comp[i]<<endl;		
	}//for loop
}

//Display player history
void Computer::display_playerhist(){
	cout<<"Player's history after current round played."<<endl;
	for(int i = 0; i<memory_player.size(); i++) {
		cout<<memory_player[i]<<endl;		
	}//for loop
}

//Feedback move 1: The computer will play as its move the move that the human played previously. 1st move random if not it's cheating
void Computer::feedbackmove_one(){	
	
	//if i = 0, computer rand, otherwise take i - 2, with player playing first
	if(memory_player.size() <= 1){
		Computer::randmove();
	}else if (memory_player.size()>0 && memory_player[memory_player.size()-2] == "Paper"){
		Computer::setmove("Paper");
		cout<<"Computer returns Paper which is the human's move in earlier round'"<<endl;
	}else if (memory_player.size()>0 && memory_player[memory_player.size()-2] == "Scissors"){
		Computer::setmove("Scissors");
		cout<<"Computer returns Scissors which is the human's move in earlier round"<<endl;	
	}else if (memory_player.size()>0 && memory_player[memory_player.size()-2] == "Rock"){
		Computer::setmove("Rock");
		cout<<"Computer returns Rock which is the human's move in earlier round"<<endl;
    }else{
    	Computer::randmove();
    	cout<<"Player's previous move is invalid/nil, hence computer uses a random move - "<<Computer::getmove()<<" instead"<<endl;
	}
}

//Feedback move 2: The computer will work out what move the human player has played the most and then play the move that would win against the filthy human's most common action.
void Computer::feedbackmove_two(){
	
	//If memory_player.size()>1, count the number of rock_freq, paper_freq, scissors_freq 
	if(memory_player.size()>1){
		rock_freq = 0;
		paper_freq = 0;
		scissors_freq = 0;
		
		for(int i = 0; i<memory_player.size(); i++) {		
		if(memory_player[i] == "Rock")			
			rock_freq++ ;
			cout<<"rock_freq"<<rock_freq<<endl;
		if(memory_player[i] == "Paper")			
			paper_freq++ ;	
			cout<<"paper_freq"<<paper_freq<<endl;		
		if(memory_player[i] == "Scissors")			
			scissors_freq++ ;	
			cout<<"scissors_freq"<<scissors_freq<<endl;		
		}//for loop		
		
		//After obtaining the frequency, compare count between Rock, Paper, Scissors
		if((rock_freq > paper_freq) && (rock_freq > scissors_freq)){Computer::setmove("Paper");
		
		}else if ((paper_freq > rock_freq) && (paper_freq > scissors_freq)){Computer::setmove("Scissors");
			
		}else if ((scissors_freq > rock_freq) && (scissors_freq > paper_freq)){Computer::setmove("Rock");
			
		}else if((rock_freq == paper_freq) && (rock_freq != scissors_freq)){Computer::setmove("Paper"); 	//Idea is not to lose, less so to win	
				
		}else if((rock_freq == scissors_freq) && (rock_freq != paper_freq)){Computer::setmove("Rock");     //Idea is not to lose, less so to win
			
		}else if((paper_freq == scissors_freq) && (paper_freq != rock_freq)){Computer::setmove("Scissors");  //Idea is not to lose, less so to win
				
		}else if((rock_freq == paper_freq) && (rock_freq == scissors_freq)){			
				if((rand()%3)==0){
					Computer::setmove("Rock");			//Randomize since there's no optimal strategy
				}else if ((rand()%3)==1){
					Computer::setmove("Paper");
				}else{
					Computer::setmove("Scissors");
				}					
		}else{cout<<"nil"<<endl;
		}		
	//condition of memory_player.size()<=1
	}else{					
		Computer::randmove();//computer returns random
		cout<<"Player's previous move is invalid/nil, hence computer uses a random move - "<<Computer::getmove()<<" instead"<<endl;
	}
	Computer::display_rpscounts();

} //end of void function

//Display rock paper scissors counts
void Computer::display_rpscounts(){
cout<<""<<endl;
cout<<"Rock counts: "<<rock_freq<<endl;
cout<<"Paper counts: "<<paper_freq<<endl;
cout<<"Scissors counts: "<<scissors_freq<<endl;	
}


//Feedback move 3: The computer will work out which of its moves have won most often and play that move.
void Computer::feedbackmove_three(){
	Computer::display_compwinhist();
	
	if(memory_comp.size() < 1){
	
		Computer::randmove();
	}else{
			
		//Calculate the win frequency
		if((memory_comp[memory_comp.size()-1] == "Rock") && (memory_player[memory_player.size()-1] == "Paper")){
			cout<<"no increase of win_freq"<<endl;
		}else if((memory_comp[memory_comp.size()-1] == "Rock") && (memory_player[memory_player.size()-1] == "Scissors")){
			rock_win_freq++;
		}else if((memory_comp[memory_comp.size()-1] == "Paper") && (memory_player[memory_player.size()-1] == "Rock")){		
			paper_win_freq++;
		}else if((memory_comp[memory_comp.size()-1] == "Paper") && (memory_player[memory_player.size()-1] == "Scissors")){
			cout<<"no increase of win_freq"<<endl;
		}else if((memory_comp[memory_comp.size()-1] == "Scissors") && (memory_player[memory_player.size()-1] == "Rock")){
			cout<<"no increase of win_freq"<<endl;
		}else if((memory_comp[memory_comp.size()-1] == "Scissors") && (memory_player[memory_player.size()-1] == "Paper")){
			scissors_win_freq++;
		}else if((memory_comp[memory_comp.size()-1] == "Rock") && (memory_player[memory_player.size()-1] == "Rock")){
			cout<<"no increase of win_freq"<<endl;		
	    }else if((memory_comp[memory_comp.size()-1] == "Paper") && (memory_player[memory_player.size()-1] == "Paper")){
	    	cout<<"no increase of win_freq"<<endl;
	    }else if((memory_comp[memory_comp.size()-1] == "Scissors") && (memory_player[memory_player.size()-1] == "Scissors")){
	    	cout<<"no increase of win_freq"<<endl;
	    }else{
	    	cout<<"Player's previous move is invalid/nil, hence computer uses a random move - "<<Computer::getmove()<<" instead"<<endl;
		}
		
		//Determine the move that computer should play based on highest _win_freq
		if((rock_win_freq > paper_win_freq) && (rock_win_freq > scissors_win_freq)){Computer::setmove("Rock");
		
		}else if ((paper_win_freq > rock_win_freq) && (paper_win_freq > scissors_win_freq)){Computer::setmove("Paper");
			
		}else if ((scissors_win_freq > rock_win_freq) && (scissors_freq > paper_win_freq)){Computer::setmove("Scissors");
			
		}else if((rock_win_freq == paper_freq) && (rock_win_freq != scissors_win_freq)){
				if((rand()%2)==0){
					Computer::setmove("Rock");			//Randomize since there's no optimal strategy
				}else{
					Computer::setmove("Paper");
				}	
				
		}else if((rock_win_freq == scissors_win_freq) && (rock_win_freq != paper_win_freq)){
		
				if((rand()%2)==0){
					Computer::setmove("Rock");			//Randomize since there's no optimal strategy
				}else{
					Computer::setmove("Scissors");
				}
			
		}else if((paper_win_freq == scissors_win_freq) && (paper_win_freq != rock_win_freq)){
		
				if((rand()%2)==0){
					Computer::setmove("Paper");			//Randomize since there's no optimal strategy
				}else{
					Computer::setmove("Scissors");
				}
				

		}else if((rock_win_freq == paper_win_freq) && (rock_win_freq == scissors_win_freq)){			
				if((rand()%3)==0){
					Computer::setmove("Rock");			//Randomize since there's no optimal strategy
				}else if ((rand()%3)==1){
					Computer::setmove("Paper");
				}else{
					Computer::setmove("Scissors");
				}					
		}else{cout<<"nil"<<endl;
		}	
				
	}//else end	
}//void

void Computer::display_compwinhist(){
	cout<<"Computer previous winning history in terms of moves (computer make its move in current round): "<<endl;
	cout<<"Computer rock win freq "<<rock_win_freq<<endl;
	cout<<"Computer paper win freq "<<paper_win_freq<<endl;
	cout<<"Computer scissors win freq "<<scissors_win_freq<<endl;
	cout<<""<<endl;
}








