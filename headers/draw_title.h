#ifndef DRAW_TITLE_H_INCLUDED
#define DRAW_TITLE_H_INCLUDED

void draw_title(int,int);
void draw_title_D(int,int);
void draw_title_o(int,int);
void draw_title_r1(int,int);
void draw_title_a(int,int);
void draw_title_s(int,int);
void draw_title_u(int,int);
void draw_title_r2(int,int);
void draw_title_e(int,int);

void draw_title(int x,int y)
{
    draw_title_D(x,y);
    draw_title_o(x,y);
    draw_title_r1(x,y);
    draw_title_a(x,y);
    draw_title_s(x,y);
    draw_title_u(x,y);
    draw_title_r2(x,y);
    draw_title_e(x,y);
    SetPos(0,30);
}

void draw_title_D(int x,int y)
{
    SetPos(x+7,y);printf("MM");SetPos(x+13,y);printf("MMMMMMMMMM");
    SetPos(x+7,y+1);printf("MMMMMMM");SetPos(x+22,y+1);printf("MMM");
    SetPos(x+6,y+2);printf("MMMM");SetPos(x+24,y+2);printf("MMM");
    SetPos(x+4,y+3);printf("MMMMM");SetPos(x+26,y+3);printf("MM");
    SetPos(x+2,y+4);printf("MMM");SetPos(x+7,y+4);printf("MM");SetPos(x+27,y+4);printf("MM");
    SetPos(x,y+5);printf("MMM");SetPos(x+7,y+5);printf("MM");SetPos(x+28,y+5);printf("MM");
    SetPos(x+7,y+6);printf("MM");SetPos(x+28,y+6);printf("MM");
    SetPos(x+7,y+7);printf("MM");SetPos(x+28,y+7);printf("MM");
    SetPos(x+7,y+8);printf("MM");SetPos(x+28,y+8);printf("MM");
    SetPos(x+7,y+9);printf("MM");SetPos(x+28,y+9);printf("MM");
    SetPos(x+7,y+10);printf("MM");SetPos(x+28,y+10);printf("MM");
    SetPos(x+7,y+11);printf("MM");SetPos(x+28,y+11);printf("MM");
    SetPos(x+7,y+12);printf("MM");SetPos(x+26,y+12);printf("MMM");
    SetPos(x+7,y+13);printf("MM");SetPos(x+23,y+13);printf("MMMM");
    SetPos(x+6,y+14);printf("MM");SetPos(x+18,y+14);printf("MMMMMM");
    SetPos(x+5,y+15);printf("MMMMMMMMMMMMMMMMMMMMMMMMMM");
}

void draw_title_o(int x,int y)
{
    SetPos(x+34,y+7);printf("MMMMMMMMMM");
    SetPos(x+33,y+8);printf("MM");SetPos(x+42,y+8);printf("MMM");
    SetPos(x+32,y+9);printf("MM");SetPos(x+42,y+9);printf("M");SetPos(x+44,y+9);printf("MM");
    SetPos(x+32,y+10);printf("MM");SetPos(x+41,y+10);printf("MM");SetPos(x+44,y+10);printf("MM");
    SetPos(x+32,y+11);printf("MM");SetPos(x+40,y+11);printf("MM");SetPos(x+44,y+11);printf("MM");
    SetPos(x+32,y+12);printf("MM");SetPos(x+38,y+12);printf("MMM");SetPos(x+44,y+12);printf("MM");
    SetPos(x+32,y+13);printf("MMMMMMMM");SetPos(x+44,y+13);printf("MM");
    SetPos(x+30,y+14);printf("MMMMM");SetPos(x+43,y+14);printf("MM");
    SetPos(x+34,y+15);printf("MMMMMMMMMM");
}

void draw_title_r1(int x,int y)
{
    SetPos(x+50,y+7);printf("MM");SetPos(x+55,y+7);printf("MMMMM");
    SetPos(x+50,y+8);printf("MM");SetPos(x+53,y+8);printf("MMM");
    SetPos(x+49,y+9);printf("MMMMM");
    SetPos(x+48,y+10);printf("MMMM");
    SetPos(x+46,y+11);printf("MMM");SetPos(x+50,y+11);printf("MM");
    SetPos(x+50,y+12);printf("MM");
    SetPos(x+50,y+13);printf("MM");
    SetPos(x+50,y+14);printf("MM");
    SetPos(x+50,y+15);printf("MM");
}

