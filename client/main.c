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
#include "menu.c"


#define DELAY 30000

int main(int argc, const char * argv[]) {

	int x = 0, y = 0;


	initscr();
	noecho();
	curs_set(FALSE); 


	menu();	





	endwin();

	return 0;
}
