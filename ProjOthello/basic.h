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



// Here we define basic rule nd matrix gen func in othello
#include"stack.h"

void creatmb(); /* Sets up the board initially */

int valid(int x, int y,int turn, int st); /* Most IMP Func of my whole program.. Reused a lot!! :0 */

void change(short int, short int, int, int, int); /* To make app changes to board after move played */
