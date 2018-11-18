#ifndef SETPOS_H_INCLUDED
#define SETPOS_H_INCLUDED

void SetPos(int x,int y)//设置当前光标位置，第一个为横轴，第二个为纵轴
{
    COORD pos;
    HANDLE handle;
    pos.X=x;
    pos.Y=y;
    handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,pos);
}

#endif // SETPOS_H_INCLUDED
