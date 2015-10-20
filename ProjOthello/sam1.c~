#include<ncurses.h>
#include<stdlib.h>
#include"basic.h"

int main() {
	
	int x, y, i, t;
	initscr();
	start_color();
	
	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 50; i++) {
		refresh();
		printw("OTHELLO");
		napms(100);
		move(i+1, i+1);
		
	}	
	clear();
	creatmb();
	printb();
	
	t = 1;
	
	attrset(COLOR_PAIR(1));
	printw("\nPlayer 1's turn\n");
	for(i = 0; i < 64; i++) {
		scanw("%d%d", &x, &y);
		valid(x,y,t);
		clear();
		printb();
		refresh();
		attrset(COLOR_PAIR(1));
		printw("\n");
		
		if(t == 1) {
			printw("Player 2's turn\n");
			t = 2;
		}	
		else {
			printw("Player 1's turn\n");
			t = 1;	
		}	
	}	
	
	endresult();
	getch();
	endwin();
	
	return 0;
}	
