#ifndef  __GAME_H__
#define  __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


extern int leicount;
extern int spacenumber;


#define  ROW 9
#define  COL 9
#define  ROWS  ROW+2
#define  COLS  COL+2

void InitBoard(char Board[ROWS][COLS], int  rows, int cols, char  set); 
void PrintBoard(char Board[ROWS][COLS], int row, int  col);
void SetMine(char Board[ROWS][COLS], int row, int  col);
int  GetMineCount(char  mine[ROWS][COLS], int  x, int  y);
void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);
void FineMine(char mine[ROWS][COLS], char  show[ROWS][COLS], int row, int  col);




#endif 