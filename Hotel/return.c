#include "..\\Hotel\returnf.h"
#include "..\\Hotel\menu.h"
#include "..\\Hotel\menu_pass.h"
int returnf(int page)//���غ��������ص���ҳ��
{
	if (page == 1)
	{
		system("cls");
		menu();
	}
	return 0;
}
int returnf1(int page)//���غ��������ص��˿�ҳ��
{
	if (page == 1)
	{
		system("cls");
		menu_pass();
	}
	return 0;
}