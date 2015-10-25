#include"start.h"
#include<ncurses.h>

int t = 2;
	
void call() {
	
	initscr();
	//move(20, 2);
	//printw("HI");
	rec();
	fetch("Letters/o.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/t.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/h.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/e.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/l.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/l.txt");
	napms(1000);
	clear();
	
	rec();
	fetch("Letters/o.txt");
	napms(1000);
	clear();
	
	napms(2000);
	clear();
	/*
	fetch("Letters/o.txt");
	fetch("Letters/t.txt");
	fetch("Letters/h.txt");
	fetch("Letters/e.txt");
	fetch("Letters/l.txt");
	fetch("Letters/l.txt");
	fetch("Letters/o.txt");
	*/
	menu();
}	


void fetch(char *s) {
	
	int i = 0, j = 0;
	FILE *f;
	f = fopen(s, "r");
	while(1) {
		fscanf(f, "%d", &b[j++][i]);
		if (j == 8) {
			j = 0;
			i++;
		}
		if(i == 8) 
			break;	 
	}
	print();
	fclose(f);
}				

void print() {
	int i = 0, j = 0;
	//move(20, 20);
	refresh();
	//move(50, 50);
	
	for(i = 0; i < 8; i++) {
		move(15+i, 60);
		for(j = 0; j < 8; j++) {
			if(b[j][i] == 0) {
				attrset(COLOR_PAIR(5)); 
				printw(" ");
			}	
			else {
				attrset(COLOR_PAIR(2));
				printw(" ");		
			}	
		}
		printw("\n");
	}
	//move(0, j);
	refresh();
}			

void rec () {
	
	fetch("Letters/o.txt");
	napms(LAG);
	clear();
	fetch("Letters/t.txt");
	napms(LAG);
	clear();
	fetch("Letters/h.txt");
	napms(LAG);
	clear();
	fetch("Letters/e.txt");
	napms(LAG);
	clear();
	fetch("Letters/l.txt");
	napms(LAG);
	clear();
	fetch("Letters/l.txt");
	napms(LAG);
	clear();
	fetch("Letters/o.txt");
	napms(LAG);
	clear();
}	

void menu() {
	
	/* We Will have 4 options 
	* START
	* LOAD
	* HELP
	* EXIT
	*/
	
	// START will have 2 choices vs Human and vs Computer
	// Load will give you the list of files saved before
	// HElp will tel you the rules of the game
	// Exit will quit the game
	
	int i, j;
	
	move((LINES/2) - 3, (COLS/2) -9);
	attrset(COLOR_PAIR(5) | A_BOLD);
	printw("***********OTHELLO***********\n");
	attrset(COLOR_PAIR(1) | A_BOLD);
	move((LINES/2) - 2, (COLS/2) -3);
	printw(">>>>>> 1.START         \n");
	move((LINES/2) - 1, (COLS/2) -3);
	printw(">>>>>> 2.LOAD       \n");
	move((LINES/2) , (COLS/2) -3);
	printw(">>>>>> 3.HELP        \n");
	move((LINES/2) + 1, (COLS/2) -3);
	printw(">>>>>> 4.EXIT              \n");
	move((LINES/2) + 3, (COLS/2) -3);
	printw("\n\n-> Select your choice.......   ");
	scanw("%d", &i);
	
	switch(i) {
		case 1: {
			clear();
			move((LINES/2) - 3, (COLS/2) -9);
			printw("&&&& &&& && & 1. Vs Human & && &&& &&&&\n");
			move((LINES/2) - 2, (COLS/2) -9);
			printw("&&&& &&& && & 2. Vs Computer & && &&& &&&&\n");
			scanw("%d", &j);
			switch(j) {
				case 1:
					clear();
					init_pair(1, COLOR_YELLOW, COLOR_BLUE);
					attrset(COLOR_PAIR(1));
					creatmb();
					printb();
					vs_human();
				break;
				case 2: {
					int k;
					move((LINES/2) - 3, (COLS/2) -9);
					printw("1. Easy\n");
					move((LINES/2) - 2, (COLS/2) -9);
					printw("2. Medium\n");
					move((LINES/2) - 1, (COLS/2) -9);
					printw("3. Hard\n");
					printw("Enter your choice\n");
					scanw("%d", &k);
					switch(k) {
						case 1: {
							clear();
							init_pair(1, COLOR_YELLOW, COLOR_BLUE);
							attrset(COLOR_PAIR(1));
							creatmb();
							printb();
							vs_comp1();
						}	
						break;
					}			
				break;
				}
			}
		}		
		break;
		case 2: {
			load();
		}	
		break;
		case 3: {
			clear();
			refresh();
			char a;
			FILE *f;
			f = fopen("Help/Guide.txt", "r");
			while((fscanf(f, "%c", &a)) != EOF) {
				printw("%c", a);
				refresh();
			}
			fclose(f);
			getch();
			menu();
		}		  
			
		break;
		case 4: 
			return;
		break;
	}
	
}								


