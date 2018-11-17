///这是集合英雄动作的头文件
#ifndef HEROMOD_H_INCLUDED
#define HEROMOD_H_INCLUDED

#include "characters.h"
#include "Mission.h"
#define GAMEOVER -1


void showPlayer(HERO PY) ///展示玩家数据
{
    switch(PY.timeP)
    {
        case 1:printf("  <<剑圣>>\n");break;
        case 2:printf("  <<忍者>>\n");break;
        case 3:printf("  <<猎人>>\n");break;
        case 4:printf("  <<角斗士>>\n");break;
        case 5:printf("  <<王子>>\n");break;
        case 6:printf("  <<圣骑士>>\n");break;
        default:break;
    }
    printf("> 生命值：%d|%d\n",PY.lifeP,PY.lifeMP);
    printf("> 经验值：%d\n",PY.Exp);
    printf("> 等级：%d\n",PY.Level);
    printf("> 行动力：%d\n",PY.actionP);
    printf("> 冒险值：%d|%d\n",PY.advP_P,PY.advP_F);
    printf("> 战斗力：%d\n",PY.fightP);
    printf("> 探索力：%d\n",PY.exploreP);
    printf("> 知识力：%d\n",PY.knowledgeP);
    printf("> 资源值：%d|%d\n",PY.resourseP,PY.resourseMP);
}

DICE HeroAction(DICE num) ///英雄行动掷骰判定函数
{
    int actP=0,i;
    int ActDP[15]={0};
    D6(ActDP,num);
    for(i=0;i<num;i++)
    {
        printf("%d ",ActDP[i]);
        switch(ActDP[i])
        {
            default:break;
            case 2:actP++;break; ///Dice2以上可以进入道路
            case 3:actP+=10;break; ///Dice3以上可以进入平原
            case 4:actP+=10;break;
            case 5:actP+=100;break; ///Dice5以上可以进入森林
            case 6:actP+=1000;break; ///Dice6爆炸，累加爆炸次数的D6
        }
    }
    if(actP>=1000) ///对于所有掷到的Dice6进行累加判定
    {
        int temp=HeroAction((unsigned)actP/1000);
        return actP+temp;
    }
    else
        return actP;
}

DICE HeroCheck(DICE num) ///英雄检查掷骰判定函数
{
    int DP=0,i;
    int DiceP[30]={0};
    D6(DiceP,num);
    for(i=0;i<num;i++)
    {
        printf("%d ",DiceP[i]);
        switch(DiceP[i])
        {
            default:break;
            case 1:DP--;break; ///Dice1时成功值为-1
            case 4:DP++;break; ///Dice4以上成功值为+1
            case 5:DP++;break;
            case 6:DP+=100;break; ///Dice6爆炸，累加爆炸次数的D6
        }
    }
    if(DP>=100) ///对于所有掷到的Dice6进行累加判定
    {
        int temp=HeroCheck((unsigned)DP/100);
        return DP+temp;
    }
    else
        return DP/100+DP%100;
}

void ResGuard(HERO *PY,int damage) ///使用资源值进行防御的函数
{
    printf("你要承受%d点伤害\n请问你使用几点资源值进行防御？\n（若不想使用请输入0）：",damage);
    int useR=0;
    scanf("%d",&useR);
    if(damage>=PY->resourseP)
    {
        if(useR>=PY->resourseP)
             useR=PY->resourseP;
        printf("你格挡了(%d)点伤害\n",useR);
        PY->lifeP+=PY->resourseP;
    }
    else
    {
        if(useR>=damage)
             useR=damage;
        printf("你格挡了(%d)点伤害\n",useR);
        PY->lifeP+=PY->resourseP;
    }
}

int ResAdd(HERO *PY) ///使用资源值进行骰子加成的函数
{
    printf("请问你需要使用多少资源值？\n（不能超过%d）：",PY->resourseP);
    int costP=0;
    scanf("%d",&costP);
    if(costP>PY->resourseP||costP<0)
    {
        printf("Error：请重新输入！");
        costP=ResAdd(PY);
    }
    else
    {
        printf("你使用了%d点的资源",costP);
        PY->resourseP-=costP;
    }
    return costP;
}

///英雄的秘宝效果
void HolySwordsman_Tre(HERO *PY) ///剑圣秘宝「远古秘药」
{
    if(PY->Treasure)
    {
        printf("剑圣秘宝「远古秘药」发动！\n");
        printf("资源值上限+1且全回复\n");
        PY->resourseMP++;
        PY->resourseP=PY->resourseMP;
    }
}

int Ninja_Tre(HERO *PY,DICE num)  ///忍者秘宝「胧霞」
{
        printf("是否使用秘宝「胧霞」？（Y/N）\n");
        printf("（一回合一次，决战阶段暴击判定前可以重投一次所有骰子）：");
        char chark_ch;
        int temp;
        scanf("%c",&chark_ch);
        switch(chark_ch)
        {
        case 'Y':
            temp=PY->fightP+ResAdd(PY);
            return HeroCheck(temp);
        case 'N':
            return num;
        default:
            printf("Error：请重新输入！");
            return Ninja_Tre(PY,num);
        }
}

int Hunter_Tre(HERO *PY,DICE num) ///猎人秘宝「致命子弹」
{
    static int canbeUse=3;
    if(canbeUse<=0)
        return num;
    if(PY->Treasure)
    {
        char chark_ch;
        printf("是否使用秘宝「致命子弹」？（Y/N）\n");
        printf("（决战阶段中限3次，本回合战斗+1）：");
        scanf("%c",&chark_ch);
        switch(chark_ch)
        {
        case 'Y':
            num=HeroCheck(++PY->fightP);
            PY->fightP--;
            canbeUse--;
            return num;
        case 'N':
            return num;
        default:
            return Hunter_Tre(PY,num);
        }
    }
    else
        return num;
}

void Gladiator_Tre(HERO *PY) ///角斗士秘宝「猛犸肉」
{
    if(PY->Treasure)
    {
        printf("角斗士秘宝「猛犸肉」发动！\n");
        printf("生命值全部恢复了\n");
        PY->lifeP=PY->lifeMP;
    }
}

void Prince_Tre(HERO *PY) ///王子秘宝「宝藏」
{
    if(PY->Treasure)
    {
        printf("王子秘宝「宝藏」发动！\n");
        printf("获得3个金币资源（金币不会因为龙的效果影响）\n");
        PY->resourseP+=3;
    }
}

void Paladin_Tre(HERO *py,HERO *PY[],int pynum) ///圣骑士秘宝「白银之盾」
{
    static int canbeUse=1;
    if(canbeUse<=0)
        exit(0);
    if(py->Treasure)
    {
        printf("圣骑士秘宝「白银之盾」发动！\n");
        printf("（决战阶段限一次，群体生命+1或单体生命+2）\n");
        int num,i;
        printf("请输入治疗者的序号（全体治疗请输入0）：");
        scanf("%d",&num);
        if(num==0)
            for(i=0;i<pynum;i++)
                PY[i]->lifeP++;
        else if(num>0 && num<=pynum)
            PY[num-1]+=2;
        else
            exit(0);
        canbeUse--;
    }
}

#endif // HEROMOD_H_INCLUDED
