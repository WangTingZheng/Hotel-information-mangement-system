#include "..\\Hotel\humingchaxun.h"
#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\tuifang.h"
#include "..\\Hotel\chaxun.h"
void humingchaxun()
{
	system("cls");
	int a;
	printf("   ����     �����     �۸�     ���      �Ƿ��д�     �Ƿ���ԡ��     �Ƿ��пյ�     ¥��       �Ƶ�\n");
	int j, flag = 0;
	for (j = 1; j < 27; j++)
	{
		if (!strcmp(room[j].booker, username_co))
		{
			flag = 1;
			printf("%d.%s       %s         %s        %s        %s           %s             %s             %s        %s\n", j, room[j].character, room[j].room_num, room[j].price, room[j].square, room[j].window, room[j].bathroom, room[j].air_condition, room[j].floor, room[j].shop_owner);
		}
	}
	if (!flag)
	{
		system("cls"); printf("û�з���\n");
	}
	printf("===================================\n");
	printf("1.ѡ���˷�    2.������һ��   3.�˳�����\n");
	while (1)
	{
		if (!scanf("%d", &a))   //���û����%d����ʽ���룬scanf�ķ���ֵӦ����0
		{
			printf("���֣���!ɵð��\n");
			fflush(stdin);//����������뻺��
			continue;
		}
		switch (a)
		{
		case 1:tuifang(); break;
		case 2:chaxun(); break;
		case 3:exit(0); break;
		default:printf("��������ȷ��ָ�\n");
		}
		if (a > 0 && a < 4)break;
	}
}