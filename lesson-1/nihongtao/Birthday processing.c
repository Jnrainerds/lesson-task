#include<stdio.h>

#define N 13;

void countDays(int y1,int y2,int m1,int m2,int d1,int d2);
void calculateDayOfWeek(int y2,int m2,int d2);
void main()
{
	int i , j ,y1, y2, m1, m2, d1, d2;
	printf("Please input your Birhday:\n");
	scanf("%d-%d-%d",&y1,&m1,&d1);
	printf("Please input the present date:\n");
	scanf("%d-%d-%d",&y2,&m2,&d2);
	countDays(y1,y2,m1,m2,d1,d2);
	printf("\n");
	calculateDayOfWeek(y2,m2,d2);
	getchar();
	getchar();
	getchar();
}

void countDays(int y1,int y2,int m1,int m2,int d1,int d2)
{
	int i , j , k, p;
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int sum = 0;
	for ( i = y1; i < y2; i++)
   {
			sum += 365;
			if ((i % 4 == 4 && i / 100 != 0 )||( i % 400 ==0 ))
				sum++;
	}
	for( j = 0;j <= m2; j++)
		sum  += a[j];
	sum += d2;
	printf("The summary of your lifes is %d days",sum);
}

void calculateDayOfWeek(int y1,int m1,int d1)
{
	int i,j,w;
	int dayUntilNow =0 ;
	for (i = 1 ; i <= y1 ; i++)
		{
			dayUntilNow += 365;
			if ((i % 4 == 4 && i / 100 != 0 )||( i % 400 ==0 ))
				dayUntilNow++;
	    }
	w = dayUntilNow % 7;
	switch(w)
	{
		case 0: printf("Firday\n");break;
		case 1: printf("Saturday\n");break;
	    case 2: printf("Sunday\n");break;
		case 3: printf("Monday\n");break;
		case 4: printf("Tuesday\n");break;
		case 5: printf("Wednesday\n");break;
		case 6: printf("Thursday\n");break;
	}
}