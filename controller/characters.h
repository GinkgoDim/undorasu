///这是用于初始化各种游戏内起始数据的头文件
#ifndef CHARACTERS_H_INCLUDED
#define CHARACTERS_H_INCLUDED

#include "stddef.h"
#include "Dice.h"
#define TRUE 1
#define FALSE 0
typedef int BOOL;

///结构体部分
typedef struct ///定义结构体HERO
{
    BOOL Treasure;           ///宝藏值
    int timeP;               ///顺序值
    int lifeP;               ///生命值
    unsigned int lifeMP;     ///生命值上限
    unsigned int actionP;    ///行动力
    unsigned int fightP;     ///战力
    unsigned int knowledgeP; ///知识
    unsigned int exploreP;   ///探索值
    unsigned int advP_F;     ///森林冒险力
    unsigned int advP_P;     ///平原冒险力
    unsigned int resourseP;  ///资源
    unsigned int resourseMP; ///资源上限
    unsigned int Exp;        ///初始经验值
    unsigned int Level;      ///初始等级
} HERO;

HERO player[6];

typedef struct ///定义龙种结构体Dragonic
{
    int angerD; ///龙怒值
    int lifeD;  ///龙生命值
} Dragonic;

///玩家初始化
HERO setHolySwordsman(void) ///设定剑圣默认数据
{
    player[0].Treasure = FALSE;
    player[0].actionP = 4;
    player[0].advP_F = 2;
    player[0].advP_P = 2;
    player[0].Exp = 0;
    player[0].exploreP = 2;
    player[0].fightP = 2;
    player[0].knowledgeP = 2;
    player[0].Level = 1;
    player[0].lifeMP = 6;
    player[0].lifeP = 6;
    player[0].resourseMP = 3;
    player[0].resourseP = 3;
    player[0].timeP = 1;
    return player[0];
}
HERO setNinja(void) ///设定忍者默认数据
{
    player[1].Treasure = FALSE;
    player[1].actionP = 4;
    player[1].advP_F = 3;
    player[1].advP_P = 1;
    player[1].Exp = 0;
    player[1].exploreP = 3;
    player[1].fightP = 2;
    player[1].knowledgeP = 1;
    player[1].Level = 1;
    player[1].lifeMP = 4;
    player[1].lifeP = 4;
    player[1].resourseMP = 2;
    player[1].resourseP = 1;
    player[1].timeP = 2;
    return player[1];
}
HERO setHunter(void) ///设定猎人默认数据
{
    player[2].Treasure = FALSE;
    player[2].actionP = 3;
    player[2].advP_F = 2;
    player[2].advP_P = 2;
    player[2].Exp = 0;
    player[2].exploreP = 2;
    player[2].fightP = 2;
    player[2].knowledgeP = 2;
    player[2].Level = 1;
    player[2].lifeMP = 5;
    player[2].lifeP = 5;
    player[2].resourseMP = 3;
    player[2].resourseP = 3;
    player[2].timeP = 3;
    return player[2];
}
HERO setGladiator(void) ///设定角斗士默认数据
{
    player[3].Treasure = FALSE;
    player[3].actionP = 3;
    player[3].advP_F = 1;
    player[3].advP_P = 2;
    player[3].Exp = 0;
    player[3].exploreP = 1;
    player[3].fightP = 4;
    player[3].knowledgeP = 1;
    player[3].Level = 1;
    player[3].lifeMP = 6;
    player[3].lifeP = 5;
    player[3].resourseMP = 0;
    player[3].resourseP = 0;
    player[3].timeP = 4;
    return player[3];
}
HERO setPrince(void) ///设定王子默认数据
{
    player[4].Treasure = FALSE;
    player[4].actionP = 3;
    player[4].advP_F = 1;
    player[4].advP_P = 2;
    player[4].Exp = 0;
    player[4].exploreP = 1;
    player[4].fightP = 1;
    player[4].knowledgeP = 3;
    player[4].Level = 1;
    player[4].lifeMP = 4;
    player[4].lifeP = 4;
    player[4].resourseMP = 0;
    player[4].resourseP = 1;
    player[4].timeP = 5;
    return player[4];
}
HERO setPaladin(void) ///设定圣骑士默认数据
{
    player[5].Treasure = FALSE;
    player[5].actionP = 3;
    player[5].advP_F = 1;
    player[5].advP_P = 2;
    player[5].Exp = 0;
    player[5].exploreP = 1;
    player[5].fightP = 3;
    player[5].knowledgeP = 2;
    player[5].Level = 1;
    player[5].lifeMP = 6;
    player[5].lifeP = 5;
    player[5].resourseMP = 2;
    player[5].resourseP = 2;
    player[5].timeP = 6;
    return player[5];
}
///龙初始化
Dragonic setSingleDarkDragon(Dragonic dra) ///设定单龙副本
{
    dra.angerD = 15;
    dra.lifeD = 9;
    return dra;
}

#endif // CHARACTERS_H_INCLUDED
