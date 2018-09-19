#include "game.h"  
void  init_board(char  board[ROW][COL], int  row, int  col)
{
	memset(board, ' ', row*col*sizeof(board[0][0]));
}
void  print_board(char  board[ROW][COL], int  row, int  col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c |  %c \n", board[i][0], board[i][1], board[i][2]);
		if (i != 2)
			printf("---|---|---\n");

	}
}
void  player_move(char board[ROW][COL], int row, int col)
{
	int q = 0;
	int w = 0;
	printf("请您下子：\n");
	while (1)
	{
		scanf_s("%d%d", &q, &w);
		if (((q> 0) && (q <= row)) && ((w > 0) && (w <= col)))
		{
			if (board[ q-1][w-1 ] == ' ')
			{
				board[q-1 ][w-1 ] = 'a';//玩家落子  
				break;
			}
			else
			{
				printf("该子已被占用不可以在此下子：\n");
			}
		}
		else
		{
			printf("输入错误请重新输入\n");
		}
	}
}
void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'b';
			break;
		}
	}

}
static  is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] != ' '))
		{
			return  board[i][0];
		}
	}
	for (j = 0; j < col; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[2][j] != ' '))
		{
			return  board[0][j];
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] != ' '))
	{
		return board[0][0];
	}
	else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' '))
	{
		return board[0][2];
	}
	else if (1 == is_full(board, ROW, COL))
	{
		return 'c';
	}
	else
		return ' ';
}
