#include "..\\Hotel\book.h"
#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\returnf.h"
#include "..\\Hotel\xiugai.h"
void book()//预定
{
	system("cls");//清屏函数
	int i = 0;//录入存储所用，switch中
	int j, j1 = 0;//循环计数及其功能判别条件，筛选时
	int ding = 0;//你想预定的房间名
	int k = 0;//switch选择所用，及其跳出判决条件，房间类型选择
	int m = 0;//switch选择所用，及其跳出判决条件，楼层选择
	int p, p1 = 0;//预定正确判决条件，最后的选择
	int h, h2;//h是身份录入的循环。h1杀熟系统的循环 h2记录输入的个人信息的位置打印到文件
	int s;
	int flag1 = 0;
loopA:printf("欢迎来到旅店预订系统，选择你想要的酒店\n");
	printf("1.青年旅馆\n");
	printf("2.梦溪酒店\n");
	printf("3.如家宾馆\n");
	printf("4.回到主菜单\n");
	printf("5.回到用户菜单\n");
	while (1)
	{
		if (!scanf("%d", &i))
		{
			printf("数字！！!\n");
			fflush(stdin);
			continue;
		}
		switch (i)
		{
		case 1: strcpy(shop_choice, hotel1); break;
		case 2: strcpy(shop_choice, hotel2); break;
		case 3: strcpy(shop_choice, hotel3); break;
		case 4:returnf(1); break;
		case 5:returnf1(1); break;
		default: printf("请重新输入\n"); break;
		}
		if (i > 0 && i < 6)break;
	}
loop9: printf("请按照下面的类别检索你想要的酒店\n");
	printf("类型           面积        \n");
	printf("1.经济         5.14平米     \n");
	printf("2.家庭         6.60平米     \n");
	printf("3.豪华         7.80平米     \n");
	printf("4.回到主菜单            \n");
	printf("5.回到用户菜单            \n");
	printf("6.回到上一级           \n");
	while (1)
	{
		if (!scanf("%d", &k))
		{
			printf("数字！！!\n");
			fflush(stdin);
			continue;
		}
		switch (k)
		{
		case 1:system(".\\Resources\\Pictures\\1.jpg"); strcpy(shop_ch, chara1); break;//插入图片和将选择信息存入数组，存入后筛选使用
		case 2:system(".\\Resources\\Pictures\\2.jpg"); strcpy(shop_ch, chara2); break;//插入图片和将选择信息存入数组，存入后筛选使用
		case 3:system(".\\Resources\\Pictures\\3.jpg"); strcpy(shop_ch, chara3); break;//插入图片和将选择信息存入数组，存入后筛选使用
		case 4:returnf(1); break;
		case 5:returnf1(1); break;
		case 6:system("cls"); goto loopA; break;
		default:printf("请重新输入"); break;
		}
		if (k > 0 && k < 7)break;
	}
	printf("请输入楼层(1~3)：\n");
	while (1)
	{
		if (!scanf("%d", &m))
		{
			printf("数字！！!\n");
			fflush(stdin);
			continue;
		}
		switch (m)
		{
		case 1:strcpy(shop_fl, flo1); break;
		case 2:strcpy(shop_fl, flo2); break;
		case 3:strcpy(shop_fl, flo3); break;
		default:printf("请重新输入"); break;
		}
		if (m > 0 && m < 4)break;
	}
	int killpass_flag = 0;
	int q;
	for (q = 100000; q >= 0; q--)
	{
		if (!strcmp(loginer_pass, killpass[q].username_killered))
			if ((killpass[q].hotel_killer1 >= 2 && !strcmp(shop_choice, hotel1)) || (killpass[q].hotel_killer2 >= 2 && !strcmp(shop_choice, hotel2)) || (killpass[q].hotel_killer3 >= 2 && !strcmp(shop_choice, hotel3)))
			{
				killpass_flag = 1;
			}
	}
	printf("   类型    房间号    价格    面积     是否有窗    是否有浴室     是否有空调    楼层       酒店\n");
	for (j = 0; j < 50; j++)//循环筛选
	{
		if (!strcmp(shop_choice, room[j].shop_owner))
			if (!strcmp(shop_ch, room[j].character))
				if (!strcmp(shop_fl, room[j].floor))
				{
					if (!strcmp(room[j].booker, none))
					{
						switch (killpass_flag)
						{
						case 1:printf("%d.%s    %s         %s      %s        %s       %s              %s             %s        %s\n", j, room[j].character, room[j].room_num, room[j].shashuprice, room[j].square, room[j].window, room[j].bathroom, room[j].air_condition, room[j].floor, room[j].shop_owner); break;
						case 0: printf("%d.%s    %s         %s       %s       %s        %s             %s             %s         %s\n", j, room[j].character, room[j].room_num, room[j].price, room[j].square, room[j].window, room[j].bathroom, room[j].air_condition, room[j].floor, room[j].shop_owner); break;
						}

						j1 = 1;
						for (p = 0; p < 50; p++)
						{
							if (room_n[p] == -1)
							{
								room_n[p] = j;
								break;
							}
							else
							{
								room_n[p + 1] = j;
								break;
							}
						}
					}
				}
	}
	if (!j1)
	{
		printf("未找到你想要的房间!\n");
		fflush(stdin);
		goto loop9;
	}
	printf("请选择你想预订的房间：\n");
loop10:   scanf("%d", &ding);
	for (p = 0; p <= 50; p++)
	{
		if (room_n[p] == ding)
		{
			strcpy(room[ding].booker, loginer_pass);//下面是测试所用打印函数
			p1 = 1;
		}
	}
	if (p1 == 0)
	{
		printf("重新输入！\n");
		fflush(stdin);
		goto loop10;
	}
	printf("请输入你的姓名：\n");
	for (h = 1; h <= 27; h++)
	{
		if (!strlen(passengeri[h].name))
		{
			fflush(stdin);
			scanf("%s", passengeri[h].name);
			h2 = h;
			break;
		}
	}
	printf("请输入你的身份证号：\n");
	for (h = 1; h <= 27; h++)
	{
		if (!strlen(passengeri[h].ID_number))
		{
			fflush(stdin);
			scanf("%s", passengeri[h].ID_number);
			h2 = h;
			break;
		}
	}

	printf("请输入你的手机号：\n");
	for (h = 1; h <= 27; h++)
	{
		if (!strlen(passengeri[h].phone_number))
		{
			fflush(stdin);
			scanf("%s", passengeri[h].phone_number);
			h2 = h;
			strcpy(passengeri[h].owner, loginer_pass);
			break;
		}
	}
	for (i = 1; i < 50; i++)
	{
		if (!strlen(passengeri[i].name))
		{
			fprintf(fp_passenger_information, "%s   %s   %s   %s\n", passengeri[h2].name, passengeri[h2].ID_number, passengeri[h2].phone_number, loginer_pass);
			if (!strlen(passengeri[i].name))
				break;
		}
	}
	for (s = 100; s > 0; s--)
	{
		if (!strcmp(killpass[s].username_killered, loginer_pass))//文档里已经有记录
		{
			flag1++;
			if (!strcmp(shop_choice, hotel1))
			{
				killpass[s].hotel_killer1++;
				break;
			}
			else if (!strcmp(shop_choice, hotel2))
			{
				killpass[s].hotel_killer2++;
				break;
			}
			else if (!strcmp(shop_choice, hotel3))
			{
				killpass[s].hotel_killer3++;
				break;
			}
			else

			{
				printf("%s\n%s\n", killpass[s].username_killered, loginer_pass);
			}
			break;
		}
	}
	switch (flag1)
	{
	case 0:
	{
		fprintf(fp_killpass, "%s  ", loginer_pass);
		if (!strcmp(shop_choice, hotel1))
			fprintf(fp_killpass, "%d ", yi);
		else
			fprintf(fp_killpass, "%d ", ling);

		if (!strcmp(shop_choice, hotel2))
			fprintf(fp_killpass, "%d ", yi);
		else
			fprintf(fp_killpass, "%d ", ling);

		if (!strcmp(shop_choice, hotel3))
			fprintf(fp_killpass, "%d\n", yi);
		else
		{
			fprintf(fp_killpass, "%d\n", ling);
		}
		break;
	}
	default:fprintf(fp_killpass, "%s  %d   %d   %d\n", loginer_pass, killpass[s].hotel_killer1, killpass[s].hotel_killer2, killpass[s].hotel_killer3);
	}
	xiugai();
	printf("成功预订！\n");
	Sleep(1000);
	exit(0);
}