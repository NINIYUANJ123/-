// 汽车.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"
#include "process.h"
#include "malloc.h"
#include "conio.h"
#include "string.h"
#include "windows.h"
int Menu(char name[10]);
int Menu1();

struct Person  //用于存储注册登录的用户名与密码
{
	char name[10];
	char password[7];
	char brand[40];
	struct Person* Next;
};
struct Person *Head;

struct SStud
{
	int nPrice;/*汽车的价格*/
	char sBrand[40];/*汽车品牌*/
	char sModel[40];//汽车型号
	float fSpeed;/*汽车零百加速时间*/
	float fOutput;//汽车排量
	char sEngine[40];//发动机类型
	int fPower;//汽车马力
	int fTorque;//汽车扭矩
	char fType[40];//汽车类型
	int fWeight;//汽车质量
	//汽车品牌 汽车型号 汽车类型 汽车的价格 汽车零百加速时间 汽车排量 发动机类型 汽车马力 汽车扭矩 汽车质量

};
typedef struct SStud DATA;
struct SNode
{
	DATA data;/*数据区*/
	struct SNode* pNext;/*地址区*/
}*g_pHead = NULL;


int Entry()
{
	system("cls");
	puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃           汽      车      选      购      系      统             ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	int flag = 0,flag1,count = 3;
	puts("\n\n\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃                           ①.客户登录                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ②.后台登录                            ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	printf("\n\t\t请选择：\t");
	scanf("    %d",&flag1);
	system("cls");
	puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	puts("\n\n\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃                              登    录                            ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	char name[10],password[10];
	char c= 0;
	int j=0;
	printf("\n\n\t\t请输入您的用户名：");
	scanf("%s",name);
	FILE* fp = fopen(name,"r");
	if (fp == NULL)
	{
		printf("哈哈哈哈哈哈");
	}
	Head = (struct Person*)malloc(sizeof(struct Person));
	Head->Next = NULL;
	struct Person *New = (struct Person*)malloc(sizeof(struct Person));
	struct Person *P = Head;
	while((fscanf(fp,"%s\t%s\n",New->name,New->password)) == 2)
	{
		P->Next = New;
		P = P->Next;
		New = (struct Person*)malloc(sizeof(struct Person));
	}
	/*New = (struct Person*)malloc(sizeof(struct Person));
	while((fscanf(fp,"%s\n",New->brand)) == 1)
	{
		P->Next = New;
		P = P->Next;
		New = (struct Person*)malloc(sizeof(struct Person));
	}*/
	P->Next = NULL;
	fclose(fp);
	do
	{
		printf("\n\t\t请输入您的密码：");
		while ((c = getch()) != 13 && j < 20)
		{
			if (c == '\b' && j >0)
			{

				putchar('\b');
				putchar(' ');
				putchar('\b');
				j--;
			}
			else
			{
				if (isprint(c))//isprint为检测C是否为可打印的函数 
				{
					putchar('*');
					password[j] = c;
					j++;
				}
			}
		}
		password[j] = '\0';
			if(strcmp(Head->Next->name,name)==0 && strcmp(Head->Next->password,password)==0 )
			{
				if(flag1 == 1)
				{
					while(Menu(name));
				}else if(flag1 == 2)
				{
					while(Menu1());
				}
				return 0;
			}else
			{
				flag = 1;
			}
		if(count == 0)
		{
			printf("本日机会已用完!!");
			Sleep(1500);
			return 0;
		}
		printf("密码错误,请重新输入!   您还有%d次机会",count--);
		Sleep(2000);
	}while(flag == 1);
}


int User()
{
	struct Person *New = (struct Person*)malloc(sizeof(struct Person));
	struct Person *P = Head;
	int flag = 0;
	do
	{
		char password1[7],password2[7],name[10];
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		puts("\n\n\t\t ---------------------------------------");
		printf("\n\n\t\t请输入您的用户名：");
		scanf("%s",&name);
		printf("\n\t\t请输入您的密码：");
		scanf("%s",&password1);
		printf("\n\t\t请再次输入您的密码：");
		scanf("%s",&password2);
		if(strcmp(password1,password2) == 0)
		{
			printf("\n\t\t注册成功，即将返回登陆界面");
			Sleep(3000);
			strcpy(New->name,name);
			strcpy(New->password,password1);
			FILE* fp = fopen(name,"a");
			fprintf(fp,"%s\t%s\n",New->name,New->password);
			fclose(fp);
			return 0;
		}else
		{
			printf("\n\t\t两次密码不一致，即将重新输入");
			Sleep(2000);
			flag=1;
		}
	}while(flag);
}


int Login()//登陆注册界面
{
	system("cls");
	//MessageBox(NULL, TEXT("您好,欢迎光临汽车选购系统"), TEXT("汽车选购系统"),MB_OK);
	puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃           汽      车      选      购      系      统             ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	puts("\n\n\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃                           ①.登陆                                ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ②.注册(新用户)                        ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           0 .退出                                ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	printf("\n\t\t请选择:      ");
	int n;
	scanf("%d",&n);
	switch(n)
	{
	case 1:
		while(Entry());
		return 0;
		break;
	case 2:
		while(User());
		break;

	}
	return n;
}


void AddHead(DATA d)/*开头插入函数,添加函数的二级函数*/
{
	struct SNode* pNew = (struct SNode*)malloc(sizeof(struct SNode));
	pNew ->data = d;/*pNew ->data为一个数据区*/
	pNew ->pNext = g_pHead;/*pNew ->pNext为一个地址,g_pHead为一个节点*/
	g_pHead = pNew;/*此方法为头插法*/
}


void AddTail(DATA d)/*尾部插入函数,添加函数的二级函数*/
{
	struct SNode* p=g_pHead;
	struct SNode *pNew = (struct SNode*)malloc(sizeof(struct SNode));
	pNew ->data = d;
	pNew ->pNext = NULL;
	if(!p)
	{
		g_pHead = pNew;
		return;
	}
	while(p)
	{
		if (p->pNext == 0)
			break;
		p = p->pNext;
	}
	p->pNext = pNew;

}


void Print()/*就是个打印函数,几乎每个函数都要用到此函数,也可以说此函数是浏览排序函数的二级函数*/
{
	puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃           汽      车      选      购      系      统             ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	printf("\n\t\t-------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t|                                                   ****            汽车管理系统      ****                                                |\n");
	printf("\t\t-------------------------------------------------------------------------------------------------------------------------------------------\n"); 
	printf("\n\n\t\t|  汽车品牌  |         型号        |   类型   | 价格(万) | 零百加速时间(秒) | 排量(L) |   发动机类型   | 马力(匹) | 扭矩(N·m) | 质量(Kg) |\n\n");
	struct SNode* p = g_pHead;/*struct SNode* p指针,先定义指针*/ 
	while(p)/*循环链表*/
	{
		printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
		p = p->pNext;
	}

}


void Input()/*case2的添加函数,添加函数的一级函数*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		DATA d;
	    printf("\n\n\t\t|                                                   ****          输入信息界面        ****                                                |\n");
	    printf("\t\t-------------------------------------------------------------------------------------------------------------------------------------------\n"); 
	    printf("\t\t|  汽车品牌  |         型号        |   类型   | 价格(万) | 零百加速时间(秒) | 排量(L) |   发动机类型   | 马力(匹) | 扭矩(N·m) | 质量(Kg) |\n\n");
		printf("\t请输入信息:");
		scanf("%s %s %s %d %f %f %s %d %d %d",&d.sBrand,&d.sModel,&d.fType,&d.nPrice,&d.fSpeed,&d.fOutput,&d.sEngine,&d.fPower,&d.fTorque,&d.fWeight);
		puts("\n\t\t\t\t1,开头插入");/*两种数据插入方式供选择*/
		puts("\t\t\t\t2,结尾插入");
		int i = 0;
	    printf("\t\t\t\t请选择插入方式:");	
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			AddHead(d);/*开头插入法*/
			break;
		case 2:
			AddTail(d);/*尾部插入法*/
			break;
		}
		Print();
		printf("\t\t\t\t是否继续添加? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


int Remove(char sBrand[20])/*布尔型的删除函数的二级函数,形参为下面一级函数的品牌名称*/
{
	struct SNode* p = g_pHead,*p1;
	if(!strcmp(sBrand,p->data.sBrand))/*先进行品牌名称的比对,下面为删除头节点*/
	{
		p = p ->pNext;/*头节点指向第二个节点,干掉老大*/
		free(p);
		return 1;
	}
	while(p)
	{
		if(!strcmp(p->data.sBrand,sBrand))/*比对品牌*/
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


void Delete()/*case3的删除函数的一级函数*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
     	puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	    printf("\n\n\t\t|                                                   ****          删除信息界面        ****                                                |\n");
	    printf("\t\t-------------------------------------------------------------------------------------------------------------------------------------------\n"); 
		Print();
		printf("\t\t\t\t请输入要删除的汽车品牌(型号):");
		char sBrand[20];
		scanf("%s",&sBrand);
		if(Remove(sBrand))/*删除函数的二级函数返回1就成功删除,返回0就是else失败*/
			puts("\n\t\t\t\t删除成功");
		else
			puts("\n\t\t\t\t该型号不存在");
		Print();
		printf("\t\t\t\t是否继续删除? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void ModifyData(char sBrand[20])/*修改函数的二级函数,此形参为下面一级函数中输入的品牌名称*/
{
	struct SNode* p = g_pHead;
	while(p)/*循环链表*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
		{
			printf("\n\t\t请重新输入新的价格:");
			int nPrice;
			scanf("%d",&nPrice);
			p ->data.nPrice = nPrice;
			Print();
			return;
		}     
		p = p ->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	system("cls");
	puts("\n\t\t\t\t你输入的型号不存在!");
}


void ModifyData1(char sBrand[20])//修改零百
{
	struct SNode* p = g_pHead;
	while(p)/*循环链表*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
		{
			printf("\n\t\t请重新输入新的零百加速时间(秒):");
			float fSpeed;
			scanf("%f",&fSpeed);
			p ->data.fSpeed = fSpeed;/*将新的数据对要修改的数据进行覆盖*/
			Print();
			return;
		}     
		p = p ->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	system("cls");
	puts("\n\t\t\t\t你输入的型号不存在!");
}


void ModifyData2(char sBrand[20])//修改排量
{
	struct SNode* p = g_pHead;
	while(p)/*循环链表*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
		{
			printf("\n\t\t请重新输入新的排量(L):");
			float fOutput;
			scanf("%f",&fOutput);
			p ->data.fOutput = fOutput;/*将新的数据对要修改的数据进行覆盖*/
			Print();
			return;
		}     
		p = p ->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	system("cls");
	puts("\n\t\t\t\t你输入的型号不存在!");
}


void ModifyData3(char sBrand[20])//修改发动机类型
{
	struct SNode* p = g_pHead;
	while(p)/*循环链表*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
		{
			printf("\n\t\t请重新输入新的发动机类型:");
			char sEngine[40];
			scanf("%s",sEngine);
			strcpy(p->data.sEngine,sEngine);/*将新的数据对要修改的数据进行覆盖*/
			Print();
			return;
		}     
		p = p ->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	system("cls");
	puts("\n\t\t\t\t你输入的型号不存在!");
}


void ModifyData4(char sBrand[20])//修改马力
{
	struct SNode* p = g_pHead;
	while(p)/*循环链表*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
		{
			printf("\n\t\t请重新输入新的马力(匹):");
			int fPower;
			scanf("%d",&fPower);
			p ->data.fPower = fPower;/*将新的数据对要修改的数据进行覆盖*/
			Print();
			return;
		}     
		p = p ->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	system("cls");
	puts("\n\t\t\t\t你输入的型号不存在!");
}


void ModifyData5(char sBrand[20])//修改扭矩
{
	struct SNode* p = g_pHead;
	while(p)/*循环链表*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
		{
			printf("\n\t\t请重新输入新的扭矩(N·m):");
			int fTorque;
			scanf("%d",&fTorque);
			p ->data.fTorque = fTorque;/*将新的数据对要修改的数据进行覆盖*/
			Print();
			return;
		}     
		p = p ->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	system("cls");
	puts("\n\t\t\t\t你输入的型号不存在!");
}


void ModifyData6(char sBrand[20])//修改质量
{
	struct SNode* p = g_pHead;
	while(p)/*循环链表*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
		{
			printf("\n\t\t请重新输入新的质量(Kg):");
			int fWeight;
			scanf("%d",&fWeight);
			p ->data.fWeight = fWeight;/*将新的数据对要修改的数据进行覆盖*/
			Print();
			return;
		}     
		p = p ->pNext;/*循环三部曲最后一步.向下遍历*/
	}
	system("cls");
	puts("\n\t\t\t\t你输入的型号不存在!");
}


