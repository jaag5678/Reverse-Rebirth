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


/* This .h file contains basic predef constants that are used freq throughout all the file ! */

#define LAG_1 50
#define LAG_2 70

#define P1 1
#define P2 2

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define DUPR 5
#define DUPL 6
#define DDOWNR 7
#define DDOWNL 8

#define REF "Save/LoadList.txt"

#define VMOV -1
#define INV 0
#define PLAY 1

#define COUNT 5

#define COMP1 2
#define COMP2 3
#define COMP3 4

#include<stdlib.h>
#include<string.h>

typedef struct direct {
	short int a;
	short int i;
}direct;
	
/* For ROXANNE (Hard mode of Gameplay) */
#define PT "Letters/ROXANNE.txt"
typedef struct prior {
	int x, y;
	int i;
	int p;
}prior;		
prior *g;
	

int a[8][8];
int b[8][8]; // Which player plays
