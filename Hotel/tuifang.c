#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\tuifang.h"
#include "..\\Hotel\xiugai.h"
void tuifang()
{
	int num;
	int z1 = 0;
	printf("������Ҫ�˶��ķ������:\n");
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
				printf("�˶��ɹ�\n");
				break;
				z1 = 1;
			}
			else
			{
				printf("�ⲻ����ķ���,��������\n");
			}
			if (z1)break;
		}
		else
		{
			printf("���֣�����ɵð����\n");
		}
	}
}