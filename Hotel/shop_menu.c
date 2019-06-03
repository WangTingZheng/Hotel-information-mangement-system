#include "..\\Hotel\shop_menu.h"
#include "..\\Hotel\toxy.h"
#include "..\\Hotel\room_xinxi.h"
#include "..\\Hotel\returnf.h"
void shop_menu()
{
	int a;
	Sleep(1000);
	system("cls");
	toxy(35, 5);
	printf("----------------------------------------------------------\n");
	toxy(35, 6);
	printf("$			1.查询信息			$\n");
	toxy(35, 7);
	printf("$			2.返回菜单			$\n");
	toxy(35, 8);
	printf("----------------------------------------------------------\n");
	printf("请输入一个1到2的数\n");
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
		case 1:room_xinxi(); break;
		case 2:returnf(1); break;
		default:printf("不符合要求，请重新输入\n");
		}
		if (a > 0 && a < 3)break;
	}
}