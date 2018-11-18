#ifndef NUMBER_ROME_H_INCLUDED
#define NUMBER_ROME_H_INCLUDED

void DRAW_ROME_num_all(int,int,int);
void DRAW_ROME_num_1(int,int);
void DRAW_ROME_num_2(int,int);
void DRAW_ROME_num_3(int,int);
void DRAW_ROME_num_4(int,int);
void DRAW_ROME_num_5(int,int);
void DRAW_ROME_num_6(int,int);
void DRAW_ROME_num_7(int,int);
void DRAW_ROME_num_8(int,int);
void DRAW_ROME_num_9(int,int);
void DRAW_ROME_num_10(int,int);
void DRAW_ROME_num_11(int,int);
void DRAW_ROME_num_12(int,int);
void DRAW_ROME_num_13(int,int);
void DRAW_ROME_num_14(int,int);
void DRAW_ROME_num_15(int,int);

/*
��Ӧ����ɫ���
0 = ��ɫ       8 = ��ɫ
1 = ��ɫ       9 = ����ɫ
2 = ��ɫ       10 = ����ɫ
3 = ǳ��ɫ     11 = ��ǳ��ɫ
4 = ��ɫ       12 = ����ɫ
5 = ��ɫ       13 = ����ɫ
6 = ��ɫ       14 = ����ɫ
7 = ��ɫ       15 = ����ɫ
*/
///�÷��� x���� y���� ������ɫ ������ɫ ��ʾ����
void number_ROME(int X,int Y,int CB,int CF,int NUM)
{
    int x,y,cf,cb;
    int i,num;
    //x=0;y=1;///�궨����ͼ�ε����Ͻ�λ��
    x=X;y=Y;
    //cf=7;cb=0;///Ϊ����ͱ���������ɫ
    cf=CF;cb=CB;
    //scanf("%d",&num);///������Ҫ��ӡ������
    num=NUM;

    setColor(7,0);///�趨���ո��ַ���ɫΪ���ֺڵ�
    for(i=0;i<8;i++)
    {
        SetPos(x,y+i);
        printf("                ");///ִ��ÿ��16������ַ��������һ��8��
    }
    setColor(cb,cf);
    DRAW_ROME_num_all(num,x,y);///ִ�л��Ƴ���

    setColor(7,0);
}

void DRAW_ROME_num_all(int num,int x,int y)
{
    switch(num)
    {
        case 1:DRAW_ROME_num_1(x,y);break;
        case 2:DRAW_ROME_num_2(x,y);break;
        case 3:DRAW_ROME_num_3(x,y);break;
        case 4:DRAW_ROME_num_4(x,y);break;
        case 5:DRAW_ROME_num_5(x,y);break;
        case 6:DRAW_ROME_num_6(x,y);break;
        case 7:DRAW_ROME_num_7(x,y);break;
        case 8:DRAW_ROME_num_8(x,y);break;
        case 9:DRAW_ROME_num_9(x,y);break;
        case 10:DRAW_ROME_num_10(x,y);break;
        case 11:DRAW_ROME_num_11(x,y);break;
        case 12:DRAW_ROME_num_12(x,y);break;
        case 13:DRAW_ROME_num_13(x,y);break;
        case 14:DRAW_ROME_num_14(x,y);break;
        case 15:DRAW_ROME_num_15(x,y);break;
        default:break;
    }
}

