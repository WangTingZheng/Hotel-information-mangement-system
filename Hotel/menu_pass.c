#include "..\\Hotel\menu_pass.h"
#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\toxy.h"
#include "..\\Hotel\returnf.h"
#include "..\\Hotel\tuifang.h"
#include "..\\Hotel\chaxun.h"
#include "..\\Hotel\book.h"
void menu_pass()//�û���¼��Ĳ˵�
{
	int a;
	Sleep(1000);
	system("cls");
	toxy(35, 5);
	printf("----------------------------------------------------------\n");
	toxy(35, 6);
	printf("$			1.Ԥ������			$\n");
	toxy(35, 7);
	printf("$			2.��ѯ��Ϣ			$\n");
	toxy(35, 8);
	printf("$			3.�˷�				$\n");
	toxy(35, 9);
	printf("$			4.���ز˵�			$\n");
	toxy(35, 10);
	printf("----------------------------------------------------------\n");
	toxy(35, 11);
	printf("������һ��1��4����\n");
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
		case 1:book(); break;
		case 2:chaxun(); break;
		case 3:tuifang(); break;
		case 4:returnf(page); break;
		default:printf("������Ҫ������������\n");
		}
		if (a > 0 && a < 5)break;
	}
}