/*THis is a Program to play the Board game OTHELLO !:)
    Copyright (C) <2015>  <Ak$h@y G>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include<ncurses.h>
#include<stdlib.h>
#include"start.h"

int main() {
	
	int x, y, i, t;
	initscr();
	
	/* Initializing some basic text color formats to be used throughout the program */
	
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(3, COLOR_BLUE, COLOR_WHITE);
	init_pair(4, COLOR_BLACK, COLOR_CYAN);
	init_pair(5, COLOR_YELLOW, COLOR_RED);
	init_pair(6, COLOR_RED, COLOR_YELLOW);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	
	call();
	flushinp();
	menu();
	
	clear();	
	getch();
	endwin();
	
	return 0;
}	
