///这是集合龙种行动的头文件
#ifndef DRAGONICMOD_H_INCLUDED
#define DRAGONICMOD_H_INCLUDED

#include "characters.h"
 void showDragonAnger(Dragonic dra) ///展示龙怒气值的函数
 {
     int i;
     printf("龙怒：");
     for(i=dra.angerD-1;i>=0;i--)
     {
         if(i==13||i==10||i==7||i==4||i==1)
             putchar('X');  ///实际中推荐X使用红色背景色
         else
             putchar('O');  ///实际中推荐O使用白色背景色
     }///010 010 010 010 010
 }

 void showDragonLife(Dragonic dra) ///展示龙生命值的函数
 {
     int i;
     printf("龙命：");
     for(i=dra.lifeD-1;i>=0;i--)
     {
         if(i%2==0)
             putchar('O');
         else
            putchar('X');
     }
     ///putchar('\n');
 }

 void DragonDisaster(HERO *PY1, HERO *PY2, HERO *PY3) ///龙祸判定函数
{
    int DD = DraD6(), DiceD[MULTI] = {0}; ///龙骰DD
    int maxPY, minPY;
    printf("恶龙飞出了巢穴！！！\n");
    printf("龙祸判定：(%d) !!!\n", DD);
    switch (DD)
    {
    case 1: ///烧毁村庄
        printf("恶龙将贝尔村焚为废墟，从此贝尔村无法进入！\n");
        printf("在贝尔村的玩家将受到2点伤害！\n");
        /**
        map[0][1]=-1;
        if(map[0][1]) ///如果有人
        {
            PY.lifeP-=2;
        }
        **/
        break;
    case 2: ///最高流放回城
        printf("来自恶龙的突袭！所有玩家投一骰子\n");
        printf("点数最高的玩家将不幸被恶龙带回主城\n");
        HeroD6(DiceD, MULTI);
        maxPY = getMAX(DiceD, MULTI);
        /**
         **/
        break;
    case 3: ///全体-1HP
        printf("恶龙对你们所有人使用了摆尾！\n");
        printf("所有在场的玩家受到1点伤害！");
        PY1->lifeP--;
        PY2->lifeP--;
        PY3->lifeP--;
        break;
    case 4: ///最低者-2HP
        printf("恶龙愤怒的践踏！所有玩家投一骰子！\n");
        printf("点数最低的玩家没有躲开，受到2点伤害！\n");
        HeroD6(DiceD, MULTI);
        minPY = getMIN(DiceD, MULTI);
        switch (minPY)
        {
        case 1:
            PY1->lifeP -= 2;
            break;
        case 2:
            PY2->lifeP -= 2;
            break;
        case 3:
            PY3->lifeP -= 2;
            break;
        default:
            break;
        }
        break;
    case 5: ///最高者-2HP
        printf("恶龙吐出了火球！所有玩家投一骰子！\n");
        printf("点数最高的玩家受到攻击，受到2点伤害！\n");
        HeroD6(DiceD, MULTI);
        maxPY = getMAX(DiceD, MULTI);
        switch (maxPY)
        {
        case 1:
            PY1->lifeP -= 2;
            break;
        case 2:
            PY2->lifeP -= 2;
            break;
        case 3:
            PY3->lifeP -= 2;
            break;
        default:
            break;
        }
        break;
    case 6: ///最低者资源清空
        printf("恶龙恐怖的龙息！所有玩家投一骰子！\n");
        printf("点数最低的玩家受到重伤，资源清空！\n");
        HeroD6(DiceD, MULTI);
        minPY = getMIN(DiceD, MULTI);
        switch (minPY)
        {
        case 1:
            PY1->resourseP = 0;
            break;
        case 2:
            PY2->resourseP = 0;
            break;
        case 3:
            PY3->resourseP = 0;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

int DragonAnger(int num, Dragonic *dra, int pynum) ///龙怒气值变化函数
{
    unsigned int angerN=num/1000;
    int DD=0;
    if(dra->angerD-angerN>=0)
    {
        while(angerN>0)
        {
            dra->angerD--;
            angerN--;
            if(dra->angerD==13||dra->angerD==10||dra->angerD==7||dra->angerD==4||dra->angerD==1)
            {
                putchar(10);
                DD++;
            }
        }
    }
    else
    {//010010010010010
        if(((dra->angerD+1)%3)!=0)
        {
            DD+=(dra->angerD+1)%3;
        }
        dra->angerD=0;
    }
    return DD;
}

#endif // DRAGONICMOD_H_INCLUDED
