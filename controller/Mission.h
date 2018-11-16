///这是集合任务效果的头文件
#ifndef MISSION_H_INCLUDED
#define MISSION_H_INCLUDED

#include "HeroMod.h"
#define SOLO 1
#define DOUBLE 2
#define MULTI 3
DICE HeroCheck(DICE);

typedef void MISSION;

///角色升级的强化
void Levelup(HERO *py)
{
    switch (py->timeP)
    {
    case 1: ///剑圣
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setHolySwordsman();
        if (tempE >= 1) ///战斗+1
        {
            if (tempE >= 2) ///探索+1
            {
                if (tempE >= 3) ///生命全满
                {
                    if (tempE >= 4) ///资源上限+1
                    {
                        if (tempE >= 5) ///战力+1
                        {
                            if (tempE >= 6) ///战力+1
                                py->fightP++;
                            py->fightP++;
                        }
                        py->resourseMP++;
                    }
                    tempL = py->lifeMP;
                }
                py->exploreP++;
            }
            py->fightP++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 2: ///忍者
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setNinja();
        if (tempE >= 2) ///探索+1
        {
            if (tempE >= 4) ///战斗+1
            {
                if (tempE >= 7) ///资源上限+1
                    py->resourseMP++;
                py->fightP++;
            }
            py->exploreP++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 3: ///猎人
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setHunter();
        if (tempE >= 2) ///战斗+1
        {
            if (tempE >= 4) ///探索+1
            {
                if (tempE >= 7) ///战斗+1
                    py->fightP++;
                py->exploreP++;
            }
            py->fightP++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 4: ///角斗士
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setGladiator();
        if (tempE >= 2) ///冒险+1
        {
            if (tempE >= 4) ///战斗+1
            {
                if (tempE >= 7) ///生命全满
                    tempL = py->lifeMP;
                py->fightP++;
            }
            py->exploreP++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 5: ///王子
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setPrince();
        if (tempE >= 2) ///战斗、探索、资源上限+1
        {
            if (tempE >= 4) ///战斗、探索、资源上限+1
            {
                if (tempE >= 7) ///战斗、探索、资源上限+1
                {
                    py->fightP++;
                    py->exploreP++;
                    py->resourseMP++;
                }
                py->fightP++;
                py->exploreP++;
                py->resourseMP++;
            }
            py->fightP++;
            py->exploreP++;
            py->resourseMP++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 6: ///圣骑士
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setPrince();
        if (tempE >= 2) ///资源上限+1
        {
            if (tempE >= 4) ///生命全满
            {
                if (tempE >= 7) ///战力+1
                    py->fightP++;
                tempL = py->lifeMP;
            }
            py->resourseMP++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    default:
        break;
    }
}

/**任务初始化**/
///****************任务一：英雄的遗言状********************
MISSION HeroLastWords_2p(HERO *PY1, HERO *PY2)
{
    PY1->Exp++;
    PY2->Exp++;
    printf("任务成功！参与者每人获得1点Exp\n");
    Levelup(PY1);
    Levelup(PY2);
}
MISSION HeroLastWords_3p(HERO *PY1, HERO *PY2, HERO *PY3)
{
    PY1->Exp++;
    PY2->Exp++;
    PY3->Exp++;
    printf("任务成功！参与者每人获得1点Exp\n");
    Levelup(PY1);
    Levelup(PY2);
    Levelup(PY3);
}
///*******************任务二：迷之碑文**********************
MISSION Inscription_1p(HERO *PY)
{
    static int CP = 2;
    int DP = HeroCheck(PY->knowledgeP);
    if (DP >= CP)
    {
        printf("\n任务成功！获得2点Exp\n");
        PY->Exp += 2;
        Levelup(PY);
    }
    else
    {
        CP -= DP;
        if (CP > 2)
            CP = 2;
        printf("\n任务失败！还剩%d点完成\n", CP);
    }
}
MISSION Inscription_2p(HERO *PY, HERO *PY2)
{
    static int CP = 2;
    int DP = HeroCheck(PY->knowledgeP + PY2->knowledgeP);
    if (DP >= CP)
    {
        printf("\n任务成功！参与者每人获得1点Exp\n");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
    }
    else
    {
        CP -= DP;
        if (CP > 2)
            CP = 2;
        printf("\n任务失败！还剩%d点完成\n", CP);
    }
}
MISSION Inscription_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    static int CP = 2;
    int DP = HeroCheck(PY->knowledgeP + PY2->knowledgeP + PY3->knowledgeP);
    if (DP >= CP)
    {
        printf("\n任务成功！参与者每人获得1点Exp\n");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
    }
    else
    {
        CP -= DP;
        if (CP > 2)
            CP = 2;
        printf("\n任务失败！还剩%d点完成\n", CP);
    }
}
///********************任务三：魔像守护者***********************
MISSION MagicGuardian_1p(HERO *PY)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！\n");
        exit(1);
    }
    static int CP = 3;
    int DP = HeroCheck(PY->fightP);
    if (DP >= CP)
    {
        printf("\n任务成功！获得2点Exp\n");
        PY->Exp += 2;
        Levelup(PY);
    }
    else
    {
        CP -= DP;
        if (CP > 3)
            CP = 3;
        printf("\n任务失败！还剩%d点完成\n", CP);
    }
}
MISSION MagicGuardian_2p(HERO *PY, HERO *PY2)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！\n");
        exit(1);
    }
    static int CP = 3;
    int DP = HeroCheck(PY->fightP + PY2->fightP);
    if (DP >= CP)
    {
        printf("\n任务成功！参与者每人获得1点Exp\n");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
    }
    else
    {
        CP -= DP;
        if (CP > 3)
            CP = 3;
        printf("\n任务失败！还剩%d点完成\n", CP);
    }
}
MISSION MagicGuardian_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！\n");
        exit(1);
    }
    static int CP = 3;
    int DP = HeroCheck(PY->fightP + PY2->fightP + PY3->fightP);
    if (DP >= CP)
    {
        printf("\n任务成功！参与者每人获得1点Exp\n");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
    }
    else
    {
        CP -= DP;
        if (CP > 3)
            CP = 3;
        printf("\n任务失败！还剩%d点完成\n", CP);
    }
}
///*************************任务四：哥布林小队*************************
MISSION GoblinTeam_1p(HERO *PY)
{
    static int CP = 3;
    int DP = HeroCheck(PY->fightP);
    if (DP >= CP)
    {
        printf("\n任务成功！获得2点Exp\n");
        PY->Exp += 3;
        Levelup(PY);
    }
    else
    {
        PY->lifeP--;
        CP -= DP;
        if (CP > 3)
            CP = 3;
        printf("\n任务失败！挑战者受到1点伤害，还剩%d点完成\n", CP);
    }
}
MISSION GoblinTeam_2p(HERO *PY, HERO *PY2)
{
    static int CP = 3;
    int DP = HeroCheck(PY->fightP + PY2->fightP);
    if (DP >= CP)
    {
        printf("\n任务成功！参与者每人获得1点Exp\n");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
    }
    else
    {
        PY->lifeP--;
        CP -= DP;
        if (CP > 3)
            CP = 3;
        printf("\n任务失败！挑战者受到1点伤害，还剩%d点完成\n", CP);
    }
}
MISSION GoblinTeam_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    static int CP = 3;
    int DP = HeroCheck(PY->fightP + PY2->fightP + PY3->fightP);
    if (DP >= CP)
    {
        printf("\n任务成功！参与者每人获得1点Exp\n");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
    }
    else
    {
        PY->lifeP--;
        CP -= DP;
        if (CP > 3)
            CP = 3;
        printf("\n任务失败！挑战者受到1点伤害，还剩%d点完成\n", CP);
    }
}
///***************************任务五：魔兽奇美拉***************************
MISSION Chimera_1p(HERO *PY)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！\n");
        exit(1);
    }
    static int CP = 2;
    int DP = HeroCheck(PY->fightP);
    if (DP >= CP)
    {
        printf("\n任务成功！获得2点Exp\n");
        PY->Exp += 2;
        Levelup(PY);
    }
    else
    {
        PY->lifeP--;
        CP -= DP;
        if (CP > 2)
            CP = 2;
        printf("\n任务失败！挑战者受到1点伤害，还剩%d点完成\n", CP);
    }
}
MISSION Chimera_2p(HERO *PY, HERO *PY2)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！\n");
        exit(1);
    }
    static int CP = 2;
    int DP = HeroCheck(PY->fightP + PY2->fightP);
    if (DP >= CP)
    {
        printf("\n任务成功！ 参与者每人获得1点Exp\n");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
    }
    else
    {
        PY->lifeP--;
        CP -= DP;
        if (CP > 2)
            CP = 2;
        printf("\n任务失败！挑战者受到1点伤害，还剩%d点完成\n", CP);
    }
}
MISSION Chimera_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！\n");
        exit(1);
    }
    static int CP = 2;
    int DP = HeroCheck(PY->fightP + PY2->fightP + PY3->fightP);
    if (DP >= CP)
    {
        printf("\n任务成功！参与者每人获得1点Exp\n");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
    }
    else
    {
        PY->lifeP--;
        CP -= DP;
        if (CP > 2)
            CP = 2;
        printf("\n任务失败！挑战者受到1点伤害，还剩%d点完成\n", CP);
    }
}
///*****************************任务六：斯芬克斯之谜**********************
MISSION SphinxMystery_1p(HERO *PY)
{
    static int CP = 1;
    int DP = HeroCheck(PY->knowledgeP);
    if (DP >= CP)
    {
        printf("任务成功！获得2点Exp\n");
        PY->Exp += 2;
        Levelup(PY);
    }
    else
    {
        PY->lifeP -= 2;
        CP -= DP;
        if (CP > 1)
            CP = 1;
        printf("\n任务失败！挑战者受到2点伤害，还剩%d点完成\n", CP);
    }
}

