///这是集合龙种行动的头文件
#ifndef DRAGONICMOD_H_INCLUDED
#define DRAGONICMOD_H_INCLUDED

extern HERO py[3];
///英雄显示的坐标
extern int hero_moving_x[4];
extern int hero_moving_y[4];
///英雄在区块的坐标
extern int hero_moving_a[4];
extern int hero_moving_b[4];
extern int map_block[7][8];

void dragon_attack(int life,int pynum);

void showDragonAnger(Dragonic dra) ///展示龙怒气值的函数
{
    int i,num_c;
    i=dra.angerD;
    if(i>=12&&i<16)
        num_c=7;
    if(i>=8&&i<12)
        num_c=9;
    if(i>=3&&i<8)
        num_c=13;
    if(i>0&&i<3)
        num_c=12;
    number_ROME(93,2,0,num_c,i);///地图右上角空位坐标(93,2)
    setColor(7,0);
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

 void DragonDisaster(int pynum) ///龙祸判定函数
{
    int i;///循环变量
    int DD = DraD6(); ///龙骰DD
    int *DiceD=(int*)malloc(pynum*sizeof(int));
    int maxPY, minPY;
    emergency_decoration(2);
    printf("恶龙飞出了巢穴！！！");
    printf("龙祸判定：(%d) !!!", DD);
    Sleep(1000);
    emergency_decoration(2);
    switch (DD)
    {
    case 1: ///烧毁村庄
        number_ARAB(7,34,0,7,1);
        printf("恶龙将贝尔村焚为废墟，从此贝尔村无法进入！");
        printf("在贝尔村的玩家将受到2点伤害！");
        draw_map_block(4,41,4);SetPos(43,5);setColor(0,4);printf("贝尔村");SetPos(44,6);printf("焚毁");
        switch(map_block[0][1]%10)
        {
            case 1:
                py[0].lifeP--;
                hero_moving_x[1]=19;
                hero_moving_y[1]=8;
                hero_moving_a[1]=1;
                hero_moving_b[1]=2;
                SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
                break;
            case 3:
                py[1].lifeP--;
                hero_moving_x[2]=21;
                hero_moving_y[2]=8;
                hero_moving_a[2]=1;
                hero_moving_b[2]=2;
                SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
                break;
            case 5:
                py[2].lifeP--;
                hero_moving_x[3]=23;
                hero_moving_y[3]=8;
                hero_moving_a[3]=1;
                hero_moving_b[3]=2;
                SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
                break;
            case 4:
                py[0].lifeP--;py[2].lifeP--;
                hero_moving_x[1]=19;
                hero_moving_y[1]=8;
                hero_moving_a[1]=1;
                hero_moving_b[1]=2;
                SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
                hero_moving_x[2]=21;
                hero_moving_y[2]=8;
                hero_moving_a[2]=1;
                hero_moving_b[2]=2;
                SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
                break;
            case 6:
                py[0].lifeP--;py[3].lifeP--;
                hero_moving_x[1]=19;
                hero_moving_y[1]=8;
                hero_moving_a[1]=1;
                hero_moving_b[1]=2;
                SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
                hero_moving_x[3]=23;
                hero_moving_y[3]=8;
                hero_moving_a[3]=1;
                hero_moving_b[3]=2;
                SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
                break;
            case 8:
                py[2].lifeP--;py[3].lifeP--;
                hero_moving_x[2]=21;
                hero_moving_y[2]=8;
                hero_moving_a[2]=1;
                hero_moving_b[2]=2;
                SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
                hero_moving_x[3]=23;
                hero_moving_y[3]=8;
                hero_moving_a[3]=1;
                hero_moving_b[3]=2;
                SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
                break;
            case 9:
                py[0].lifeP--;py[1].lifeP--;py[2].lifeP--;
                hero_moving_x[1]=19;
                hero_moving_y[1]=8;
                hero_moving_a[1]=1;
                hero_moving_b[1]=2;
                SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
                hero_moving_x[2]=21;
                hero_moving_y[2]=8;
                hero_moving_a[2]=1;
                hero_moving_b[2]=2;
                SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
                hero_moving_x[3]=23;
                hero_moving_y[3]=8;
                hero_moving_a[3]=1;
                hero_moving_b[3]=2;
                SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
                break;
            default:break;
        }
        map_block[0][1]=-6;
        setColor(7,0);
        break;
    case 2: ///最高流放回城
        number_ARAB(7,34,0,7,2);
        printf("来自恶龙的突袭！所有玩家投一骰子");
        printf("点数最高的玩家将不幸被恶龙带回主城");
        HeroD6(DiceD, pynum);
        maxPY = getMAX(DiceD, pynum);
        switch (maxPY)
        {
        case 1:
            printf(" (P1)");
            SetPos(hero_moving_x[1],hero_moving_y[1]);printf("  ");
            hero_moving_x[1]=31;
            hero_moving_y[1]=38;
            hero_moving_a[1]=6;
            hero_moving_b[1]=3;
            SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
            break;
        case 2:
            printf(" (P2)");
            SetPos(hero_moving_x[2],hero_moving_y[2]);printf("  ");
            hero_moving_x[2]=27;
            hero_moving_y[2]=33;
            hero_moving_a[2]=5;
            hero_moving_b[2]=2;
            SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
            break;
        case 3:
            printf(" (P3)");
            SetPos(hero_moving_x[3],hero_moving_y[3]);printf("  ");
            hero_moving_x[3]=41;
            hero_moving_y[3]=33;
            hero_moving_a[3]=5;
            hero_moving_b[3]=3;
            SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
            break;
        default:
            break;
        }
        break;
    case 3: ///全体-1HP
        number_ARAB(7,34,0,7,3);
        printf("恶龙对你们所有人使用了摆尾！");
        printf("所有在场的玩家受到1点伤害！");
        for(i=0;i<pynum;i++)
            py[i].lifeP--;
        break;
    case 4: ///最低者-2HP
        number_ARAB(7,34,0,7,4);
        printf("恶龙愤怒的践踏！所有玩家投一骰子！");
        printf("点数最低的玩家受到2点伤害！");
        HeroD6(DiceD, pynum);
        minPY = getMIN(DiceD, pynum);
        switch (minPY)
        {
        case 1:
            printf(" (P1)");
            py[0].lifeP -= 2;
            break;
        case 2:
            printf(" (P2)");
            py[1].lifeP -= 2;
            break;
        case 3:
            printf(" (P3)");
            py[2].lifeP -= 2;
            break;
        default:
            break;
        }
        break;
    case 5: ///最高者-2HP
        number_ARAB(7,34,0,7,5);
        printf("恶龙吐出了火球！所有玩家投一骰子！");
        printf("点数最高的玩家受到2点伤害！");
        HeroD6(DiceD, pynum);
        maxPY = getMAX(DiceD, pynum);
        switch (maxPY)
        {
        case 1:
            printf(" (P1)");
            py[0].lifeP -= 2;
            break;
        case 2:
            printf(" (P2)");
            py[1].lifeP -= 2;
            break;
        case 3:
            printf(" (P3)");
            py[2].lifeP -= 2;
            break;
        default:
            break;
        }
        break;
    case 6: ///最低者资源清空
        number_ARAB(7,34,0,7,6);
        printf("恶龙恐怖的龙息！所有玩家投一骰子！");
        printf("点数最低的玩家受到重伤，资源清空！");
        HeroD6(DiceD, pynum);
        minPY = getMIN(DiceD, pynum);
        switch (minPY)
        {
        case 1:
            printf(" (P1)");
            py[0].resourseP = 0;
            break;
        case 2:
            printf(" (P2)");
            py[1].resourseP = 0;
            break;
        case 3:
            printf(" (P3)");
            py[2].resourseP = 0;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

int DragonAnger(int num, Dragonic *dra) ///龙怒气值变化函数
{
    unsigned int angerN=num/1000;
    int DD=0;
    int temp;temp=dra->angerD;
    if(temp-angerN>=0)
    {
        while(angerN>0)
        {
            dra->angerD--;
            angerN--;
            if(dra->angerD==13||dra->angerD==10||dra->angerD==7||dra->angerD==4||dra->angerD==1)
            {
                DD++;
            }
        }
    }
    else
    {
        if(((temp+1)%3)!=0)
        {
            DD+=(temp+1)/3;
        }
        dra->angerD=0;
    }
    return DD;
}

void FinalBattle(HERO *PY,int pynum,Dragonic *dra) ///决战函数
{
    int num=HeroCheck(PY->fightP+ResAdd(py));
    int i,secnum=0;
    if(PY->timeP==2)
        num=Ninja_Tre(py,num);
    if(PY->timeP==3)
        num=Hunter_Tre(py,num);
    if(PY->timeP==6)
        Paladin_Tre(PY,pynum);
    recheck:
    {
        if(num<=-1) ///Dice<0:即死
        {
            PY->lifeP=0;
        }
        else if(num==0) ///Dice=0:玩家-4LP
        {
            PY->lifeP-=4;
        }
        else if(num==1) ///Dice=1:全体-1LP
        {
            for(i=0;i<pynum;i++)
                py[i].lifeP--;
        }
        else if(num==2) ///Dice=2:联携攻击（全体-1）
        {
            num+=HeroCheck(pynum);
            if(secnum==0)
                goto recheck;
            else
                for(i=0;i<pynum;i++)
                    py[i].lifeP--;
            secnum++;
        }
        else if(num==3) ///Dice=3:玩家-2龙-1
        {
            PY->lifeP-=2;
            dra->lifeD--;
            dragon_attack(dra->lifeD,pynum);
        }
        else if(num==4) ///Dice=4：龙-1
        {
            dra->lifeD--;
            dragon_attack(dra->lifeD,pynum);
        }
        else ///Dice>4: 龙-2
        {
            dra->lifeD--;
            dragon_attack(dra->lifeD,pynum);
            dra->lifeD--;
            dragon_attack(dra->lifeD,pynum);
        }
    }
}

void dragon_attack(int life,int pynum)
{
    if(life==8||life==6||life==4||life==2)
    {
        int *DiceD=(int*)malloc(pynum*sizeof(int));
        int DD=DraD6();///龙骰DD
        if(DD==1)
        {
            emergency_decoration(2);
            printf("思考龙生，无事发生");
        }
        if(DD==2||DD==3)
        {
            emergency_decoration(2);
            printf("龙息攻击，所有玩家承受1点伤害");
            int i;
            for(i=0;i<pynum;i++)
            {
                py[i].lifeP--;
            }
        }
        if(DD==4||DD==5||DD==6)
        {
            emergency_decoration(2);
            printf("鲁莽突进，所有玩家投掷1枚骰子，点数最低的玩家承受2点伤害");
            py[getMIN(DiceD,pynum)].lifeP-=2;
        }
    }
}

#endif // DRAGONICMOD_H_INCLUDED
