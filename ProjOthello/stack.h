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


// Reason I'm using a stack is to enhance the reusability of the valid function
#include"impdef.h"
typedef struct stack {
	direct *a;
	int ct;
}stack;

void init(stack *s);
void push(stack *s, direct t);
direct pop(stack *s);
int full(stack *s);
int empty(stack *s);	
