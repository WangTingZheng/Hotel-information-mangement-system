#include "..\\Hotel\menu.h"
#include "..\Hotel\DataSheet.h"
#include "..\\Hotel\toxy.h"
void menu()//主菜单
{
	int a;
	printf("\n");
	printf("\n");
	toxy(40, 5);    //一个定位函数，可从屏幕的该坐标点开始定位执行下一个语句
	printf("          欢迎来到酒店预订系统！          \n");
	toxy(40, 6);
	printf("==========================================\n");
	toxy(40, 7);
	printf("||		1.旅客登陆		||\n");
	toxy(40, 8);
	printf("||		2.店家登陆		||\n");
	toxy(40, 9);
	printf("||		3.退出系统		||\n");
	toxy(40, 10);
	printf("==========================================\n");
	toxy(40, 11);
	printf("请输入一个1到3的数\n");
	page = 1;
	while (1)
	{
		if (!scanf_s("%d", &a, sizeof(a)))   //如果没有以%d的形式输入，scanf的返回值应该是0
		{
			printf("数字！！!傻冒！\n");
			fflush(stdin);//清除键盘输入缓存
			continue;
		}
		switch (a)
		{
		case 1:passenger_login(); break;
		case 2:shop_login(); break;
		case 3:exit(0); break;
		default:printf("请输入正确的指令！\n");
		}
		if (a > 0 && a < 4)break;
	}
}