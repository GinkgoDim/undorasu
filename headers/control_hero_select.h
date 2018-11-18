#ifndef CONTROL_HERO_SELECT_INCLUDED
#define CONTROL_HERO_SELECT_INCLUDED
///以下批注是按键所对应的键码
// w=119 e=101
//a=97 s=115 d=100
// z=122 x=120
//1=49 2=50 3=51 4=52 5=53 6=54 0=48
extern char key_button[9];
extern int count;
void control_hero_select()
{
    //HERO py[3];
    extern HERO py[3];
    int ch;///检测输入字符
    int i;///循环变量i,即用即赋值
    int room_choice=1,room_x=53,room_y=21;

    while(1)
    {///在开始游戏之前进行 信息初始化 人物选择 查看帮助 修改键位 查看音乐 的循环
        play_music(1);
        int select_HEROS[6]={0,0,0,0,0,0};                                      ///判断出动的英雄              这三句还负责保持初始化
        int select_count=0;                                                     ///判断当前出动的人数
        count=0;                                                            ///count为已参战的英雄编号

        SetPos(room_x,room_y);printf("=>");
        SetPos(6,44);printf("选择英雄出征!");
        while (1)
        {///按键操作的循环
            if (_kbhit())
            {///如果有按键按下，则_kbhit()函数返回真
                ch = _getch();                                                  ///使用_getch()函数获取按下的键值
                emergency_decoration(2);                                        ///将输入区域清空并回到输入区域初始位置
                if(key_button[0]==ch)                                           ///剑圣
                    switch(select_HEROS[0])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[0]=1;select_count++;printf("剑圣想要出征");
                                draw_hero_select_flash_choice(0,0,9,8,2);///淡蓝色
                                draw_hero_introduce_choice(1,7,0);
                            }
                            else if(select_count==3)
                                printf("人数已满！");
                            break;
                        case 1:
                            select_HEROS[0]=0;select_count--;
                            draw_hero_select_flash_choice(0,7,0,8,2);
                            draw_hero_introduce_choice(2,7,0);
                            break;
                        default:break;
                    }
                if(key_button[1]==ch)                                           ///忍者
                    switch(select_HEROS[1])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[1]=1;select_count++;printf("忍者想要出征");
                                draw_hero_select_flash_choice(1,0,10,8,2);///淡绿色
                                draw_hero_introduce_choice(3,7,0);
                            }
                            else if(select_count==3)
                                printf("人数已满！");
                            break;
                        case 1:
                            select_HEROS[1]=0;select_count--;
                            draw_hero_select_flash_choice(1,7,0,8,2);
                            draw_hero_introduce_choice(4,7,0);
                            break;
                        default:break;
                    }
                if(key_button[2]==ch)                                           ///猎人
                    switch(select_HEROS[2])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[2]=1;select_count++;printf("猎人想要出征");
                                draw_hero_select_flash_choice(2,0,14,8,2);///淡黄色
                                draw_hero_introduce_choice(5,7,0);
                            }
                            else if(select_count==3)
                                printf("人数已满！");
                            break;
                        case 1:
                            select_HEROS[2]=0;select_count--;
                            draw_hero_select_flash_choice(2,7,0,8,2);
                            draw_hero_introduce_choice(6,7,0);
                            break;
                        default:break;
                    }
                if(key_button[4]==ch)                                           ///角斗士
                    switch(select_HEROS[3])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[3]=1;select_count++;printf("角斗士想要出征");
                                draw_hero_select_flash_choice(4,0,12,8,2);///淡红色
                                draw_hero_introduce_choice(7,7,0);
                            }
                            else if(select_count==3)
                                printf("人数已满！");
                            break;
                        case 1:
                            select_HEROS[3]=0;select_count--;
                            draw_hero_select_flash_choice(4,7,0,8,2);
                            draw_hero_introduce_choice(8,7,0);
                            break;
                        default:break;
                    }
                if(key_button[5]==ch)                                           ///王子
                    switch(select_HEROS[4])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[4]=1;select_count++;printf("王子想要出征");
                                draw_hero_select_flash_choice(5,0,13,8,2);///淡紫色
                                draw_hero_introduce_choice(9,7,0);
                            }
                            else if(select_count==3)
                                printf("人数已满！");
                            break;
                        case 1:
                            select_HEROS[4]=0;select_count--;
                            draw_hero_select_flash_choice(5,7,0,8,2);
                            draw_hero_introduce_choice(10,7,0);
                            break;
                        default:break;
                    }
                if(key_button[6]==ch)                                           ///圣骑士
                    switch(select_HEROS[5])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[5]=1;select_count++;printf("圣骑士想要出征");
                                draw_hero_select_flash_choice(6,0,11,8,2);///浅绿色
                                draw_hero_introduce_choice(11,7,0);
                            }
                            else if(select_count==3)
                                printf("人数已满！");
                            break;
                        case 1:
                            select_HEROS[5]=0;select_count--;
                            draw_hero_select_flash_choice(6,7,0,8,2);
                            draw_hero_introduce_choice(12,7,0);
                            break;
                        default:break;
                    }
                if(key_button[3]==ch)                                           ///按下开始按钮 检测人数 生成角色
                {
                    switch(select_count)
                    {
                        case 0:printf("目前没有英雄出动！");break;
                        default:                                                ///为英雄初始化生成英雄结构体
                        {
                            i=0;                                                ///i为标准循环变量，声明在上文
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setHolySwordsman();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setNinja();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setHunter();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setGladiator();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setPrince();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setPaladin();printf("%d",py[count].timeP);
                                count++;
                            }
                            emergency_decoration(2);
                            preparation();///初始化一部分数据
                            printf(" 准备好! ");
                            Sleep(1000);printf("3 ");
                            Sleep(1000);printf("2 ");
                            Sleep(1000);printf("1 ");
                            Sleep(1000);
                        }
                        break;
                    }
                    if(select_count!=0)
                        break;
                }
                setColor(7,0);
                if(ch==27)                                                      ///ESC热键退出 ESC键的键值时27
                {
                    printf("英雄们退怯了");
                    exit(0);
                }
                if(ch==13)                                                      ///生成进入当前所指房间
                {
                    room_choice+=10;
                    break;///当按下ESC时结束循环，ESC键的键值时27.
                }
                if(key_button[7]==ch)                                           ///选择项向上移
                {
                    if(room_choice>1)
                    {
                        SetPos(room_x,room_y);
                        printf("  ");
                        room_y--;
                        SetPos(room_x,room_y);
                        printf("=>");
                        room_choice--;
                    }
                }
                if(key_button[8]==ch)                                           ///选择项向下移
                {
                    if(room_choice<3)
                    {
                        SetPos(room_x,room_y);
                        printf("  ");
                        room_y++;
                        SetPos(room_x,room_y);
                        printf("=>");
                        room_choice++;
                    }
                }
                SetPos(6,44);
            }
        }
        if(room_choice>10)                                                      ///根据判断选择进入房间或者退出函数
        {
            switch(room_choice)
            {
                case 11:
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_help();
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_hero_select(0,7,0,8,8,2);                              ///绘制英雄选择模组的图形
                    draw_hero_select_word(7,0,8,2,1);                           ///绘制英雄选择模组的文字
                    break;
                case 12:
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_key_config_help();
                    setColor(0,7);                                              ///设置按键修改模组颜色为黑字白底
                    draw_key_config(32,2);                                      ///绘制按键修改模组的图形
                    draw_key_config_word(32,2,1);                               ///绘制按键修改模组的文字
                    control_key_config(0,14);                                   ///按键修改模组
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_hero_select(0,7,0,8,8,2);                              ///绘制英雄选择模组的图形
                    draw_hero_select_word(7,0,8,2,1);                           ///绘制英雄选择模组的文字
                    break;
                case 13:
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    music_room();                                               ///音乐室模组
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_hero_select(0,7,0,8,8,2);                              ///绘制英雄选择模组的图形
                    draw_hero_select_word(7,0,8,2,1);                           ///绘制英雄选择模组的文字
                    break;
                default:break;
            }
            room_choice-=10;
        }
        else
        {
            emergency_decoration(1);
            emergency_decoration(2);
            emergency_decoration(3);
            break;
        }
    }
}

#endif // CONTROL_HERO_SELECT_INCLUDED
///通用函数名
//HERO setHolySwordsman(void) ///设定剑圣默认数据
//HERO setNinja(void) ///设定忍者默认数据
//HERO setHunter(void) ///设定猎人默认数据
//HERO setGladiator(void) ///设定角斗士默认数据
//HERO setPrince(void) ///设定王子默认数据
//HERO setPaladin(void) ///设定圣骑士默认数据

///引用英雄的方法
/*
HERO py[3];
py[0]=setPaladin();
py[1]=setHolySwordsman();
py[2]=setHunter();
*/
