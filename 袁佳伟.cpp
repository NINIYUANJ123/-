// 袁佳伟.cpp : Defines the entry point for the console application.
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
	pNew ->data = d;/*pNew ->data为一个数据区*/
	pNew ->pNext = g_pHead;/*pNew ->pNext为一个地址,g_pHead为一个节点*/
	g_pHead = pNew;/*此方法为头插法*/
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


int Remove(int nNumb)/*布尔型*/
{
	struct SNode* p = g_pHead,*p1;
	if(nNumb == p->data.nNumb)/*此为删除头节点*/
	{
		g_pHead = p ->pNext;/*头节点指向第二个节点,干掉老大*/
		free(p);
		return 1;
	}
	while(p)
	{
		if(p->data.nNumb == nNumb)/*比对学号*/
		{
			p1->pNext = p->pNext;/*让p1指向的下一个变为p指向的下一个,就是跨国p*/
			free(p);/*释放掉p*/
			return 1;/*成功*/
		}
		p1 = p;/*p1为上一个节点的地址*/
		p = p ->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	return 0;/*失败*/
}


void Print()
{
    puts("\t\t\t\t学号\t姓名\t数学成绩");
	struct SNode* p = g_pHead;/*struct SNode* p为一个指针*/
	while(p)
	{
		printf("\t\t\t\t%d\t%s\t%0.1f\n",p->data.nNumb,p->data.sName,p->data.fMath);
		p = p->pNext;
	}/*此为链表循环62节*/
//prntf("%d\t%s\t%0.1f\n");
}


void Input()
{
	char c = 0;
	do
	{
		system("cls");
		DATA d;
		printf("\n\n\t\t\t\t请输入学号,姓名和数学成绩:");
		scanf("%d %s %f",&d.nNumb,&d.sName,&d.fMath);
		puts("\t\t\t\t1,头插入");
		puts("\t\t\t\t2,尾插入");
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
		printf("\t\t\t\t是否继续添加? [y/n]");
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
		printf("\t\t\t\t请输入要删除的学号:");
		int nNumb;
		scanf("%d",&nNumb);
		if(Remove(nNumb))/*返回1就成功删除,返回0就是else失败*/
			puts("\t\t\t\t删除成功");
		else
			puts("\t\t\t\t学号不存在");
		Print();
		printf("\t\t\t\t是否继续删除? [y/n]");
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
		if(p ->data.nNumb == nNumb)/*比对学号*/
		{
			printf("\t\t\t\t请输入新的姓名和数学成绩:");
			char sName[20];
			float fMath;
			scanf("%s %f",sName,&fMath);
			p ->data.fMath = fMath;
			strcpy(p ->data.sName,sName);/*栈内的数据复制到堆内*/
			return;
		}
		p = p ->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	puts("\t\t\t\t你输入的学号不存在!");
}


void Modify()
{
	char c = 0;
	do
	{
		system("cls");
		Print();
		printf("\t\t\t\t请输入要修改的学号:");
		int nNumb;
		scanf("%d",&nNumb);
		ModifyData(nNumb);
		Print();
		printf("\t\t\t\t是否继续修改? [y/n]");
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
		struct SNode* p = g_pHead;/*struct SNode* p为一个指针*/
		int nNumb = 0;
		printf("\n\t\t\t\t请输入学号:");
		scanf("%d",&nNumb);
		puts("\t\t\t\t学号\t姓名\t数学成绩");
		while(p)
		{
			if(p ->data.nNumb == nNumb)
			{
				printf("\t\t\t\t%d\t%s\t%0.1f\n",p ->data.nNumb,p ->data.sName,p ->data.nNumb);
				break;
			}
			p = p->pNext;
		}/*此为链表循环62节*/
		printf("\t\t\t\t是否继续查找? [y/n]");
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
		printf("\t\t\t\t请输入要查找的姓名:");
		scanf("%s",sName);
		while(p)
		{
			if(!strcmp(p ->data.sName , sName))
				printf("\t\t\t\t学号: %d\t姓名: %s\t数学成绩: %0.1f\n",p ->data.nNumb,p ->data.sName,p ->data.fMath);
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
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
		printf("\t\t\t\t请输入分数段的初末分数(使用空格间隔):");
		scanf("%f %f",&fMin,&fMax);
		while(p)
		{
			if((p->data.fMath>=fMin)&&(p->data.fMath<=fMax))
				printf("\t\t\t\t学号: %d\t姓名: %s\t数学成绩: %0.1f\n",p ->data.nNumb,p ->data.sName,p ->data.fMath);
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


int Find()/*改为int是为了防止查找查不到回到主菜单*/
{
	system("cls");
	puts("\n\t\t\t\t1,按学号查找: ");
	puts("\t\t\t\t2,按姓名查找: ");
	puts("\t\t\t\t3,按分数段查找: ");
	puts("\t\t\t\t0,返回主菜单: ");
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
		printf("输入错误");
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
     	printf("\t\t\t\t是否继续? [y/n]");
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
     	printf("\t\t\t\t是否继续? [y/n]");
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
     	printf("\t\t\t\t是否继续? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');

}

int Browse()
{
	system("cls");
	puts("1,按学号排序");
	puts("2,按姓名排序");
	puts("3,按数学成绩排序");
	puts("0,返回主菜单");
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
	puts("\t\t\t\t*1, 浏览所有信息*");
    puts("\t\t\t\t*2, 添加信息    *");
	puts("\t\t\t\t*3, 删除信息    *");
	puts("\t\t\t\t*4, 修改信息    *");
	puts("\t\t\t\t*5, 查找信息    *");
	puts("\t\t\t\t*0, 退出        *");
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


void Save()/*视频链表项目的增删改查34分钟处*/
{
	FILE* fp = fopen("./stud.lv","wb");
	SNode* p = g_pHead;
	while(p)/*依次循环到链表结尾*/
	{
		fwrite(p,1,sizeof(DATA),fp);//第一个成员变量的地址和结构体的地址是相同的,所以p和*/
		/*fwrite(&p->data,1,sizeof(p->data),fp);//p ->data 类型是struct sstud的类型*/
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
		puts("\t\t\t\t*请输入四位登录密码:*");
		puts("\t\t\t\t* * * * * * * * * * *");
		int x = 0;
		printf("\t\t\t\t");
		scanf("%d",&x);
		if(x == 1111)
		while(Menu())
			 ;
		else
			printf("\t\t\t\t(输入有误,请重新输入,您还有%d次机会)\n\n",i);
		printf("\t\t\t\t  退出请按[n]  继续请按[y]");
		c = getch();
		putch('\n');
	
	}while(i && c != 'N' && c != 'n');
	Save();
	RemoveAll();
	return 0;
}
