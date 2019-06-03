#include "..\\Hotel\toxy.h"
#include "..\\Hotel\chaxun.h"
#include"..\\Hotel\humingchaxun.h"
#include "..\\Hotel\\haomachaxun.h"
#include "..\\Hotel\returnf.h"
void chaxun()
{
	system("cls");
	int a;
	toxy(35, 5);
	printf("================================\n");
	toxy(35, 6);
	printf("$        1.房间号查询         $\n");
	toxy(35, 7);
	printf("$        2.此账户查询         $\n");
	toxy(35, 8);
	printf("$        3.返回主菜单         $\n");
	toxy(35, 9);
	printf("$        4.返回用户菜单       $\n");
	toxy(35, 10);
	printf("================================\n");
	toxy(35, 11);
	printf("请输入一个1到4的数\n");
	while (1)
	{
		if (!scanf("%d", &a))
		{
			printf("数字！！!\n");
			fflush(stdin);
			continue;
		}
		switch (a)
		{
		case 1:haomachaxun(); break;
		case 2:humingchaxun(); break;
		case 3:returnf(1); break;
		case 4:returnf1(1); break;
		default:printf("不符合要求，请重新输入\n");
		}
		if (a > 0 && a < 5)break;
	}
}