void draw_title_a(int x,int y)
{
    SetPos(x+61,y+7);printf("MMMMMMMM");
    SetPos(x+59,y+8);printf("MMM");SetPos(x+68,y+8);printf("MMM");
    SetPos(x+69,y+9);printf("MM");
    SetPos(x+69,y+10);printf("MM");
    SetPos(x+60,y+11);printf("MMMMMMMM");SetPos(x+69,y+11);printf("MM");
    SetPos(x+59,y+12);printf("MM");SetPos(x+68,y+12);printf("MM");
    SetPos(x+59,y+13);printf("MM");SetPos(x+68,y+13);printf("MM");
    SetPos(x+59,y+14);printf("MM");SetPos(x+68,y+14);printf("MM");SetPos(x+73,y+14);printf("M");
    SetPos(x+60,y+15);printf("MMMMMMMM");SetPos(x+69,y+15);printf("MMMM");
}

void draw_title_s(int x,int y)
{
    SetPos(x+75,y+7);printf("MMMMMMMMM");
    SetPos(x+74,y+8);printf("MM");SetPos(x+83,y+8);printf("MM");
    SetPos(x+74,y+9);printf("MM");SetPos(x+83,y+9);printf("MM");
    SetPos(x+74,y+10);printf("MM");SetPos(x+87,y+10);printf("M");
    SetPos(x+75,y+11);printf("MMMMMMMMM");SetPos(x+85,y+11);printf("MMM");
    SetPos(x+81,y+12);printf("MMMM");
    SetPos(x+74,y+13);printf("MM");SetPos(x+79,y+13);printf("MMM");SetPos(x+83,y+13);printf("MM");
    SetPos(x+74,y+14);printf("MMMMM");SetPos(x+83,y+14);printf("MM");
    SetPos(x+75,y+15);printf("MMMMMMMMM");
}

void draw_title_u(int x,int y)
{
    SetPos(x+88,y+7);printf("MM");SetPos(x+100,y+7);printf("MM");
    SetPos(x+88,y+8);printf("MM");SetPos(x+100,y+8);printf("MM");
    SetPos(x+88,y+9);printf("MM");SetPos(x+100,y+9);printf("MM");
    SetPos(x+88,y+10);printf("MM");SetPos(x+100,y+10);printf("MM");
    SetPos(x+88,y+11);printf("MM");SetPos(x+100,y+11);printf("MM");
    SetPos(x+88,y+12);printf("MM");SetPos(x+100,y+12);printf("MM");
    SetPos(x+88,y+13);printf("MM");SetPos(x+100,y+13);printf("MM");SetPos(x+105,y+13);printf("M");
    SetPos(x+89,y+14);printf("MM");SetPos(x+99,y+14);printf("MMM");SetPos(x+104,y+14);printf("MM");
    SetPos(x+90,y+15);printf("MMMMMMMMMM");SetPos(x+101,y+15);printf("MMMM");
}

void draw_title_r2(int x,int y)
{
    SetPos(x+106,y+7);printf("MM");SetPos(x+111,y+7);printf("MMMMM");
    SetPos(x+106,y+8);printf("MM");SetPos(x+109,y+8);printf("MMM");
    SetPos(x+105,y+9);printf("MMMMM");
    SetPos(x+103,y+10);printf("MMMMM");
    SetPos(x+106,y+11);printf("MM");
    SetPos(x+106,y+12);printf("MM");
    SetPos(x+106,y+13);printf("MM");
    SetPos(x+106,y+14);printf("MM");
    SetPos(x+106,y+15);printf("MM");
}

void draw_title_e(int x,int y)
{
    SetPos(x+120,y+7);printf("MMMMMMM");
    SetPos(x+114,y+8);printf("M");SetPos(x+117,y+8);printf("MMMM");SetPos(x+126,y+8);printf("MM");
    SetPos(x+113,y+9);printf("M");SetPos(x+115,y+9);printf("MMM");SetPos(x+127,y+9);printf("MM");
    SetPos(x+113,y+10);printf("M");SetPos(x+115,y+10);printf("MM");SetPos(x+125,y+10);printf("MMMM");
    SetPos(x+113,y+11);printf("M");SetPos(x+115,y+11);printf("MM");SetPos(x+119,y+11);printf("MMMMMMMM");
    SetPos(x+114,y+12);printf("MMMMMM");
    SetPos(x+116,y+13);printf("MM");
    SetPos(x+116,y+14);printf("MM");SetPos(x+130,y+14);printf("MMM");
    SetPos(x+117,y+15);printf("MMM");SetPos(x+127,y+15);printf("MMMMM");
    SetPos(x+119,y+16);printf("MMMMMMMMM");
}
#endif // DRAW_TITLE_H_INCLUDED
