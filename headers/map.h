#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

extern char key_button[9];

void draw_start(int,int,int);
void draw_process1(int,int,int);
void draw_process2(int,int,int);
void draw_end(int,int,int);
void draw_apart_y(int,int);
void draw_apart_x(int,int);

void draw_line1(int,int,int);
void draw_line2(int,int,int);
void draw_line3(int,int,int);
void draw_line4(int,int,int);
void draw_line5();
void draw_line6();

void draw_map_block(int,int,int);

void draw_map()
{
    int n=5,x=1,y=3;///n为最上层六边形数量，x和y是地图初相位偏移量
    n=6*n+1;

    ///绘制地图
    setColor(0,7);
    draw_start(n,x+8,y);
    draw_process1(n,x+8,y+3);
    draw_process1(n,x+8,y+4);
    draw_start(n+6,x+6,y+5);
    draw_process2(n+12,x+4,y+8);
    draw_process2(n+12,x+4,y+9);
    draw_start(n+12,x+4,y+10);
    draw_process1(n+12,x+4,y+13);
    draw_process1(n+12,x+4,y+14);
    draw_start(n+18,x+2,y+15);
    draw_process2(n+24,x,y+18);
    draw_process2(n+24,x,y+19);
    draw_process2(n+24,x,y+20);
    draw_end(n+18,x+2,y+21);
    draw_process1(n+12,x+4,y+24);
    draw_process1(n+12,x+4,y+25);
    draw_end(n+12,x+4,y+26);
    draw_process2(n+12,x+4,y+29);
    draw_process2(n+12,x+4,y+30);
    draw_end(n+6,x+6,y+31);
    draw_process1(n,x+8,y+34);
    draw_process1(n,x+8,y+35);
    draw_end(n,x+8,y+36);


    ///绘制中心区域色块 绘制中心区域文字提示
    draw_map_block(6,29,4);SetPos(32,5);setColor(14,6);printf("平原");SetPos(32,6);printf("冒险");
    draw_map_block(15,41,4);SetPos(43,5);setColor(0,15);printf("贝尔村");SetPos(44,6);printf("休息");
    draw_map_block(6,53,4);SetPos(56,5);setColor(14,6);printf("平原");SetPos(56,6);printf("冒险");
    draw_map_block(2,65,4);SetPos(68,5);setColor(11,2);printf("森林");SetPos(66,6);printf("冒/侦/挑");
    draw_map_block(5,77,4);SetPos(81,5);setColor(12,5);printf("山");SetPos(80,6);printf("????");SetPos(79,8);printf(" 宝藏 ");

    draw_map_block(2,23,9);SetPos(26,10);setColor(11,2);printf("森林");SetPos(24,11);printf("冒/侦/挑");
    draw_map_block(6,35,9);SetPos(38,10);setColor(14,6);printf("平原");SetPos(38,11);printf("冒险");
    draw_map_block(6,47,9);SetPos(50,10);setColor(14,6);printf("平原");SetPos(48,11);printf("冒/侦/挑");
    draw_map_block(2,59,9);SetPos(62,10);setColor(11,2);printf("森林");SetPos(60,11);printf("冒/侦/挑");
    draw_map_block(2,71,9);SetPos(74,10);setColor(11,2);printf("森林");SetPos(72,11);printf("冒/侦/挑");
    draw_map_block(2,83,9);SetPos(86,10);setColor(11,2);printf("森林");SetPos(84,11);printf("冒/侦/挑");

    draw_map_block(5,17,14);SetPos(21,15);setColor(12,5);printf("山");SetPos(20,16);printf("????");SetPos(19,18);printf(" 宝藏 ");
    draw_map_block(6,29,14);SetPos(32,15);setColor(14,6);printf("平原");SetPos(30,16);printf("冒/侦/挑");
    draw_map_block(2,41,14);SetPos(44,15);setColor(11,2);printf("森林");SetPos(42,16);printf("冒/侦/挑");
    draw_map_block(5,53,14);SetPos(57,15);setColor(12,5);printf("山");SetPos(56,16);printf("????");SetPos(55,18);printf(" 宝藏 ");
    draw_map_block(6,65,14);SetPos(68,15);setColor(14,6);printf("平原");SetPos(66,16);printf("冒/侦/挑");
    draw_map_block(6,77,14);SetPos(80,15);setColor(14,6);printf("平原");SetPos(80,16);printf("冒险");
    draw_map_block(2,89,14);SetPos(92,15);setColor(11,2);printf("森林");SetPos(90,16);printf("冒/侦/挑");

    draw_map_block(2,11,19);SetPos(14,20);setColor(11,2);printf("森林");SetPos(12,21);printf("冒/侦/挑");
    draw_map_block(2,23,19);SetPos(26,20);setColor(11,2);printf("森林");SetPos(24,21);printf("冒/侦/挑");
    draw_map_block(6,35,19);SetPos(38,20);setColor(14,6);printf("平原");SetPos(38,21);printf("冒险");
    draw_map_block(2,47,19);SetPos(50,20);setColor(11,2);printf("森林");SetPos(48,21);printf("冒/侦/挑");
    draw_map_block(2,59,19);SetPos(62,20);setColor(11,2);printf("森林");SetPos(60,21);printf("冒/侦/挑");
    draw_map_block(15,71,19);SetPos(73,20);setColor(0,15);printf("法兰镇");SetPos(74,21);printf("休息");
    draw_map_block(2,83,19);SetPos(86,20);setColor(11,2);printf("森林");SetPos(84,21);printf("冒/侦/挑");
    draw_map_block(5,95,19);SetPos(99,20);setColor(12,5);printf("山");SetPos(98,21);printf("????");SetPos(97,23);printf(" 宝藏 ");

    draw_map_block(6,17,24);SetPos(20,25);setColor(14,6);printf("平原");SetPos(20,26);printf("冒险");
    draw_map_block(6,29,24);SetPos(32,25);setColor(14,6);printf("平原");SetPos(32,26);printf("冒险");
    draw_map_block(6,41,24);SetPos(44,25);setColor(14,6);printf("平原");SetPos(44,26);printf("冒险");
    draw_map_block(8,53,24);SetPos(56,25);setColor(15,8);printf("道路");
    draw_map_block(8,65,24);SetPos(68,25);setColor(15,8);printf("道路");
    draw_map_block(6,77,24);SetPos(80,25);setColor(14,6);printf("平原");SetPos(80,26);printf("冒险");
    draw_map_block(6,89,24);SetPos(92,25);setColor(14,6);printf("平原");SetPos(90,26);printf("冒/侦/挑");

    draw_map_block(15,23,29);SetPos(26,30);setColor(0,15);printf("哈维");SetPos(26,31);printf("休息");
    draw_map_block(15,35,29);SetPos(38,30);setColor(0,15);printf("尼亚");SetPos(38,31);printf("休息");
    draw_map_block(8,47,29);SetPos(50,30);setColor(15,8);printf("道路");
    draw_map_block(6,59,29);SetPos(62,30);setColor(14,6);printf("平原");SetPos(62,31);printf("冒险");
    draw_map_block(2,71,29);SetPos(74,30);setColor(11,2);printf("森林");SetPos(72,31);printf("冒/侦/挑");
    draw_map_block(2,83,29);SetPos(86,30);setColor(11,2);printf("森林");SetPos(84,31);printf("冒/侦/挑");

    draw_map_block(15,29,34);SetPos(32,35);setColor(0,15);printf("主城");SetPos(32,36);printf("休息");
    draw_map_block(6,41,34);SetPos(44,35);setColor(14,6);printf("平原");SetPos(44,36);printf("冒险");
    draw_map_block(6,53,34);SetPos(56,35);setColor(14,6);printf("平原");SetPos(56,36);printf("冒险");
    draw_map_block(2,65,34);SetPos(68,35);setColor(11,2);printf("森林");SetPos(66,36);printf("冒/侦/挑");
    draw_map_block(5,77,34);SetPos(81,35);setColor(12,5);printf("山");SetPos(80,36);printf("????");SetPos(79,38);printf(" 宝藏 ");

    ///任务清单
    setColor(7,0);
    SetPos(115,15);printf("英雄的遗言状");
    SetPos(115,16);printf("  多个英雄同时宣言完成");
    SetPos(115,17);printf("迷之碑文");
    SetPos(115,18);printf("  知识力 2");
    SetPos(115,19);printf("魔像守护者");
    SetPos(115,20);printf("  探索力 3 挑战受1血");
    SetPos(115,21);printf("哥布林小队");
    SetPos(115,22);printf("  战斗力 3 失败受1血");
    SetPos(115,23);printf("魔兽奇美拉");
    SetPos(115,24);printf("  战斗力 2 挑战受1血");
    SetPos(115,25);printf("  失败受1血");
    SetPos(115,26);printf("斯芬克斯之谜 单人");
    SetPos(115,27);printf("  知识力 1 失败受2血");

    ///龙祸显示
    setColor(7,0);SetPos(12,33);printf("龙  祸");
    number_ARAB(7,34,0,7,0);

    SetPos(8,3);printf(">%c  左上",key_button[0]);
    SetPos(8,4);printf(">%c  右上",key_button[1]);
    SetPos(8,5);printf(">%c   左",key_button[2]);
    SetPos(8,6);printf(">%c   右",key_button[4]);
    SetPos(8,7);printf(">%c  左下",key_button[5]);
    SetPos(8,8);printf(">%c  右下",key_button[6]);

    SetPos(8,9);printf(">%c  放弃移动",key_button[3]);
    SetPos(8,10);printf(">%c  确认",key_button[7]);
    SetPos(8,11);printf(">%c  取消",key_button[8]);

    SetPos(93,38);printf(">当输入数字之后");
    SetPos(93,39);printf(">按回车才是确定");

    play_music(2);
    ///龙怒倒计时
    setColor(7,0);SetPos(98,10);printf("龙  怒");
    int i,num_c;
    num_c=12;
    for(i=0;i<16;i++)
    {
        number_ROME(93,2,0,num_c,i);///地图右上角空位坐标(93,2)
        if(i>=0&&i<4)
        {
            Sleep(250);
        }
        if(i>=4&&i<8)
        {
            num_c=13;
            Sleep(350);
        }
        if(i>=8&&i<12)
        {
            num_c=9;
            Sleep(500);
        }
        if(i>=12&&i<16)
        {
            num_c=7;
            Sleep(800);
        }
    }

    ///绘制分隔符
    /*
    draw_apart_x(146,0);
    draw_apart_x(146,1);
    draw_apart_x(146,42);
    draw_apart_x(146,43);
    draw_apart_y(110,46);
    draw_apart_y(140,46);
    draw_apart_y(3,46);
    */
    setColor(7,0);SetPos(6,44);
}

