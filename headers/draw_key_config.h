#ifndef DRAW_KEY_CONFIG_H
#define DRAW_KEY_CONFIG_H
void draw_key_config(int,int);///两个数值未图的基准点
void draw_key_config_word(int,int,int);///前两个数值未图的基准点，后一个1是绘制，非1为抹除
void draw_key_config_draw_line1();
void draw_key_config_draw_line2();
void draw_key_config_draw_apart_y(int,int);///纵向分隔符
void draw_key_config_draw_apart_x(int,int);///横向分隔符
void draw_key_config_help();

void draw_key_config_empire_line();

void draw_key_config(int x,int y)
{
    SetPos(x-2,y+1);printf("            ");SetPos(x+20,y+1);printf("            ");
    SetPos(x-4,y+2);printf("   ");SetPos(x+9,y+2);printf("   ");SetPos(x+18,y+2);printf("   ");SetPos(x+31,y+2);printf("   ");
    SetPos(x-6,y+3);printf("   ");SetPos(x+11,y+3);printf("   ");SetPos(x+16,y+3);printf("   ");SetPos(x+33,y+3);printf("   ");
    SetPos(x-8,y+4);printf("   ");SetPos(x+13,y+4);printf("    ");SetPos(x+35,y+4);printf("   ");
    SetPos(x-8,y+5);printf("  ");SetPos(x+14,y+5);printf("  ");SetPos(x+36,y+5);printf("  ");
    SetPos(x-8,y+6);printf("  ");SetPos(x+14,y+6);printf("  ");SetPos(x+36,y+6);printf("  ");
    SetPos(x-8,y+7);printf("  ");SetPos(x+14,y+7);printf("  ");SetPos(x+36,y+7);printf("  ");
    SetPos(x-8,y+8);printf("  ");SetPos(x+14,y+8);printf("  ");SetPos(x+36,y+8);printf("  ");
    SetPos(x-8,y+9);printf("  ");SetPos(x+14,y+9);printf("  ");SetPos(x+36,y+9);printf("  ");
    SetPos(x-8,y+10);printf("  ");SetPos(x+14,y+10);printf("  ");SetPos(x+36,y+10);printf("  ");
    SetPos(x-9,y+11);printf("    ");SetPos(x+13,y+11);printf("    ");SetPos(x+35,y+11);printf("    ");
    SetPos(x-11,y+12);printf("   ");SetPos(x-6,y+12);printf("   ");SetPos(x+11,y+12);printf("   ");SetPos(x+16,y+12);printf("   ");SetPos(x+33,y+12);printf("   ");SetPos(x+38,y+12);printf("   ");
    SetPos(x-13,y+13);printf("   ");SetPos(x-4,y+13);printf("   ");SetPos(x+9,y+13);printf("   ");SetPos(x+18,y+13);printf("   ");SetPos(x+31,y+13);printf("   ");SetPos(x+40,y+13);printf("   ");
    SetPos(x-15,y+14);printf("   ");SetPos(x-2,y+14);printf("   ");SetPos(x+7,y+14);printf("   ");SetPos(x+20,y+14);printf("   ");SetPos(x+29,y+14);printf("   ");SetPos(x+42,y+14);printf("   ");
    SetPos(x-17,y+15);printf("   ");SetPos(x,y+15);printf("   ");SetPos(x+5,y+15);printf("   ");SetPos(x+22,y+15);printf("   ");SetPos(x+27,y+15);printf("   ");SetPos(x+44,y+15);printf("   ");
    SetPos(x-19,y+16);printf("   ");SetPos(x+2,y+16);printf("    ");SetPos(x+24,y+16);printf("    ");SetPos(x+46,y+16);printf("   ");
    SetPos(x-19,y+17);printf("  ");SetPos(x+3,y+17);printf("  ");SetPos(x+25,y+17);printf("  ");SetPos(x+47,y+17);printf("  ");
    SetPos(x-19,y+18);printf("  ");SetPos(x+3,y+18);printf("  ");SetPos(x+25,y+18);printf("  ");SetPos(x+47,y+18);printf("  ");
    SetPos(x-19,y+19);printf("  ");SetPos(x+3,y+19);printf("  ");SetPos(x+25,y+19);printf("  ");SetPos(x+47,y+19);printf("  ");
    SetPos(x-19,y+20);printf("  ");SetPos(x+3,y+20);printf("  ");SetPos(x+25,y+20);printf("  ");SetPos(x+47,y+20);printf("  ");
    SetPos(x-19,y+21);printf("  ");SetPos(x+3,y+21);printf("  ");SetPos(x+25,y+21);printf("  ");SetPos(x+47,y+21);printf("  ");
    SetPos(x-19,y+22);printf("  ");SetPos(x+3,y+22);printf("  ");SetPos(x+25,y+22);printf("  ");SetPos(x+47,y+22);printf("  ");
    SetPos(x-19,y+23);printf("   ");SetPos(x+2,y+23);printf("    ");SetPos(x+24,y+23);printf("    ");SetPos(x+46,y+23);printf("   ");
    SetPos(x-17,y+24);printf("   ");SetPos(x,y+24);printf("   ");SetPos(x+5,y+24);printf("   ");SetPos(x+22,y+24);printf("   ");SetPos(x+27,y+24);printf("   ");SetPos(x+44,y+24);printf("   ");
    SetPos(x-15,y+25);printf("   ");SetPos(x-2,y+25);printf("   ");SetPos(x+7,y+25);printf("   ");SetPos(x+20,y+25);printf("   ");SetPos(x+29,y+25);printf("   ");SetPos(x+42,y+25);printf("   ");
    SetPos(x-13,y+26);printf("   ");SetPos(x-4,y+26);printf("   ");SetPos(x+9,y+26);printf("   ");SetPos(x+18,y+26);printf("   ");SetPos(x+31,y+26);printf("   ");SetPos(x+40,y+26);printf("   ");
    SetPos(x-11,y+27);printf("   ");SetPos(x-6,y+27);printf("   ");SetPos(x+11,y+27);printf("   ");SetPos(x+16,y+27);printf("   ");SetPos(x+33,y+27);printf("   ");SetPos(x+38,y+27);printf("   ");
    SetPos(x-9,y+28);printf("    ");SetPos(x+13,y+28);printf("    ");SetPos(x+35,y+28);printf("    ");
    SetPos(x-8,y+29);printf("  ");SetPos(x+14,y+29);printf("  ");SetPos(x+36,y+29);printf("  ");
    SetPos(x-8,y+30);printf("  ");SetPos(x+14,y+30);printf("  ");SetPos(x+36,y+30);printf("  ");
    SetPos(x-8,y+31);printf("  ");SetPos(x+14,y+31);printf("  ");SetPos(x+36,y+31);printf("  ");
    SetPos(x-8,y+32);printf("  ");SetPos(x+14,y+32);printf("  ");SetPos(x+36,y+32);printf("  ");
    SetPos(x-8,y+33);printf("  ");SetPos(x+14,y+33);printf("  ");SetPos(x+36,y+33);printf("  ");
    SetPos(x-8,y+34);printf("  ");SetPos(x+14,y+34);printf("  ");SetPos(x+36,y+34);printf("  ");
    SetPos(x-8,y+35);printf("   ");SetPos(x+13,y+35);printf("    ");SetPos(x+35,y+35);printf("   ");
    SetPos(x-6,y+36);printf("   ");SetPos(x+11,y+36);printf("   ");SetPos(x+16,y+36);printf("   ");SetPos(x+33,y+36);printf("   ");
    SetPos(x-4,y+37);printf("   ");SetPos(x+9,y+37);printf("   ");SetPos(x+18,y+37);printf("   ");SetPos(x+31,y+37);printf("   ");
    SetPos(x-2,y+38);printf("            ");SetPos(x+20,y+38);printf("            ");

    SetPos(x+51,y+6);printf("              ");
    SetPos(x+50,y+7);printf("  ");SetPos(x+64,y+7);printf("  ");
    SetPos(x+49,y+8);printf("  ");SetPos(x+65,y+8);printf("  ");
    SetPos(x+49,y+9);printf("  ");SetPos(x+65,y+9);printf("  ");
    SetPos(x+49,y+10);printf("  ");SetPos(x+65,y+10);printf("  ");
    SetPos(x+49,y+11);printf("  ");SetPos(x+65,y+11);printf("  ");
    SetPos(x+50,y+12);printf("  ");SetPos(x+64,y+12);printf("  ");
    SetPos(x+51,y+13);printf("              ");

    SetPos(x+51,y+26);printf("              ");
    SetPos(x+50,y+27);printf("  ");SetPos(x+64,y+27);printf("  ");
    SetPos(x+49,y+28);printf("  ");SetPos(x+65,y+28);printf("  ");
    SetPos(x+49,y+29);printf("  ");SetPos(x+65,y+29);printf("  ");
    SetPos(x+49,y+30);printf("  ");SetPos(x+65,y+30);printf("  ");
    SetPos(x+49,y+31);printf("  ");SetPos(x+65,y+31);printf("  ");
    SetPos(x+50,y+32);printf("  ");SetPos(x+64,y+32);printf("  ");
    SetPos(x+51,y+33);printf("              ");
}

