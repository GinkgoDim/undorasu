#ifndef CONTROL_HEROS_LOOP_H_INCLUDED
#define CONTROL_HEROS_LOOP_H_INCLUDED

void conrtol_heros_loop(int);

extern HERO py[3];
extern int map_block[7][8];
extern int hero_moving_x[4];
extern int hero_moving_y[4];
extern int hero_moving_a[4];
extern int hero_moving_b[4];
extern char key_button[9];
extern int dragon_anger;
extern Dragonic dra;
extern int count;

int hero_step=9999;

void conrtol_heros_loop(int n)
{
    int n_loop,i,time;
    n_loop=0;
    switch(n)
    {
        case 1:
            map_block[6][3]+=1;
            while(n_loop<n)
            {
                HolySwordsman_Res(&py[n_loop]);///剑圣资源回复判定
                Prince_Res(&py[n_loop]);///王子资源回复判定
                showPlayer(py[n_loop]);SetPos(6,44);
                Sleep(1000);emergency_decoration(2);
                printf("P%d turn:  ",n_loop+1);
                hero_step=HeroAction(py[n_loop].actionP);Sleep(500);
                if(py[n_loop].timeP==6)
                {
                    hero_step=Paladin_Res(&py[n_loop],hero_step);
                    showPlayer(py[n_loop]);
                }
                time=DragonAnger(hero_step,&dra);/**龙怒次数**/
                for(i=0;i<time;i++)
                {
                    DragonDisaster(count);///龙祸效果
                    showPlayer(py[n_loop]);SetPos(6,44);
                }
                if(dra.angerD<=0)
                {
                    break;
                }
                showDragonAnger(dra);///显示龙怒气值
                ///英雄在地图内移动
                map_moving(hero_step,n_loop+1,&hero_moving_x[n_loop+1],&hero_moving_y[n_loop+1],&hero_moving_a[n_loop+1],&hero_moving_b[n_loop+1]);
                control_block_choice(n_loop,hero_moving_a[n_loop+1],hero_moving_b[n_loop+1]);
                n_loop++;
                if(n_loop==n)
                    n_loop-=n;
            }
            break;
        case 2:
            map_block[6][3]+=1;map_block[5][2]+=3;
            while(n_loop<n)
            {
                HolySwordsman_Res(&py[n_loop]);
                Prince_Res(&py[n_loop]);
                showPlayer(py[n_loop]);SetPos(6,44);
                Sleep(1000);emergency_decoration(2);
                printf("P%d turn:  ",n_loop+1);
                hero_step=HeroAction(py[n_loop].actionP);Sleep(500);
                if(py[n_loop].timeP==6)
                {
                    hero_step=Paladin_Res(&py[n_loop],hero_step);
                    showPlayer(py[n_loop]);
                }
                time=DragonAnger(hero_step,&dra);/**龙怒次数**/
                for(i=0;i<time;i++)
                {
                    DragonDisaster(count);///龙祸效果
                    showPlayer(py[n_loop]);SetPos(6,44);
                }
                if(dra.angerD<=0)
                {
                    break;
                }
                showDragonAnger(dra);///显示龙怒气值
                map_moving(hero_step,n_loop+1,&hero_moving_x[n_loop+1],&hero_moving_y[n_loop+1],&hero_moving_a[n_loop+1],&hero_moving_b[n_loop+1]);
                control_block_choice(n_loop,hero_moving_a[n_loop+1],hero_moving_b[n_loop+1]);
                n_loop++;
                if(n_loop==n)
                    n_loop-=n;
            }
            break;
        case 3:
            map_block[6][3]+=1;map_block[5][2]+=3;map_block[5][3]+=5;
            while(n_loop<n)
            {
                HolySwordsman_Res(&py[n_loop]);
                Prince_Res(&py[n_loop]);
                showPlayer(py[n_loop]);SetPos(6,44);
                Sleep(1000);emergency_decoration(2);
                printf("P%d turn:  ",n_loop+1);
                hero_step=HeroAction(py[n_loop].actionP);Sleep(500);
                if(py[n_loop].timeP==6)
                {
                     hero_step=Paladin_Res(&py[n_loop],hero_step);
                     showPlayer(py[n_loop]);
                }
                time=DragonAnger(hero_step,&dra);/**龙怒次数**/
                for(i=0;i<time;i++)
                {
                    DragonDisaster(count);///龙祸效果
                    showPlayer(py[n_loop]);SetPos(6,44);
                }
                if(dra.angerD<=0)
                {
                    break;
                }
                showDragonAnger(dra);///显示龙怒气值
                map_moving(hero_step,n_loop+1,&hero_moving_x[n_loop+1],&hero_moving_y[n_loop+1],&hero_moving_a[n_loop+1],&hero_moving_b[n_loop+1]);
                control_block_choice(n_loop,hero_moving_a[n_loop+1],hero_moving_b[n_loop+1]);
                n_loop++;
                if(n_loop==n)
                    n_loop-=n;
            }
            break;
        default:break;
    }
}

#endif // CONTROL_HEROS_LOOP_H_INCLUDED
