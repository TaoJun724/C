#include"game.h"
void  menu()
{
	printf("*****三子棋游戏*****\n");
	printf("*****   0.START*****\n");
	printf("*****   1. EXIT*****\n");
	printf("********************\n");
}
void game()
{
	char ret;
	char board[ROW][COL];
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);
	while (1)
	{
		printf("玩家走：\n");
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != ' ')
			break;
		printf("电脑走：\n");
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != ' ')
			break;
	}
	if (ret == 'a')
	{
		printf(" 哈哈你比电脑还厉害哦!\n");
	}
	else if (ret == 'b')
	{
		printf("嘿嘿电脑比你略胜一筹!\n");
	}
	else if (ret == 'c')
	{
		printf("哇，你和电脑都好厉害哇\n");
	}
}
int  main()
{
	int i = 0;
	srand((unsigned)time(NULL));
	do
	{
		int i;
		menu();
		printf("请选择:");
		scanf_s("%d", &i);
		switch (i)
		{
		case 0:
			game();
			break;
		case 1:
			printf("游戏退出\n");
			break;
		default:
			printf("选择错误，请重新输入!\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;


}