/********************任务奖励************************/
void DraBook(HERO *py1, HERO *py2, HERO *py3) ///任务奖励：秘龙之书（1）
{
    printf("获得秘龙之书！所有人经验值+1\n");
    py1->Exp++;
    py2->Exp++;
    py3->Exp++;
}

void DraWeapon(HERO *py1, HERO *py2, HERO *py3) ///任务奖励：屠龙武器（2）
{
    printf("获得屠龙武器！所有人战斗力+1\n");
    py1->fightP++;
    py2->fightP++;
    py3->fightP++;
}

void DraMapPlece(Dragonic *Dra) ///任务奖励：匿龙地图（3）
{
    printf("获得匿龙地图！龙遭受一次突袭，受到1点伤害\n");
    Dra->lifeD--;
}

void DraBlood(HERO *py1, HERO *py2, HERO *py3) ///任务奖励：古龙之血（4）
{
    printf("获得古龙之血！所有人生命值全回复\n");
    py1->lifeP = py1->lifeMP;
    py2->lifeP = py2->lifeMP;
    py3->lifeP = py3->lifeMP;
}

void DraTreasure(HERO *py) ///任务奖励：龙之秘宝（5）
{
    printf("获得龙之秘宝！启动秘宝效果\n");
    py->Treasure = TRUE;
}

#endif