void draw_key_config_word(int x,int y,int n)
{
    if(n==1)
    {
        SetPos(x-1,y+7);printf("方向键左上");
        SetPos(x+21,y+7);printf("方向键右上");
        SetPos(x-11,y+19);printf("方向键左");
        SetPos(x+10,y+19);printf("放弃移动键");
        SetPos(x+33,y+19);printf("方向键右");
        SetPos(x-1,y+31);printf("方向键左下");
        SetPos(x+21,y+31);printf("方向键右下");
        SetPos(x+53,y+9);printf("确认  上翻");
        SetPos(x+53,y+29);printf("取消  下翻");
    }
    else
    {
        SetPos(x-1,y+7);printf("          ");
        SetPos(x+21,y+7);printf("          ");
        SetPos(x-11,y+19);printf("        ");
        SetPos(x+10,y+19);printf("          ");
        SetPos(x+33,y+19);printf("        ");
        SetPos(x-1,y+31);printf("          ");
        SetPos(x+21,y+31);printf("          ");
        SetPos(x+53,y+9);printf("          ");
        SetPos(x+53,y+29);printf("          ");
    }
}
void draw_key_config_empire_line()
{
    ///绘制分隔符
    draw_key_config_draw_apart_x(146,0);
    draw_key_config_draw_apart_x(146,1);
    draw_key_config_draw_apart_x(146,42);
    draw_key_config_draw_apart_x(146,43);
    draw_key_config_draw_apart_y(110,46);
    draw_key_config_draw_apart_y(140,46);
    draw_key_config_draw_apart_y(3,46);
}

void draw_key_config_draw_line1()
{
    setColor(7,0);printf("| |");
}
void draw_key_config_draw_line2()
{
    setColor(7,0);printf("_");
}
void draw_key_config_draw_apart_y(int x,int y)///纵向分隔符
{
    int i;
    for(i=0;i<y;i++)
    {
        SetPos(x,i);draw_key_config_draw_line1();
    }
}
void draw_key_config_draw_apart_x(int x,int y)///横向分隔符
{
    int i;
    SetPos(0,y);
    for(i=0;i<x;i++)
        draw_key_config_draw_line2();
}

void draw_key_config_help()
{
    SetPos(115,3);printf("按下ENTER修改");
    SetPos(115,4);printf("press ENTER to modify");
    SetPos(115,6);printf("按下ESC退出");
    SetPos(115,7);printf("press ESC to back");
}
#endif // DRAW_KEY_CONFIG_H
