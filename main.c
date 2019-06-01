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
char loginer_pass[100]={'\0'};  //用来储存当前登陆旅客的身份（用户名）用于打印用户信息等
char loginer_shop[100]={'\0'};   //用来储存当前登陆店家管理员的身份（用户名）
char shop_choice[100]={'\0'};//筛选用
char shop_ch[100]={'\0'};//筛选用
char shop_fl[100]={'\0'};//筛选用
char floor_choice[100]={'\0'};//筛选用

char none[10]={"无"};
char hotel1[100]={"青年旅馆"};
char hotel2[100]={"梦溪酒店"};
char hotel3[100]={"如家宾馆"};
char chara1[100]={"经济"};
char chara2[100]={"家庭"};
char chara3[100]={"豪华"};
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
void menu()//主菜单
{
    int a;
    printf("\n");
    printf("\n");
    toxy(40,5);    //一个定位函数，可从屏幕的该坐标点开始定位执行下一个语句
    printf("          欢迎来到酒店预订系统！          \n");
    toxy(40,6);
    printf("==========================================\n");
    toxy(40,7);
    printf("||		1.旅客登陆		||\n");
    toxy(40,8);
    printf("||		2.店家登陆		||\n");
    toxy(40,9);
    printf("||		3.退出系统		||\n");
    toxy(40,10);
    printf("==========================================\n");
    toxy(40,11);
    printf("请输入一个1到3的数\n");
    page=1;
	while(1)
	{
		if(!scanf("%d",&a))   //如果没有以%d的形式输入，scanf的返回值应该是0
		{
			printf("数字！！!傻冒！\n");
			fflush(stdin);//清除键盘输入缓存
			continue;
		}
    	switch(a)
    	{
     		case 1:passenger_login();break;
      		case 2:shop_login();break;
      		case 3:exit(0);break;
      		default:printf("请输入正确的指令！\n");
   		}
		if(a>0&&a<4)break;
	}
}
void passenger_login()//用户登录
{
    int i;
    int flag=0;
    int m,n;
    int flag1=0;

    char password_co[100];
    system("cls");
    printf("欢迎来到登陆系统！         \n");
    while(1)
    {
        printf("请输入账号：\n");
        scanf("%s",username_co);
        for(i=0;i<100;i++)
        {
            if(!strcmp(username_co,passenger[i].username)) //比对输入的用户名是否在结构体中存在
            {
                flag=1;                //flag法记录是否匹配到所输入的用户名
                flag1=i;  //记下该用户名的行数方便给出对应的密码
            }
        }
        if(!flag)
        {
            printf("找不到此用户！\n");
            printf("1.返回上一级  2.继续输入\n");
loop:     if(scanf("%d",&m))
            {

                if(m==1)
                {
                    system("cls");
                    menu();
                }
                else if(m!=2)
                {
                    printf("请输入1或2!\n");  //提示应该输入1和2并且要求用户重新输入
                    fflush(stdin);
                    goto loop;
                }
            }
            else
            {
                printf("请输入数字！！\n"); //提示用户输入数字
                fflush(stdin);
                goto loop;
            }

        }
        else  //如果找到有用户名就跳出该步骤进入输密码阶段
        {
            break;
        }
    }
    while(1)
    {
        printf("请输入你的密码：\n");
        scanf("%s",password_co);
        if(!strcmp(password_co,passenger[flag1].password))
        {
            printf("登陆成功！\n");//该语句后接主界面
            break;
        }
        else
        {
            printf("你输入的密码错误！是否重新输入？\n");
            printf("1.返回上一级      2.继续输入\n");
    loop2:   if(scanf("%d",&n))
             {
                if(n==1)
                {
                    system("cls");
                    menu();
                }
                else if(n!=2)
                {
                    printf("请输入1或2！\n");
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
                printf("请输入数字！\n");
                fflush(stdin);
                goto loop2;
            }
        }
    }
            strcpy(loginer_pass,passenger[flag].username);
            Sleep(1000);
            menu_pass();

}
void shop_login()//店家登录
{
    int i;
    int flag=0;
    int m,n;
    int flag1=0;

    char password_co[100];
    system("cls");
    printf("欢迎来到登陆系统！         \n");
    while(1)
    {
        printf("请输入账号：\n");
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
            printf("找不到此用户！\n");
            printf("1.返回上一级  2.继续输入\n");
loop:     if(scanf("%d",&m))
            {

                if(m==1)
                {
                    system("cls");
                    menu();
                }
                else if(m!=2)
                {
                    printf("请输入1或2!\n");
                    fflush(stdin);
                    goto loop;
                }
            }
            else
            {
                printf("请输入数字！！\n");
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
        printf("请输入你的密码：\n");
        scanf("%s",password_co);
        if(!strcmp(password_co,shop[flag1].password))
        {
            printf("登陆成功！\n");//该语句后接主界面
            break;
        }
        else
        {
            printf("你输入的密码错误！是否重新输入？\n");
            printf("1.返回上一级      2.继续输入\n");
    loop2:   if(scanf("%d",&n))
             {
                if(n==1)
                {
                    system("cls");
                    menu();
                }
                else if(n!=2)
                {
                    printf("请输入1或2！\n");
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
                printf("请输入数字！\n");
                fflush(stdin);
                goto loop2;
            }
        }
    }
    shop_menu();
}
void predo()//文件定义
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

while(!feof(fp_login_passenger)) //从文件中读取数据到结构体
    {
        fscanf(fp_login_passenger,"%s%s",passenger[i].username,passenger[i].password);
        i++;
    }
while(!feof(fp_login_shop)) //从文件中读取数据到结构体
    {
        fscanf(fp_login_shop,"%s%s",shop[j].username,shop[j].password);
        j++;
    }
while(!feof(fp_hotel_room)) //从文件中读取数据到结构体
    {
        fscanf(fp_hotel_room,"%s%s%s%s%s%s%s%s%s%s%s%s%s",room[z].character,room[z].room_num,room[z].price,room[z].square,room[z].window,room[z].VIP,room[z].bathroom,room[z].air_condition,room[z].booker,room[z].floor,room[z].shop_owner,room[z].xuhao,room[z].shashuprice);
        z++;
    }
while(!feof(fp_passenger_information)) //从文件中读取数据到结构体
    {
        fscanf(fp_passenger_information,"%s%s%s%s",passengeri[q].name,passengeri[q].ID_number,passengeri[q].phone_number,passengeri[q].owner);
        q++;
    }
while(!feof(fp_killpass)) //从文件中读取数据到结构体
    {
        fscanf(fp_killpass,"%s%d%d%d",killpass[m].username_killered,&killpass[m].hotel_killer1,&killpass[m].hotel_killer2,&killpass[m].hotel_killer3);
        m++;
    }
}
int returnf(int page)//返回函数，返回到主页面
{
    if(page==1)
    {
        system("cls");
        menu();
    }
    return 0;
}
int returnf1(int page)//返回函数，返回到顾客页面
{
    if(page==1)
    {
        system("cls");
        menu_pass();
    }
    return 0;
}

void passenger_inf()//查询所用函数
{
    system("cls");
    int i;
    int flag=0;
    char room_number[100];
    printf("打印你定的所有房间，请输入你要查询的房间号：\n");
    scanf("%s",room_number);
    for(i=1;i<26;i++)
    {
        if(!strcmp(loginer_pass,room[i].booker))//loginer_pass为当前正在登陆系统的用户
        {
            if(!strcmp(room_number,room[i].room_num))//打印出所有用户所大房间号相符并且是该用户预订的房间
            {
                printf("序号     类型     房间号     价格     面积      是否有窗     是否有浴室     是否有空调     楼层     酒店\n");
                printf("%s.%s  %s  %s  %s  %s  %s  %s  %s  %s\n",room[i].xuhao,room[i].character,room[i].room_num,room[i].price,room[i].square,room[i].window,room[i].bathroom,room[i].air_condition,room[i].floor,room[i].shop_owner);
            }
        }
    }
    if(flag==0)
    {
        printf("没有找到你的信息\n");
    }

}
void book()//预定
{
    system("cls");//清屏函数
    int i=0;//录入存储所用，switch中
    int j,j1=0;//循环计数及其功能判别条件，筛选时
    int ding=0;//你想预定的房间名
    int k=0;//switch选择所用，及其跳出判决条件，房间类型选择
    int m=0;//switch选择所用，及其跳出判决条件，楼层选择
    int p,p1=0;//预定正确判决条件，最后的选择
    int h,h2;//h是身份录入的循环。h1杀熟系统的循环 h2记录输入的个人信息的位置打印到文件
    int s;
    int flag1=0;
loopA:printf("欢迎来到旅店预订系统，选择你想要的酒店\n");
    printf("1.青年旅馆\n");
    printf("2.梦溪酒店\n");
    printf("3.如家宾馆\n");
	printf("4.回到主菜单\n");
	printf("5.回到用户菜单\n");
	while(1)
	{
		if(!scanf("%d",&i))
		{
			printf("数字！！!\n");
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
        	default: printf("请重新输入\n");break;
    	}
		if(i>0&&i<6)break;
	}
 loop9: printf("请按照下面的类别检索你想要的酒店\n");
    printf("类型           面积        \n");
    printf("1.经济         5.14平米     \n");
    printf("2.家庭         6.60平米     \n");
    printf("3.豪华         7.80平米     \n");
	printf("4.回到主菜单            \n");
	printf("5.回到用户菜单            \n");
	printf("6.回到上一级           \n");
	while(1)
	{
		if(!scanf("%d",&k))
		{
			printf("数字！！!\n");
			fflush(stdin);
			continue;
		}
		switch(k)
		{
			case 1:system("1.jpg");strcpy(shop_ch,chara1);break;//插入图片和将选择信息存入数组，存入后筛选使用
			case 2:system("2.jpg");strcpy(shop_ch,chara2);break;//插入图片和将选择信息存入数组，存入后筛选使用
			case 3:system("3.jpg");strcpy(shop_ch,chara3);break;//插入图片和将选择信息存入数组，存入后筛选使用
			case 4:returnf(1);break;
			case 5:returnf1(1);break;
			case 6:system("cls");goto loopA;break;
			default :printf("请重新输入");break;
		}
		if(k>0&&k<7)break;
	}
	printf("请输入楼层(1~3)：\n");
	while(1)
	{
		if(!scanf("%d",&m))
		{
			printf("数字！！!\n");
			fflush(stdin);
			continue;
		}
		switch(m)
		{
			case 1:strcpy(shop_fl,flo1);break;
			case 2:strcpy(shop_fl,flo2);break;
			case 3:strcpy(shop_fl,flo3);break;
			default :printf("请重新输入");break;
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
	printf("   类型    房间号    价格    面积     是否有窗    是否有浴室     是否有空调    楼层       酒店\n");
	for(j=0;j<50;j++)//循环筛选
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
                    printf("未找到你想要的房间!\n");
                    fflush(stdin);
                    goto loop9;
                }
    printf("请选择你想预订的房间：\n");
    loop10:   scanf("%d",&ding);
        for(p=0;p<=50;p++)
    {
        if(room_n[p]==ding)
        {
            strcpy(room[ding].booker,loginer_pass);//下面是测试所用打印函数
            p1=1;
        }
    }
   if(p1==0)
   {
       printf("重新输入！\n");
       fflush(stdin);
       goto loop10;
   }
    printf("请输入你的姓名：\n");
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
    printf("请输入你的身份证号：\n");
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

    printf("请输入你的手机号：\n");
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
        if(!strcmp(killpass[s].username_killered,loginer_pass))//文档里已经有记录
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
 printf("成功预订！\n");
 Sleep(1000);
 exit(0);

}
void menu_pass()//用户登录后的菜单
{
	int a;
	Sleep(1000);
	system("cls");
	toxy(35,5);
	printf("----------------------------------------------------------\n");
	toxy(35,6);
    printf("$			1.预订房间			$\n");
    toxy(35,7);
    printf("$			2.查询信息			$\n");
    toxy(35,8);
    printf("$			3.退房				$\n");
    toxy(35,9);
	printf("$			4.返回菜单			$\n");
	toxy(35,10);
	printf("----------------------------------------------------------\n");
	toxy(35,11);
	printf("请输入一个1到4的数\n");
	while(1)
	{
		if(!scanf("%d",&a))
			{
				printf("数字！！!\n");
				fflush(stdin);
				continue;
			}
		switch(a)
		{
			case 1:book();break;
			case 2:chaxun();break;
			case 3:tuifang();break;
			case 4:returnf(page);break;
			default :printf("不符合要求，请重新输入\n");
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
		printf("按1回到菜单，按其它键退出系统\n");
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
    printf("$			1.查询信息			$\n");
    toxy(35,7);
	printf("$			2.返回菜单			$\n");
	toxy(35,8);
	printf("----------------------------------------------------------\n");
	printf("请输入一个1到2的数\n");
	while(1)
	{
		if(!scanf("%d",&a))
			{
				printf("数字！！!\n");
				fflush(stdin);
				continue;
			}
		switch(a)
		{
			case 1:room_xinxi();break;
			case 2:returnf(1);break;
			default :printf("不符合要求，请重新输入\n");
		}
		if(a>0&&a<3)break;
	}
}
void tuifang()
{
    int num;
    int z1=0;
    printf("请输入要退订的房间序号:\n");
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
            printf("退订成功\n");
            break;
            z1=1;
        }
        else
        {
            printf("这不是你的房间,重新输入\n");
        }
        if(z1)break;
       }
       else
       {
           printf("数字！！！傻冒！！\n");
       }
    }
}
void humingchaxun()
{
    system("cls");
    int a;
    printf("   类型     房间号     价格     面积      是否有窗     是否有浴室     是否有空调     楼层       酒店\n");
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
        system("cls");printf("没有房间\n");
    }
    printf("===================================\n");
    printf("1.选择退房    2.返回上一级   3.退出程序\n");
    while(1)
	{
		if(!scanf("%d",&a))   //如果没有以%d的形式输入，scanf的返回值应该是0
		{
			printf("数字！！!傻冒！\n");
			fflush(stdin);//清除键盘输入缓存
			continue;
		}
    	switch(a)
    	{
     		case 1:tuifang();break;
      		case 2:chaxun();break;
      		case 3:exit(0);break;
      		default:printf("请输入正确的指令！\n");
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
    printf("$        1.房间号查询         $\n");
    toxy(35,7);
    printf("$        2.此账户查询         $\n");
    toxy(35,8);
    printf("$        3.返回主菜单         $\n");
    toxy(35,9);
    printf("$        4.返回用户菜单       $\n");
    toxy(35,10);
    printf("================================\n");
    toxy(35,11);
    printf("请输入一个1到4的数\n");
	while(1)
	{
		if(!scanf("%d",&a))
			{
				printf("数字！！!\n");
				fflush(stdin);
				continue;
			}
		switch(a)
		{
			case 1:haomachaxun();break;
			case 2:humingchaxun();break;
			case 3:returnf(1);break;
			case 4:returnf1(1);break;
			default :printf("不符合要求，请重新输入\n");
		}
		if(a>0&&a<5)break;
	}
}
void haomachaxun()
{
    int j,flag=0;
    int a;
    char haoma[100]={'\0'};
    printf("                     类型     房间号     价格     面积      是否有窗     是否有浴室     是否有空调     楼层       酒店\n");
    fflush(stdin);
    while(1)
    {
        printf("输入要查询的房间号：\n");
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
            system("cls");printf("没有房间\n");
        }
        else
        break;
    }
   printf("===================================\n");
    printf("1.选择退房    2.返回上一级   3.退出程序\n");
    while(1)
	{
		if(!scanf("%d",&a))   //如果没有以%d的形式输入，scanf的返回值应该是0
		{
			printf("数字！！!傻冒！\n");
			fflush(stdin);//清除键盘输入缓存
			continue;
		}
    	switch(a)
    	{
     		case 1:tuifang();break;
      		case 2:chaxun();break;
      		case 3:exit(0);break;
      		default:printf("请输入正确的指令！\n");
   		}
		if(a>0&&a<4)break;
	}
}


