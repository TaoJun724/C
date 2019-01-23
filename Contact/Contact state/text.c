#include "Contact.h"


#pragma  warning(disable:4996)

void menu()
{
	printf("**********************************\n");
	printf("******** 1.add    2.del **********\n");
	printf("******** 3.search 4.modify  ******\n");
	printf("******** 5.show   6.sort  ********\n");
	printf("******** 7.empty  0.exit  ********\n");
}


int main()
{
	int input = 0;
	struct Contact my_son;
	InitContact(&my_son);
	do
	{
		menu();
		printf("ÇëÑ¡Ôñ>");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&my_son);
			break;
		case DEL:
			DelContact(&my_son);
			break;
		case SHOW:
			ShowContact(&my_son);
			break;
		case EXIT:
			DestoryContact(&my_son);
			break;
		default:
			printf("Ñ¡Ôñ´íÎó.");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}