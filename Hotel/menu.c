#include "..\\Hotel\menu.h"
#include "..\Hotel\DataSheet.h"
#include "..\\Hotel\toxy.h"
void menu()//���˵�
{
	int a;
	printf("\n");
	printf("\n");
	toxy(40, 5);    //һ����λ�������ɴ���Ļ�ĸ�����㿪ʼ��λִ����һ�����
	printf("          ��ӭ�����Ƶ�Ԥ��ϵͳ��          \n");
	toxy(40, 6);
	printf("==========================================\n");
	toxy(40, 7);
	printf("||		1.�ÿ͵�½		||\n");
	toxy(40, 8);
	printf("||		2.��ҵ�½		||\n");
	toxy(40, 9);
	printf("||		3.�˳�ϵͳ		||\n");
	toxy(40, 10);
	printf("==========================================\n");
	toxy(40, 11);
	printf("������һ��1��3����\n");
	page = 1;
	while (1)
	{
		if (!scanf_s("%d", &a, sizeof(a)))   //���û����%d����ʽ���룬scanf�ķ���ֵӦ����0
		{
			printf("���֣���!ɵð��\n");
			fflush(stdin);//����������뻺��
			continue;
		}
		switch (a)
		{
		case 1:passenger_login(); break;
		case 2:shop_login(); break;
		case 3:exit(0); break;
		default:printf("��������ȷ��ָ�\n");
		}
		if (a > 0 && a < 4)break;
	}
}