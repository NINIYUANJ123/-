// ����.cpp : Defines the entry point for the console application.
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

struct Person  //���ڴ洢ע���¼���û���������
{
	char name[10];
	char password[7];
	char brand[40];
	struct Person* Next;
};
struct Person *Head;

struct SStud
{
	int nPrice;/*�����ļ۸�*/
	char sBrand[40];/*����Ʒ��*/
	char sModel[40];//�����ͺ�
	float fSpeed;/*������ټ���ʱ��*/
	float fOutput;//��������
	char sEngine[40];//����������
	int fPower;//��������
	int fTorque;//����Ť��
	char fType[40];//��������
	int fWeight;//��������
	//����Ʒ�� �����ͺ� �������� �����ļ۸� ������ټ���ʱ�� �������� ���������� �������� ����Ť�� ��������

};
typedef struct SStud DATA;
struct SNode
{
	DATA data;/*������*/
	struct SNode* pNext;/*��ַ��*/
}*g_pHead = NULL;


int Entry()
{
	system("cls");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	int flag = 0,flag1,count = 3;
	puts("\n\n\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.�ͻ���¼                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.��̨��¼                            ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	printf("\n\t\t��ѡ��\t");
	scanf("    %d",&flag1);
	system("cls");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\n\n\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                              ��    ¼                            ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	char name[10],password[10];
	char c= 0;
	int j=0;
	printf("\n\n\t\t�����������û�����");
	scanf("%s",name);
	FILE* fp = fopen(name,"r");
	if (fp == NULL)
	{
		printf("������������");
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
		printf("\n\t\t�������������룺");
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
				if (isprint(c))//isprintΪ���C�Ƿ�Ϊ�ɴ�ӡ�ĺ��� 
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
			printf("���ջ���������!!");
			Sleep(1500);
			return 0;
		}
		printf("�������,����������!   ������%d�λ���",count--);
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		puts("\n\n\t\t ---------------------------------------");
		printf("\n\n\t\t�����������û�����");
		scanf("%s",&name);
		printf("\n\t\t�������������룺");
		scanf("%s",&password1);
		printf("\n\t\t���ٴ������������룺");
		scanf("%s",&password2);
		if(strcmp(password1,password2) == 0)
		{
			printf("\n\t\tע��ɹ����������ص�½����");
			Sleep(3000);
			strcpy(New->name,name);
			strcpy(New->password,password1);
			FILE* fp = fopen(name,"a");
			fprintf(fp,"%s\t%s\n",New->name,New->password);
			fclose(fp);
			return 0;
		}else
		{
			printf("\n\t\t�������벻һ�£�������������");
			Sleep(2000);
			flag=1;
		}
	}while(flag);
}


