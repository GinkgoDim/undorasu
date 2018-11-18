#ifndef EMERGENCY_DECORATION_H_INCLUDED
#define EMERGENCY_DECORATION_H_INCLUDED

void fn_clear_middle();
void fn_clear_down();
void fn_clear_right();
void fn_clear_down2();

void emergency_decoration(int i)
{
    switch(i)
    {
    case 1:
        fn_clear_middle();break;
    case 2:
        fn_clear_down();break;
    case 3:
        fn_clear_right();break;
    case 4:
        fn_clear_down2();break;
    default:
        break;
    }
}

void fn_clear_middle()///清除中央矩形区域
{
    setColor(7,0);
    int x=6,y=2,i,j;
    ///清除范围为 6,2 到 107,41
    for(i=0;i<40;i++)
        for(j=0;j<102;j+=17)
        {
            SetPos(x+j,y+i);printf("                 ");///17个空格,相当于每行循环6遍
        }
}

void fn_clear_down()///清除下方输入区域
{
    setColor(7,0);
    int x=6,y=44,i;
    for(i=0;i<102;i+=17)
    {
        SetPos(x+i,y);printf("                 ");
    }
    SetPos(x,y);
}

void fn_clear_right()///清除右侧输入区域
{//113,2 139,41
    setColor(7,0);
    int x=113,y=2,i;
    for(i=0;i<=39;i++)
    {
        //SetPos(x,y+i);printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@");///26个空
        SetPos(x,y+i);printf("                           ");///26个空
    }
    SetPos(x,y);
}

void fn_clear_down2()///清除下方第二行输入区域
{
    setColor(7,0);
    int x=6,y=45,i;
    for(i=0;i<102;i+=17)
    {
        SetPos(x+i,y);printf("                 ");
    }
    SetPos(x,y);
}
#endif // EMERGENCY_DECORATION_H_INCLUDED
