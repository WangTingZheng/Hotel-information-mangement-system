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
	printf("$        1.����Ų�ѯ         $\n");
	toxy(35, 7);
	printf("$        2.���˻���ѯ         $\n");
	toxy(35, 8);
	printf("$        3.�������˵�         $\n");
	toxy(35, 9);
	printf("$        4.�����û��˵�       $\n");
	toxy(35, 10);
	printf("================================\n");
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
		case 1:haomachaxun(); break;
		case 2:humingchaxun(); break;
		case 3:returnf(1); break;
		case 4:returnf1(1); break;
		default:printf("������Ҫ������������\n");
		}
		if (a > 0 && a < 5)break;
	}
}