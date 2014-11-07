#include<stdio.h>

void showCalendar(int year,int month)
{
	printf("    %d年%d月\n",year,month);
	printf("==============================\n");
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");
	printf("==============================\n");
	int dayNum=1,firstWeek,lastDay;
	int getFirst(int year,int month);
	int getLast(int year,int month);
	firstWeek=getFirst(year,month);
	lastDay=getLast(year,month);
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<7;j++)
		{
			if(i==0&&j<firstWeek)
				printf("    ");
			else
			{
				printf("%4d",dayNum);
				dayNum++;
			}
			if(dayNum>lastDay)
				break;
		
		}
			printf("\n");
		if(dayNum>lastDay)
			break;	
	
	}
}
int getFirst(int year,int month)
{
	int firstWeek;
	int dayDistance(int year,int month);
	firstWeek=dayDistance(year,month)%7+1;
	return firstWeek;
}
int getLast(int year,int month)
{
	int isLeap(int year);
	if(month==2)
		if(isLeap(year))
			return 29;
		else return 28;
	else if (month==4||month==6||month==9||month==11)
		return 30;
	else return 31;
}
int dayDistance(int year,int month)
{
	int disYear,disMonth,disDay;
	disYear=year-1;
	disMonth=month-1;
	disDay=disYear*365+(disYear/4-disYear/100+disYear/400);
	return disDay;
}
int isLeap(int year)
{
	if(year%400==0)
		return 1;
	else if(year%100==0)
		return 0;
	else if(year%4==0)
		return 1;
	else 
		return 0;
}
void main()
{
	int year,month;
	printf("请输入年月：");
	scanf("y=%d m=%d",&year,&month);
	showCalendar(year,month);
}