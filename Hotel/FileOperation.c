#include "DataSheet.h"
#include "FileOperation.h"
void FileOperation()//文件定义
{
	int i = 0;
	int j = 0;
	int q = 0;
	int z = 0;
	int m = 0;
	fopen_s(&fp_login_passenger,"..\\Resurces\\Data\\login_passenger.txt", "rt+");
	fopen_s(&fp_login_shop,"..\\Resurces\\Data\\login_shop.txt", "rb");
	fopen_s(&fp_passenger_information,"..\\Resurces\\Data\\passenger_information.txt", "rt+");
	fopen_s(&fp_hotel_room,"..\\Resurces\\Data\\hotel_room.txt", "rt+");
	fopen_s(&fp_killpass,"..\\Resurces\\Data\\killpass.txt", "rt+");

	while (!feof(fp_login_passenger)) //从文件中读取数据到结构体
	{
		fscanf_s(fp_login_passenger, "%s%s", passenger[i].username, passenger[i].password, sizeof(unsigned int), sizeof(unsigned int));
		i++;
	}
	while (!feof(fp_login_shop)) //从文件中读取数据到结构体
	{
		fscanf_s(fp_login_shop, "%s%s", shop[j].username, shop[j].password, sizeof(unsigned int), sizeof(unsigned int));
		j++;
	}
	while (!feof(fp_hotel_room)) //从文件中读取数据到结构体
	{
		fscanf_s(fp_hotel_room, "%s%s%s%s%s%s%s%s%s%s%s%s%s", room[z].character, room[z].room_num, room[z].price, room[z].square, room[z].window, room[z].VIP, room[z].bathroom, room[z].air_condition, room[z].booker, room[z].floor, room[z].shop_owner, room[z].xuhao, room[z].shashuprice, sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int));
		z++;
	}
	while (!feof(fp_passenger_information)) //从文件中读取数据到结构体
	{
		fscanf_s(fp_passenger_information, "%s%s%s%s", passengeri[q].name, passengeri[q].ID_number, passengeri[q].phone_number, passengeri[q].owner, sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int), sizeof(unsigned int));
		q++;
	}
	while (!feof(fp_killpass)) //从文件中读取数据到结构体
	{
		fscanf_s(fp_killpass, "%s%d%d%d", killpass[m].username_killered, &killpass[m].hotel_killer1, &killpass[m].hotel_killer2, &killpass[m].hotel_killer3);
		m++;
	}
}