///这是集合任务效果的头文件
#ifndef MISSION_H_INCLUDED
#define MISSION_H_INCLUDED

DICE HeroCheck(DICE);

typedef int MISSION;
extern int map_mountain[6];
extern int count;
extern HERO py[3];
extern Dragonic dra;
extern int map_block[7][8];
extern int CP_2,CP_3,CP_4,CP_5,CP_6;

void mission_mountain(int mountain,int out);

void DraTreasure(HERO *,MISSION); ///任务奖励：龙之秘宝（5）
void DraBlood(HERO py[],int pynum,MISSION out); ///任务奖励：古龙之血（4）
void DraMapPlece(Dragonic *Dra,MISSION out); ///任务奖励：匿龙地图（3）
void DraWeapon(HERO py[],int pynum,MISSION out); ///任务奖励：屠龙武器（2）
void DraBook(HERO py[],int pynum,MISSION out); ///任务奖励：秘龙之书（1）
void mission_reward(int n,int n_loop,int pynum,MISSION out);

MISSION HeroLastWords_2p(HERO *PY1, HERO *PY2);
MISSION HeroLastWords_3p(HERO *PY1, HERO *PY2, HERO *PY3);
MISSION Inscription_1p(HERO *PY);
MISSION Inscription_2p(HERO *PY, HERO *PY2);
MISSION Inscription_3p(HERO *PY, HERO *PY2, HERO *PY3);
MISSION MagicGuardian_1p(HERO *PY);
MISSION MagicGuardian_2p(HERO *PY, HERO *PY2);
MISSION MagicGuardian_3p(HERO *PY, HERO *PY2, HERO *PY3);
MISSION GoblinTeam_1p(HERO *PY);
MISSION GoblinTeam_2p(HERO *PY, HERO *PY2);
MISSION GoblinTeam_3p(HERO *PY, HERO *PY2, HERO *PY3);
MISSION Chimera_1p(HERO *PY);
MISSION Chimera_2p(HERO *PY, HERO *PY2);
MISSION Chimera_3p(HERO *PY, HERO *PY2, HERO *PY3);
MISSION SphinxMystery_1p(HERO *PY);

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
                            {
                                py->fightP++;
                                py->Level++;
                            }
                            py->fightP++;
                            py->Level++;
                        }
                        py->resourseMP++;
                        py->Level++;
                    }
                    tempL = py->lifeMP;
                    py->Level++;
                }
                py->exploreP++;
                py->Level++;
            }
            py->fightP++;
            py->Level++;
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
                {
                    py->resourseMP++;
                    py->Level++;
                }
                py->fightP++;
                py->Level++;
            }
            py->exploreP++;
            py->Level++;
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
                {
                    py->fightP++;
                    py->Level++;
                }
                py->exploreP++;
                py->Level++;
            }
            py->fightP++;
            py->Level++;
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
                {
                    tempL = py->lifeMP;
                    py->Level++;
                }
                py->fightP++;
                py->Level++;
            }
            py->exploreP++;
            py->Level++;
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
                    py->Level++;
                }
                py->fightP++;
                py->exploreP++;
                py->resourseMP++;
                py->Level++;
            }
            py->fightP++;
            py->exploreP++;
            py->resourseMP++;
            py->Level++;
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
                {
                    py->fightP++;
                    py->Level++;
                }
                tempL = py->lifeMP;
                py->Level++;
            }
            py->resourseMP++;
            py->Level++;
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

