#include "..\\Hotel\returnf.h"
#include "..\\Hotel\menu.h"
#include "..\\Hotel\menu_pass.h"
int returnf(int page)//返回函数，返回到主页面
{
	if (page == 1)
	{
		system("cls");
		menu();
	}
	return 0;
}
int returnf1(int page)//返回函数，返回到顾客页面
{
	if (page == 1)
	{
		system("cls");
		menu_pass();
	}
	return 0;
}