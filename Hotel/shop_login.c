#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\shop_login.h"
#include "..\\Hotel\menu.h"
#include "..\\Hotel\shop_menu.h"

void shop_login()//��ҵ�¼
{
	int i;
	int flag = 0;
	int m, n;
	int flag1 = 0;

	char password_co[100];
	system("cls");
	printf("��ӭ������½ϵͳ��         \n");
	while (1)
	{
		printf("�������˺ţ�\n");
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
			printf("�Ҳ������û���\n");
			printf("1.������һ��  2.��������\n");
		loop:     if (scanf("%d", &m))
		{

			if (m == 1)
			{
				system("cls");
				menu();
			}
			else if (m != 2)
			{
				printf("������1��2!\n");
				fflush(stdin);
				goto loop;
			}
		}
				  else
		{
			printf("���������֣���\n");
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
		printf("������������룺\n");
		scanf("%s", password_co);
		if (!strcmp(password_co, shop[flag1].password))
		{
			printf("��½�ɹ���\n");//�������������
			break;
		}
		else
		{
			printf("���������������Ƿ��������룿\n");
			printf("1.������һ��      2.��������\n");
		loop2:   if (scanf("%d", &n))
		{
			if (n == 1)
			{
				system("cls");
				menu();
			}
			else if (n != 2)
			{
				printf("������1��2��\n");
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
			printf("���������֣�\n");
			fflush(stdin);
			goto loop2;
		}
		}
	}
	shop_menu();
}