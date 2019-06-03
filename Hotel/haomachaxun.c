#include "..\\Hotel\haomachaxun.h"
#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\tuifang.h"
#include "..\\Hotel\chaxun.h"
void haomachaxun()
{
	int j, flag = 0;
	int a;
	char haoma[100] = { '\0' };
	printf("                     类型     房间号     价格     面积      是否有窗     是否有浴室     是否有空调     楼层       酒店\n");
	fflush(stdin);
	while (1)
	{
		printf("输入要查询的房间号：\n");
		scanf("%s", haoma);
		for (j = 1; j < 27; j++)
		{
			if (!strcmp(room[j].room_num, haoma))
				if (!strcmp(room[j].booker, loginer_pass))
				{
					flag++;
					printf("                  %d.%s       %s         %s        %s        %s           %s             %s             %s        %s\n", j, room[j].character, room[j].room_num, room[j].price, room[j].square, room[j].window, room[j].bathroom, room[j].air_condition, room[j].floor, room[j].shop_owner);
				}
		}

		if (!flag)
		{
			system("cls"); printf("没有房间\n");
		}
		else
			break;
	}
	printf("===================================\n");
	printf("1.选择退房    2.返回上一级   3.退出程序\n");
	while (1)
	{
		if (!scanf("%d", &a))   //如果没有以%d的形式输入，scanf的返回值应该是0
		{
			printf("数字！！!傻冒！\n");
			fflush(stdin);//清除键盘输入缓存
			continue;
		}
		switch (a)
		{
		case 1:tuifang(); break;
		case 2:chaxun(); break;
		case 3:exit(0); break;
		default:printf("请输入正确的指令！\n");
		}
		if (a > 0 && a < 4)break;
	}
}


