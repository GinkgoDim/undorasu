///这是集合英雄动作的头文件
#ifndef HEROMOD_H_INCLUDED
#define HEROMOD_H_INCLUDED

extern char key_button[9];
extern HERO py[3];

//113,2  113,41  139,2  139,41右侧界面参数
void showPlayer(HERO PY) ///展示玩家数据
{
    SetPos(115,3);
    switch(PY.timeP)
    {
        case 1:printf("  <<剑圣>>");break;
        case 2:printf("  <<忍者>>");break;
        case 3:printf("  <<猎人>>");break;
        case 4:printf("  <<角斗士>>");break;
        case 5:printf("  <<王子>>");break;
        case 6:printf("  <<圣骑士>>");break;
        default:break;
    }
    SetPos(115,4);printf(">>  生命值：%d|%d\n",PY.lifeP,PY.lifeMP);
    SetPos(115,5);printf(">>  经验值：%d\n",PY.Exp);
    SetPos(115,6);printf(">>  等级：%d\n",PY.Level);
    SetPos(115,7);printf(">>  行动力：%d\n",PY.actionP);
    SetPos(115,8);printf(">>  冒险值：%d|%d\n",PY.advP_P,PY.advP_F);
    SetPos(115,9);printf(">>  战斗力：%d\n",PY.fightP);
    SetPos(115,10);printf(">>  探索力：%d\n",PY.exploreP);
    SetPos(115,11);printf(">>  知识力：%d\n",PY.knowledgeP);
    SetPos(115,12);printf(">>  资源值：%d|%d\n",PY.resourseP,PY.resourseMP);
    SetPos(115,13);printf(">>  龙秘宝：%d\n",PY.Treasure);
    SetPos(6,44);
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
            case 1:DP++;break; ///Dice1时成功值为-1
            case 4:DP+=10;break; ///Dice4以上成功值为+1
            case 5:DP+=10;break;
            case 6:DP+=100;break; ///Dice6爆炸，累加爆炸次数的D6
        }
    }
    if(DP>=100) ///对于所有掷到的Dice6进行累加判定
    {
        int temp=HeroCheck((unsigned)DP/100);
        return DP/100+(DP%100-DP%10)/10-DP%10+temp;
    }
    else
        return DP/100+(DP%100-DP%10)/10-DP%10;
}

void HeroSleep(HERO *PY) ///英雄休息函数
{
    if((PY->lifeMP-PY->lifeP)>=2)
        PY->lifeP+=2;
    else
        PY->lifeP=PY->lifeMP;
    if(PY->timeP==3)
        PY->resourseP=PY->resourseMP;
}

DICE HeroExplore(DICE num) ///英雄冒险掷骰判定函数
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
            case 1:DP++;break; ///Dice1-2时成功值为-1
            case 2:DP++;break;
            case 5:DP+=10;break; ///Dice5以上成功值为+1
            case 6:DP+=100;break; ///Dice6爆炸，累加爆炸次数的D6
        }
    }
    if(DP>=100) ///对于所有掷到的Dice6进行累加判定
    {
        int temp1=HeroExplore((unsigned)DP/100);
        int temp2=DP%10;
        return DP/100+(DP%100-DP%10)/10-temp2+temp1;
    }
    else
        return DP/100+(DP%100-DP%10)/10-DP%10;
}

void ResGuard(HERO *PY,int damage) ///使用资源值进行防御的函数
{
    Sleep(1000);emergency_decoration(2);
    printf("你要承受%d点伤害 请问你使用几点资源值进行防御?(若不想使用请输入0):",damage);
    int useR=0;
    scanf("%d",&useR);
    if(damage>=PY->resourseP)
    {
        if(useR>=PY->resourseP)
             useR=PY->resourseP;
        SetPos(6,44);emergency_decoration(2);
        printf("你格挡了(%d)点伤害 ",useR);
        PY->lifeP+=useR;
        PY->resourseP-=useR;
    }
    else
    {
        if(useR>=PY->resourseP)
             useR=PY->resourseP;
        if(useR>=damage)
             useR=damage;
        SetPos(6,44);emergency_decoration(2);
        printf("你格挡了(%d)点伤害 ",useR);
        PY->resourseP-=useR;
        PY->lifeP+=useR;
    }
}

int ResAdd(HERO *PY) ///使用资源值进行骰子加成的函数
{
    if(PY->resourseP==0)
        return 0;
    Sleep(1000);emergency_decoration(2);
    printf("请问你需要使用多少资源值?(不能超过%d)：",PY->resourseP);
    int costP=0;
    scanf("%d",&costP);
    if(costP>PY->resourseP||costP<0)
    {
        SetPos(6,44);emergency_decoration(2);
        printf("Error：请重新输入！");
        costP=ResAdd(PY);
    }
    else
    {
        SetPos(6,44);emergency_decoration(2);
        printf("你使用了%d点的资源 ",costP);
        PY->resourseP-=costP;
    }
    return costP;
}