void mission_choice(int n,int mountain)///进行挑战，传入发起者序号(0 1 2)和山的特征值
{
    int out;///判断任务是否完成
    int a[5];
    a[0]=mountain/10000;mountain-=10000*a[0];///山标
    a[1]=mountain/1000;mountain-=1000*a[1];///奖励标
    a[2]=mountain/100;mountain-=100*a[2];///任务标
    a[3]=mountain/10;mountain-=10*a[3];///进度标
    a[4]=mountain;///人数标
    switch(a[2])
    {
        case 0:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                printf("人数不足");break;
            }
            else
            {
                if(a[4]==4||a[4]==6||a[4]==8)
                {
                    out=HeroLastWords_2p(&py[n],&py[(a[4]-2*n-2)/2]);
                }
                if(a[4]==9)
                {
                    int n1,n2;
                    switch(a[4]-n)
                    {
                        case 4:n1=1;n2=2;break;
                        case 6:n1=1;n2=3;break;
                        case 8:n1=2;n2=3;break;
                    }
                    out=HeroLastWords_3p(&py[n],&py[n1],&py[n2]);
                }
                mission_reward(a[1],n,count,out);
                mission_mountain(a[0],out);
                break;
            }
            break;///任务1
        case 1:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                out=Inscription_1p(&py[n]);
            }
            if(a[4]==4||a[4]==6||a[4]==8)
            {
                out=Inscription_2p(&py[n],&py[(a[4]-2*n-2)/2]);
            }
            if(a[4]==9)
            {
                int n1,n2;
                switch(a[4]-n)
                {
                    case 4:n1=1;n2=2;break;
                    case 6:n1=1;n2=3;break;
                    case 8:n1=2;n2=3;break;
                }
                out=Inscription_3p(&py[n],&py[n1],&py[n2]);
            }
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///任务2
        case 2:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                out=MagicGuardian_1p(&py[n]);
            }
            if(a[4]==4||a[4]==6||a[4]==8)
            {
                out=MagicGuardian_2p(&py[n],&py[(a[4]-2*n-2)/2]);
            }
            if(a[4]==9)
            {
                int n1,n2;
                switch(a[4]-n)
                {
                    case 4:n1=1;n2=2;break;
                    case 6:n1=1;n2=3;break;
                    case 8:n1=2;n2=3;break;
                }
                out=MagicGuardian_3p(&py[n],&py[n1],&py[n2]);
            }
            ResGuard(&py[n],1);
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///任务3
        case 3:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                out=GoblinTeam_1p(&py[n]);
            }
            if(a[4]==4||a[4]==6||a[4]==8)
            {
                out=GoblinTeam_2p(&py[n],&py[(a[4]-2*n-2)/2]);
            }
            if(a[4]==9)
            {
                int n1,n2;
                switch(a[4]-n)
                {
                    case 4:n1=1;n2=2;break;
                    case 6:n1=1;n2=3;break;
                    case 8:n1=2;n2=3;break;
                }
                out=GoblinTeam_3p(&py[n],&py[n1],&py[n2]);
            }
            if(out==0)
                ResGuard(&py[n],1);
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///任务4
        case 4:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                out=Chimera_1p(&py[n]);
            }
            if(a[4]==4||a[4]==6||a[4]==8)
            {
                out=Chimera_2p(&py[n],&py[(a[4]-2*n-2)/2]);
            }
            if(a[4]==9)
            {
                int n1,n2;
                switch(a[4]-n)
                {
                    case 4:n1=1;n2=2;break;
                    case 6:n1=1;n2=3;break;
                    case 8:n1=2;n2=3;break;
                }
                out=Chimera_3p(&py[n],&py[n1],&py[n2]);
            }
            if(out==0)
                ResGuard(&py[n],2);
            else
                ResGuard(&py[n],1);
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///任务5
        case 5:
            out=SphinxMystery_1p(&py[n]);
            if(out==0)
                ResGuard(&py[n],2);
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///任务6
        default:break;
    }
}

void mission_mountain(int mountain,int out)///如果任务完成，地块数值需要改变，当再次来到该板块则不发生挑战/侦查判定
{
    if(out!=0)
    {
        switch(mountain)
        {
            case 1:
                map_block[0][3]-=100;map_block[1][4]-=100;map_block[1][5]-=100;
                break;
            case 2:
                map_block[1][0]-=200;map_block[2][1]-=200;map_block[3][1]-=200;map_block[3][0]-=200;
                break;
            case 3:
                map_block[1][2]-=300;map_block[1][3]-=300;map_block[2][2]-=300;map_block[2][4]-=300;map_block[3][3]-=300;map_block[3][4]-=300;
                break;
            case 4:
                map_block[2][6]-=400;map_block[3][6]-=400;map_block[4][7]-=400;
                break;
            case 5:
                map_block[6][6]-=500;map_block[5][6]-=500;map_block[5][7]-=500;
                break;
            default:break;
        }
    }
}

