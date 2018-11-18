#ifndef CONTROL_BLOCK_CHOICE_H_INCLUDED
#define CONTROL_BLOCK_CHOICE_H_INCLUDED

extern int map_block[7][8];
extern char key_button[9];
extern int map_mountain[6];
extern HERO py[3];///记录了参加游戏的角色

void control_block_choice(int,int,int);
void hero_action1(int,int*,int,int);
void hero_action2(int,int,int);
void block_choice_explore_p(int);
void block_choice_explore_f(int);
void mountain_spy(int);
void mountain_reward(int);
void mountain_mission(int);

void control_block_choice(int n,int a,int b)
{
    SetPos(113,33);printf(" >选择进行行动");
    if(map_block[a][b]%100>=10&&map_block[a][b]%100<20)
    {
        SetPos(113,34);printf("                ");
        SetPos(113,35);printf("                ");
        SetPos(113,34);printf("  (%c) 休息",key_button[7]);
    }
    if(map_block[a][b]%100>=20&&map_block[a][b]%100<30)
    {
        SetPos(113,34);printf("                ");
        SetPos(113,35);printf("                ");
        SetPos(113,34);printf("      无事可做");
    }
    if(map_block[a][b]%100>=30&&map_block[a][b]%100<40)
    {
        SetPos(113,34);printf("                ");
        SetPos(113,35);printf("                ");
        SetPos(113,34);printf("  (%c) 冒险",key_button[7]);
    }
    if(map_block[a][b]%100>=40&&map_block[a][b]%100<50)
    {
        SetPos(113,34);printf("                ");
        SetPos(113,35);printf("                ");
        SetPos(113,34);printf("  (%c) 冒险",key_button[7]);
        Ninja_Res(&py[n]);
    }
    if(map_block[a][b]/100>0)
    {
        SetPos(113,35);printf("  (%c) 侦查/挑战",key_button[8]);
        int add_temp;///用于记录本次该山附近英雄编码
        switch(map_block[a][b]/100)
        {
            case 1:
                add_temp=map_block[0][3]%10+map_block[1][4]%10+map_block[1][5]%10;
                map_mountain[1]+=add_temp;
                break;
            case 2:
                add_temp=map_block[1][0]%10+map_block[2][1]%10+map_block[3][1]%10+map_block[3][0]%10;
                map_mountain[2]+=add_temp;
                break;
            case 3:
                add_temp=map_block[1][2]%10+map_block[1][3]%10+map_block[2][2]%10+map_block[2][4]%10+map_block[3][3]%10+map_block[3][4]%10;
                map_mountain[3]+=add_temp;
                break;
            case 4:
                add_temp=map_block[2][6]%10+map_block[3][6]%10+map_block[4][7]%10;
                map_mountain[4]+=add_temp;
                break;
            case 5:
                add_temp=map_block[6][6]%10+map_block[5][6]%10+map_block[5][7]%10;
                map_mountain[5]+=add_temp;
                break;
            default:break;
        }
        hero_action1(n,&map_mountain[map_block[a][b]/100],a,b);
        map_mountain[map_block[a][b]/100]-=add_temp;///将山上的英雄编码去除，保证下次运行正确
    }
    else
    {
        hero_action2(n,a,b);
    }
}

void hero_action1(int n,int *mountain_num,int a,int b)
{
    int ch;
    while (1)
    {
        if(map_block[a][b]%100>=30&&map_block[a][b]%100<40)///在平原，冒险 山的附近，侦查/挑战
        {
            if (_kbhit())
            {//如果有按键按下，则_kbhit()函数返回真
                ch = _getch();//使用_getch()函数获取按下的键值
                if(ch==key_button[7])///冒险
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("平原冒险!");
                    block_choice_explore_p(n);
                    break;
                }
                if(ch==key_button[8])///侦查/挑战
                {
                    if((*mountain_num)%100<10)
                    {
                        emergency_decoration(2);
                        SetPos(6,44);printf("侦查!");
                        (*mountain_num)+=10;
                        mountain_spy(*mountain_num);
                    }
                    else
                    {
                        emergency_decoration(2);
                        SetPos(6,44);printf("挑战! ");
                        mission_choice(n,*mountain_num);///进行挑战，传入发起者序号(0 1 2)和山的特征值
                    }
                    break;
                }
            }
        }
        if(map_block[a][b]%100>=40&&map_block[a][b]%100<50)///在森林，冒险 山的附近，侦查/挑战
        {
            if (_kbhit())
            {//如果有按键按下，则_kbhit()函数返回真
                ch = _getch();//使用_getch()函数获取按下的键值
                if(ch==key_button[7])///冒险
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("森林冒险!");
                    block_choice_explore_f(n);
                    break;
                }
                if(ch==key_button[8])///侦查/挑战
                {
                    if((*mountain_num)%100<10)
                    {
                        emergency_decoration(2);
                        SetPos(6,44);printf("侦查!");
                        (*mountain_num)+=10;
                        mountain_spy(*mountain_num);
                    }
                    else
                    {
                        emergency_decoration(2);
                        SetPos(6,44);printf("挑战! ");
                        mission_choice(n,*mountain_num);///进行挑战，传入发起者序号(0 1 2)和山的特征值
                    }
                    break;
                }
            }
        }
    }
}

