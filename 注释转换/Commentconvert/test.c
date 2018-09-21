#define _CRT_SECURE_NO_WARNINGS 1


#include "CommentConver.h"



void test()
{
	FILE* pfIn = NULL;
	FILE* pfOut = NULL;
	pfIn = fopen("input.c","r");
	if (NULL == pfIn)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	pfOut = fopen("output.c", "w");
	if (NULL == pfOut)
	{
		perror("open file for  write");
		fclose(pfIn);
		exit(EXIT_FAILURE);
	}
	CommentConvert(pfIn, pfOut);
}




int  main()
{
	test();
	system("pause");
	return 0;
}