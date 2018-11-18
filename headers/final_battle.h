#ifndef FINAL_BATTLE_H_INCLUDED
#define FINAL_BATTLE_H_INCLUDED

extern HERO py[3];
extern Dragonic dra;
extern int count;

void final_battle_loop(int n)
{
    play_music(3);
    int death_count=0;
    int n_loop;
    n_loop=0;
    for(n_loop=0;n_loop<n;n_loop++)
    {
        HolySwordsman_Tre(&py[n_loop]);
        Gladiator_Tre(&py[n_loop]);
        Prince_Tre(&py[n_loop]);
    }
    n_loop=0;

    SetPos(119,31);printf(">>龙的生命值<<");

    switch(n)
    {
        case 1:
            while(n_loop<n)
            {
                HolySwordsman_Res(&py[n_loop]);///剑圣资源回复判定
                showPlayer(py[n_loop]);
                number_ARAB(118,33,0,7,dra.lifeD);
                if(dra.lifeD<=0)
                {
                    SetPos(6,44);emergency_decoration(2);
                    printf("各位勇士降伏了恶龙");break;
                }
                if(py[n_loop].lifeP>0)
                    FinalBattle(&py[n_loop],count,&dra);
                showPlayer(py[n_loop]);
                number_ARAB(118,33,0,7,dra.lifeD);
                if(py[n_loop].lifeP<=0)
                    death_count++;
                if(death_count==n)
                {
                    SetPos(6,44);emergency_decoration(2);
                    printf("显然恶龙饱餐了一顿");break;
                }
                n_loop++;
                if(n_loop==n)
                {
                    n_loop-=n;
                    death_count=0;
                }
            }
            break;
        case 2:
            while(n_loop<n)
            {
                HolySwordsman_Res(&py[n_loop]);///剑圣资源回复判定
                showPlayer(py[n_loop]);
                number_ARAB(118,33,0,7,dra.lifeD);
                if(dra.lifeD<=0)
                {
                    SetPos(6,44);emergency_decoration(2);
                    printf("各位勇士降伏了恶龙");break;
                }
                if(py[n_loop].lifeP>0)
                    FinalBattle(&py[n_loop],count,&dra);
                showPlayer(py[n_loop]);
                number_ARAB(118,33,0,7,dra.lifeD);
                if(py[n_loop].lifeP<=0)
                    death_count++;
                if(death_count==n)
                {
                    SetPos(6,44);emergency_decoration(2);
                    printf("显然恶龙饱餐了一顿");break;
                }
                n_loop++;
                if(n_loop==n)
                {
                    n_loop-=n;
                    death_count=0;
                }
            }
            break;
        case 3:
            while(n_loop<n)
            {
                HolySwordsman_Res(&py[n_loop]);///剑圣资源回复判定
                showPlayer(py[n_loop]);
                number_ARAB(118,33,0,7,dra.lifeD);
                if(dra.lifeD<=0)
                {
                    SetPos(6,44);emergency_decoration(2);
                    printf("各位勇士降伏了恶龙");break;
                }
                if(py[n_loop].lifeP>0)
                    FinalBattle(&py[n_loop],count,&dra);
                showPlayer(py[n_loop]);
                number_ARAB(118,33,0,7,dra.lifeD);
                if(py[n_loop].lifeP<=0)
                    death_count++;
                if(death_count==n)
                {
                    SetPos(6,44);emergency_decoration(2);
                    printf("显然恶龙饱餐了一顿");break;
                }
                n_loop++;
                if(n_loop==n)
                {
                    n_loop-=n;
                    death_count=0;
                }
            }
            break;
        default:break;
    }
}

#endif // FINAL_BATTLE_H_INCLUDED
