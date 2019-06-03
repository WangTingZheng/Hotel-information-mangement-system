#include <stdio.h>

FILE*fp_login_passenger;
FILE*fp_login_shop;
FILE*fp_passenger_information;
FILE*fp_hotel_room;
FILE*fp_killpass;
char username_co[100];
const int yi = 1;
const int ling = 0;

int i;
int page = 1;
char loginer_pass[100] = { '\0' };  //用来储存当前登陆旅客的身份（用户名）用于打印用户信息等
char loginer_shop[100] = { '\0' };   //用来储存当前登陆店家管理员的身份（用户名）
char shop_choice[100] = { '\0' };//筛选用
char shop_ch[100] = { '\0' };//筛选用
char shop_fl[100] = { '\0' };//筛选用
char floor_choice[100] = { '\0' };//筛选用

char none[10] = { "无" };
char hotel1[100] = { "青年旅馆" };
char hotel2[100] = { "梦溪酒店" };
char hotel3[100] = { "如家宾馆" };
char chara1[100] = { "经济" };
char chara2[100] = { "家庭" };
char chara3[100] = { "豪华" };
char flo1[10] = { "1" };
char flo2[10] = { "2" };
char flo3[10] = { "3" };

int room_n[50] = { -1 };

struct passenger_login_data
{
	char username[100];
	char password[100];
}passenger[50];

struct shop_login_data
{
	char username[100];
	char password[100];
}shop[3];

struct passenger_information_data
{
	char name[100];
	char ID_number[100];
	char phone_number[100];
	char owner[100];
}passengeri[50];

struct hotel_data
{
	char character[100];
	char room_num[10];
	char price[100];
	char square[10];

	char window[10];
	char VIP[10];
	char bathroom[10];
	char air_condition[10];

	char booker[100];
	char floor[100];
	char shop_owner[100];
	char xuhao[100];
	char shashuprice[100];
}room[100];

struct killpass_data
{
	char username_killered[100];
	int  hotel_killer1;
	int  hotel_killer2;
	int  hotel_killer3;
}killpass[100000];
