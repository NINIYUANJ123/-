// ื๗าต.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>
#include<stdio.h>
typedef int DATA;
struct SNode
{
	DATA data;
	struct SNode* pNext;
}*g_pHead = NULL;

void AddHead(DATA d)
{
	struct SNode* pNew = (struct SNode*)malloc(sizeof(struct SNode));
	pNew ->data = d;
	pNew ->pNext = g_pHead;
	g_pHead = pNew;
}

void Print()
{
	struct SNode* p = g_pHead;
	while(p)
	{
		printf("%d\n",p->data);
		p = p ->pNext;
	}

}
void Remove(DATA d)
{
	struct SNode* p = g_pHead,*p1;
	if(p ->data == d)
	{
		g_pHead = p ->pNext;
		free(p);
		return ;
	}
	while(p)
	{
		if(p ->data == d)
		{
			p1->pNext = p->pNext;
			free(p);
			break;
		}
		p1 = p;
		p = p ->pNext;
	}
}

void Modify(int old,int New)
{
	struct SNode* p = g_pHead;
	while(p)
	{
		if(p ->data == old)
			p->data=New;
		p=p->pNext;
	}
}


int main(int argc, char* argv[])
{
	AddHead(1);
	AddHead(2);
	AddHead(3);
	AddHead(4);
	AddHead(5);
	AddHead(6);
	Remove(6);
	Modify(1,6);
	Print();
	return 0;
}
