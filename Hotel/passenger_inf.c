#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\passenger_inf.h"
void passenger_inf()//��ѯ���ú���
{
	system("cls");
	int i;
	int flag = 0;
	char room_number[100];
	printf("��ӡ�㶨�����з��䣬��������Ҫ��ѯ�ķ���ţ�\n");
	scanf("%s", room_number);
	for (i = 1; i < 26; i++)
	{
		if (!strcmp(loginer_pass, room[i].booker))//loginer_passΪ��ǰ���ڵ�½ϵͳ���û�
		{
			if (!strcmp(room_number, room[i].room_num))//��ӡ�������û����󷿼����������Ǹ��û�Ԥ���ķ���
			{
				printf("���     ����     �����     �۸�     ���      �Ƿ��д�     �Ƿ���ԡ��     �Ƿ��пյ�     ¥��     �Ƶ�\n");
				printf("%s.%s  %s  %s  %s  %s  %s  %s  %s  %s\n", room[i].xuhao, room[i].character, room[i].room_num, room[i].price, room[i].square, room[i].window, room[i].bathroom, room[i].air_condition, room[i].floor, room[i].shop_owner);
			}
		}
	}
	if (flag == 0)
	{
		printf("û���ҵ������Ϣ\n");
	}
}