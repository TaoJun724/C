#ifndef _COMMENT_CONVERT_H_
#define _COMMENT_CONVERT_H_



#include<stdio.h>
#include<stdlib.h>


enum  State
{
	NUL_STATE,//ÎÞ×¢ÊÍ×´Ì¬
	C_STATE,//C×¢ÊÍ×´Ì¬
	CPP_STATE,//C++×¢ÊÍ×´Ì¬
	END_STATE//½áÊø×´Ì¬
};

void CommentConvert(FILE* pfIn, FILE *pfOut); //×¢ÊÍ×´Ì¬
void DoCState(FILE* pfIn, FILE *pfOut, enum State* ps);//C×´Ì¬
void DoCppState(FILE* pfIn, FILE *pfOut, enum State* ps);//C++×´Ì¬ 
void DoNulState(FILE* pfIn, FILE *pfOut, enum State* ps);//½áÊø




#endif