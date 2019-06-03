#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\shop_login.h"
#include "..\\Hotel\menu.h"
#include "..\\Hotel\shop_menu.h"

void shop_login()//店家登录
{
	int i;
	int flag = 0;
	int m, n;
	int flag1 = 0;

	char password_co[100];
	system("cls");
	printf("欢迎来到登陆系统！         \n");
	while (1)
	{
		printf("请输入账号：\n");
		scanf("%s", username_co);
		for (i = 0; i < 100; i++)
		{
			if (!strcmp(username_co, shop[i].username))
			{
				flag++;
				flag1 = i;
			}
		}
		if (!flag)
		{
			printf("找不到此用户！\n");
			printf("1.返回上一级  2.继续输入\n");
		loop:     if (scanf("%d", &m))
		{

			if (m == 1)
			{
				system("cls");
				menu();
			}
			else if (m != 2)
			{
				printf("请输入1或2!\n");
				fflush(stdin);
				goto loop;
			}
		}
				  else
		{
			printf("请输入数字！！\n");
			fflush(stdin);
			goto loop;
		}

		}
		else
		{
			break;
		}
	}
	while (1)
	{
		printf("请输入你的密码：\n");
		scanf("%s", password_co);
		if (!strcmp(password_co, shop[flag1].password))
		{
			printf("登陆成功！\n");//该语句后接主界面
			break;
		}
		else
		{
			printf("你输入的密码错误！是否重新输入？\n");
			printf("1.返回上一级      2.继续输入\n");
		loop2:   if (scanf("%d", &n))
		{
			if (n == 1)
			{
				system("cls");
				menu();
			}
			else if (n != 2)
			{
				printf("请输入1或2！\n");
				fflush(stdin);
				goto loop2;
			}
			else
			{
				continue;
			}
		}
				 else
		{
			printf("请输入数字！\n");
			fflush(stdin);
			goto loop2;
		}
		}
	}
	shop_menu();
}