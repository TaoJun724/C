#include"game.h"
void  menu()
{
	printf("*****��������Ϸ*****\n");
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
		printf("����ߣ�\n");
		player_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != ' ')
			break;
		printf("�����ߣ�\n");
		computer_move(board, ROW, COL);
		print_board(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != ' ')
			break;
	}
	if (ret == 'a')
	{
		printf(" ������ȵ��Ի�����Ŷ!\n");
	}
	else if (ret == 'b')
	{
		printf("�ٺٵ��Ա�����ʤһ��!\n");
	}
	else if (ret == 'c')
	{
		printf("�ۣ���͵��Զ���������\n");
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
		printf("��ѡ��:");
		scanf_s("%d", &i);
		switch (i)
		{
		case 0:
			game();
			break;
		case 1:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("ѡ���������������!\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;


}