//Create some vector memory for 2 vectors - 1 to record computer, 1 to record player? Refer to Yahtzee, and 

#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Player.h"

using std::string;
using namespace std;

class Computer: public Player{
	private:
		string compid;
		string player_move;

		//Use a vector to store the computer moves
		vector<string>memory_comp;
		vector<string>memory_player;		
		
		//For stage 3.2 
		int rock_freq ;
		int scissors_freq ;
		int paper_freq ;
		
		//For stage 3.3
		double rock_win_freq;
		double scissors_win_freq;
		double paper_win_freq;
		
	public:   //only public methods can gain access to private variables
	    Computer(string m, string cid, string pm);
	 
	    string getcid();
	    void setcid(string);
		void randmove();
		void storecompmove();
		
		string getplayermove();
	    void setplayermove(string);	    
		void storeplayermove(string);
		
		void display_comphist();
		void display_playerhist();
		
		void display_compwinhist();
		
		
	//Stage 3 moves
		//Stage 3.1 move. The computer will play as its move the move that the human played previously. 1st move random if not it's cheating
		void feedbackmove_one();
		
		//Stage 3.2 move. The computer will work out what move the human player has played the most and then play the move that would win against the filthy human's most common action.
		//Within storeplayermove. include private variables rock, paper, scissors to see how many times. Then fin dthe max within the 3
		void feedbackmove_two();
		void display_rpscounts();
		
		//Stage 3.3 move. The computer will work out which of its moves have won most often and play that move.
		//Within this stage3.3 void function , create int rock_win, paper_win, scissors_win variables with i++ to add to the count when computer wins
		void feedbackmove_three();
	
};
#endif