int Login()//��½ע�����
{
	system("cls");
	//MessageBox(NULL, TEXT("����,��ӭ��������ѡ��ϵͳ"), TEXT("����ѡ��ϵͳ"),MB_OK);
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\n\n\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.��½                                ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.ע��(���û�)                        ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           0 .�˳�                                ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	printf("\n\t\t��ѡ��:      ");
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


void AddHead(DATA d)/*��ͷ���뺯��,��Ӻ����Ķ�������*/
{
	struct SNode* pNew = (struct SNode*)malloc(sizeof(struct SNode));
	pNew ->data = d;/*pNew ->dataΪһ��������*/
	pNew ->pNext = g_pHead;/*pNew ->pNextΪһ����ַ,g_pHeadΪһ���ڵ�*/
	g_pHead = pNew;/*�˷���Ϊͷ�巨*/
}


void AddTail(DATA d)/*β�����뺯��,��Ӻ����Ķ�������*/
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


void Print()/*���Ǹ���ӡ����,����ÿ��������Ҫ�õ��˺���,Ҳ����˵�˺���������������Ķ�������*/
{
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	printf("\n\t\t-------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t|                                                   ****            ��������ϵͳ      ****                                                |\n");
	printf("\t\t-------------------------------------------------------------------------------------------------------------------------------------------\n"); 
	printf("\n\n\t\t|  ����Ʒ��  |         �ͺ�        |   ����   | �۸�(��) | ��ټ���ʱ��(��) | ����(L) |   ����������   | ����(ƥ) | Ť��(N��m) | ����(Kg) |\n\n");
	struct SNode* p = g_pHead;/*struct SNode* pָ��,�ȶ���ָ��*/ 
	while(p)/*ѭ������*/
	{
		printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
		p = p->pNext;
	}

}


void Input()/*case2����Ӻ���,��Ӻ�����һ������*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		DATA d;
	    printf("\n\n\t\t|                                                   ****          ������Ϣ����        ****                                                |\n");
	    printf("\t\t-------------------------------------------------------------------------------------------------------------------------------------------\n"); 
	    printf("\t\t|  ����Ʒ��  |         �ͺ�        |   ����   | �۸�(��) | ��ټ���ʱ��(��) | ����(L) |   ����������   | ����(ƥ) | Ť��(N��m) | ����(Kg) |\n\n");
		printf("\t��������Ϣ:");
		scanf("%s %s %s %d %f %f %s %d %d %d",&d.sBrand,&d.sModel,&d.fType,&d.nPrice,&d.fSpeed,&d.fOutput,&d.sEngine,&d.fPower,&d.fTorque,&d.fWeight);
		puts("\n\t\t\t\t1,��ͷ����");/*�������ݲ��뷽ʽ��ѡ��*/
		puts("\t\t\t\t2,��β����");
		int i = 0;
	    printf("\t\t\t\t��ѡ����뷽ʽ:");	
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			AddHead(d);/*��ͷ���뷨*/
			break;
		case 2:
			AddTail(d);/*β�����뷨*/
			break;
		}
		Print();
		printf("\t\t\t\t�Ƿ�������? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


int Remove(char sBrand[20])/*�����͵�ɾ�������Ķ�������,�β�Ϊ����һ��������Ʒ������*/
{
	struct SNode* p = g_pHead,*p1;
	if(!strcmp(sBrand,p->data.sBrand))/*�Ƚ���Ʒ�����Ƶıȶ�,����Ϊɾ��ͷ�ڵ�*/
	{
		p = p ->pNext;/*ͷ�ڵ�ָ��ڶ����ڵ�,�ɵ��ϴ�*/
		free(p);
		return 1;
	}
	while(p)
	{
		if(!strcmp(p->data.sBrand,sBrand))/*�ȶ�Ʒ��*/
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


void Delete()/*case3��ɾ��������һ������*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
     	puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    printf("\n\n\t\t|                                                   ****          ɾ����Ϣ����        ****                                                |\n");
	    printf("\t\t-------------------------------------------------------------------------------------------------------------------------------------------\n"); 
		Print();
		printf("\t\t\t\t������Ҫɾ��������Ʒ��(�ͺ�):");
		char sBrand[20];
		scanf("%s",&sBrand);
		if(Remove(sBrand))/*ɾ�������Ķ�����������1�ͳɹ�ɾ��,����0����elseʧ��*/
			puts("\n\t\t\t\tɾ���ɹ�");
		else
			puts("\n\t\t\t\t���ͺŲ�����");
		Print();
		printf("\t\t\t\t�Ƿ����ɾ��? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void ModifyData(char sBrand[20])/*�޸ĺ����Ķ�������,���β�Ϊ����һ�������������Ʒ������*/
{
	struct SNode* p = g_pHead;
	while(p)/*ѭ������*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
		{
			printf("\n\t\t�����������µļ۸�:");
			int nPrice;
			scanf("%d",&nPrice);
			p ->data.nPrice = nPrice;
			Print();
			return;
		}     
		p = p ->pNext;/*ѭ�����������һ��.���±���*/
	}
	system("cls");
	puts("\n\t\t\t\t��������ͺŲ�����!");
}


void ModifyData1(char sBrand[20])//�޸����
{
	struct SNode* p = g_pHead;
	while(p)/*ѭ������*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
		{
			printf("\n\t\t�����������µ���ټ���ʱ��(��):");
			float fSpeed;
			scanf("%f",&fSpeed);
			p ->data.fSpeed = fSpeed;/*���µ����ݶ�Ҫ�޸ĵ����ݽ��и���*/
			Print();
			return;
		}     
		p = p ->pNext;/*ѭ�����������һ��.���±���*/
	}
	system("cls");
	puts("\n\t\t\t\t��������ͺŲ�����!");
}


void ModifyData2(char sBrand[20])//�޸�����
{
	struct SNode* p = g_pHead;
	while(p)/*ѭ������*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
		{
			printf("\n\t\t�����������µ�����(L):");
			float fOutput;
			scanf("%f",&fOutput);
			p ->data.fOutput = fOutput;/*���µ����ݶ�Ҫ�޸ĵ����ݽ��и���*/
			Print();
			return;
		}     
		p = p ->pNext;/*ѭ�����������һ��.���±���*/
	}
	system("cls");
	puts("\n\t\t\t\t��������ͺŲ�����!");
}


