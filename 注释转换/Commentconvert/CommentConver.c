#define _CRT_SECURE_NO_WARNINGS 1


#include "CommentConver.h"






void CommentConvert(FILE* pfIn, FILE *pfOut)
{

	enum State state = NUL_STATE;   
	while (state != END_STATE)
	{
		switch (state)
		{
		case NUL_STATE:
			DoNulState(pfIn, pfOut, &state);
			break;
		case C_STATE:
			DoCState(pfIn, pfOut, &state);
			break;
		case CPP_STATE:
			DoCppState(pfIn, pfOut, &state);
			break;
		default:
			break;
		}
	}
}




void DoCState(FILE* pfIn, FILE *pfOut, enum State* ps)
{
	int first = 0;
	int second = 0;
	int third = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '*':
	{
				second = fgetc(pfIn);
				switch (second)
				{
				case '/'://����C״̬���������*/��˵��������C״̬��ע��  
					third = fgetc(pfIn);//����ֻ�ǿ��Ǳ���ע�͵�������  
					if (third == '\n')
					{
						fputc(third, pfOut);
					}
					else
					{
						ungetc(third, pfIn);//������\0ʱ����*/�������������ݣ����Ի���һ��  
						fputc('\n', pfOut);
					}
					*ps = NUL_STATE;
					break;
				case '*':
					fputc(first, pfOut);
					ungetc(second, pfIn);//��������*�����һ�������ĵ�*  
					break;
				default:
					fputc(first, pfOut);
					break;
				}
	}
		break;
	case '\n'://Cע�ͻ�������  
		fputc(first, pfOut);
		fputc('/', pfOut);
		fputc('/', pfOut);
		break;
	case EOF:
		fputc(first, pfOut);
		*ps = END_STATE;
	default:
		fputc(first, pfOut);
		break;
	}
}
void DoCppState(FILE* pfIn, FILE *pfOut, enum State* ps)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '\n':
	{
				  fputc('\n', pfOut);
				  *ps = NUL_STATE;
	}
		break;
	case EOF:
		fputc(first, fputc('\n', pfOut));

		*ps = NUL_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}



void DoNulState(FILE* pfIn, FILE *pfOut, enum State* ps)
{
	int first = 0;
	int second = 0;
	int third = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '/':
		second = fgetc(pfIn);
		switch (second)
		{
		case '*':
		{
					fputc('/', pfOut);//������/*ʱ�൱����C״̬��״̬�ı�ΪC״̬  
					fputc('/', pfOut);//Ȼ���Cע�͵ı�־/*��ΪC++ע�͵ı�־//  
					*ps = C_STATE;
		}
			break;
		case '/':
		{
					fputc(first, pfOut);//����//�൱��C++״̬������ת��ֱ�ӰѶ����ı�־д��ȥ  
					fputc(second, pfOut);
					*ps = CPP_STATE;//״̬��ΪC++״̬  
		}
			break;
		default:
			fputc(first, pfOut);
			fputc(second, pfOut);
			break;
		}
		break;
	case EOF://����EOFֱ�Ӱ�״̬��Ϊ����  
		fputc(first, pfOut);
		*ps = END_STATE;
		break;
	default:
		fputc(first, pfOut);//û�ж���ע�͵ı�ע��ֱ�ӰѶ�����д��ȥ  
		break;
	}
}

