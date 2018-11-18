#ifndef SETCOLOR_H_INCLUDED
#define SETCOLOR_H_INCLUDED

void setColor(unsigned short ForeColor,unsigned short BackGroundColor)///第一个参数是背景颜色，第二个参数是字体颜色
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
    SetConsoleTextAttribute(handle,ForeColor+BackGroundColor*0x10);//设置颜色
}

#endif // SETCOLOR_H_INCLUDED