void ModifyData3(char sBrand[20])//�޸ķ���������
{
	struct SNode* p = g_pHead;
	while(p)/*ѭ������*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
		{
			printf("\n\t\t�����������µķ���������:");
			char sEngine[40];
			scanf("%s",sEngine);
			strcpy(p->data.sEngine,sEngine);/*���µ����ݶ�Ҫ�޸ĵ����ݽ��и���*/
			Print();
			return;
		}     
		p = p ->pNext;/*ѭ�����������һ��.���±���*/
	}
	system("cls");
	puts("\n\t\t\t\t��������ͺŲ�����!");
}


void ModifyData4(char sBrand[20])//�޸�����
{
	struct SNode* p = g_pHead;
	while(p)/*ѭ������*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
		{
			printf("\n\t\t�����������µ�����(ƥ):");
			int fPower;
			scanf("%d",&fPower);
			p ->data.fPower = fPower;/*���µ����ݶ�Ҫ�޸ĵ����ݽ��и���*/
			Print();
			return;
		}     
		p = p ->pNext;/*ѭ�����������һ��.���±���*/
	}
	system("cls");
	puts("\n\t\t\t\t��������ͺŲ�����!");
}


void ModifyData5(char sBrand[20])//�޸�Ť��
{
	struct SNode* p = g_pHead;
	while(p)/*ѭ������*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
		{
			printf("\n\t\t�����������µ�Ť��(N��m):");
			int fTorque;
			scanf("%d",&fTorque);
			p ->data.fTorque = fTorque;/*���µ����ݶ�Ҫ�޸ĵ����ݽ��и���*/
			Print();
			return;
		}     
		p = p ->pNext;/*ѭ�����������һ��.���±���*/
	}
	system("cls");
	puts("\n\t\t\t\t��������ͺŲ�����!");
}


void ModifyData6(char sBrand[20])//�޸�����
{
	struct SNode* p = g_pHead;
	while(p)/*ѭ������*/
	{
		if(!strcmp(p->data.sModel,sBrand))/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
		{
			printf("\n\t\t�����������µ�����(Kg):");
			int fWeight;
			scanf("%d",&fWeight);
			p ->data.fWeight = fWeight;/*���µ����ݶ�Ҫ�޸ĵ����ݽ��и���*/
			Print();
			return;
		}     
		p = p ->pNext;/*ѭ�����������һ��.���±���*/
	}
	system("cls");
	puts("\n\t\t\t\t��������ͺŲ�����!");
}


