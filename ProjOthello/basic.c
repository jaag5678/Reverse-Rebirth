#include"basic.h"
#include<stdio.h>
int a[8][8];

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
	
	int i, j;
	for(i = 0; i < 8; i++)
		printf("%d ", i);

	printf("\n");
	
	for(i = 0; i < 8; i++)
		printf("--");

	printf("\n");
		
	for(i = 0; i < 8; i++) {
		for(j = 0; j < 8; j++) {
			printf("%d ", a[j][i]);
		}
		printf(" | %d\n", i);
	}
}
void valid(int x, int y, int turn) {
	
	direct s;
	int i, j = 0, t;
	
	s.a = 0;
	
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
		if(x - i == 1) 
			printf(" ");//INVALID
		else if (a[i][y] == 0)
			printf(" ");//INVALID
		else {
			s.a = LEFT; //VALID
			change(s.a, i, x, y, turn);
		}	
			//s.i[0] = i-1;
			
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
		if(i - x == 1) 
			printf(" ");//INVALID
		else if (a[i][y] == 0)
			printf(" ");//INVALID
		else {
			s.a = RIGHT; //VALID
			change(s.a, i, x, y, turn);
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
		if(y - i == 1) 
			printf(" ");//INVALID
		else if (a[x][i] ==0)
			printf(" ");//INVALID
		else {
			s.a = UP; //VALID
			change(s.a, i , x, y, turn);
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
		if(i - y == 1) 
			printf(" ");//INVALID
		else if (a[x][i] == 0)
			printf(" ");//INVALID
		else {
			s.a = DOWN; //VALID	
			change(s.a, i, x, y, turn);
		}		
	
	// Fifth we go DIAGONALLY RIGHT DOWN.. 
		for(i = 1; ((x+i) < 8 && (y+i)<8); i++) {
			if(a[x+i][y+i] == t)
				continue;
			else {
				i++;
				break;
			}	
		}
		
	// Now need to analyze this after loop
		if(i == 2) 
			printf(" ");//INVALID
		else if (a[x+i-1][y+i-1] == 0)
			printf(" ");//INVALID
		else {
			s.a = DDOWNR; //VALID	
			change(s.a, i, x, y, turn);
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
		
	// Now need to analyze this after loop
		if(i == 2) 
			printf(" ");//INVALID
		else if (a[x-i+1][y-i+1] == 0)
			printf(" ");//INVALID
		else {
			s.a = DUPL; //VALID	
			change(s.a, i, x, y, turn);
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
		
	// Now need to analyze this after loop
		if(i == 2) 
			printf(" ");//INVALID
		else if (a[x+i-1][y-i+1] == 0)
			printf(" ");//INVALID
		else {
			s.a = DUPR; //VALID	
			change(s.a, i, x, y, turn);
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
		
	// Now need to analyze this after loop
		if(i == 2) 
			printf(" ");//INVALID
		else if (a[x-i+1][y+i-1] == 0)
			printf(" ");//INVALID
		else {
			s.a = DDOWNL; //VALID	
			change(s.a, i, x, y, turn);
		}
			
		printf("\n");	
		if(s.a == 0) {
			printf("INVALID MOVE PLAY AGAIN\n");
			if(t == 1) {
				printf("Player 2's turn\n");	
				scanf("%d%d", &x, &y);		
				valid(x,y,2);
			}	
			else {
				printf("Player 1's turn\n");
				scanf("%d%d", &x, &y);		
				valid(x,y,1);
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
		
}				  
  
  
  
  
  										
							
								
			
