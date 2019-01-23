#ifndef __CONTACT_H__
#define __CONTACT_H__


#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#include<errno.h>


enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	EMPTY
};

#define FileName "contact.txt"
#define CAP 3
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 30
#define MAX 1000

typedef struct PeoInfo
{
	char name[MAX_NAME];
	short age;
	char sex[MAX_SEX];
	char addr[MAX_ADDR];
}PeoInfo, *pPeoInfo;

//¾²Ì¬
typedef struct Contact
{
	pPeoInfo  data;
	unsigned   int sz;
	int capacity;
}Contact, *pContact;


void CheckCapacity(pContact pc);
void LoadContact(pContact pc);
void InitContact(pContact pc);
void AddContact(pContact pc);
void ShowContact(pContact pc);
void DelContact(pContact pc);
void DestoryContact(pContact pc);
void SearchContact(pContact pc);
void EmptyContact(pContact pc);
void ModifyContact(pContact pc);
void SortContact(pContact pc);

#endif