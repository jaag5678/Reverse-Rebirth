#include<stdio.h>
#include<stdlib.h>
#include"basic.h"

int main() {
	
	int x, y, i, t;
	creatmb();
	printb();
	
	t = 1;
	printf("Player 1's turn\n");
	for(i = 0; i < 64; i++) {
		scanf("%d%d", &x, &y);
		valid(x,y,t);
		printb();
		
		if(t == 1) {
			printf("Player 2's turn\n");
			t = 2;
		}	
		else {
			printf("Player 1's turn\n");
			t = 1;	
		}	
	}	
	
	endresult();
	
	return 0;
}	