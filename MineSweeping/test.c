#include "game.h"

int leicount;
int Spacenumber;

void  menu()
{
	printf("**************************************\n");
	printf("************** 1.play ****************\n");
	printf("************** 0.exit ****************\n");
	printf("**************************************\n");
}

void  game()
{
	char mine[ROWS][COLS] = { '0' };
	char show[ROWS][COLS] = { '0' };


	InitBoard(mine, ROW, COL, '0');
	InitBoard(show, ROWS, COLS, '*');


	PrintBoard(show, ROW, COL);

	SetMine(mine, ROW, COL);
	
	FineMine(mine,show,ROW,COL );
}

int  main()
{
	int  input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>;");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
				game();
				break;
		case 0:
		        break;
		default:
			printf("ѡ��������������룡");
			break;
		}
	} while (input);



	system("pause");
	return 0;



}