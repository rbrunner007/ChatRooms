#include <stdio.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10

int start_x = 0;
int start_y = 0;

char *choices[] = {
	"Enter Username",
	"Connect",

};

int n_choices = sizeof(choices) / sizeof(char *);
void printMenu(WINDOW *menu_win, int highlight);


int menu() {

	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	clear();
	noecho();
	cbreak();
	start_x = (80 - WIDTH) / 2;
	start_y = (24 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, start_y, start_x);
	keypad(menu_win, TRUE);
	mvprintw(0, 0, "Use arrow key (up or down) to select");
	refresh();
	printMenu(menu_win, highlight);

	while(1) {

		c = wgetch(menu_win);
		switch(c) {

			case KEY_UP:
				if (highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:
				refresh();
				break;
		}

		printMenu(menu_win, highlight);
		if (choice != 0)
			break;
	}

	clrtoeol();
	refresh();
	endwin();
	return 0;

}

char * getUsername() {

	char * username[12];

	return username;
	
}


void printMenu(WINDOW *menu_win, int highlight) {
	
	int x, y, i;

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for (i = 0; i < n_choices; ++i) {
		if (highlight == i + 1) {
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}
