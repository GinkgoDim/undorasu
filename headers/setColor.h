#ifndef SETCOLOR_H_INCLUDED
#define SETCOLOR_H_INCLUDED

void setColor(unsigned short ForeColor,unsigned short BackGroundColor)///��һ�������Ǳ�����ɫ���ڶ���������������ɫ
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��ǰ���ھ��
    SetConsoleTextAttribute(handle,ForeColor+BackGroundColor*0x10);//������ɫ
}

#endif // SETCOLOR_H_INCLUDED
