#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
FILE*fp_login_passenger;
FILE*fp_login_shop;
FILE*fp_passenger_information;
FILE*fp_hotel_room;
FILE*fp_killpass;
char username_co[100];
const int yi=1;
const int ling=0;


int i;
int page=1;
char loginer_pass[100]={'\0'};  //�������浱ǰ��½�ÿ͵���ݣ��û��������ڴ�ӡ�û���Ϣ��
char loginer_shop[100]={'\0'};   //�������浱ǰ��½��ҹ���Ա����ݣ��û�����
char shop_choice[100]={'\0'};//ɸѡ��
char shop_ch[100]={'\0'};//ɸѡ��
char shop_fl[100]={'\0'};//ɸѡ��
char floor_choice[100]={'\0'};//ɸѡ��

char none[10]={"��"};
char hotel1[100]={"�����ù�"};
char hotel2[100]={"��Ϫ�Ƶ�"};
char hotel3[100]={"��ұ���"};
char chara1[100]={"����"};
char chara2[100]={"��ͥ"};
char chara3[100]={"����"};
char flo1[10]={"1"};
char flo2[10]={"2"};
char flo3[10]={"3"};

int room_n[50]={-1};

int returnf(int page);
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

int i;
void predo();
void menu();
void passenger_login();
void shop_login();
void passenger_inf();
void book();
void menu_pass();
void xiugai();
void room_xinxi();
void shop_menu();
void tuifang();
void humingchaxun();
void chaxun();
void haomachaxun();
void toxy(int x, int y);
int main()
{
    predo();
    menu();
}
void menu()//���˵�
{
    int a;
    printf("\n");
    printf("\n");
    toxy(40,5);    //һ����λ�������ɴ���Ļ�ĸ�����㿪ʼ��λִ����һ�����
    printf("          ��ӭ�����Ƶ�Ԥ��ϵͳ��          \n");
    toxy(40,6);
    printf("==========================================\n");
    toxy(40,7);
    printf("||		1.�ÿ͵�½		||\n");
    toxy(40,8);
    printf("||		2.��ҵ�½		||\n");
    toxy(40,9);
    printf("||		3.�˳�ϵͳ		||\n");
    toxy(40,10);
    printf("==========================================\n");
    toxy(40,11);
    printf("������һ��1��3����\n");
    page=1;
	while(1)
	{
		if(!scanf("%d",&a))   //���û����%d����ʽ���룬scanf�ķ���ֵӦ����0
		{
			printf("���֣���!ɵð��\n");
			fflush(stdin);//����������뻺��
			continue;
		}
    	switch(a)
    	{
     		case 1:passenger_login();break;
      		case 2:shop_login();break;
      		case 3:exit(0);break;
      		default:printf("��������ȷ��ָ�\n");
   		}
		if(a>0&&a<4)break;
	}
}
void passenger_login()//�û���¼
{
    int i;
    int flag=0;
    int m,n;
    int flag1=0;

    char password_co[100];
    system("cls");
    printf("��ӭ������½ϵͳ��         \n");
    while(1)
    {
        printf("�������˺ţ�\n");
        scanf("%s",username_co);
        for(i=0;i<100;i++)
        {
            if(!strcmp(username_co,passenger[i].username)) //�ȶ�������û����Ƿ��ڽṹ���д���
            {
                flag=1;                //flag����¼�Ƿ�ƥ�䵽��������û���
                flag1=i;  //���¸��û������������������Ӧ������
            }
        }
        if(!flag)
        {
            printf("�Ҳ������û���\n");
            printf("1.������һ��  2.��������\n");
loop:     if(scanf("%d",&m))
            {

                if(m==1)
                {
                    system("cls");
                    menu();
                }
                else if(m!=2)
                {
                    printf("������1��2!\n");  //��ʾӦ������1��2����Ҫ���û���������
                    fflush(stdin);
                    goto loop;
                }
            }
            else
            {
                printf("���������֣���\n"); //��ʾ�û���������
                fflush(stdin);
                goto loop;
            }

        }
        else  //����ҵ����û����������ò������������׶�
        {
            break;
        }
    }
    while(1)
    {
        printf("������������룺\n");
        scanf("%s",password_co);
        if(!strcmp(password_co,passenger[flag1].password))
        {
            printf("��½�ɹ���\n");//�������������
            break;
        }
        else
        {
            printf("���������������Ƿ��������룿\n");
            printf("1.������һ��      2.��������\n");
    loop2:   if(scanf("%d",&n))
             {
                if(n==1)
                {
                    system("cls");
                    menu();
                }
                else if(n!=2)
                {
                    printf("������1��2��\n");
                    fflush(stdin);
                    goto loop2;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                printf("���������֣�\n");
                fflush(stdin);
                goto loop2;
            }
        }
    }
            strcpy(loginer_pass,passenger[flag].username);
            Sleep(1000);
            menu_pass();

}
void shop_login()//��ҵ�¼
{
    int i;
    int flag=0;
    int m,n;
    int flag1=0;

    char password_co[100];
    system("cls");
    printf("��ӭ������½ϵͳ��         \n");
    while(1)
    {
        printf("�������˺ţ�\n");
        scanf("%s",username_co);
        for(i=0;i<100;i++)
        {
            if(!strcmp(username_co,shop[i].username))
            {
                flag++;
                flag1=i;
            }
        }
        if(!flag)
        {
            printf("�Ҳ������û���\n");
            printf("1.������һ��  2.��������\n");
loop:     if(scanf("%d",&m))
            {

                if(m==1)
                {
                    system("cls");
                    menu();
                }
                else if(m!=2)
                {
                    printf("������1��2!\n");
                    fflush(stdin);
                    goto loop;
                }
            }
            else
            {
                printf("���������֣���\n");
                fflush(stdin);
                goto loop;
            }

        }
        else
        {
            break;
        }
    }
    while(1)
    {
        printf("������������룺\n");
        scanf("%s",password_co);
        if(!strcmp(password_co,shop[flag1].password))
        {
            printf("��½�ɹ���\n");//�������������
            break;
        }
        else
        {
            printf("���������������Ƿ��������룿\n");
            printf("1.������һ��      2.��������\n");
    loop2:   if(scanf("%d",&n))
             {
                if(n==1)
                {
                    system("cls");
                    menu();
                }
                else if(n!=2)
                {
                    printf("������1��2��\n");
                    fflush(stdin);
                    goto loop2;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                printf("���������֣�\n");
                fflush(stdin);
                goto loop2;
            }
        }
    }
    shop_menu();
}
void predo()//�ļ�����
{
    int i=0;
    int j=0;
    int q=0;
    int z=0;
    int m=0;
fp_login_passenger=fopen("login_passenger.txt","rt+");
fp_login_shop=fopen("login_shop.txt","rb");
fp_passenger_information=fopen("passenger_information.txt","rt+");
fp_hotel_room=fopen("hotel_room.txt","rt+");
fp_killpass=fopen("killpass.txt","rt+");

while(!feof(fp_login_passenger)) //���ļ��ж�ȡ���ݵ��ṹ��
    {
        fscanf(fp_login_passenger,"%s%s",passenger[i].username,passenger[i].password);
        i++;
    }
while(!feof(fp_login_shop)) //���ļ��ж�ȡ���ݵ��ṹ��
    {
        fscanf(fp_login_shop,"%s%s",shop[j].username,shop[j].password);
        j++;
    }
while(!feof(fp_hotel_room)) //���ļ��ж�ȡ���ݵ��ṹ��
    {
        fscanf(fp_hotel_room,"%s%s%s%s%s%s%s%s%s%s%s%s%s",room[z].character,room[z].room_num,room[z].price,room[z].square,room[z].window,room[z].VIP,room[z].bathroom,room[z].air_condition,room[z].booker,room[z].floor,room[z].shop_owner,room[z].xuhao,room[z].shashuprice);
        z++;
    }
while(!feof(fp_passenger_information)) //���ļ��ж�ȡ���ݵ��ṹ��
    {
        fscanf(fp_passenger_information,"%s%s%s%s",passengeri[q].name,passengeri[q].ID_number,passengeri[q].phone_number,passengeri[q].owner);
        q++;
    }
while(!feof(fp_killpass)) //���ļ��ж�ȡ���ݵ��ṹ��
    {
        fscanf(fp_killpass,"%s%d%d%d",killpass[m].username_killered,&killpass[m].hotel_killer1,&killpass[m].hotel_killer2,&killpass[m].hotel_killer3);
        m++;
    }
}
int returnf(int page)//���غ��������ص���ҳ��
{
    if(page==1)
    {
        system("cls");
        menu();
    }
    return 0;
}
int returnf1(int page)//���غ��������ص��˿�ҳ��
{
    if(page==1)
    {
        system("cls");
        menu_pass();
    }
    return 0;
}

void passenger_inf()//��ѯ���ú���
{
    system("cls");
    int i;
    int flag=0;
    char room_number[100];
    printf("��ӡ�㶨�����з��䣬��������Ҫ��ѯ�ķ���ţ�\n");
    scanf("%s",room_number);
    for(i=1;i<26;i++)
    {
        if(!strcmp(loginer_pass,room[i].booker))//loginer_passΪ��ǰ���ڵ�½ϵͳ���û�
        {
            if(!strcmp(room_number,room[i].room_num))//��ӡ�������û����󷿼����������Ǹ��û�Ԥ���ķ���
            {
                printf("���     ����     �����     �۸�     ���      �Ƿ��д�     �Ƿ���ԡ��     �Ƿ��пյ�     ¥��     �Ƶ�\n");
                printf("%s.%s  %s  %s  %s  %s  %s  %s  %s  %s\n",room[i].xuhao,room[i].character,room[i].room_num,room[i].price,room[i].square,room[i].window,room[i].bathroom,room[i].air_condition,room[i].floor,room[i].shop_owner);
            }
        }
    }
    if(flag==0)
    {
        printf("û���ҵ������Ϣ\n");
    }

}
void book()//Ԥ��
{
    system("cls");//��������
    int i=0;//¼��洢���ã�switch��
    int j,j1=0;//ѭ���������书���б�������ɸѡʱ
    int ding=0;//����Ԥ���ķ�����
    int k=0;//switchѡ�����ã����������о���������������ѡ��
    int m=0;//switchѡ�����ã����������о�������¥��ѡ��
    int p,p1=0;//Ԥ����ȷ�о�����������ѡ��
    int h,h2;//h�����¼���ѭ����h1ɱ��ϵͳ��ѭ�� h2��¼����ĸ�����Ϣ��λ�ô�ӡ���ļ�
    int s;
    int flag1=0;
loopA:printf("��ӭ�����õ�Ԥ��ϵͳ��ѡ������Ҫ�ľƵ�\n");
    printf("1.�����ù�\n");
    printf("2.��Ϫ�Ƶ�\n");
    printf("3.��ұ���\n");
	printf("4.�ص����˵�\n");
	printf("5.�ص��û��˵�\n");
	while(1)
	{
		if(!scanf("%d",&i))
		{
			printf("���֣���!\n");
			fflush(stdin);
			continue;
		}
    	switch(i)
    	{
        	case 1: strcpy(shop_choice,hotel1);break;
        	case 2: strcpy(shop_choice,hotel2);break;
        	case 3: strcpy(shop_choice,hotel3);break;
			case 4:returnf(1);break;
			case 5:returnf1(1);break;
        	default: printf("����������\n");break;
    	}
		if(i>0&&i<6)break;
	}
 loop9: printf("�밴�����������������Ҫ�ľƵ�\n");
    printf("����           ���        \n");
    printf("1.����         5.14ƽ��     \n");
    printf("2.��ͥ         6.60ƽ��     \n");
    printf("3.����         7.80ƽ��     \n");
	printf("4.�ص����˵�            \n");
	printf("5.�ص��û��˵�            \n");
	printf("6.�ص���һ��           \n");
	while(1)
	{
		if(!scanf("%d",&k))
		{
			printf("���֣���!\n");
			fflush(stdin);
			continue;
		}
		switch(k)
		{
			case 1:system("1.jpg");strcpy(shop_ch,chara1);break;//����ͼƬ�ͽ�ѡ����Ϣ�������飬�����ɸѡʹ��
			case 2:system("2.jpg");strcpy(shop_ch,chara2);break;//����ͼƬ�ͽ�ѡ����Ϣ�������飬�����ɸѡʹ��
			case 3:system("3.jpg");strcpy(shop_ch,chara3);break;//����ͼƬ�ͽ�ѡ����Ϣ�������飬�����ɸѡʹ��
			case 4:returnf(1);break;
			case 5:returnf1(1);break;
			case 6:system("cls");goto loopA;break;
			default :printf("����������");break;
		}
		if(k>0&&k<7)break;
	}
	printf("������¥��(1~3)��\n");
	while(1)
	{
		if(!scanf("%d",&m))
		{
			printf("���֣���!\n");
			fflush(stdin);
			continue;
		}
		switch(m)
		{
			case 1:strcpy(shop_fl,flo1);break;
			case 2:strcpy(shop_fl,flo2);break;
			case 3:strcpy(shop_fl,flo3);break;
			default :printf("����������");break;
		}
		if(m>0&&m<4)break;
	}
	int killpass_flag=0;
	int q;
	for(q=100000;q>=0;q--)
    {
        if(!strcmp(loginer_pass,killpass[q].username_killered))
            if((killpass[q].hotel_killer1>=2&&!strcmp(shop_choice,hotel1))||(killpass[q].hotel_killer2>=2&&!strcmp(shop_choice,hotel2))||(killpass[q].hotel_killer3>=2&&!strcmp(shop_choice,hotel3)))
            {
                killpass_flag=1;
            }
    }
	printf("   ����    �����    �۸�    ���     �Ƿ��д�    �Ƿ���ԡ��     �Ƿ��пյ�    ¥��       �Ƶ�\n");
	for(j=0;j<50;j++)//ѭ��ɸѡ
    {
        if(!strcmp(shop_choice,room[j].shop_owner))
            if(!strcmp(shop_ch,room[j].character))
                if(!strcmp(shop_fl,room[j].floor))
                {
                    if(!strcmp(room[j].booker,none))
                        {
                            switch(killpass_flag)
                                {
                                    case 1 :printf("%d.%s    %s         %s      %s        %s       %s              %s             %s        %s\n",j,room[j].character,room[j].room_num,room[j].shashuprice,room[j].square,room[j].window,room[j].bathroom,room[j].air_condition,room[j].floor,room[j].shop_owner);break;
                                    case 0: printf("%d.%s    %s         %s       %s       %s        %s             %s             %s         %s\n",j,room[j].character,room[j].room_num,room[j].price,room[j].square,room[j].window,room[j].bathroom,room[j].air_condition,room[j].floor,room[j].shop_owner);break;
                                }

                                j1=1;
                            for(p=0;p<50;p++)
                            {
                                    if(room_n[p]==-1)
                                {
                                    room_n[p]=j;
                                    break;
                                }
                                    else
                                {
                                    room_n[p+1]=j;
                                    break;
                                }
                            }
                        }
                }
    }
                if(!j1)
                {
                    printf("δ�ҵ�����Ҫ�ķ���!\n");
                    fflush(stdin);
                    goto loop9;
                }
    printf("��ѡ������Ԥ���ķ��䣺\n");
    loop10:   scanf("%d",&ding);
        for(p=0;p<=50;p++)
    {
        if(room_n[p]==ding)
        {
            strcpy(room[ding].booker,loginer_pass);//�����ǲ������ô�ӡ����
            p1=1;
        }
    }
   if(p1==0)
   {
       printf("�������룡\n");
       fflush(stdin);
       goto loop10;
   }
    printf("���������������\n");
    for(h=1;h<=27;h++)
    {
        if(!strlen(passengeri[h].name))
            {
                fflush(stdin);
                scanf("%s",passengeri[h].name);
                h2=h;
                break;
            }
    }
    printf("������������֤�ţ�\n");
    for(h=1;h<=27;h++)
    {
        if(!strlen(passengeri[h].ID_number))
            {
                fflush(stdin);
                scanf("%s",passengeri[h].ID_number);
                h2=h;
                break;
            }
    }

    printf("����������ֻ��ţ�\n");
    for(h=1;h<=27;h++)
    {
        if(!strlen(passengeri[h].phone_number))
            {
                fflush(stdin);
                scanf("%s",passengeri[h].phone_number);
                h2=h;
                strcpy(passengeri[h].owner,loginer_pass);
                break;
            }
    }
      for(i=1;i<50;i++)
        {
            if(!strlen(passengeri[i].name))
              {
                fprintf(fp_passenger_information,"%s   %s   %s   %s\n",passengeri[h2].name,passengeri[h2].ID_number,passengeri[h2].phone_number,loginer_pass);
                if(!strlen(passengeri[i].name))
                break;
              }
        }
    for(s=100;s>0;s--)
    {
        if(!strcmp(killpass[s].username_killered,loginer_pass))//�ĵ����Ѿ��м�¼
        {
            flag1++;
            if(!strcmp(shop_choice,hotel1))
                {
                    killpass[s].hotel_killer1++;
                    break;
                }
            else if(!strcmp(shop_choice,hotel2))
                {
                    killpass[s].hotel_killer2++;
                    break;
                }
            else if(!strcmp(shop_choice,hotel3))
                {
                    killpass[s].hotel_killer3++;
                    break;
                }
            else

                {
                    printf("%s\n%s\n",killpass[s].username_killered,loginer_pass);
                }
                break;
        }
    }
    switch(flag1)
    {
        case 0:
        {
            fprintf(fp_killpass,"%s  ",loginer_pass);
            if(!strcmp(shop_choice,hotel1))
                fprintf(fp_killpass,"%d ",yi);
            else
                fprintf(fp_killpass,"%d ",ling);

            if(!strcmp(shop_choice,hotel2))
                fprintf(fp_killpass,"%d ",yi);
            else
                fprintf(fp_killpass,"%d ",ling);

            if(!strcmp(shop_choice,hotel3))
                fprintf(fp_killpass,"%d\n",yi);
            else
                {
                    fprintf(fp_killpass,"%d\n",ling);
                }
                break;
        }
       default :fprintf(fp_killpass,"%s  %d   %d   %d\n",loginer_pass,killpass[s].hotel_killer1,killpass[s].hotel_killer2,killpass[s].hotel_killer3);
    }
   xiugai();
 printf("�ɹ�Ԥ����\n");
 Sleep(1000);
 exit(0);

}
void menu_pass()//�û���¼��Ĳ˵�
{
	int a;
	Sleep(1000);
	system("cls");
	toxy(35,5);
	printf("----------------------------------------------------------\n");
	toxy(35,6);
    printf("$			1.Ԥ������			$\n");
    toxy(35,7);
    printf("$			2.��ѯ��Ϣ			$\n");
    toxy(35,8);
    printf("$			3.�˷�				$\n");
    toxy(35,9);
	printf("$			4.���ز˵�			$\n");
	toxy(35,10);
	printf("----------------------------------------------------------\n");
	toxy(35,11);
	printf("������һ��1��4����\n");
	while(1)
	{
		if(!scanf("%d",&a))
			{
				printf("���֣���!\n");
				fflush(stdin);
				continue;
			}
		switch(a)
		{
			case 1:book();break;
			case 2:chaxun();break;
			case 3:tuifang();break;
			case 4:returnf(page);break;
			default :printf("������Ҫ������������\n");
		}
		if(a>0&&a<5)break;
	}
}
void xiugai()
{
    int z;
    fp_hotel_room=fopen("hotel_room.txt","w");
    for(z=0;z<26;z++)
    {
        fprintf(fp_hotel_room,"%s          %s      %s      %s      %s      %s       %s      %s      %s     %s      %s    %s     %s\n",room[z].character,room[z].room_num,room[z].price,room[z].square,room[z].window,room[z].VIP,room[z].bathroom,room[z].air_condition,room[z].booker,room[z].floor,room[z].shop_owner,room[z].xuhao,room[z].shashuprice);
    }
}
void room_xinxi()
{
	fp_hotel_room=fopen("hotel_room.txt","r");
		int c;
		int a;
		while((c=fgetc(fp_hotel_room))!=EOF) putchar(c);
		printf("��1�ص��˵������������˳�ϵͳ\n");
		if(scanf("%d",&a))
        {
            if(a==1)
            {
                system("cls");
                menu();
            }
        }
}
void shop_menu()
{
    int a;
	Sleep(1000);
	system("cls");
	toxy(35,5);
	printf("----------------------------------------------------------\n");
	toxy(35,6);
    printf("$			1.��ѯ��Ϣ			$\n");
    toxy(35,7);
	printf("$			2.���ز˵�			$\n");
	toxy(35,8);
	printf("----------------------------------------------------------\n");
	printf("������һ��1��2����\n");
	while(1)
	{
		if(!scanf("%d",&a))
			{
				printf("���֣���!\n");
				fflush(stdin);
				continue;
			}
		switch(a)
		{
			case 1:room_xinxi();break;
			case 2:returnf(1);break;
			default :printf("������Ҫ������������\n");
		}
		if(a>0&&a<3)break;
	}
}
void tuifang()
{
    int num;
    int z1=0;
    printf("������Ҫ�˶��ķ������:\n");
    while(1)
    {
        getchar();
        if(scanf("%d",&num))
       {
           printf("%d",num);
        if(!strcmp(room[num].booker,username_co))
        {
            strcpy(room[num].booker,none);
            xiugai();
            printf("�˶��ɹ�\n");
            break;
            z1=1;
        }
        else
        {
            printf("�ⲻ����ķ���,��������\n");
        }
        if(z1)break;
       }
       else
       {
           printf("���֣�����ɵð����\n");
       }
    }
}
void humingchaxun()
{
    system("cls");
    int a;
    printf("   ����     �����     �۸�     ���      �Ƿ��д�     �Ƿ���ԡ��     �Ƿ��пյ�     ¥��       �Ƶ�\n");
    int j,flag=0;
    for(j=1;j<27;j++)
    {
            if(!strcmp(room[j].booker,username_co))
        {
            flag=1;
            printf("%d.%s       %s         %s        %s        %s           %s             %s             %s        %s\n",j,room[j].character,room[j].room_num,room[j].price,room[j].square,room[j].window,room[j].bathroom,room[j].air_condition,room[j].floor,room[j].shop_owner);
        }
    }
    if(!flag)
    {
        system("cls");printf("û�з���\n");
    }
    printf("===================================\n");
    printf("1.ѡ���˷�    2.������һ��   3.�˳�����\n");
    while(1)
	{
		if(!scanf("%d",&a))   //���û����%d����ʽ���룬scanf�ķ���ֵӦ����0
		{
			printf("���֣���!ɵð��\n");
			fflush(stdin);//����������뻺��
			continue;
		}
    	switch(a)
    	{
     		case 1:tuifang();break;
      		case 2:chaxun();break;
      		case 3:exit(0);break;
      		default:printf("��������ȷ��ָ�\n");
   		}
		if(a>0&&a<4)break;
	}

}
void toxy(int x, int y)
{
    COORD pos = { x , y };
    HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out, pos);
}
void chaxun()
{
    system("cls");
    int a;
    toxy(35,5);
    printf("================================\n");
    toxy(35,6);
    printf("$        1.����Ų�ѯ         $\n");
    toxy(35,7);
    printf("$        2.���˻���ѯ         $\n");
    toxy(35,8);
    printf("$        3.�������˵�         $\n");
    toxy(35,9);
    printf("$        4.�����û��˵�       $\n");
    toxy(35,10);
    printf("================================\n");
    toxy(35,11);
    printf("������һ��1��4����\n");
	while(1)
	{
		if(!scanf("%d",&a))
			{
				printf("���֣���!\n");
				fflush(stdin);
				continue;
			}
		switch(a)
		{
			case 1:haomachaxun();break;
			case 2:humingchaxun();break;
			case 3:returnf(1);break;
			case 4:returnf1(1);break;
			default :printf("������Ҫ������������\n");
		}
		if(a>0&&a<5)break;
	}
}
void haomachaxun()
{
    int j,flag=0;
    int a;
    char haoma[100]={'\0'};
    printf("                     ����     �����     �۸�     ���      �Ƿ��д�     �Ƿ���ԡ��     �Ƿ��пյ�     ¥��       �Ƶ�\n");
    fflush(stdin);
    while(1)
    {
        printf("����Ҫ��ѯ�ķ���ţ�\n");
        scanf("%s",haoma);
        for(j=1;j<27;j++)
        {
            if(!strcmp(room[j].room_num,haoma))
                if(!strcmp(room[j].booker,loginer_pass))
            {
                flag++;
                printf("                  %d.%s       %s         %s        %s        %s           %s             %s             %s        %s\n",j,room[j].character,room[j].room_num,room[j].price,room[j].square,room[j].window,room[j].bathroom,room[j].air_condition,room[j].floor,room[j].shop_owner);
            }
        }

        if(!flag)
        {
            system("cls");printf("û�з���\n");
        }
        else
        break;
    }
   printf("===================================\n");
    printf("1.ѡ���˷�    2.������һ��   3.�˳�����\n");
    while(1)
	{
		if(!scanf("%d",&a))   //���û����%d����ʽ���룬scanf�ķ���ֵӦ����0
		{
			printf("���֣���!ɵð��\n");
			fflush(stdin);//����������뻺��
			continue;
		}
    	switch(a)
    	{
     		case 1:tuifang();break;
      		case 2:chaxun();break;
      		case 3:exit(0);break;
      		default:printf("��������ȷ��ָ�\n");
   		}
		if(a>0&&a<4)break;
	}
}


