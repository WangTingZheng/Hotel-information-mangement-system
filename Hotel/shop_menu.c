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
	printf("$			1.��ѯ��Ϣ			$\n");
	toxy(35, 7);
	printf("$			2.���ز˵�			$\n");
	toxy(35, 8);
	printf("----------------------------------------------------------\n");
	printf("������һ��1��2����\n");
	while (1)
	{
		if (!scanf("%d", &a))
		{
			printf("���֣���!\n");
			fflush(stdin);
			continue;
		}
		switch (a)
		{
		case 1:room_xinxi(); break;
		case 2:returnf(1); break;
		default:printf("������Ҫ������������\n");
		}
		if (a > 0 && a < 3)break;
	}
}