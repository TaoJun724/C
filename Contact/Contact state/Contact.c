#define _CRT_SECURE_NO_WARNINGS 1


#include "Contact.h"

void LoadContact(pContact pc)
{
	FILE *pfRead = fopen(FileName, "r");
	PeoInfo  tmp = { 0 };
	if (pfRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	//����
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead))
	{
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pfRead);
	pfRead = NULL;
}
void InitContact(pContact pc)
{
	pc->sz = 0;
	pc->capacity = CAP;
	pc->data = (pPeoInfo)calloc(pc->capacity,sizeof(PeoInfo));//������Ԫ�ظ�����Ԫ�ش�С
	if (pc->data == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	//�����ļ���Ϣ
	LoadContact(pc);
}
void CheckCapacity(pContact pc)
{
	if (pc->capacity == pc->sz)
	{
		pPeoInfo ptr = realloc(pc->data, (pc->capacity += 2)*sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
		}
		printf("���ݳɹ�\n");
	}
}
void AddContact(pContact pc)
{
	CheckCapacity(pc);
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�Ѿ�����\n");
		return;
	}

	printf("����������:>");
	scanf("%s", (pc->data[pc->sz].name));
	printf("�������Ա�:>");
	scanf("%s", (pc->data[pc->sz].sex));
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������ַ:>");
	scanf("%s", (pc->data[pc->sz].addr));
	pc->sz++;
	printf("��ӳɹ�\n");
}

void ShowContact(pContact pc)
{
	unsigned int i = 0;
	printf("%10s\t%5s\t%5s\t%10s\t\n", "name", "age", "sex", "addr");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s\t%5d\t%5s\t%10s\t\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr);
	}
}
static int Find(pContact pc, char name[])
{
	unsigned int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void DelContact(pContact pc)
{
	unsigned int i;
	int pos;
	char  name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("û�п�ɾ��Ϣ\n");
		return;
	}
	printf("������Ҫɾ��������");
	scanf("%s", name);
	pos = Find(pc, name);
	if (pos == -1)
	{
		printf("ɾ�����û�������\n");
		return;
	}
	else
	{
		for (i = pos; i <pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�\n");
	}
}
void SaveContact(pContact pc)
{
	FILE* pfWrite = fopen(FileName, "w");
	if (pfWrite == NULL)
	{
		perror("open file for write");
		exit(EXIT_FAILURE);
	}
	unsigned int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}
void DestoryContact(pContact pc)
{
	//�����ļ�
	SaveContact(pc);
	//����
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	printf("����ͨѶ¼\n");
}


void EmptyContact(pContact pc)
{
	printf(" \n");
	memset(pc->data, 0, sizeof(pc->data));
	pc->sz = 0;
	printf("�Ѿ����\n");
}



void SearchContact(pContact pc)
{
	unsigned int i;
	char  name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("û����������Ϣ\n");
		return;
	}
	printf("������Ҫ���ҵ�����");
	scanf("%s", name);
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			printf("���ҳɹ�\n");
			printf("%10s\t%5d\t%5s\t%10s\t\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].addr);
		}
	}
}
void ModifyContact(pContact pc)
{
	int pos;
	char  name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("û�п��޸���Ϣ\n");
		return;
	}
	printf("������Ҫ�޸ĵ�����");
	scanf("%s", name);
	pos = Find(pc, name);
	if (pos == -1)
	{
		printf("�޸ĵ��û�������\n");
		return;
	}
	else
	{
		printf("����������:>");
		scanf("%s", (pc->data[pos].name));
		printf("�������Ա�:>");
		scanf("%s", (pc->data[pos].sex));
		printf("����������:>");
		scanf("%d", &(pc->data[pos].age));
		printf("�������ַ:>");
		scanf("%s", (pc->data[pos].addr));
		printf("�޸ĳɹ�\n");
	}
}
void SortContact(pContact pc)
{
	unsigned int i = 0;
	unsigned int j = 0;
	if (pc->sz == 0)
	{
		printf("û�п�������Ϣ\n");
		return;
	}
	for (i = 0; i < pc->sz - 1; i++)
	{
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp((pc->data[j].name), (pc->data[j + 1].name))>0)//strcmp  str1>str2��Ϊ����
			{
				PeoInfo t;
				t = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = t;
			}
		}
	}

}
