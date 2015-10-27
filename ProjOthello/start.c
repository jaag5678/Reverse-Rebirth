#include"start.h"
#include<ncurses.h>

int t = 2;
	
void call() {
	
	initscr();

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
	refresh();
	
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
	refresh();
}			

void rec () {
	
	fetch("Letters/o.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/t.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/h.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/e.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/l.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/l.txt");
	napms(LAG_1);
	clear();
	fetch("Letters/o.txt");
	napms(LAG_1);
	clear();
}	

void lag() {
	int i;
	for(i = 0; i < 3; i++) {
		printw(" ");
		refresh();
		napms(LAG_2);
	}	
}	
	
void menu() {
	
	int i, j;
	
	move((LINES/2) - 3, (COLS/2) -20);
	attrset(COLOR_PAIR(5) | A_BOLD | A_UNDERLINE);
	
	printw(" O");
	refresh();
	lag();
	printw("T");
	refresh();
	lag();
	printw("H");
	refresh();
	lag();
	printw("E");
	refresh();
	lag();
	printw("L");
	refresh();
	lag();
	printw("L");
	refresh();
	lag();
	printw("O");
	refresh();
	lag();	
	napms(1000);
	attroff(COLOR_PAIR(5));

	move((LINES/2) - 2, (COLS/2) -10);
	printw(">>>>>> 1.START\n");
	move((LINES/2) - 1, (COLS/2) -10);
	printw(">>>>>> 2.LOAD\n");
	move((LINES/2) , (COLS/2) -10);
	printw(">>>>>> 3.HELP\n");
	move((LINES/2) + 1, (COLS/2) -10);
	printw(">>>>>> 4.EXIT\n");
	move((LINES/2) + 3, (COLS/2) -10);
	attroff(A_UNDERLINE);
	printw("\n\n-> Select your choice.......");
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
					printw("VS HUMAN [");
					printw("Type -1 to Save]");
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
							printw("VS COMP [");
							printw("Type -1 to Save]");
							init_pair(1, COLOR_YELLOW, COLOR_BLUE);
							attrset(COLOR_PAIR(1));
							creatmb();
							printb();
							vs_comp1();
						}	
						break;
						case 2: {
							clear();
							printw("VS COMP [");
							printw("Type -1 to Save]");
							init_pair(1, COLOR_YELLOW, COLOR_BLUE);
							attrset(COLOR_PAIR(1));
							creatmb();
							printb();
							vs_comp2();
						}
						break;
						case 3: {	
							clear();
							printw("VS COMP [");
							printw("Type -1 to Save]");
							init_pair(1, COLOR_YELLOW, COLOR_BLUE);
							attrset(COLOR_PAIR(1));
							creatmb();
							printb();
							vs_comp3();
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
	int x, y, ty;
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, b, c;
		c = -1;
		if(t == 1)
			ty = 2;
		else
			ty = 1;	
			
		for(d = 0; d < 8; d++) {
			for(b = 0; b < 8; b++) {
				if(a[d][b] == 0)
					c = valid(d, b, ty, VMOV);
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
	//printw("Hi\n");
	scanw("%s", s);
	refresh();
	//printw("Hi\n");
	char *q = malloc(sizeof(char)*20);
	q = strcat(q, "Save/");
	q = strcat(q, s);
	FILE *f;
	//printw("Hi\n");
	//printw("\n%s\n", s);
	f = fopen(q, "a+");
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
	fclose(f);
	
	f = fopen(REF, "a+");
	fprintf(f, "%s", s);
	fprintf(f, "%c", ' ');
	fprintf(f, "%d", t);
	fprintf(f, "%c", '\n');
	fclose(f);
	
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
	int x, y, ty;
	int i, tog = 0;
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, b, c;
		c = -1;
		if(t == 1) 
			ty = 2;
		else
			ty = 1;
				
		for(d = 0; d < 8; d++) {
			for(b = 0; b < 8; b++) {
				if(a[d][b] == 0)
					c = valid(d, b, ty, VMOV);
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
			if(x == -1) {
				save(t);
				break;
			}	
			valid(x,y,t, PLAY);
		}
		else {
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
				
void vs_comp2() {

	int x, y, ty;
	int i, tog = 0;
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, e, c;
		c = -1;
		if(t == 1) 
			ty = 2;
		else
			ty = 1;
				
		for(d = 0; d < 8; d++) {
			for(e = 0; e < 8; e++) {
				if(a[d][e] == 0)
					c = valid(d, e, ty, VMOV);
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
			if(x == -1) {
				save(t);
				break;
			}	
			valid(x,y,t, PLAY);
		}
		else {	
			t = 2;
			for(x = 0; x < 8; x ++) 
				for(y = 0; y < 8; y++)
					b[x][y] = 0;
			
			for(x = 0; x < 8; x ++) 
				for(y = 0; y < 8; y++) 
					valid(x, y, t, COMP2);			
	
			int max = b[0][0];
			int max_x = 0; 
			int max_y = 0;
			for(x = 0; x < 8; x ++) { 
				for(y = 0; y < 8; y++) { 
					if(max < b[x][y]) { 
						max = b[x][y];
						max_x = x;
						max_y = y;
					}
				}
			}	
			valid(max_x, max_y, t, PLAY);
		}		
		clear();
		printb();
		refresh();
		attrset(COLOR_PAIR(1));
		printw("\n");
	}
	endresult();
}			
				
void vs_comp3() {
	
	int k, j;
	int x, y, ty;
	int i, tog = 0;
	
	// Make the priority table ready to refer
	FILE *f;
	//printw("HAHA\n");
	//refresh();
	f = fopen(PT, "r");
	for(k = 0; k < 8; k++)
		for(j = 0; j < 8; j++)
			fscanf(f, "%d", &b[j][k]);
	//printw("HEHE\n");
	//refresh();
	g = malloc(sizeof(prior));
	
	attrset(COLOR_PAIR(1));
	for(i = 0; i < 64; i++) {
		
		int d, e, c;
		c = -1;
		if(t == 1) 
			ty = 2;
		else
			ty = 1;
				
		for(d = 0; d < 8; d++) {
			for(e = 0; e < 8; e++) {
				if(a[d][e] == 0)
					c = valid(d, e, ty, VMOV);
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
			if(x == -1) {
				save(t);
				break;
			}	
			valid(x,y,t, PLAY);
		}
	//COMP S TURN
	// Now call the func to check all valid moves using st COMP3
		else {
			g->x = 0;
			g->y = 0;
			g->i = 0;
			g->p = -1;
			t = 2;
			for(k = 0; k < 8; k++) {
				for(j = 0; j < 8; j++) { 
					if(a[i][j] == 0) {
						if(a[k][j] == 0)
							valid(k, j, t, COMP3);
					}		
				}
			}	
	// now go and make app changes to the valid function
	
	//Once done now call valid func with the coord stored in g
			valid(g->x, g->y, t, PLAY);
		}	
	//Done....
		clear();
		printb();
		refresh();
		attrset(COLOR_PAIR(1));
		printw("\n");
	}
	endresult();
}			
				
	
		
	
	
	
	
	
	
	
	
	
	
	





