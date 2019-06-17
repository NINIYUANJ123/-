// Ԭ��ΰ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <process.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>


struct SStud
{
	int nNumb;
	char sName[20];
	float fMath;
};
typedef struct SStud DATA;
struct SNode
{
	DATA data;
	struct SNode* pNext;
};
struct SNode *g_pHead = NULL;


void AddHead(DATA d)
{
	struct SNode* pNew = (struct SNode*)malloc(sizeof(struct SNode));
	pNew ->data = d;/*pNew ->dataΪһ��������*/
	pNew ->pNext = g_pHead;/*pNew ->pNextΪһ����ַ,g_pHeadΪһ���ڵ�*/
	g_pHead = pNew;/*�˷���Ϊͷ�巨*/
}


void AddTail(DATA d)
{
	struct SNode* pTail=g_pHead;
	struct SNode *pNew = (struct SNode*)malloc(sizeof(struct SNode));
	pNew ->data = d;
	pNew ->pNext = NULL;
	if(!pTail)
	{
		g_pHead = pNew;
		return;
	}
	while(pTail ->pNext)
		pTail = pTail ->pNext;
	pTail ->pNext = pNew;

}


int Remove(int nNumb)/*������*/
{
	struct SNode* p = g_pHead,*p1;
	if(nNumb == p->data.nNumb)/*��Ϊɾ��ͷ�ڵ�*/
	{
		g_pHead = p ->pNext;/*ͷ�ڵ�ָ��ڶ����ڵ�,�ɵ��ϴ�*/
		free(p);
		return 1;
	}
	while(p)
	{
		if(p->data.nNumb == nNumb)/*�ȶ�ѧ��*/
		{
			p1->pNext = p->pNext;/*��p1ָ�����һ����Ϊpָ�����һ��,���ǿ��p*/
			free(p);/*�ͷŵ�p*/
			return 1;/*�ɹ�*/
		}
		p1 = p;/*p1Ϊ��һ���ڵ�ĵ�ַ*/
		p = p ->pNext;/*ѭ�����������һ��.���±���*/
	}
	return 0;/*ʧ��*/
}


