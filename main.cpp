#include "HeroMod.h"
#include "DragonicMod.h"
int main()
{
    ///主函数初始化英雄(测试)
    HERO py[3];
    py[0]=setGladiator();
    py[1]=setPrince();
    py[2]=setPaladin();
    showPlayer(py[0]);
    ///主函数初始化龙
    Dragonic Dark_D;
    Dark_D=setSingleDarkDragon(Dark_D);
    showDragonAnger(Dark_D);
    printf("\n%d\n",Dark_D.angerD);
    ///主函数龙怒改变
    DragonAnger(HeroAction(py[0].actionP),&Dark_D,3);
    printf("\n%d\n",Dark_D.angerD);
    showDragonAnger(Dark_D);
    ///任务实现
    putchar(10);
    printf("任务实现测试：\n");
    Chimera_2p(&py[0],&py[2]);
    showPlayer(py[0]);
    Chimera_2p(&py[0],&py[2]);
    showPlayer(py[0]);
    Chimera_2p(&py[0],&py[2]);
    showPlayer(py[0]);
    Chimera_2p(&py[0],&py[2]);
    showPlayer(py[0]);
    Chimera_2p(&py[0],&py[2]);
    showPlayer(py[0]);
    return 0;
}