void vs_human() {
	int i, tog = 0;
	int x, y;
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, b, c;
		c = -1;
		for(d = 0; d < 8; d++) {
			for(b = 0; b < 8; b++) {
				if(a[d][b] == 0)
					c = valid(d, b, t, VMOV);
				if(c == 1) 
					break;
			}	
			if(c == 1)	
				break;
		}
		
		if(c == -1) {
			tog++;
			printw("NO VALID MOVES AVAIL\n");
			if(t == 2)
				t = 1;
			else
				t = 2;
			if(tog == 2)		
				endresult();		
		}	
		else
			tog = 0;
			
		if(t == 1) {
			printw("Player 2's turn\n");
			t = 2;
		}	
		else {
			printw("Player 1's turn\n");
			t = 1;	
		}	
		scanw("%d%d", &x, &y);
		if(x == -1) {
			save(t);
			break;
		}	
		valid(x,y,t, PLAY);
		clear();
		printb();
		refresh();
		attrset(COLOR_PAIR(1));
		printw("\n");
		
		
	}
	endresult();
}		

void save(int t) {
	clear();
	int i, j;
	i = 0; 
	j = 0;
	
	char s[5];
	printw("Type the name you want to keep for your saved game\n");
	printw("Hi\n");
	scanw("%s", s);
	refresh();
	//printw("Hi\n");
	char *q = malloc(sizeof(char)*20);
	q = strcat(q, "Save/");
	q = strcat(q, s);
	FILE *f;
	//printw("Hi\n");
	//printw("\n%s\n", s);
	f = fopen(q, "wb");
	while(1) {	
		fprintf(f, "%d", a[j++][i]);
		fprintf(f, "%c", ' ');
		if (j == 8) {
			j = 0;
			i++;
		}
		if(i == 8) 
			break;	 
	}
	//Gotta save the list of names of saved files in another list
	f = fopen(REF, "w");
	fprintf(f, "%s", s);
	fprintf(f, "%c", ' ');
	fprintf(f, "%d", t);
	fprintf(f, "%c", '\n');
	getch();
	menu();
}

void load() {
	
	clear();
	int i, j;
	i = 0;
	j = 0;
	
	FILE *f, *p;
	f = fopen(REF, "r");
	char s[10];
	
	while(fscanf(f, "%s", s) != EOF)
		printw("%s\n", s);
	
	printw("0Which game you wanna load??\n");
	scanw("%s", s);
	refresh();
	printw("HAHAHH\n");
	
	char *q = malloc(sizeof(char) * 20);
	q = strcat(q, "Save/");
	q = strcat(q, s);
	
	p = fopen(q, "r");
	
	while(fscanf(p, "%d", &a[j++][i]) != EOF) {
		if (j == 8) {
			j = 0;
			i++;
		}
		if(i == 8) 
			break;
	}
	fscanf(f, "%d", &t);
	fclose(p);
	fclose(f);
	getch();
	clear();
	printb();
	vs_human();		
}		


void vs_comp1() {

	//First need var for coordinates
	//printw("Hi");
	int x, y;
	int i, tog = 0;
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, b, c;
		c = -1;
		for(d = 0; d < 8; d++) {
			for(b = 0; b < 8; b++) {
				if(a[d][b] == 0)
					c = valid(d, b, t, VMOV);
				if(c == 1) 
					break;
			}	
			if(c == 1)	
				break;
		}
		
		if(c == -1) {
			tog++;
			printw("NO VALID MOVES AVAIL\n");
			if(t == 2)
				t = 1;
			else 
				t = 2;
				
			if(tog == 2) 
				endresult();		
		}
		else 
			tog = 0;
		c = -1;
		
		if(t == 2) {
			printw("Human's turn\n");
			scanw("%d%d", &x, &y);
			t = 1;
			valid(x,y,t, PLAY);
		}
		else {
			//printw("Here\n");
			//refresh();
			t = 2;
			for(d = 0; d < 8; d++) {
				for(b = 0; b < 8; b++) {
					if(a[d][b] == 0) 
						c = valid(d, b, t, COMP1);
					if(c == 1) 
						break;
				}	
				if(c == 1) {
					valid(d, b, t, PLAY);	
					break;
				}	
			}
		}
		
		clear();
		printb();
		refresh();
		attrset(COLOR_PAIR(1));
		printw("\n");
	}
	endresult();
}		
				




