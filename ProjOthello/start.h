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

// Will have funtions that will enable the starting of the game in a decent way
#include"basic.h"

//Set of functioons for start

void fetch(char *);
void call();
void print();
void rec();
void lag();

/* Set of functions to be used for printing during gameplay */
void printb();
void inv_print();
void endresult();

// Functions related to menu
void menu();

// Save and load
void save(int, int);
void load();

/* Functions related to mode of game */
void vs_human();
void vs_comp1();
void vs_comp2(); 
void vs_comp3(); 
