#include"basic.h"
#include"ncurses.h"

void creatmb() {
	
	int i, j;
	
	//set all elements to zero initiallly
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			a[i][j] = 0;
		}
	}
	
	// Now set middle elements
		a[3][3] = a[4][4] = 1;
		a[3][4] = a[4][3] = 2;
		
}

// We supply the coordinates to the func to see if the move is valid
void printb() {
	
	int i, j, k = 0;
	init_pair(2, COLOR_MAGENTA, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	init_pair(5, COLOR_RED, COLOR_YELLOW);
	
	printw("VS HUMAN [");
	printw("Type -1 to Save]");
	attrset(COLOR_PAIR(5));
	
	move(k,53);
	printw(" ");
	for(i = 0; i < 8; i++)  
		printw(" %d ", i);
	k++;
	//printw(" ");
	printw("\n");
	
	move(k,53);
	for(i = 0; i < 8; i++) 
		printw(" --");
	printw(" ");	
	k++;
	printw("\n");
		
	for(i = 0; i < 8; i++) {
		move(k+1, 50);
		attrset(COLOR_PAIR(5));	
		printw("%d |", i);
		attrset(COLOR_PAIR(2));
		printw(" ");
		for(j = 0; j < 8; j++) {
			if(a[j][i] == 0) {
				attrset(COLOR_PAIR(2)); 
				printw(" _ ");
			}	
			else if(a[j][i] == 1) {
				attron(COLOR_PAIR(3) | A_BOLD);
				printw(" O ");
				attroff(COLOR_PAIR(3) | A_BOLD);
			}	
			else {
				attron(COLOR_PAIR(4) | A_BOLD);
				printw(" O ");
				attroff(COLOR_PAIR(4) | A_BOLD);				
			}
			attrset(COLOR_PAIR(2));		
		}
		k+=2;
		attrset(COLOR_PAIR(5));
		printw("| %d", i);
		attrset(COLOR_PAIR(2));	
	}
	
	attrset(COLOR_PAIR(5));
	move(k,53);
	for(i = 0; i < 8; i++) 
		printw(" --");
	printw(" ");	
	k++;
	move(k,53);
	printw(" ");
	for(i = 0; i < 8; i++)  
		printw(" %d ", i);
	//printw(" ");	
	k++;
	printw("\n");
	printw("\n");
	
	getch();	
}
int valid(int x, int y, int turn, int st) {
	
	stack *s;
	direct z;
	s = malloc(sizeof(stack));
	init(s);
	int i, j = 0, t;
	
	if(turn == P1)
		t = 2;
	else
		t = 1;
							 
	// First we go left.. note that y is constant
		for(i = x; i > 0; i--) {
			if(a[i-1][y] == t)
				continue;
			else {
				i--;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!((x - i) == 1) && !(a[i][y] == 0) && !(a[i][y] == t)  && !(x == i)) {
			if(st == VMOV)
				return 1; 
			z.a = LEFT; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}
			if(st == COMP2) {
				b[x][y] = b[x][y] + (x-i);
			}		 
			push(s, z);
		}	
			
	// Second we go right.. note that y is constant
		for(i = x; i < 7; i++) {
			if(a[i+1][y] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!((i - x) == 1) && !(a[i][y] == 0) && !(a[i][y] == t) && !(x == i)) { 
			if(st == VMOV)
				return 1; 
			z.a = RIGHT; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	 
			if(st == COMP2) {
				b[x][y] = b[x][y] + (i - x);
			}	
			push(s, z);
		}	
					
	// Third we go up.. note that x is constant
		for(i = y; i > 0; i--) {
			if(a[x][i-1] == t)
				continue;
			else {
				i--;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!((y - i) == 1) && !(a[x][i] ==0) && !(a[x][i] == t) && !(y == i)) { 
			if(st == VMOV)
				return 1; 
			z.a = UP; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	 
			if(st == COMP2) {
				b[x][y] = b[x][y] + (y-i);
			}	
			push(s, z);
		}	
	// Fourth we go down.. note that x is constant
		for(i = y; i < 7; i++) {
			if(a[x][i+1] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!((i - y) == 1) && !(a[x][i] == 0) && !(a[x][i] == t) && !(y == i)) {
			if(st == VMOV)
				return 1; 
			z.a = DOWN; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	 
			if(st == COMP2) {
				b[x][y] = b[x][y] + (i - y);
			}	
			push(s, z);	
		}		
	
	// Fifth we go DIAGONALLY RIGHT DOWN.. 
		for(i = 1; ((x+i) < 8 && (y+i) < 8); i++) {
			if(a[x+i][y+i] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(!(i == 2) && !(a[x+i-1][y+i-1] == 0) && !(a[x+i-1][y+i-1] == t)) {
			if(st == VMOV)
				return 1; 
			z.a = DDOWNR; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	 
			if(st == COMP2) {
				b[x][y] = b[x][y] + i;
			}	
			push(s, z);		
		}
			
	// Sixth we go DIAGONALLY LEFT UP.. 
		for(i = 1; ((x-i) > 0 && (y-i) > 0); i++) {
			if(a[x-i][y-i] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		if(i == 1)
			i++;
		
	// Now need to analyze this after loop
		if(!(i == 2) && !(a[x-i+1][y-i+1] == 0) && !(a[x-i+1][y-i+1] == t)) { 
			if(st == VMOV)
				return 1; 
			z.a = DUPL; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	
			if(st == COMP2) {
				b[x][y] = b[x][y] + i;
			}	 
			push(s, z);		
		}			
	
	// Seventh we go DIAGONALLY RIGHT UP.. 
		for(i = 1; ((x+i) < 8 && (y-i) > 0 ); i++) {
			if(a[x+i][y-i] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		if(i == 1)
			i++;
		
	// Now need to analyze this after loop
		if(!(i == 2) && !(a[x+i-1][y-i+1] == 0) && !(a[x+i-1][y-i+1] == t)) { 
			if(st == VMOV)
				return 1; 
			z.a = DUPR; //VALID
			z.i = i;
			if(st == COMP1) {
				return 1;
			}	
			if(st == COMP2) {
				b[x][y] = b[x][y] + i;
			}	 
			push(s, z);		
		}			
	
	// Eighth we go DIAGONALLY LEFT DOWN.. 
		for(i = 1; ((x-i) > 0 && (y+i) < 8 ); i++) {
			if(a[x-i][y+i] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		if(i == 1)
			i++;
	// Now need to analyze this after loop
		if(!(i == 2) && !(a[x-i+1][y+i-1] == 0) && !(a[x-i+1][y+i-1] == t)) { 
			if(st == VMOV)
				return 1; 
			z.a = DDOWNL;
			z.i = i; //VALID
			if(st == COMP1) {
				return 1;
			}	
			if(st == COMP2) {
				b[x][y] = b[x][y] + i;
			}	 
			push(s, z);		
		}
		if(st == VMOV) 
			return -1;
		if(st == COMP1)
			return -1;
		if(st == COMP2)
			return -1;		
			
		if(empty(s)) {	
			printw("\n");
			init_pair(1, COLOR_YELLOW, COLOR_BLUE);
			attrset(COLOR_PAIR(1));	
			printw("INVALID MOVE PLAY AGAIN\n");
			if(t == 1) {
				printw("Player 2's turn");	
				attron(COLOR_PAIR(4) | A_BOLD);
				printw(" O\n");
				scanw("%d%d", &x, &y);
				attroff(COLOR_PAIR(4) | A_BOLD);		
				valid(x,y,2, PLAY);
			}
			else {
				printw("Player 1's turn");
				attron(COLOR_PAIR(3) | A_BOLD);
				printw(" O\n");
				scanw("%d%d", &x, &y);
				attroff(COLOR_PAIR(3) | A_BOLD);		
				valid(x,y,1, PLAY);
				attroff(COLOR_PAIR(1));
			}		
		}
		else {		
			while(!empty(s)) {
				z = pop(s);
				printw("%d %d", z.a, z.i);
				change(z.a, z.i, x, y, turn);
			}	 	
		}									
}

void change(short int c, short int b, int x, int y, int t) {
	
	int i;
	
	switch(c) {
		case(LEFT): {
				for(i = x; i > b; i--) 
					a[i][y] = t;
		}
		break;
		
		case(RIGHT): {
				for(i = x; i < b; i++)
					a[i][y] = t;
		}
		break;			
		
		case(UP): { 
			for(i = y; i > b; i--) 
				a[x][i] = t;
		}
		break;
		
		case(DOWN): {
			for(i = y; i < b; i++)
				a[x][i] = t;
		}
		break;	
		
		case(DUPR): {
			for(i = 0; i < b; i++) 
				a[x+i][y-i] = t;
		}
		break;	
		
		case(DUPL): {
			for(i = 0; i < b; i++) 
				a[x-i][y-i] = t;
		}
		break;		
			
		case(DDOWNR): {
			for(i = 0; i < b; i++) 
				a[x+i][y+i] = t;
		}
		break;
		
		case(DDOWNL): {
			for(i = 0; i < b; i++) 
				a[x-i][y+i] = t;
		}
		break;													
	}	
}	
			
void endresult() {
	
	int i,j, ct1, ct2;
	ct1 = 0;
	ct2 = 0;
				
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			if(a[i][j] == 1)
				ct1++;
			else
				ct2++;	
		}
	}
	
	if(ct1 > ct2) 
		printf("Player 1 wins\n");
	else if(ct2 > ct1)
		printf("Player 2 wins\n");
	else
		printf("It's a draw\n");
	
	menu();	
}				  
  
  
  
  
  										
							
								
			
