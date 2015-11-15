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


#include"stack.h"

void init(stack *s) {
	s->ct = 0;
}
	
void push(stack *s, direct t) {
	
	if(s->ct == 0) {
		s->a = malloc(sizeof(direct));
		s->a[s->ct].a = t.a ;
		s->a[s->ct].i = t.i;
		s->ct++;
	}
	else {
		s->a = realloc(s->a, sizeof(int) * (s->ct+1));
		s->a[s->ct].a = t.a ;
		s->a[s->ct].i = t.i;
		s->ct++;
	}
}			

direct pop(stack *s) {
	s->ct--;
	return s->a[s->ct];
}
	
int full(stack *s) {
	return;
}	 
	
int empty(stack *s) {
	if(!s->ct)
		return 1;
	return 0;	
}		
