#include "..\\Hotel\xiugai.h"
#include "..\\Hotel\DataSheet.h"
void xiugai()
{
	int z;
	fp_hotel_room = fopen("hotel_room.txt", "w");
	for (z = 0; z < 26; z++)
	{
		fprintf(fp_hotel_room, "%s          %s      %s      %s      %s      %s       %s      %s      %s     %s      %s    %s     %s\n", room[z].character, room[z].room_num, room[z].price, room[z].square, room[z].window, room[z].VIP, room[z].bathroom, room[z].air_condition, room[z].booker, room[z].floor, room[z].shop_owner, room[z].xuhao, room[z].shashuprice);
	}
}