/**任务初始化**/
///****************任务一：英雄的遗言状********************
MISSION HeroLastWords_2p(HERO *PY1, HERO *PY2)
{
    PY1->Exp++;
    PY2->Exp++;
    printf("任务成功！参与者每人获得1点Exp ");
    Levelup(PY1);
    Levelup(PY2);
    return 1;
}
MISSION HeroLastWords_3p(HERO *PY1, HERO *PY2, HERO *PY3)
{
    PY1->Exp++;
    PY2->Exp++;
    PY3->Exp++;
    printf("任务成功！参与者每人获得1点Exp ");
    Levelup(PY1);
    Levelup(PY2);
    Levelup(PY3);
    return 1;
}
///*******************任务二：迷之碑文**********************
MISSION Inscription_1p(HERO *PY)
{
    int DP = HeroCheck(PY->knowledgeP+ResAdd(PY));Sleep(500);
    if (DP >= CP_2)
    {
        printf("任务成功！获得2点Exp ");
        PY->Exp += 2;
        Levelup(PY);
        return 1;
    }
    else
    {
        CP_2 -= DP;
        if (CP_2 > 2)
            CP_2 = 2;
        printf("任务失败！还剩%d点完成 ", CP_2);
        return 0;
    }
}
MISSION Inscription_2p(HERO *PY, HERO *PY2)
{
    int DP = HeroCheck(PY->knowledgeP + PY2->knowledgeP+ResAdd(PY));Sleep(500);
    if (DP >= CP_2)
    {
        printf("任务成功！参与者每人获得1点Exp ");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
        return 1;
    }
    else
    {
        CP_2 -= DP;
        if (CP_2 > 2)
            CP_2 = 2;
        printf("任务失败！还剩%d点完成 ", CP_2);
        return 0;
    }
}
MISSION Inscription_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    int DP = HeroCheck(PY->knowledgeP + PY2->knowledgeP + PY3->knowledgeP+ResAdd(PY));Sleep(500);
    if (DP >= CP_2)
    {
        printf("任务成功！参与者每人获得1点Exp ");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
        return 1;
    }
    else
    {
        CP_2 -= DP;
        if (CP_2 > 2)
            CP_2 = 2;
        printf("任务失败！还剩%d点完成 ", CP_2);
        return 0;
    }
}
///********************任务三：魔像守护者***********************
MISSION MagicGuardian_1p(HERO *PY)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！ ");
        exit(1);
    }
    int DP = HeroCheck(PY->exploreP+ResAdd(PY));Sleep(500);
    if (DP >= CP_3)
    {
        printf("任务成功！获得2点Exp ");
        PY->Exp += 2;
        Levelup(PY);
        return 1;
    }
    else
    {
        CP_3 -= DP;
        if (CP_3 > 3)
            CP_3 = 3;
        printf("任务失败！还剩%d点完成 ", CP_3);
        return 0;
    }
}
MISSION MagicGuardian_2p(HERO *PY, HERO *PY2)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！ ");
        exit(1);
    }
    int DP = HeroCheck(PY->exploreP + PY2->exploreP+ResAdd(PY));Sleep(500);
    if (DP >= CP_3)
    {
        printf("任务成功！参与者每人获得1点Exp ");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
        return 1;
    }
    else
    {
        CP_3 -= DP;
        if (CP_3 > 3)
            CP_3 = 3;
        printf("任务失败！还剩%d点完成 ", CP_3);
        return 0;
    }
}
MISSION MagicGuardian_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！ ");
        exit(1);
    }
    int DP = HeroCheck(PY->exploreP + PY2->exploreP + PY3->exploreP+ResAdd(PY));Sleep(500);
    if (DP >= CP_3)
    {
        printf("任务成功！参与者每人获得1点Exp ");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
        return 1;
    }
    else
    {
        CP_3 -= DP;
        if (CP_3 > 3)
            CP_3 = 3;
        printf("任务失败！还剩%d点完成 ", CP_3);
        return 0;
    }
}
///*************************任务四：哥布林小队*************************
MISSION GoblinTeam_1p(HERO *PY)
{
    int DP = HeroCheck(PY->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_4)
    {
        printf("任务成功！获得2点Exp ");
        PY->Exp += 3;
        Levelup(PY);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_4 -= DP;
        if (CP_4 > 3)
            CP_4 = 3;
        printf("任务失败！挑战者受到1点伤害，还剩%d点完成 ", CP_4);
        return 0;
    }
}
MISSION GoblinTeam_2p(HERO *PY, HERO *PY2)
{
    int DP = HeroCheck(PY->fightP + PY2->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_4)
    {
        printf("任务成功！参与者每人获得1点Exp ");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_4 -= DP;
        if (CP_4 > 3)
            CP_4 = 3;
        printf("任务失败！挑战者受到1点伤害，还剩%d点完成 ", CP_4);
        return 0;
    }
}
MISSION GoblinTeam_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    int DP = HeroCheck(PY->fightP + PY2->fightP + PY3->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_4)
    {
        printf("任务成功！参与者每人获得1点Exp ");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_4 -= DP;
        if (CP_4 > 3)
            CP_4 = 3;
        printf("任务失败！挑战者受到1点伤害，还剩%d点完成 ", CP_4);
        return 0;
    }
}
///***************************任务五：魔兽奇美拉***************************
MISSION Chimera_1p(HERO *PY)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！ ");
        return 0;
    }
    int DP = HeroCheck(PY->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_5)
    {
        printf("任务成功！获得2点Exp ");
        PY->Exp += 2;
        Levelup(PY);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_5 -= DP;
        if (CP_5 > 2)
            CP_5 = 2;
        printf("任务失败！挑战者受到1点伤害，还剩%d点完成 ", CP_5);
        return 0;
    }
}
MISSION Chimera_2p(HERO *PY, HERO *PY2)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！ ");
        return 0;
    }
    int DP = HeroCheck(PY->fightP + PY2->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_5)
    {
        printf("任务成功！ 参与者每人获得1点Exp ");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_5 -= DP;
        if (CP_5 > 2)
            CP_5 = 2;
        printf("任务失败！挑战者受到1点伤害，还剩%d点完成 ", CP_5);
        return 0;
    }
}
MISSION Chimera_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("生命值不足，不能进行此挑战！ ");
        exit(1);
    }
    int DP = HeroCheck(PY->fightP + PY2->fightP + PY3->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_5)
    {
        printf("任务成功！参与者每人获得1点Exp ");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_5 -= DP;
        if (CP_5 > 2)
            CP_5 = 2;
        printf("任务失败！挑战者受到1点伤害，还剩%d点完成 ", CP_5);
        return 0;
    }
}
///*****************************任务六：斯芬克斯之谜**********************
MISSION SphinxMystery_1p(HERO *PY)
{
    int DP = HeroCheck(PY->knowledgeP+ResAdd(PY));Sleep(500);
    if (DP >= CP_6)
    {
        printf("任务成功！获得2点Exp ");
        PY->Exp += 2;
        Levelup(PY);
        return 1;
    }
    else
    {
        PY->lifeP -= 2;
        CP_6 -= DP;
        if (CP_6 > 1)
            CP_6 = 1;
        printf("任务失败！挑战者受到2点伤害，还剩%d点完成 ", CP_6);
        return 0;
    }
}