void Modify()/*case4���޸ĺ�����һ������*/
{
	int d;
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		Print();
		printf("\n\t\t������Ҫ�޸ĵ������ͺ�:");
		char sBrand[20];
		scanf("%s",&sBrand);
		puts("\n\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
		puts("\t\t\t\t*           1,�޸ļ۸�                       3,�޸�����                      5,�޸�����                  7,�޸�����   *");
		puts("\t\t\t\t*           2,�޸���ټ���ʱ��               4,�޸ķ���������                6,�޸�Ť��                               *");
		puts("\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
		printf("\n\t\t��ѡ���������޸ĵ�ѡ��:");
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
		//ModifyData(sBrand);�������Ʒ��ͨ���޸ĺ����Ķ�����������
		printf("\t\t�Ƿ�����޸�? [y/n]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;/*struct SNode* pΪһ��ָ��,�ȶ���ָ��*/
		int nPrice = 0;
		printf("\n\t\t\t\t������۸�:");
		scanf("%d",&nPrice);
		puts("\t\t\t\tƷ��(�ͺ�)\t�۸�(��)\t��ټ���(��)");
		while(p)
		{
			if(p ->data.nPrice == nPrice)/*�ȶ���ͬ�ļ۸�*/
			{
				printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				break;
			}
			p = p->pNext;
		}
		printf("\t\t\t\t�Ƿ��������? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


void FindbyBrand()/*ͨ��Ʒ�Ʋ���*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t������Ҫ��Ʒ��:");
		scanf("%s",sBrand);
		while(p) //ѭ������
		{
			if(strcmp(p ->data.sBrand , sBrand) == 0)//�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp
				printf("\t\t|  %-10s|  %-19s|\n",p->data.sBrand,p->data.sModel);
			p = p ->pNext;
		}
		printf("\t\t\t\t�Ƿ��������? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');

}


void FindbySpeed()/*ͨ������ʱ��β���*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		float fMin;/*�趨��������������������ʱ���*/
		float fMax;
		printf("\t\t\t\t��������ټ���ʱ��εĳ�ĩʱ��(ʹ�ÿո���):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*ѭ������*/
		{
			if((p->data.fSpeed>=fMin)&&(p->data.fSpeed<=fMax))/*�ȶԼ���ʱ���Ƿ��ڴ�ʱ�����*/
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
		printf("\t\t\t\t�Ƿ��������? [y/n]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t��������������:");
		scanf("%s",sBrand);
		while(p)/*ѭ������*/
		{
			if(strcmp(p ->data.fType , sBrand) == 0)/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
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
		printf("\t\t\t\t�Ƿ��������? [y/n]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		float fMin;/*�趨��������������������ʱ���*/
		float fMax;
		printf("\t\t\t\t������������������(ʹ�ÿո���):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*ѭ������*/
		{
			if((p->data.fOutput>=fMin)&&(p->data.fOutput<=fMax))/*�ȶԼ���ʱ���Ƿ��ڴ�ʱ�����*/		
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
		printf("\t\t\t\t�Ƿ��������? [y/n]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
        puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t�����뷢��������:");
		scanf("%s",sBrand);
		while(p)/*ѭ������*/
		{
			if(strcmp(p ->data.sEngine , sBrand) == 0)/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
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
		printf("\t\t\t\t�Ƿ��������? [y/n]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		float fMin;/*�趨��������������������ʱ���*/
		float fMax;
		printf("\t\t\t\t��������������������ֵ(ʹ�ÿո���):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*ѭ������*/
		{
			if((p->data.fPower>=fMin)&&(p->data.fPower<=fMax))/*�ȶԼ���ʱ���Ƿ��ڴ�ʱ�����*/
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
		printf("\t\t\t\t�Ƿ��������? [y/n]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		float fMin;/*�趨��������������������ʱ���*/
		float fMax;
		printf("\t\t\t\t������������λ��Ť��(ʹ�ÿո���):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*ѭ������*/
		{
			if((p->data.fTorque>=fMin)&&(p->data.fTorque<=fMax))/*�ȶԼ���ʱ���Ƿ��ڴ�ʱ�����*/
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
		printf("\t\t\t\t�Ƿ��������? [y/n]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		float fMin;/*�趨��������������������ʱ���*/
		float fMax;
		printf("\t\t\t\t������������������(ʹ�ÿո���):");
		scanf("%f %f",&fMin,&fMax);
		while(p)/*ѭ������*/
		{
			if((p->data.fWeight>=fMin)&&(p->data.fWeight<=fMax))/*�ȶԼ���ʱ���Ƿ��ڴ�ʱ�����*/
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
		printf("\t\t\t\t�Ƿ��������? [y/n]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		char sBrand[20];
		printf("\t\t\t\t�������ͺ�:");
		scanf("%s",sBrand);
		while(p)/*ѭ������*/
		{
			if(strcmp(p ->data.sModel , sBrand) == 0)/*�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp*/
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
		printf("\t\t\t\t�Ƿ��������? [y/n]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'N' && c != 'n');
}


int Find()/*case5�Ĳ��Һ���,��int��Ϊ�˲��Ҳ鲻����ʱ����Իص����˵�*/
{
	system("cls");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\n\n\t\t\t\t��������������������������������������������������������������������");
	puts("\t\t\t\t��         ��          ��         ��");
	puts("\t\t���������������������������������ߩ����������������������������������������������������������������ߩ�����������������������������������");
	puts("\t\t��                           ��.���������ͺŲ���                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.�����������Ͳ���                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.���������۸����                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.������������ʱ�����                ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.����������������                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.���շ����������                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.����������������                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.��������Ť�ز���                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.����������������                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           0. �˳�                                ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	int i;
	printf("\\n\t\t��ѡ��������Ĳ��ҷ�ʽ:");
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


void SortbyPrice()/*���ռ۸�ߵ�����*/
{
	char c = 0;
	do{
		system("cls");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
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
     	printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');

}


void SortbySpeed()/*������ټ����ٶ�ʱ�䳤������*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
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
     	printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');

}


void sortbyInput()/*����ԭʼ��������ʱ��˳��ֱ�����,��ʵ����ǰ���Print����*/
{
	char c = 0;
	do
	{
		system("cls");
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		Print();
		printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
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
     	printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
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
     	printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
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
     	printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
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
     	printf("\n\n\n\t\t\t\t�Ƿ����? [y]");
		c = getch();
		putch(c);
		putch('\n');
	}while(c != 'Y' && c != 'y');
}


int Browse()/*case1���������,�������������ģʽ*/
{
	system("cls");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\n\n\t\t\t\t��������������������������������������������������������������������");
	puts("\t\t\t\t��         �          ��         ��");
	puts("\t\t���������������������������������ߩ����������������������������������������������������������������ߩ�����������������������������������");
	puts("\t\t��                           ��.����ԭʼ��������                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.������������ʱ������                ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.���������۸�����                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.��������Ť������                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.����������������                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.����������������                    ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.����������������                    ��");
	puts("\t\t�贈������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           0. �˳�                                ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	int i = 0;
	printf("\n\t\t\t\t��ѡ�������������ʽ:");
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


void Save()/*���溯��*/
{
	FILE* fp;
	fp = fopen("./stud.","wb");/*studΪ���ݵ��ļ���*/
	SNode* p = g_pHead ;
	while(p)/*����ѭ���������β*/
	{
		fwrite(&p->data,1,sizeof(p->data),fp);//��һ����Ա�����ĵ�ַ�ͽṹ��ĵ�ַ����ͬ��,����p��*/
		p = p ->pNext;
	}
	fclose(fp);
	FILE* fp1;
	char name[20];
	printf("���ٴ������û���:");
	scanf("%s",name);
	fp1 = fopen(name,"a");/*studΪ���ݵ��ļ���*/
	struct Person *New = Head->Next->Next ;
	while(New
		)/*����ѭ���������β*/
	{
		fprintf(fp,"%s\n",New->brand);//��һ����Ա�����ĵ�ַ�ͽṹ��ĵ�ַ����ͬ��,����p��*/
		New = New ->Next;
	}
	fclose(fp1);
}


void Load()/*�������ݺ���*/
{
	FILE* fp;
    DATA data;
	fp = fopen("./stud.","rb");
	while(fread(&data,1,sizeof(data),fp))
		AddTail(data);
	fclose(fp);

}


int Menu1()/*�������˵�����,2������*/
{
	system("cls");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	puts("\t\t������������������������������������������������������������������������������������������������������������������������������������");
	puts("\n\n\t\t\t\t��������������������������������������������������������������������");
	puts("\t\t\t\t��         ��          ̨         ��");
	puts("\t\t���������������������������������ߩ����������������������������������������������������������������ߩ�����������������������������������");
	puts("\t\t��                           ��.�����Ϣ                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.�����Ϣ                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.ɾ����Ϣ                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.�޸���Ϣ                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                            0. �˳�                               ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	int i = 0;
	printf("\t\t\t\t��ѡ��:    ");
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
		puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
	    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
		struct SNode* p = g_pHead;
		char sBrand[10][20];
		int d = 0,i;
		printf("\t\t\t\t��������Ҫ�Աȼ�����������:");
		scanf("%d",&d);
		for(i=0;i<d;i++)
		{
			printf("\n\t\t\t\t�������%d�����ͺ�:",i+1);
			scanf("%s",sBrand[i]);
		}
		for(i=0;i<d;i++)
		{   
			 p = g_pHead;
			while(p)//ѭ������
			{
				if(strcmp(p ->data.sModel , sBrand[i]) == 0)
				{//�ַ��Ƚϱ�����strcmp,�����õȺ�ֱ�ӱȽ�,Ҳ��дΪ!strcmp
					printf("\n\n\t\t|  ����Ʒ��  |         �ͺ�        |   ����   | �۸�(��) | ��ټ���ʱ��(��) | ����(L) |   ����������   | ����(ƥ) | Ť��(N��m) | ����(Kg) |\n\n");
					printf("\t\t|  %-10s|  %-19s|    %-6s|   %-7d|       %-10.1f |   %-5.1f |   %-13s|   %-7d|    %-8d|  %-8d|\n\n",p->data.sBrand,p->data.sModel,p->data.fType,p->data.nPrice,p->data.fSpeed,p->data.fOutput,p->data.sEngine,p->data.fPower,p->data.fTorque,p->data.fWeight);
				}
				p = p ->pNext;
			}
		}
		printf("\n\t\t\t\t�Ƿ��������? [y/n]");
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



int Menu(char name[10])/*���˵�����,2������*/
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
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
    puts("\t\t��           ��      ��      ѡ      ��      ϵ      ͳ             ��");
    puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	puts("\n\n\t\t\t\t��������������������������������������������������������������������");
	puts("\t\t\t\t��         ��          ��         ��");
	puts("\t\t���������������������������������ߩ����������������������������������������������������������������ߩ�����������������������������������");
	puts("\t\t��                           ��.�������                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.����Ʒ��                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.���ҳ���                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.�Աȳ���                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.�����¼                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.����ϲ��                            ��");
	puts("\t\t�ǩ�������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           ��.����                                ��");
	puts("\t\t�贈������������������������������������������������������������������������������������������������������������������������������������");
	puts("\t\t��                           0. �˳�                                ��");
	puts("\t\t����������������������������������������������������������������������������������������������������������������������������������������");
	int i = 0;
	printf("\t\t\t\t��ѡ��:");
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


int main(int argc, char* argv[])/*������,1������*/
{
	Load();
	system("color F2");
	while(Login());
	Save();
}
