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
				case '/'://进入C状态后如果读到*/就说明结束了C状态的注释  
					third = fgetc(pfIn);//这里只是考虑避免注释到了正文  
					if (third == '\n')
					{
						fputc(third, pfOut);
					}
					else
					{
						ungetc(third, pfIn);//读到非\0时就是*/后面有正文内容，所以回退一下  
						fputc('\n', pfOut);
					}
					*ps = NUL_STATE;
					break;
				case '*':
					fputc(first, pfOut);
					ungetc(second, pfIn);//遇到两个*，则第一个是正文的*  
					break;
				default:
					fputc(first, pfOut);
					break;
				}
	}
		break;
	case '\n'://C注释换行问题  
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
					fputc('/', pfOut);//当读到/*时相当于是C状态，状态改变为C状态  
					fputc('/', pfOut);//然后把C注释的标志/*变为C++注释的标志//  
					*ps = C_STATE;
		}
			break;
		case '/':
		{
					fputc(first, pfOut);//遇到//相当于C++状态，不用转换直接把读到的标志写进去  
					fputc(second, pfOut);
					*ps = CPP_STATE;//状态变为C++状态  
		}
			break;
		default:
			fputc(first, pfOut);
			fputc(second, pfOut);
			break;
		}
		break;
	case EOF://遇到EOF直接把状态变为结束  
		fputc(first, pfOut);
		*ps = END_STATE;
		break;
	default:
		fputc(first, pfOut);//没有读到注释的标注就直接把读到的写进去  
		break;
	}
}

