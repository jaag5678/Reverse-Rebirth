// Here we define basic rule nd matrix gen func in othello

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

typedef struct direct {
	short int a;
}direct;
	
void creatmb();
void valid(int x, int y,int turn);
void printb();
void change(short int, short int, int, int, int);
void endresult(void);
