#include "..\\Hotel\menu_pass.h"
#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\toxy.h"
#include "..\\Hotel\returnf.h"
#include "..\\Hotel\tuifang.h"
#include "..\\Hotel\chaxun.h"
#include "..\\Hotel\book.h"
void menu_pass()//用户登录后的菜单
{
	int a;
	Sleep(1000);
	system("cls");
	toxy(35, 5);
	printf("----------------------------------------------------------\n");
	toxy(35, 6);
	printf("$			1.预订房间			$\n");
	toxy(35, 7);
	printf("$			2.查询信息			$\n");
	toxy(35, 8);
	printf("$			3.退房				$\n");
	toxy(35, 9);
	printf("$			4.返回菜单			$\n");
	toxy(35, 10);
	printf("----------------------------------------------------------\n");
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
		case 1:book(); break;
		case 2:chaxun(); break;
		case 3:tuifang(); break;
		case 4:returnf(page); break;
		default:printf("不符合要求，请重新输入\n");
		}
		if (a > 0 && a < 5)break;
	}
}