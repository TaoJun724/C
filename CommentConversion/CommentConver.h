#ifndef _COMMENT_CONVERT_H_
#define _COMMENT_CONVERT_H_



#include<stdio.h>
#include<stdlib.h>


enum  State
{
	NUL_STATE,//��ע��״̬
	C_STATE,//Cע��״̬
	CPP_STATE,//C++ע��״̬
	END_STATE//����״̬
};

void CommentConvert(FILE* pfIn, FILE *pfOut); //ע��״̬
void DoCState(FILE* pfIn, FILE *pfOut, enum State* ps);//C״̬
void DoCppState(FILE* pfIn, FILE *pfOut, enum State* ps);//C++״̬ 
void DoNulState(FILE* pfIn, FILE *pfOut, enum State* ps);//����




#endif