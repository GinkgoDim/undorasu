#ifndef SETPOS_H_INCLUDED
#define SETPOS_H_INCLUDED

void SetPos(int x,int y)//���õ�ǰ���λ�ã���һ��Ϊ���ᣬ�ڶ���Ϊ����
{
    COORD pos;
    HANDLE handle;
    pos.X=x;
    pos.Y=y;
    handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,pos);
}

#endif // SETPOS_H_INCLUDED
