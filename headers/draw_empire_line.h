#ifndef DRAW_EMPIRE_LINE_H
#define DRAW_EMPIRE_LINE_H
void draw_empire_line();
void draw_empire_line_draw_line1();
void draw_empire_line_draw_line2();
void draw_empire_line_draw_apart_y(int x,int y);///纵向分隔符
void draw_empire_line_draw_apart_x(int x,int y);///横向分隔符

void draw_empire_line()
{
    ///绘制分隔符
    draw_empire_line_draw_apart_x(146,0);
    draw_empire_line_draw_apart_x(146,1);
    draw_empire_line_draw_apart_x(146,42);
    draw_empire_line_draw_apart_x(146,43);
    draw_empire_line_draw_apart_y(110,46);
    draw_empire_line_draw_apart_y(140,46);
    draw_empire_line_draw_apart_y(3,46);
}

void draw_empire_line_draw_line1()
{
    setColor(7,0);printf("| |");
}
void draw_empire_line_draw_line2()
{
    setColor(7,0);printf("_");
}

void draw_empire_line_draw_apart_y(int x,int y)///纵向分隔符
{
    int i;
    for(i=0;i<y;i++)
    {
        SetPos(x,i);draw_empire_line_draw_line1();
    }
}
void draw_empire_line_draw_apart_x(int x,int y)///横向分隔符
{
    int i;
    SetPos(0,y);
    for(i=0;i<x;i++)
        draw_empire_line_draw_line2();
}
#endif // DRAW_EMPIRE_LINE_H
