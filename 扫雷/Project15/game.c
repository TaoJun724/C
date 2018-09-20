#include "game.h"
int leicounte;
int spacenumber;
void InitBoard(char Board[ROWS][COLS], int rows, int  cols, char  set)
{
	memset(Board, set, rows*cols*sizeof(Board[0][0]));
}

void PrintBoard(char Board[ROWS][COLS], int row, int  col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= row; j++)
	{
		printf("%-3d", j);
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		printf("%-2d", i+1);
		for (j = 0; j < col; j++)
		{
			printf(" %c ", Board[i][j]);
		
		}
		printf("\n");
	}
	printf("\n");


}


void SetMine(char Board[ROWS][COLS], int row, int  col)
{
	int  leicount = 9;
	int x = 0;
	int y = 0;
	while (leicount)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if ( '0' == Board[x][y])
		{
			Board[x][y] = '1' ;
			leicount--;

		}

	}
}

static  int  GetMineCount(char  mine[ROWS][COLS], int  x, int  y)
{
	int minecount = 0;
    if (mine[x - 1][y] == '1')
		minecount++;
	if (mine[x - 1][y + 1] == '1')
		minecount++;
	if (mine[x][y + 1] == '1')
		minecount++;
	if (mine[x + 1][y + 1] == '1')
		minecount++;
	if (mine[x + 1][y] == '1')
		minecount++;
	if (mine[x + 1][y - 1] == '1')
		minecount++;
	if (mine[x][y - 1] == '1')
		minecount++;
	if (mine[x - 1][y - 1] == '1')
		minecount++;
	return minecount;
}

void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	
	if (0 == GetMineCount(mine, x, y))
	{

		show[x][y] = ' ';
		if (show[x][y - 1] == '*')
		{
			expand(mine, show, row, col, x, (y - 1));
		}

		if (show[x][y + 1] == '*')
		{
			expand(mine, show, row, col, x, (y + 1));
		}

		if (show[x - 1][y] == '*')
		{
			expand(mine, show, row, col, (x - 1), y);
		}

		if (show[x + 1][y] == '*')
		{
			expand(mine, show, row, col, (x + 1), y);
		}
	}
	else
	{
		show[x][y] = GetMineCount(mine, x, y) + '0';
	}

}


void FineMine(char mine[ROWS][COLS], char  show[ROWS][COLS], int row, int  col)
{
	int x = 0;
	int y = 0;
	int  leicount = 9;
	int  ret = 0;
	while (leicount)
	{
		printf("请输入你的坐标;");
		scanf_s("%d%d", &x, &y);
		printf("\n");
		ret++;
		
		while (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			x--;
			y--;
			if ('1' == mine[x][y])
			{
				if (1 == ret)
				{
					printf("再给你一次机会！\n");
					printf("\n");
					break;
				}
				else
				{
					printf("GAME OVER!\n");
					printf("\n");
					return 0;
				}
			}
			else
			{
				expand(mine, show, row, col, x, y);
				PrintBoard(show, ROW, COL);
				break;
			}

			if (0 == (x >= 1 && x <= row && y >= 1 && y <= col))
			{
				printf("输入非法！请重新输入！\n");
				printf("\n");
			}
		}
	}
	if (0 == leicount)
	{
		printf("恭喜你，扫雷成功！\n");
		printf("\n");
	}

}