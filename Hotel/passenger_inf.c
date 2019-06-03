#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\passenger_inf.h"
void passenger_inf()//查询所用函数
{
	system("cls");
	int i;
	int flag = 0;
	char room_number[100];
	printf("打印你定的所有房间，请输入你要查询的房间号：\n");
	scanf("%s", room_number);
	for (i = 1; i < 26; i++)
	{
		if (!strcmp(loginer_pass, room[i].booker))//loginer_pass为当前正在登陆系统的用户
		{
			if (!strcmp(room_number, room[i].room_num))//打印出所有用户所大房间号相符并且是该用户预订的房间
			{
				printf("序号     类型     房间号     价格     面积      是否有窗     是否有浴室     是否有空调     楼层     酒店\n");
				printf("%s.%s  %s  %s  %s  %s  %s  %s  %s  %s\n", room[i].xuhao, room[i].character, room[i].room_num, room[i].price, room[i].square, room[i].window, room[i].bathroom, room[i].air_condition, room[i].floor, room[i].shop_owner);
			}
		}
	}
	if (flag == 0)
	{
		printf("没有找到你的信息\n");
	}
}