void DRAW_ROME_num_1(int x,int y)
{
    SetPos(x+5,y+1);printf("      ");
    SetPos(x+7,y+2);printf("  ");
    SetPos(x+7,y+3);printf("  ");
    SetPos(x+7,y+4);printf("  ");
    SetPos(x+7,y+5);printf("  ");
    SetPos(x+5,y+6);printf("      ");
}
void DRAW_ROME_num_2(int x,int y)
{
    SetPos(x+4,y+1);printf("        ");
    SetPos(x+5,y+2);printf("  ");SetPos(x+9,y+2);printf("  ");
    SetPos(x+5,y+3);printf("  ");SetPos(x+9,y+3);printf("  ");
    SetPos(x+5,y+4);printf("  ");SetPos(x+9,y+4);printf("  ");
    SetPos(x+5,y+5);printf("  ");SetPos(x+9,y+5);printf("  ");
    SetPos(x+4,y+6);printf("        ");
}
void DRAW_ROME_num_3(int x,int y)
{
    SetPos(x+3,y+1);printf("          ");
    SetPos(x+4,y+2);printf("  ");SetPos(x+7,y+2);printf("  ");SetPos(x+10,y+2);printf("  ");
    SetPos(x+4,y+3);printf("  ");SetPos(x+7,y+3);printf("  ");SetPos(x+10,y+3);printf("  ");
    SetPos(x+4,y+4);printf("  ");SetPos(x+7,y+4);printf("  ");SetPos(x+10,y+4);printf("  ");
    SetPos(x+4,y+5);printf("  ");SetPos(x+7,y+5);printf("  ");SetPos(x+10,y+5);printf("  ");
    SetPos(x+3,y+6);printf("          ");
}
void DRAW_ROME_num_4(int x,int y)
{
    SetPos(x+3,y+1);printf("          ");
    SetPos(x+4,y+2);printf("  ");SetPos(x+7,y+2);printf("  ");SetPos(x+10,y+2);printf("  ");
    SetPos(x+4,y+3);printf("  ");SetPos(x+7,y+3);printf("  ");SetPos(x+10,y+3);printf("  ");
    SetPos(x+4,y+4);printf("  ");SetPos(x+7,y+4);printf("  ");SetPos(x+10,y+4);printf("  ");
    SetPos(x+4,y+5);printf("  ");SetPos(x+8,y+5);printf("   ");
    SetPos(x+3,y+6);printf("    ");SetPos(x+9,y+6);printf(" ");
}
void DRAW_ROME_num_5(int x,int y)
{
    SetPos(x+3,y+1);printf("    ");SetPos(x+9,y+1);printf("    ");
    SetPos(x+4,y+2);printf("  ");SetPos(x+10,y+2);printf("  ");
    SetPos(x+4,y+3);printf("  ");SetPos(x+10,y+3);printf("  ");
    SetPos(x+5,y+4);printf("  ");SetPos(x+9,y+4);printf("  ");
    SetPos(x+6,y+5);printf("    ");
    SetPos(x+7,y+6);printf("  ");
}
void DRAW_ROME_num_6(int x,int y)
{
    SetPos(x+3,y+1);printf("          ");
    SetPos(x+4,y+2);printf("  ");SetPos(x+7,y+2);printf("  ");SetPos(x+10,y+2);printf("  ");
    SetPos(x+4,y+3);printf("  ");SetPos(x+7,y+3);printf("  ");SetPos(x+10,y+3);printf("  ");
    SetPos(x+4,y+4);printf("  ");SetPos(x+7,y+4);printf("  ");SetPos(x+10,y+4);printf("  ");
    SetPos(x+5,y+5);printf("   ");SetPos(x+10,y+5);printf("  ");
    SetPos(x+6,y+6);printf(" ");SetPos(x+9,y+6);printf("    ");

}
void DRAW_ROME_num_7(int x,int y)
{
    SetPos(x+3,y+1);printf("          ");
    SetPos(x+4,y+2);printf(" ");SetPos(x+6,y+2);printf(" ");SetPos(x+9,y+2);printf(" ");SetPos(x+11,y+2);printf(" ");
    SetPos(x+4,y+3);printf(" ");SetPos(x+6,y+3);printf(" ");SetPos(x+9,y+3);printf(" ");SetPos(x+11,y+3);printf(" ");
    SetPos(x+4,y+4);printf(" ");SetPos(x+6,y+4);printf(" ");SetPos(x+9,y+4);printf(" ");SetPos(x+11,y+4);printf(" ");
    SetPos(x+5,y+5);printf(" ");SetPos(x+9,y+5);printf(" ");SetPos(x+11,y+5);printf(" ");
    SetPos(x+5,y+6);printf(" ");SetPos(x+8,y+6);printf("     ");
}
void DRAW_ROME_num_8(int x,int y)
{
    SetPos(x+2,y+1);printf("            ");
    SetPos(x+3,y+2);printf(" ");SetPos(x+5,y+2);printf(" ");SetPos(x+8,y+2);printf(" ");SetPos(x+10,y+2);printf(" ");SetPos(x+12,y+2);printf(" ");
    SetPos(x+3,y+3);printf(" ");SetPos(x+5,y+3);printf(" ");SetPos(x+8,y+3);printf(" ");SetPos(x+10,y+3);printf(" ");SetPos(x+12,y+3);printf(" ");
    SetPos(x+3,y+4);printf(" ");SetPos(x+5,y+4);printf(" ");SetPos(x+8,y+4);printf(" ");SetPos(x+10,y+4);printf(" ");SetPos(x+12,y+4);printf(" ");
    SetPos(x+4,y+5);printf(" ");SetPos(x+8,y+5);printf(" ");SetPos(x+10,y+5);printf(" ");SetPos(x+12,y+5);printf(" ");
    SetPos(x+4,y+6);printf(" ");SetPos(x+7,y+6);printf("       ");
}
void DRAW_ROME_num_9(int x,int y)
{
    SetPos(x+3,y+1);printf("          ");
    SetPos(x+4,y+2);printf("  ");SetPos(x+7,y+2);printf("  ");SetPos(x+10,y+2);printf("  ");
    SetPos(x+4,y+3);printf("  ");SetPos(x+8,y+3);printf("   ");
    SetPos(x+4,y+4);printf("  ");SetPos(x+8,y+4);printf("   ");
    SetPos(x+4,y+5);printf("  ");SetPos(x+7,y+5);printf("  ");SetPos(x+10,y+5);printf("  ");
    SetPos(x+3,y+6);printf("          ");
}
void DRAW_ROME_num_10(int x,int y)
{
    SetPos(x+3,y+1);printf("          ");
    SetPos(x+4,y+2);printf("   ");SetPos(x+9,y+2);printf("   ");
    SetPos(x+6,y+3);printf("    ");
    SetPos(x+6,y+4);printf("    ");
    SetPos(x+4,y+5);printf("   ");SetPos(x+9,y+5);printf("   ");
    SetPos(x+3,y+6);printf("          ");
}
void DRAW_ROME_num_11(int x,int y)
{
    SetPos(x+3,y+1);printf("          ");
    SetPos(x+4,y+2);printf("  ");SetPos(x+7,y+2);printf("  ");SetPos(x+10,y+2);printf("  ");
    SetPos(x+5,y+3);printf("   ");SetPos(x+10,y+3);printf("  ");
    SetPos(x+5,y+4);printf("   ");SetPos(x+10,y+4);printf("  ");
    SetPos(x+4,y+5);printf("  ");SetPos(x+7,y+5);printf("  ");SetPos(x+10,y+5);printf("  ");
    SetPos(x+3,y+6);printf("          ");
}
void DRAW_ROME_num_12(int x,int y)
{
    SetPos(x+2,y+1);printf("            ");
    SetPos(x+3,y+2);printf("  ");SetPos(x+6,y+2);printf("  ");SetPos(x+10,y+2);printf(" ");SetPos(x+12,y+2);printf(" ");
    SetPos(x+4,y+3);printf("   ");SetPos(x+10,y+3);printf(" ");SetPos(x+12,y+3);printf(" ");
    SetPos(x+4,y+4);printf("   ");SetPos(x+10,y+4);printf(" ");SetPos(x+12,y+4);printf(" ");
    SetPos(x+3,y+5);printf("  ");SetPos(x+6,y+5);printf("  ");SetPos(x+10,y+5);printf(" ");SetPos(x+12,y+5);printf(" ");
    SetPos(x+2,y+6);printf("            ");
}
void DRAW_ROME_num_13(int x,int y)
{
    SetPos(x+1,y+1);printf("              ");
    SetPos(x+2,y+2);printf("  ");SetPos(x+5,y+2);printf("  ");SetPos(x+9,y+2);printf(" ");SetPos(x+11,y+2);printf(" ");SetPos(x+13,y+2);printf(" ");
    SetPos(x+3,y+3);printf("   ");SetPos(x+9,y+3);printf(" ");SetPos(x+11,y+3);printf(" ");SetPos(x+13,y+3);printf(" ");
    SetPos(x+3,y+4);printf("   ");SetPos(x+9,y+4);printf(" ");SetPos(x+11,y+4);printf(" ");SetPos(x+13,y+4);printf(" ");
    SetPos(x+2,y+5);printf("  ");SetPos(x+5,y+5);printf("  ");SetPos(x+9,y+5);printf(" ");SetPos(x+11,y+5);printf(" ");SetPos(x+13,y+5);printf(" ");
    SetPos(x+1,y+6);printf("              ");
}
void DRAW_ROME_num_14(int x,int y)
{
    SetPos(x+1,y+1);printf("              ");
    SetPos(x+2,y+2);printf("  ");SetPos(x+5,y+2);printf("  ");SetPos(x+9,y+2);printf(" ");SetPos(x+11,y+2);printf(" ");SetPos(x+13,y+2);printf(" ");
    SetPos(x+3,y+3);printf("   ");SetPos(x+9,y+3);printf(" ");SetPos(x+11,y+3);printf(" ");SetPos(x+13,y+3);printf(" ");
    SetPos(x+3,y+4);printf("   ");SetPos(x+9,y+4);printf(" ");SetPos(x+11,y+4);printf(" ");SetPos(x+13,y+4);printf(" ");
    SetPos(x+2,y+5);printf("  ");SetPos(x+5,y+5);printf("  ");SetPos(x+9,y+5);printf(" ");SetPos(x+12,y+5);printf(" ");
    SetPos(x+1,y+6);printf("          ");SetPos(x+12,y+6);printf(" ");
}
void DRAW_ROME_num_15(int x,int y)
{
    SetPos(x+1,y+1);printf("              ");
    SetPos(x+2,y+2);printf("  ");SetPos(x+5,y+2);printf("  ");SetPos(x+9,y+2);printf("  ");SetPos(x+12,y+2);printf("  ");
    SetPos(x+3,y+3);printf("   ");SetPos(x+9,y+3);printf("  ");SetPos(x+12,y+3);printf("  ");
    SetPos(x+3,y+4);printf("   ");SetPos(x+9,y+4);printf("  ");SetPos(x+12,y+4);printf("  ");
    SetPos(x+2,y+5);printf("  ");SetPos(x+5,y+5);printf("  ");SetPos(x+10,y+5);printf("   ");
    SetPos(x+1,y+6);printf("       ");SetPos(x+11,y+6);printf(" ");
}

#endif // NUMBER_ROME_H_INCLUDED
