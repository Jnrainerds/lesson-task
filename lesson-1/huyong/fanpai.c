#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>
void shuchuint(char a[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
	for(j=0;j<4;j++) {printf("%2c",a[i][j]);}
	printf("\n");
	}
}
int panduan(char a[4][4])
{
	int i,j,s=1;
	for(i=0;i<4;i++)
	{	
		for(j=0;j<4;j++)
		{
		if(a[i][j]=='*')
		s=0;
		break;
		}
		
	}
	return s;
}
int main()
{
	int i,j,x1,y1,x2,y2,k=0,m,n,s;	
	char a[4][4]={'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'};
	char c[16]={'2','8','7','1','1','6','7','8','4','2','3','6','4','3','5','5'};
	char b[4][4];
	printf("����һ�������������ķ�����Ϸ��\nһ��ʼ��10s��ʱ��۲����������4x4�����������������з��ƣ�������ͬ���Ƴɹ�.\nHave a try��\n");
	printf("******************************************************************\n");
	printf("���»س�����Ϸ��ʼ��");
	while(getchar()==10)
	{
		srand((unsigned)time(NULL));
		for(i=0;i<1000;i++)
		{
			m=rand()%16;
			n=rand()%16;
			s=c[m];
			c[m]=c[n];
			c[n]=s;
		}
		for(i=0;i<4;i++)
		{
		for(j=0;j<4;j++)
		{
			b[i][j]=c[k];
			k++;
		}
		}
		shuchuint(b);
		Sleep(5000);
		system("cls");
		shuchuint(a);
		while(panduan(a)==0)
		{
			lab1:
			printf("x1= ,y1= (1~4)\t");scanf("%d%d",&x1,&y1);
			if(!(x1>=1&&x1<=4)||!(y1>=1&&y1<=4)) {printf("����ȷ���룡"); goto lab1;}
			printf("\nx2= ,y2= (1~4)\t");scanf("%d%d",&x2,&y2);
			lab2:
			if(!(x2>=1&&x2<=4)||!(y2>=1&&y2<=4)) {printf("����ȷ���룡"); goto lab2;}
			if(b[x1-1][y1-1]==b[x2-1][y2-1])
			{
			a[x1-1][y1-1]=b[x1-1][y1-1];
			a[x2-1][y2-1]=b[x2-1][y2-1];
			shuchuint(a);
			printf("��ȷ��Go on��\n");
			}
			else
			{
				a[x1-1][y1-1]=b[x1-1][y1-1];
				a[x2-1][y2-1]=b[x2-1][y2-1];
				shuchuint(a);
				printf("����ȷӴ��");
				Sleep(2000);
				system("cls");
				a[x1-1][y1-1]='*';
				a[x2-1][y2-1]='*';
				shuchuint(a);
			}
		}
		printf("U Win����");
	}
}