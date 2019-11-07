/************************************************
*						*
*	ChatRooms - a chat room game for 	*
*		    played in the terminal	*
*						*
*	Created by: DDS CyTeam 6		*
*						*
*						*
*						*
*************************************************/

#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int main(int argc, const char * argv[]) {

	int x = 0, y = 0;


	initscr();
	noecho();
	curs_set(FALSE); 


	while(1) {
	clear();
	
  
  // do something
  
	refresh();

	usleep(DELAY);
	x++;

	}


	endwin();
	return 0;
}
