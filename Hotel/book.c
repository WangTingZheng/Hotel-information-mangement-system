#include "..\\Hotel\book.h"
#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\returnf.h"
#include "..\\Hotel\xiugai.h"
void book()//Ԥ��
{
	system("cls");//��������
	int i = 0;//¼��洢���ã�switch��
	int j, j1 = 0;//ѭ���������书���б�������ɸѡʱ
	int ding = 0;//����Ԥ���ķ�����
	int k = 0;//switchѡ�����ã����������о���������������ѡ��
	int m = 0;//switchѡ�����ã����������о�������¥��ѡ��
	int p, p1 = 0;//Ԥ����ȷ�о�����������ѡ��
	int h, h2;//h�����¼���ѭ����h1ɱ��ϵͳ��ѭ�� h2��¼����ĸ�����Ϣ��λ�ô�ӡ���ļ�
	int s;
	int flag1 = 0;
loopA:printf("��ӭ�����õ�Ԥ��ϵͳ��ѡ������Ҫ�ľƵ�\n");
	printf("1.�����ù�\n");
	printf("2.��Ϫ�Ƶ�\n");
	printf("3.��ұ���\n");
	printf("4.�ص����˵�\n");
	printf("5.�ص��û��˵�\n");
	while (1)
	{
		if (!scanf("%d", &i))
		{
			printf("���֣���!\n");
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
		default: printf("����������\n"); break;
		}
		if (i > 0 && i < 6)break;
	}
loop9: printf("�밴�����������������Ҫ�ľƵ�\n");
	printf("����           ���        \n");
	printf("1.����         5.14ƽ��     \n");
	printf("2.��ͥ         6.60ƽ��     \n");
	printf("3.����         7.80ƽ��     \n");
	printf("4.�ص����˵�            \n");
	printf("5.�ص��û��˵�            \n");
	printf("6.�ص���һ��           \n");
	while (1)
	{
		if (!scanf("%d", &k))
		{
			printf("���֣���!\n");
			fflush(stdin);
			continue;
		}
		switch (k)
		{
		case 1:system(".\\Resources\\Pictures\\1.jpg"); strcpy(shop_ch, chara1); break;//����ͼƬ�ͽ�ѡ����Ϣ�������飬�����ɸѡʹ��
		case 2:system(".\\Resources\\Pictures\\2.jpg"); strcpy(shop_ch, chara2); break;//����ͼƬ�ͽ�ѡ����Ϣ�������飬�����ɸѡʹ��
		case 3:system(".\\Resources\\Pictures\\3.jpg"); strcpy(shop_ch, chara3); break;//����ͼƬ�ͽ�ѡ����Ϣ�������飬�����ɸѡʹ��
		case 4:returnf(1); break;
		case 5:returnf1(1); break;
		case 6:system("cls"); goto loopA; break;
		default:printf("����������"); break;
		}
		if (k > 0 && k < 7)break;
	}
	printf("������¥��(1~3)��\n");
	while (1)
	{
		if (!scanf("%d", &m))
		{
			printf("���֣���!\n");
			fflush(stdin);
			continue;
		}
		switch (m)
		{
		case 1:strcpy(shop_fl, flo1); break;
		case 2:strcpy(shop_fl, flo2); break;
		case 3:strcpy(shop_fl, flo3); break;
		default:printf("����������"); break;
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
	printf("   ����    �����    �۸�    ���     �Ƿ��д�    �Ƿ���ԡ��     �Ƿ��пյ�    ¥��       �Ƶ�\n");
	for (j = 0; j < 50; j++)//ѭ��ɸѡ
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
		printf("δ�ҵ�����Ҫ�ķ���!\n");
		fflush(stdin);
		goto loop9;
	}
	printf("��ѡ������Ԥ���ķ��䣺\n");
loop10:   scanf("%d", &ding);
	for (p = 0; p <= 50; p++)
	{
		if (room_n[p] == ding)
		{
			strcpy(room[ding].booker, loginer_pass);//�����ǲ������ô�ӡ����
			p1 = 1;
		}
	}
	if (p1 == 0)
	{
		printf("�������룡\n");
		fflush(stdin);
		goto loop10;
	}
	printf("���������������\n");
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
	printf("������������֤�ţ�\n");
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

	printf("����������ֻ��ţ�\n");
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
		if (!strcmp(killpass[s].username_killered, loginer_pass))//�ĵ����Ѿ��м�¼
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
	printf("�ɹ�Ԥ����\n");
	Sleep(1000);
	exit(0);
}