void Print()
{
    puts("\t\t\t\tѧ��\t����\t��ѧ�ɼ�");
	struct SNode* p = g_pHead;/*struct SNode* pΪһ��ָ��*/
	while(p)
	{
		printf("\t\t\t\t%d\t%s\t%0.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
		p = p->pNext;
	}/*��Ϊ����ѭ��62��*/
//prntf("%d\t%s\t%0.1f\n");
}


void Input()
{
	char c = 0;
	do
	{
		system("cls");
		DATA d;
		printf("\n\n\t\t\t\t������ѧ��,��������ѧ�ɼ�:");
		scanf("%d %s %f",&d.nNumb,&d.sName,&d.fMath);
		puts("\t\t\t\t1,ͷ����");
		puts("\t\t\t\t2,β����");
		int i = 0;
		printf("\t\t\t\t");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			AddHead(d);
			break;
		case 2:
			AddTail(d);
			break;
		}
		Print();
		printf("\t\t\t\t�Ƿ�������? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void Delete()
{
	char c = 0;
	do
	{
		system("cls");
		Print();
		printf("\t\t\t\t������Ҫɾ����ѧ��:");
		int nNumb;
		scanf("%d",&nNumb);
		if(Remove(nNumb))/*����1�ͳɹ�ɾ��,����0����elseʧ��*/
			puts("\t\t\t\tɾ���ɹ�");
		else
			puts("\t\t\t\tѧ�Ų�����");
		Print();
		printf("\t\t\t\t�Ƿ����ɾ��? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void ModifyData(int nNumb)
{
	struct SNode* p = g_pHead,*p1;
	while(p)
	{
		if(p ->data.nNumb == nNumb)/*�ȶ�ѧ��*/
		{
			printf("\t\t\t\t�������µ���������ѧ�ɼ�:");
			char sName[20];
			float fMath;
			scanf("%s %f",sName,&fMath);
			p ->data.fMath = fMath;
			strcpy(p ->data.sName,sName);/*ջ�ڵ����ݸ��Ƶ�����*/
			return;
		}
		p = p ->pNext;/*ѭ�����������һ��.���±���*/
	}
	puts("\t\t\t\t�������ѧ�Ų�����!");
}


void Modify()
{
	char c = 0;
	do
	{
		system("cls");
		Print();
		printf("\t\t\t\t������Ҫ�޸ĵ�ѧ��:");
		int nNumb;
		scanf("%d",&nNumb);
		ModifyData(nNumb);
		Print();
		printf("\t\t\t\t�Ƿ�����޸�? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void FindbyNumb()
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode* p = g_pHead;/*struct SNode* pΪһ��ָ��*/
		int nNumb = 0;
		printf("\n\t\t\t\t������ѧ��:");
		scanf("%d",&nNumb);
		puts("\t\t\t\tѧ��\t����\t��ѧ�ɼ�");
		while(p)
		{
			if(p ->data.nNumb == nNumb)
			{
				printf("\t\t\t\t%d\t%s\t%0.1f\n",p ->data.nNumb,p ->data.sName,p ->data.nNumb);
				break;
			}
			p = p->pNext;
		}/*��Ϊ����ѭ��62��*/
		printf("\t\t\t\t�Ƿ��������? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void FindbyName()
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode* p = g_pHead;
		char sName[20];
		printf("\t\t\t\t������Ҫ���ҵ�����:");
		scanf("%s",sName);
		while(p)
		{
			if(!strcmp(p ->data.sName , sName))
				printf("\t\t\t\tѧ��: %d\t����: %s\t��ѧ�ɼ�: %0.1f\n",p ->data.nNumb,p ->data.sName,p ->data.fMath);
			p = p ->pNext;
		}
		printf("\t\t\t\t�Ƿ��������? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void FindbyMath()
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode* p = g_pHead;
		float fMin;
		float fMax;
		printf("\t\t\t\t����������εĳ�ĩ����(ʹ�ÿո���):");
		scanf("%f %f",&fMin,&fMax);
		while(p)
		{
			if((p->data.fMath>=fMin)&&(p->data.fMath<=fMax))
				printf("\t\t\t\tѧ��: %d\t����: %s\t��ѧ�ɼ�: %0.1f\n",p ->data.nNumb,p ->data.sName,p ->data.fMath);
			p = p ->pNext;
		}
		printf("\t\t\t\t�Ƿ��������? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


int Find()/*��Ϊint��Ϊ�˷�ֹ���Ҳ鲻���ص����˵�*/
{
	system("cls");
	puts("\n\t\t\t\t1,��ѧ�Ų���: ");
	puts("\t\t\t\t2,����������: ");
	puts("\t\t\t\t3,�������β���: ");
	puts("\t\t\t\t0,�������˵�: ");
	int i = 0;
	printf("\t\t\t\t      ");
	scanf("%d",&i);
	switch(i)
	{
	case 1:
		FindbyNumb();
		break;
	case 2:
		FindbyName();
		break;
	case 3:
		FindbyMath();
		break;
	default:
		printf("�������");
		return i;
	}
	return i;
}

void SortbyNumb()
{
	char c = 0;
	do{
		system("cls");
		struct SNode * p = g_pHead,*q,*pMin;
		if(!p)
			return;
		if(!p ->pNext)
			return;
		while(p)
		{
			pMin = p;
			q = p ->pNext;
			while(q)
			{
				if(q ->data.nNumb < pMin ->data.nNumb)
					pMin = q;
				q = q->pNext;
			}
			if(p != pMin)
			{
				DATA t = p ->data;
				p ->data = pMin ->data;
				pMin ->data = t;
			}
			p = p ->pNext;
		}
		Print();
     	printf("\t\t\t\t�Ƿ����? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');

}

void SortbyName()
{
	char c = 0;
	do{
		system("cls");
		struct SNode * p = g_pHead,*q,*pMin;
		if(!p)
			return;
		if(!p ->pNext)
			return;
		while(p)
		{
			pMin = p;
			q = p ->pNext;
			while(q)
			{
				if(strcmp(q ->data.sName,pMin ->data.sName)<0)
					pMin = q;
				q = q->pNext;
			}
			if(p != pMin)
			{
				DATA t = p ->data;
				p ->data = pMin ->data;
				pMin ->data = t;
			}
			p = p ->pNext;
		}
		Print();
     	printf("\t\t\t\t�Ƿ����? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');

}

void SortbyMath()
{
	char c = 0;
	do
	{
		system("cls");
		struct SNode * p = g_pHead,*q,*pMin;
		if(!p)
			return;
		if(!p ->pNext)
			return;
		while(p)
		{
			pMin = p;
			q = p ->pNext;
			while(q)
			{
				if(q ->data.fMath < pMin ->data.fMath)
					pMin = q;
				q = q->pNext;
			}
			if(p != pMin)
			{
				DATA t = p ->data;
				p ->data = pMin ->data;
				pMin ->data = t;
			}
			p = p ->pNext;
		}
		Print();
     	printf("\t\t\t\t�Ƿ����? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');

}

int Browse()
{
	system("cls");
	puts("1,��ѧ������");
	puts("2,����������");
	puts("3,����ѧ�ɼ�����");
	puts("0,�������˵�");
	int i = 0;
	scanf("%d",&i);
	switch(i)
	{
	case 1:
		SortbyNumb();
		break;
	case 2:
		SortbyName();
		break;
	case 3:
		SortbyMath();
		break;
	default:
		return i;
	}
	return i;
}


int Menu()
{
	system("cls");
	puts("\n\n\t\t\t\t* * * * * * * * *");
	puts("\t\t\t\t*1, ���������Ϣ*");
    puts("\t\t\t\t*2, �����Ϣ    *");
	puts("\t\t\t\t*3, ɾ����Ϣ    *");
	puts("\t\t\t\t*4, �޸���Ϣ    *");
	puts("\t\t\t\t*5, ������Ϣ    *");
	puts("\t\t\t\t*0, �˳�        *");
	puts("\t\t\t\t* * * * * * * * *");
	int i = 0;
	printf("\t\t\t\t      ");
	scanf("%d",&i);
	switch(i)
	{
        case 1:
			while(Browse())
				;
			Print();
			break;
		case 2:
			Input();
			break;
		case 3:
			Delete();
			break;
		case 4:
			Modify();
			break;
		case 5:
			while(Find())
				;
			break;
	}
	return i;

}


void Save()/*��Ƶ������Ŀ����ɾ�Ĳ�34���Ӵ�*/
{
	FILE* fp = fopen("./stud.lv","wb");
	SNode* p = g_pHead;
	while(p)/*����ѭ���������β*/
	{
		fwrite(p,1,sizeof(DATA),fp);//��һ����Ա�����ĵ�ַ�ͽṹ��ĵ�ַ����ͬ��,����p��*/
		/*fwrite(&p->data,1,sizeof(p->data),fp);//p ->data ������struct sstud������*/
		p = p ->pNext;
	}
	fclose(fp);
}

void Load()
{
	FILE* fp = fopen("./stud.lv","rb");
	DATA data;
	while(fread(&data,1,sizeof(data),fp)>0)
		AddTail(data);
	fclose(fp);

}


void RemoveAll()
{
	struct SNode* p = g_pHead,*p1;
	while(p)
	{
		p1 = p;
		p = p->pNext;
		free(p1);
	}
}


int main(int argc, char* argv[])
{//0xcc
	float f = 0.0f;//float wei

	Load();
	int i = 3;
	char c = 0;
    do
	{
		system("cls");
		i = i - 1 ;
		puts("\n\n\t\t\t\t* * * * * * * * * * *");
		puts("\t\t\t\t*��������λ��¼����:*");
		puts("\t\t\t\t* * * * * * * * * * *");
		int x = 0;
		printf("\t\t\t\t");
		scanf("%d",&x);
		if(x == 1111)
		while(Menu())
			 ;
		else
			printf("\t\t\t\t(��������,����������,������%d�λ���)\n\n",i);
		printf("\t\t\t\t  �˳��밴[n]  �����밴[y]");
		c = getch();
		putch('\n');
	
	}while(i && c != 'N' && c != 'n');
	Save();
	RemoveAll();
	return 0;
}
