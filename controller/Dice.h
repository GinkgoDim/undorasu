///这是集合骰子功能的头文件
#ifndef DICE_H_INCLUDED
#define DICE_H_INCLUDED

#include "stddef.h"
typedef int DICE;

///骰子控制函数
void D6(int *p,int frequency)
{
    int i;
    srand((unsigned)(time(NULL)));
    sleep(1);
    for(i=0;i<frequency;i++)
        *(p+i)=rand()%6+1;
}  ///1s刷新一次
DICE DraD6() ///单个骰子返回值函数
{
    srand((unsigned)(time(NULL)));
    sleep(1);
    return rand()%6+1;
}
void HeroD6(int *p,int num) ///用于每个人投掷骰子的龙骰判定
{
    int i;
    srand((unsigned)(time(NULL)));
    for(i=0;i<num;i++)
    {
        printf("%d号玩家请投骰：",i+1);
        ///system("pause");
        printf("您的结果是：");
        sleep(1);
        *(p+i)=rand()%6+1;
        printf("%d",*(p+i));
        putchar(10);
    }
}

#endif // DICE_H_INCLUDED