void Modify()/*case4的修改函数的一级函数*/
{
	int d;
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		Print();
		printf("\n\t\t请输入要修改的汽车型号:");
		char sBrand[20];
		scanf("%s",&sBrand);
		puts("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
		puts("\t\t\t\t*           1,修改价格                       3,修改排量                      5,修改马力                  7,修改质量   *");
		puts("\t\t\t\t*           2,修改零百加速时间               4,修改发动机类型                6,修改扭矩                               *");
		puts("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
		printf("\n\t\t请选择您所需修改的选项:");
		scanf("%d",&d);
		switch(d)
		{
			case 1:
				ModifyData(sBrand);
				break;
			case 2:
				ModifyData1(sBrand);
				break;
			case 3:
				ModifyData2(sBrand);
				break;
			case 4:
				ModifyData3(sBrand);
				break;
			case 5:
				ModifyData4(sBrand);
				break;
			case 6:
				ModifyData5(sBrand);
				break;
			case 7:
				ModifyData6(sBrand);
				break;
		}
		//ModifyData(sBrand);将输入的品牌通过修改函数的二级函数处理
		printf("\t\t是否继续修改? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void FindbyPrice()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;/*struct SNode* p为一个指针,先定义指针*/
		int nPrice = 0;
		printf("\n\t\t\t\t请输入价格:");
		scanf("%d",&nPrice);
		puts("\t\t\t\t品牌(型号)\t价格(万)\t零百加速(秒)");
		while(p)
		{
			if(p ->data.nPrice == nPrice)/*比对相同的价格*/
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				break;
			}
			p = p->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void FindbyBrand()/*通过品牌查找*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t请输入要的品牌:");
		scanf("%s",sBrand);
		while(p) //循环链表
		{
			if(strcmp(p ->data.sBrand , sBrand) == 0)//字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp
				printf("\t\t|  %-10s|  %-19s|\n",p->data.sBrand,p->data.sModel);
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void FindbySpeed()/*通过加速时间段查找*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		puts("\t\t┃           汽      车      选      购      系      统             ┃");
		puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		float fMin;/*设定两个参数用来定义两个时间段*/
		float fMax;
		printf("\t\t\t\t请输入零百加速时间段的初末时间(使用空格间隔):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*循环链表*/
		{
			if((p->data.fSpeed>=fMin)&&(p->data.fSpeed<=fMax))/*比对加速时间是否在此时间段内*/
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				struct Person *New = (struct Person *)malloc(sizeof(struct Person));
				struct Person *p1= Head;
				strcpy(New->brand,p->data.sModel);
				New->Next = NULL;
				while(p1)
				{
					if (p1->Next == 0)
						break;
					p1 = p1->Next;
				}
			}
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void FindbyType()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t请输入汽车类型:");
		scanf("%s",sBrand);
		while(p)/*循环链表*/
		{
			if(strcmp(p ->data.fType , sBrand) == 0)/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				struct Person *New = (struct Person *)malloc(sizeof(struct Person));
				struct Person *p1= Head;
				strcpy(New->brand,p->data.sModel);
				New->Next = NULL;
				while(p1)
				{
					if (p1->Next == 0)
						break;
					p1 = p1->Next;
				}
			}
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void FindbyOutput()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		puts("\t\t┃           汽      车      选      购      系      统             ┃");
		puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		float fMin;/*设定两个参数用来定义两个时间段*/
		float fMax;
		printf("\t\t\t\t请输入两个整数排量(使用空格间隔):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*循环链表*/
		{
			if((p->data.fOutput>=fMin)&&(p->data.fOutput<=fMax))/*比对加速时间是否在此时间段内*/		
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				struct Person *New = (struct Person *)malloc(sizeof(struct Person));
				struct Person *p1= Head;
				strcpy(New->brand,p->data.sModel);
				New->Next = NULL;
				while(p1)
				{
					if (p1->Next == 0)
						break;
					p1 = p1->Next;
				}
			}
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void FindbyEngine()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
        puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t请输入发动机类型:");
		scanf("%s",sBrand);
		while(p)/*循环链表*/
		{
			if(strcmp(p ->data.sEngine , sBrand) == 0)/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				struct Person *New = (struct Person *)malloc(sizeof(struct Person));
				struct Person *p1= Head;
				strcpy(New->brand,p->data.sModel);
				New->Next = NULL;
				while(p1)
				{
					if (p1->Next == 0)
						break;
					p1 = p1->Next;
				}
				p1->Next = New;
			}
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void FindbyPower()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		float fMin;/*设定两个参数用来定义两个时间段*/
		float fMax;
		printf("\t\t\t\t请输入两个整百数马力值(使用空格间隔):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*循环链表*/
		{
			if((p->data.fPower>=fMin)&&(p->data.fPower<=fMax))/*比对加速时间是否在此时间段内*/
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				struct Person *New = (struct Person *)malloc(sizeof(struct Person));
				struct Person *p1= Head;
				strcpy(New->brand,p->data.sModel);
				New->Next = NULL;
				while(p1)
				{
					if (p1->Next == 0)
						break;
					p1 = p1->Next;
				}
			}
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void FindbyTorque()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		float fMin;/*设定两个参数用来定义两个时间段*/
		float fMax;
		printf("\t\t\t\t请输入两个百位数扭矩(使用空格间隔):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*循环链表*/
		{
			if((p->data.fTorque>=fMin)&&(p->data.fTorque<=fMax))/*比对加速时间是否在此时间段内*/
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				struct Person *New = (struct Person *)malloc(sizeof(struct Person));
				struct Person *p1= Head;
				strcpy(New->brand,p->data.sModel);
				New->Next = NULL;
				while(p1)
				{
					if (p1->Next == 0)
						break;
					p1 = p1->Next;
				}
			}
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void FindbyWeight()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		float fMin;/*设定两个参数用来定义两个时间段*/
		float fMax;
		printf("\t\t\t\t请输入两个整数重量(使用空格间隔):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*循环链表*/
		{
			if((p->data.fWeight>=fMin)&&(p->data.fWeight<=fMax))/*比对加速时间是否在此时间段内*/
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				struct Person *New = (struct Person *)malloc(sizeof(struct Person));
				struct Person *p1= Head;
				strcpy(New->brand,p->data.sModel);
				New->Next = NULL;
				while(p1)
				{
					if (p1->Next == 0)
						break;
					p1 = p1->Next;
				}
			}
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void FindbyModel()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		puts("\t\t┃           汽      车      选      购      系      统             ┃");
		puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t请输入型号:");
		scanf("%s",sBrand);
		while(p)/*循环链表*/
		{
			if(strcmp(p ->data.sModel , sBrand) == 0)/*字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp*/
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				struct Person *New = (struct Person *)malloc(sizeof(struct Person));
				struct Person *p1= Head;
				strcpy(New->brand,p->data.sModel);
				New->Next = NULL;
				while(p1)
				{
					if (p1->Next == 0)
						break;
					p1 = p1->Next;
				}
				p1->Next = New;
			}
			p = p ->pNext;
		}
		printf("\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


int Find()/*case5的查找函数,用int是为了查找查不到的时候可以回到主菜单*/
{
	system("cls");
	puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃           汽      车      选      购      系      统             ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	puts("\n\n\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t\t\t┃         查          找         ┃");
	puts("\t\t┏━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃                           ①.按照汽车型号查找                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ②.按照汽车类型查找                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ③.按照汽车价格查找                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ④.按照汽车加速时间查找                ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑤.按照汽车排量查找                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑥.按照发动机类查找                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑦.按照汽车马力查找                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑧.按照汽车扭矩查找                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑨.按照汽车重量查找                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           0. 退出                                ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	int i;
	printf("\\n\t\t请选择您所需的查找方式:");
	scanf("%d",&i);
	switch(i)
	{
	case 1:
		FindbyModel();
		break;
	case 3:
		FindbyPrice();
		break;
	case 2:
		FindbyType();
		break;
	case 4:
		FindbySpeed();
		break;
	case 5:
		FindbyOutput();
		break;
	case 6:
		FindbyEngine();
		break;
    case 7:
		FindbyPower();
		break;
	case 8:
		FindbyTorque();
		break;
	case 9:
		FindbyWeight();
		break;
	default:
		return i;
	}
	return i;
}


void SortbyPrice()/*按照价格高低排序*/
{
	char c = 0;
	do{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode * p = g_pHead,*q,*pMin;
		while(p)
		{
			pMin = p;
			q = p ->pNext;
			while(q)
			{
				if(q ->data.nPrice < pMin ->data.nPrice)
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
     	printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');

}


void SortbySpeed()/*按照零百加速速度时间长短排序*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode * p = g_pHead,*q,*pMin;
		while(p)
		{
			pMin = p;
			q = p ->pNext;
			while(q)
			{
				if(q ->data.fSpeed < pMin ->data.fSpeed)
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
     	printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');

}


void sortbyInput()/*按照原始输入数据时的顺序直接输出,其实就是前面的Print函数*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		Print();
		printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');

}


void SortbyTorque()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode * p = g_pHead,*q,*pMin;
		while(p)
		{
			pMin = p;
			q = p ->pNext;
			while(q)
			{
				if(q ->data.fTorque < pMin ->data.fTorque)
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
     	printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');
}


void SortbyOutput()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode * p = g_pHead,*q,*pMin;
		while(p)
		{
			pMin = p;
			q = p ->pNext;
			while(q)
			{
				if(q ->data.fOutput < pMin ->data.fOutput)
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
     	printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');
}


void SortbyPower()
{	
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode * p = g_pHead,*q,*pMin;
		while(p)
		{
			pMin = p;
			q = p ->pNext;
			while(q)
			{
				if(q ->data.fPower < pMin ->data.fPower)
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
     	printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');
}


void SortbyWeight()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode * p = g_pHead,*q,*pMin;
		while(p)
		{
			pMin = p;
			q = p ->pNext;
			while(q)
			{
				if(q ->data.fWeight < pMin ->data.fWeight)
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
     	printf("\n\n\n\t\t\t\t是否继续? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');
}


int Browse()/*case1的浏览函数,共三种浏览排序模式*/
{
	system("cls");
	puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃           汽      车      选      购      系      统             ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	puts("\n\n\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t\t\t┃         浏          览         ┃");
	puts("\t\t┏━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃                           ①.按照原始数据排序                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ②.按照汽车加速时间排序                ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ③.按照汽车价格排序                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ④.按照汽车扭矩排序                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑤.按照汽车排量排序                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑥.按照汽车马力排序                    ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑦.按照汽车重量排序                    ┃");
	puts("\t\t╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           0. 退出                                ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	int i = 0;
	printf("\n\t\t\t\t请选择您所需的排序方式:");
	scanf("%d",&i);
	switch(i)
	{
	case 1:
		sortbyInput();
		break;
	case 3:
		SortbyPrice();
		break;
	case 2:
		SortbySpeed();
		break;
	case 4:
		SortbyTorque();
		break;
	case 5:
		SortbyOutput();
		break;
	case 6:
		SortbyPower();
		break;
	case 7:
		SortbyWeight();
		break;

	default:
		return i;
	}
	return i;
}


void Save()/*保存函数*/
{
	FILE* fp;
	fp = fopen("./stud.","wb");/*stud为数据的文件名*/
	SNode* p = g_pHead ;
	while(p)/*依次循环到链表结尾*/
	{
		fwrite(&p->data,1,sizeof(p->data),fp);//第一个成员变量的地址和结构体的地址是相同的,所以p和*/
		p = p ->pNext;
	}
	fclose(fp);
	FILE* fp1;
	char name[20];
	printf("请再次输入用户名:");
	scanf("%s",name);
	fp1 = fopen(name,"a");/*stud为数据的文件名*/
	struct Person *New = Head->Next->Next ;
	while(New
		)/*依次循环到链表结尾*/
	{
		fprintf(fp,"%s\n",New->brand);//第一个成员变量的地址和结构体的地址是相同的,所以p和*/
		New = New ->Next;
	}
	fclose(fp1);
}


void Load()/*加载数据函数*/
{
	FILE* fp;
    DATA data;
	fp = fopen("./stud.","rb");
	while(fread(&data,1,sizeof(data),fp))
		AddTail(data);
	fclose(fp);

}


int Menu1()/*店主主菜单函数,2级函数*/
{
	system("cls");
	puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃           汽      车      选      购      系      统             ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	puts("\n\n\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t\t\t┃         后          台         ┃");
	puts("\t\t┏━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃                           ①.浏览信息                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ②.添加信息                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ①.删除信息                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ②.修改信息                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                            0. 退出                               ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	int i = 0;
	printf("\t\t\t\t请选择:    ");
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
	}
	return i;

}


void Contrast()
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	    puts("\t\t┃           汽      车      选      购      系      统             ┃");
	    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		struct SNode* p = g_pHead;
		char sBrand[10][20];
		int d = 0,i;
		printf("\t\t\t\t请输入需要对比几辆车的数量:");
		scanf("%d",&d);
		for(i=0;i<d;i++)
		{
			printf("\n\t\t\t\t请输入第%d辆的型号:",i+1);
			scanf("%s",sBrand[i]);
		}
		for(i=0;i<d;i++)
		{   
			 p = g_pHead;
			while(p)//循环链表
			{
				if(strcmp(p ->data.sModel , sBrand[i]) == 0)
				{//字符比较必须用strcmp,不能用等号直接比较,也可写为!strcmp
					printf("\n\n\t\t|  汽车品牌  |         型号        |   类型   | 价格(万) | 零百加速时间(秒) | 排量(L) |   发动机类型   | 马力(匹) | 扭矩(N·m) | 质量(Kg) |\n\n");
					printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				}
				p = p ->pNext;
			}
		}
		printf("\n\t\t\t\t是否继续查找? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void Record()
{}


void Suggest()
{}


void Statistics()
{
	struct Person *p = Head->Next->Next->Next->Next;
	while(p)
	{
		printf("%s ",p->brand);
		p = p->Next;
	}
	system("pause");
}



int Menu(char name[10])/*主菜单函数,2级函数*/
{
	FILE* fp = fopen(name,"r");
	struct Person *P = Head->Next;
		struct Person *p1 = (struct Person*)malloc(sizeof(struct Person));
	while((fscanf(fp,"%s\n",p1->brand)) == 1)
	{
		P->Next = p1;
		P = P->Next;
		p1 = (struct Person*)malloc(sizeof(struct Person));
	}
	P->Next = NULL;
	fclose(fp);
	system("cls");
	puts("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
    puts("\t\t┃           汽      车      选      购      系      统             ┃");
    puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	puts("\n\n\t\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("\t\t\t\t┃         客          户         ┃");
	puts("\t\t┏━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┓");
	puts("\t\t┃                           ①.浏览所有                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ②.查找品牌                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ③.查找车型                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ④.对比车型                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑤.浏览记录                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑥.猜你喜欢                            ┃");
	puts("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           ⑦.介绍                                ┃");
	puts("\t\t╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
	puts("\t\t┃                           0. 退出                                ┃");
	puts("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	int i = 0;
	printf("\t\t\t\t请选择:");
	scanf("%d",&i);
	switch(i)
	{
        case 1:
			while(Browse());  //ok
			Print();
			break;
		case 2:
			FindbyBrand();    //ok
			break;
		case 3:
			while(Find());   //ok
			break;
		case 4:
			Contrast();     //ok
			break;
		case 5:
			Record();       
			break;
		case 6:
			Suggest();
			break;
		case 7:
			Statistics();
		break;
	}
	return i;

}


int main(int argc, char* argv[])/*主函数,1级函数*/
{
	Load();
	system("color F2");
	while(Login());
	Save();
}
