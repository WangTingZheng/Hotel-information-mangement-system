#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\room_xinxi.h"
#include "..\\Hotel\menu.h"
void room_xinxi()
{
	fp_hotel_room = fopen("hotel_room.txt", "r");
	int c;
	int a;
	while ((c = fgetc(fp_hotel_room)) != EOF) putchar(c);
	printf("��1�ص��˵������������˳�ϵͳ\n");
	if (scanf("%d", &a))
	{
		if (a == 1)
		{
			system("cls");
			menu();
		}
	}
}