/********************任务奖励************************/
void mission_reward(int n,int n_loop,int pynum,MISSION out)
{
    switch(n)
    {
        case 0:DraBook(py,pynum,out);break;
        case 1:DraWeapon(py,pynum,out);break;
        case 2:DraMapPlece(&dra,out);break;
        case 3:DraBlood(py,pynum,out);break;
        case 4:DraTreasure(&py[n_loop],out);break;
    }
}

void DraBook(HERO py[],int pynum,MISSION out) ///任务奖励：秘龙之书（1）
{
    if(out!=0)
    {
        int i;
        printf("获得秘龙之书！所有人经验值+1 ");
        for(i=0;i<pynum;i++)
            py[i].Exp++;
    }
}

void DraWeapon(HERO py[],int pynum,MISSION out) ///任务奖励：屠龙武器（2）
{
    if(out!=0)
    {
        int i;
        printf("获得屠龙武器！所有人战斗力+1 ");
        for(i=0;i<pynum;i++)
            py[i].fightP++;
    }
}

void DraMapPlece(Dragonic *Dra,MISSION out) ///任务奖励：匿龙地图（3）
{
    if(out!=0)
    {
        printf("获得匿龙地图！龙遭受一次突袭，受到1点伤害 ");
        Dra->lifeD--;
    }
}

void DraBlood(HERO py[],int pynum,MISSION out) ///任务奖励：古龙之血（4）
{
    if(out!=0)
    {
        int i;
        printf("获得古龙之血！所有人生命值全回复 ");
        for(i=0;i<pynum;i++)
            py[i].lifeP=py[i].lifeMP;
    }
}

void DraTreasure(HERO *py,MISSION out) ///任务奖励：龙之秘宝（5）
{
    if(out!=0)
    {
        printf("获得龙之秘宝！启动秘宝效果 ");
        py->Treasure = TRUE;
    }
}

#endif