void draw_line1(int n,int x,int y)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(i%6==4)
        {
            SetPos(x,y);printf("  ");x=x+2;
        }
        else
        {
            x=x+2;
        }

    }
}
void draw_line2(int n,int x,int y)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(i%6==3||i%6==5)
        {
            SetPos(x,y);printf("  ");x=x+2;
        }
        else
        {
            x=x+2;
        }
    }
}
void draw_line3(int n,int x,int y)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(i%6==2||i%6==0)
        {
            SetPos(x,y);printf("  ");x=x+2;
        }
        else
        {
            x=x+2;
        }
    }
}
void draw_line4(int n,int x,int y)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(i%6==1)
        {
            SetPos(x,y);printf("  ");x=x+2;
        }
        else
        {
            x=x+2;
        }
    }
}
void draw_line5()
{
    setColor(7,0);printf("| |");
}
void draw_line6()
{
    setColor(7,0);printf("_");
}

void draw_start(int n,int x,int y)///绘制六边形顶部
{
    SetPos(3*x,y);draw_line1(n,3*x,y);
    SetPos(3*x,y+1);draw_line2(n,3*x,y+1);
    SetPos(3*x,y+2);draw_line3(n,3*x,y+2);
}
void draw_process1(int n,int x,int y)///六边形中部绘制1 六边形中部绘制存在两种情况，分开描述
{
    SetPos(3*x,y);draw_line4(n,3*x,y);
}
void draw_process2(int n,int x,int y)///六边形中部绘制2
{
    SetPos(3*x,y);draw_line1(n,3*x,y);
}
void draw_end(int n,int x,int y)///绘制六边形底部
{
    SetPos(3*x,y);draw_line3(n,3*x,y);
    SetPos(3*x,y+1);draw_line2(n,3*x,y+1);
    SetPos(3*x,y+2);draw_line1(n,3*x,y+2);
}
void draw_apart_y(int x,int y)///纵向分隔符
{
    int i;
    for(i=0;i<y;i++)
    {
        SetPos(x,i);draw_line5();
    }
}
void draw_apart_x(int x,int y)///横向分隔符
{
    int i;
    SetPos(0,y);
    for(i=0;i<x;i++)
        draw_line6();
}

void draw_map_block(int color,int x,int y)
{
    setColor(0,color);
    SetPos(x+4,y);printf("  ");
    SetPos(x+2,y+1);printf("      ");
    SetPos(x,y+2);printf("  ");SetPos(x+2,y+2);printf("      ");SetPos(x+8,y+2);printf("  ");
    SetPos(x,y+3);printf("  ");SetPos(x+2,y+3);printf("      ");SetPos(x+8,y+3);printf("  ");
    SetPos(x,y+4);printf("  ");SetPos(x+8,y+4);printf("  ");
    SetPos(x+2,y+5);printf("      ");
    SetPos(x+4,y+6);printf("  ");
}

#endif // MAP_H_INCLUDED
