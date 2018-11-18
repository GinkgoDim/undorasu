#ifndef CONTROL_MAP_MOVING_H_INCLUDED
#define CONTROL_MAP_MOVING_H_INCLUDED

int moving_block_check_all(int);
int block_check_6();
int block_check_forest();
int block_check_plain();
int block_check_road();

extern int map_block[7][8];
int step_show[4]={0,0,0,0};

void map_moving(int,int,int*,int*,int*,int*);
///横向间距6全角字符 纵向间距5字符
//a=97 s=115 d=100 w=119 h=104 q=113 e=101 z=122 x=120

void map_moving(int step,int n,int *hero_moving_x,int *hero_moving_y,int *hero_moving_a,int *hero_moving_b)
{
    int step_copy1;                 ///定义用于数据备份的成员
    int x,y,a,b;
    x=*hero_moving_x;y=*hero_moving_y;a=*hero_moving_a;b=*hero_moving_b;///创建人物移动参数的副本，用于取消恢复初始化
    SetPos(x,y);printf("P%d",n);    ///初始化人物显示

    step_copy1=step;                ///步数换算程序
    if(step_copy1/1000>=1)          ///任意
    {
        step_show[3]=step_copy1/1000;
        step_copy1-=1000*step_show[3];
    }
    if(step_copy1/100>=1)           ///森林
    {
        step_show[2]=step_copy1/100;
        step_copy1-=100*step_show[2];
    }
    if(step_copy1/10>=1)            ///平原
    {
        step_show[1]=step_copy1/10;
        step_copy1-=10*step_show[1];
    }
    if(step_copy1>=1)               ///道路
    {
        step_show[0]=step_copy1;
    }
    SetPos(113,37);printf(" 移动：  ");
    SetPos(113,38);printf(" 任意：  %d",step_show[3]);
    SetPos(113,39);printf(" 森林：  %d",step_show[2]);
    SetPos(113,40);printf(" 平原：  %d",step_show[1]);
    SetPos(113,41);printf(" 道路：  %d",step_show[0]);

    int ch,ch_again;
    while (1)
    {
        if (_kbhit())
        {//如果有按键按下，则_kbhit()函数返回真
            emergency_decoration(2);
            ch = _getch();//使用_getch()函数获取按下的键值
            if(key_button[0]==ch)                                               ///左上移动
                if(a>0&&b>0)                                                    ///边界判断
                {
                    if(moving_block_check_all(map_block[a-1][b-1])==1)          ///地块判断 扣除相应步数
                    {
                        SetPos(x,y);printf("  ");SetPos(x-6,y-5);
                        map_block[a][b]-=2*n-1;                                 ///将脚下的区块人物标识去除
                        x-=6;y-=5;a--;b--;
                        map_block[a][b]+=2*n-1;                                 ///在新的区块产生人物标识
                        printf("P%d",n);
                    }
                }
            if(key_button[1]==ch)                                               ///右上移动
                if(a>0&&b-4<a)
                {
                    if(moving_block_check_all(map_block[a-1][b])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x+6,y-5);
                        map_block[a][b]-=2*n-1;
                        x+=6;y-=5;a--;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[2]==ch)                                               ///左移动
                if(b>0&&b+3>a)
                {
                    if(moving_block_check_all(map_block[a][b-1])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x-12,y);
                        map_block[a][b]-=2*n-1;
                        x-=12;b--;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[3]==ch||key_button[7]==ch)                            ///放弃继续移动
            {
                SetPos(6,44);
                emergency_decoration(2);
                printf("放弃继续移动？");
                if(key_button[3]==ch_again)
                {
                    emergency_decoration(2);
                    printf("放弃继续移动！");
                    break;
                }
            }
            if(key_button[4]==ch)                                               ///右移动
                if(b<7&&b-4<a)
                {
                    if(moving_block_check_all(map_block[a][b+1])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x+12,y);
                        map_block[a][b]-=2*n-1;
                        x+=12;b++;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[5]==ch)                                               ///左下移动
                if(b+3>a&&a<6)
                {
                    if(moving_block_check_all(map_block[a+1][b])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x-6,y+5);
                        map_block[a][b]-=2*n-1;
                        x-=6;y+=5;a++;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[6]==ch)                                               ///右下移动
                if(a<6&&b<7)
                {
                    if(moving_block_check_all(map_block[a+1][b+1])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x+6,y+5);x+=6;y+=5;
                        map_block[a][b]-=2*n-1;
                        a++;b++;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[8]==ch)                                               ///取消移动按键 恢复程序段的初始化
            {
                SetPos(x,y);printf("  ");
                map_block[a][b]-=2*n-1;
                x=*hero_moving_x;y=*hero_moving_y;a=*hero_moving_a;b=*hero_moving_b;
                map_block[a][b]+=2*n-1;
                SetPos(x,y);printf("P%d",n);

                step_copy1=step;                ///步数换算程序
                if(step_copy1/1000>=1)          ///任意
                {
                    step_show[3]=step_copy1/1000;
                    step_copy1-=1000*step_show[3];
                }
                if(step_copy1/100>=1)           ///森林
                {
                    step_show[2]=step_copy1/100;
                    step_copy1-=100*step_show[2];
                }
                if(step_copy1/10>=1)            ///平原
                {
                    step_show[1]=step_copy1/10;
                    step_copy1-=10*step_show[1];
                }
                if(step_copy1>=1)               ///道路
                {
                    step_show[0]=step_copy1;
                }
                SetPos(121,38);printf(" %d",step_show[3]);
                SetPos(121,39);printf(" %d",step_show[2]);
                SetPos(121,40);printf(" %d",step_show[1]);
                SetPos(121,41);printf(" %d",step_show[0]);
            }
            if (ch==27)                                                         ///热键ESC退出
            {
                SetPos(6,44);
                emergency_decoration(2);
                printf("退出游戏？");
                if(ch_again==27)
                {
                    emergency_decoration(2);
                    printf("退出游戏！");
                    exit(0);
                }
            }//当按下ESC时循环，ESC键的键值时27.
            ch_again=ch;///保存最近一次按键键值 判定前后两次按键是否相同
            SetPos(6,44);
        }
    }
    *hero_moving_x=x;*hero_moving_y=y;*hero_moving_a=a;*hero_moving_b=b;///创建移动参数的修改，用于实用修改
}

int moving_block_check_all(int block)
{
    if(block%100>=10&&block%100<30)
        return block_check_road();
    if(block%100>=30&&block%100<40)
        return block_check_plain();
    if(block%100>=40&&block%100<50)
        return block_check_forest();
    return 0;
}

int block_check_6()
{
    if(step_show[3]>0)
    {
        step_show[3]--;
        SetPos(121,38);printf(" %d",step_show[3]);
        return 1;
    }
    else
        return 0;
}

int block_check_forest()
{
    if(step_show[2]>0)
    {
        step_show[2]--;
        SetPos(121,39);printf(" %d",step_show[2]);
        return 1;
    }
    else
        return block_check_6();
}

int block_check_plain()
{
    if(step_show[1]>0)
    {
        step_show[1]--;
        SetPos(121,40);printf(" %d",step_show[1]);
        return 1;
    }
    else
        return block_check_forest();
}

int block_check_road()
{
    if(step_show[0]>0)
    {
        step_show[0]--;
        SetPos(121,41);printf(" %d",step_show[0]);
        return 1;
    }
    else
        return block_check_plain();
}

#endif // CONTROL_MAP_MOVING_H_INCLUDED