void hero_action2(int n,int a,int b)
{
    int ch;
    while (1)
    {
        if(map_block[a][b]%100>=20&&map_block[a][b]%100<30)///在道路上，无事可做
        {
            break;
        }
        if(map_block[a][b]%100>=10&&map_block[a][b]%100<20)///在城镇村，休息
        {
            if (_kbhit())
            {//如果有按键按下，则_kbhit()函数返回真
                ch = _getch();//使用_getch()函数获取按下的键值
                if(ch==key_button[7])
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("休息!");
                    HeroSleep(&py[n]); ///英雄休息函数
                    showPlayer(py[n]);
                    break;
                }
            }
        }
        if(map_block[a][b]%100>=30&&map_block[a][b]%100<40)///在平原，冒险
        {
            if (_kbhit())
            {//如果有按键按下，则_kbhit()函数返回真
                ch = _getch();//使用_getch()函数获取按下的键值
                if(ch==key_button[7])
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("平原冒险!");
                    block_choice_explore_p(n);///英雄冒险掷骰判定函数
                    break;
                }
            }
        }
        if(map_block[a][b]%100>=40&&map_block[a][b]%100<50)///在森林，冒险
        {
            if (_kbhit())
            {//如果有按键按下，则_kbhit()函数返回真
                ch = _getch();//使用_getch()函数获取按下的键值
                if(ch==key_button[7])
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("森林冒险!");
                    block_choice_explore_f(n);
                    break;
                }
            }
        }
    }
}

void block_choice_explore_p(int n)
{
    int temp;
    temp=HeroExplore(py[n].advP_P+ResAdd(&py[n]));Sleep(500);
    if(temp==1)
    {
        py[n].Exp++;py[n].lifeP--;
        ResGuard(&py[n],1); ///使用资源值进行防御的函数
        Levelup(&py[n]);
    }
    if(temp>=2)
    {
        py[n].Exp++;
        Levelup(&py[n]);
    }
    if(temp<=-1)
    {
        py[n].lifeP--;
        ResGuard(&py[n],1); ///使用资源值进行防御的函数
    }
    if(py[n].timeP==4&&py[n].lifeP<py[n].lifeMP)///角斗士平原冒险生命值回复
        py[n].lifeP++;
}

void block_choice_explore_f(int n)
{
    int temp;
    temp=HeroExplore(py[n].advP_F+ResAdd(&py[n]));Sleep(500);
    if(temp==1)
    {
        py[n].Exp++;py[n].lifeP--;
        ResGuard(&py[n],1); ///使用资源值进行防御的函数
        Levelup(&py[n]);
    }
    if(temp>=2)
    {
        py[n].Exp++;
        Levelup(&py[n]);
    }
    if(temp<=-1)
    {
        py[n].lifeP--;
        ResGuard(&py[n],1); ///使用资源值进行防御的函数
    }
}

void mountain_spy(int mountain)
{
    setColor(12,5);///深紫色背景，淡红色字符
    switch(mountain/10000)
    {
        case 1:
            SetPos(77,6);mountain_mission((mountain%1000)/100);
            SetPos(78,7);mountain_reward((mountain%10000)/1000);
            break;
        case 2:
            SetPos(17,16);mountain_mission((mountain%1000)/100);
            SetPos(18,17);mountain_reward((mountain%10000)/1000);
            break;
        case 3:
            SetPos(53,16);mountain_mission((mountain%1000)/100);
            SetPos(54,17);mountain_reward((mountain%10000)/1000);
            break;
        case 4:
            SetPos(95,21);mountain_mission((mountain%1000)/100);
            SetPos(96,22);mountain_reward((mountain%10000)/1000);
            break;
        case 5:
            SetPos(77,36);mountain_mission((mountain%1000)/100);
            SetPos(78,37);mountain_reward((mountain%10000)/1000);
            break;
    }
    setColor(7,0);///黑色背景，白色字符
}

void mountain_reward(int n)
{
    switch(n)
    {
        case 0:printf("秘龙之书");break;
        case 1:printf("屠龙武器");break;
        case 2:printf("匿龙地图");break;
        case 3:printf("古龙之血");break;
        case 4:printf("龙之秘宝");break;
    }

}

void mountain_mission(int n)
{
    switch(n)
    {
        case 0:printf("英雄遗言状");break;
        case 1:printf(" 迷之碑文");break;
        case 2:printf("魔像守护者");break;
        case 3:printf("哥布林小队");break;
        case 4:printf("魔兽奇美拉");break;
        case 5:printf(" 斯芬克斯");break;
    }
}

#endif // CONTROL_BLOCK_CHOICE_H_INCLUDED
