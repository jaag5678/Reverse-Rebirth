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
#define PLAY 1

#define COMP1 2
#define COMP2 3
#define COMP3 4

#include<stdlib.h>
#include<string.h>

typedef struct direct {
	short int a;
	short int i;
}direct;
	

int a[8][8];
int b[8][8]; // Which player plays
