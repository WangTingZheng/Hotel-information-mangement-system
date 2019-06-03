#include "..\\Hotel\DataSheet.h"
#include "..\\Hotel\room_xinxi.h"
#include "..\\Hotel\menu.h"
void room_xinxi()
{
	fp_hotel_room = fopen("hotel_room.txt", "r");
	int c;
	int a;
	while ((c = fgetc(fp_hotel_room)) != EOF) putchar(c);
	printf("按1回到菜单，按其它键退出系统\n");
	if (scanf("%d", &a))
	{
		if (a == 1)
		{
			system("cls");
			menu();
		}
	}
}