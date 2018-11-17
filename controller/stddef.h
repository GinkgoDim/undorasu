///这是集合系统头文件和宏定义的头文件
#ifndef STDDEF_H_INCLUDED
#define STDDEF_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> ///linux上类似Windows.h的头文件
#include <malloc.h>

#define FALSE 0
#define ERROR -1

int getMAX(int *dice, int num) ///获取最大值
{
    int i, maxD, maxI;
    maxD = dice[0];
    maxI = 0;
    for (i = 0; i < num; i++)
    {
        if (dice[i] > maxD)
        {
            maxD = dice[i];
            maxI = i;
        }
    }
    return maxI + 1;
}

int getMIN(int *dice, int num) ///获取最小值
{
    int i, minD, minI;
    minD = dice[0];
    minI = 0;
    for (i = 0; i < num; i++)
    {
        if (dice[i] < minD)
        {
            minD = dice[i];
            minI = i;
        }
    }
    return minI + 1;
}

#endif // STDDEF_H_INCLUDED