///==========英雄的秘宝效果==========
void HolySwordsman_Tre(HERO *PY) ///剑圣秘宝「远古秘药」
{
    if(PY->Treasure&&PY->timeP==1)
    {
        printf("剑圣秘宝「远古秘药」发动！");
        printf("资源值上限+1且全回复");
        PY->resourseMP++;
        PY->resourseP=PY->resourseMP;
    }
}

int Ninja_Tre(HERO *PY,DICE num)  ///忍者秘宝「胧霞」
{
    printf("是否使用秘宝「胧霞」？（Y/N）");
    printf("（一回合一次，决战阶段暴击判定前可以重投一次所有骰子）：");
    int ch;
    int temp;
    while (1)
    {
        if (_kbhit())
        {//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            if(ch==key_button[7])
            {
                temp=PY->fightP+ResAdd(PY);
                return HeroCheck(temp);
            }
            if(ch==key_button[8])
            {
                return num;
            }
        }
    }
}

int Hunter_Tre(HERO *PY,DICE num) ///猎人秘宝「致命子弹」
{
    static int canbeUse=3;
    if(canbeUse<=0)
        return num;
    if(PY->Treasure)
    {
        printf("是否使用秘宝「致命子弹」？（Y/N）");
        printf("（决战阶段中限3次，本回合战斗+1）：");
        int ch;
        while (1)
        {
            if (_kbhit())
            {//如果有按键按下，则_kbhit()函数返回真
                ch = _getch();//使用_getch()函数获取按下的键值
                if(ch==key_button[7])
                {
                    num+=HeroCheck(1);
                    PY->fightP--;
                    canbeUse--;
                    return num;
                }
                if(ch==key_button[8])
                {
                    return num;
                }
            }
        }
    }
    else
        return num;
}

void Gladiator_Tre(HERO *PY) ///角斗士秘宝「猛犸肉」
{
    if(PY->Treasure&&PY->timeP==4)
    {
        printf("角斗士秘宝「猛犸肉」发动！");
        printf("生命值全部恢复了");
        PY->lifeP=PY->lifeMP;
    }
}

void Prince_Tre(HERO *PY) ///王子秘宝「宝藏」
{
    if(PY->Treasure&&PY->timeP==5)
    {
        printf("王子秘宝「宝藏」发动！");
        printf("决战阶段获得4个金币资源");
        PY->resourseP+=4;
    }
}

void Paladin_Tre(HERO *PY,int pynum) ///圣骑士秘宝「白银之盾」
{
    static int canbeUse=1;
    if(canbeUse==1)
    {
        if(PY->Treasure)
        {
            printf("圣骑士秘宝「白银之盾」发动！");
            printf("（决战阶段限一次，群体生命+1或单体生命+2）");
            int num,i;
            printf("请输入治疗者的序号（全体治疗请输入0）：");
            scanf("%d",&num);
            if(num==0)
                for(i=0;i<pynum;i++)
                    py[i].lifeP++;
            else if(num>0 && num<=pynum)
                py[num-1].lifeP+=2;
            canbeUse--;
        }
    }

}

///==========英雄的资源回复==========
void HolySwordsman_Res(HERO *PY)
{
    if(PY->resourseP<PY->resourseMP&&PY->timeP==1)
        PY->resourseP++;
}

void Ninja_Res(HERO *PY)
{
    if(PY->resourseP<PY->resourseMP&&PY->timeP==2)
        PY->resourseP++;
}

void Prince_Res(HERO *PY)
{
    if(PY->resourseP<=PY->resourseMP&&PY->timeP==5)
        PY->resourseP=PY->resourseMP;
}

int Paladin_Res(HERO *PY,int num)
{
    printf("是否使用圣骑士的效果?(%c/%c)",key_button[7],key_button[8]);
    printf("(消耗最大的行动骰，回复1点资源值):");
    int ch;
    while(1)///按下ESC退出修改界面，按下ENTER开始进行修改
    {
        if (_kbhit())
        {///如果有按键按下，则_kbhit()函数返回真
            ch = _getch();///使用_getch()函数获取按下的键值
            if(ch==key_button[7]&&(PY->resourseP<PY->resourseMP))
            {
                if(num>=1000)
                    num-=1000;
                else if(num>=100)
                    num-=100;
                else if(num>=10)
                    num-=10;
                else
                    num--;
                PY->resourseP++;
                break;
            }
            if(ch==key_button[7]&&(PY->resourseP==PY->resourseMP))
            {
                printf("资源值全满");
                break;
            }
            if(ch==key_button[8])
                break;
        }
    }
    return num;
}
#endif // HEROMOD_H_INCLUDED
