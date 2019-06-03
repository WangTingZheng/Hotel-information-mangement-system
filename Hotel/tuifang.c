#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\tuifang.h"
#include "..\\Hotel\xiugai.h"
void tuifang()
{
	int num;
	int z1 = 0;
	printf("请输入要退订的房间序号:\n");
	while (1)
	{
		getchar();
		if (scanf("%d", &num))
		{
			printf("%d", num);
			if (!strcmp(room[num].booker, username_co))
			{
				strcpy(room[num].booker, none);
				xiugai();
				printf("退订成功\n");
				break;
				z1 = 1;
			}
			else
			{
				printf("这不是你的房间,重新输入\n");
			}
			if (z1)break;
		}
		else
		{
			printf("数字！！！傻冒！！\n");
		}
	}
}