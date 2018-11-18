#ifndef DRAW_HELP_H_INCLUDED
#define DRAW_HELP_H_INCLUDED
///1355531
void draw_help();
void draw_help_page1();
void draw_help_page2();
void draw_help_page3();
void draw_help_block(int color,int x,int y);

void draw_help()
{
    int page=1;
    int ch;
    draw_help_page1();
    SetPos(115,3);printf("按下回车翻页");
    SetPos(115,4);printf("Press 'Enter' next page");
    SetPos(115,6);printf("按下ESC返回");
    SetPos(115,7);printf("Press 'ESC' back");
    SetPos(6,44);printf("Page 1");
    while(1)///按下ESC退出修改界面，按下ENTER开始进行修改
    {
        if (_kbhit())
        {///如果有按键按下，则_kbhit()函数返回真
            ch = _getch();///使用_getch()函数获取按下的键值
            emergency_decoration(2);
            if(ch==13)
            {
                switch(page)
                {
                    case 1:
                        page++;
                        emergency_decoration(1);
                        draw_help_page2();
                        break;
                    case 2:
                        page++;
                        emergency_decoration(1);
                        draw_help_page3();
                        break;
                    case 3:
                        page=1;
                        emergency_decoration(1);
                        draw_help_page1();
                        break;
                    default:break;
                }
            }
            SetPos(6,44);printf("Page %d",page);
            if(ch==27)
                break;
        }
    }
}

void draw_help_page1()
{
    SetPos(10,4);printf("热心制作者的帮助页面");
    SetPos(10,6);printf("生命值(n/n)\t\t生命值降到0玩家扮演的角色就会阵亡，冒险过程中阵亡游戏就会结束");
    SetPos(10,8);printf("经验值\t\t经验值提升可以提升角色等级获得增益");
    SetPos(10,10);printf("资源值\t\t每个角色都有特殊的资源值，拥有特殊的回复手段");
    SetPos(10,11);printf("\t\t\t游戏中名称有 魔力 忍术 魔弹 部下 金币 信仰心");
    SetPos(10,12);printf("\t\t\t它们可以用来防御，或者多投掷骰子提升成功率");
    SetPos(10,14);printf("人物基础属性\t\t移动(n) 冒险(n/n) 战斗(n) 探索(n) 学识(n)");
    SetPos(10,15);printf("\t\t\t其中冒险数值前一个为平原冒险数值，后一个为森林冒险数值");
    SetPos(10,17);printf("秘宝\t\t\t每个角色拥有强大效果的特殊技能，需要入手[龙之秘宝]才可使用");

    SetPos(10,20);printf("龙怒\t\t\t总值为15，每当玩家的移动骰投掷出6的时候会降1，降至0会激怒龙强制进入决战");
    SetPos(10,21);printf("龙祸\t\t\t当龙怒位于14 11 8 5 2处，龙怒到对应值时激发龙祸，此时投掷龙骰子触发事件");
    SetPos(10,23);printf("龙祸表:");
    SetPos(10,24);printf("    1焚毁贝尔村 贝尔村被烧毁！所有在贝尔村的玩家受到2点伤害");
    SetPos(10,25);printf("    2擒抓拐投   所有玩家投掷1枚骰子，点数最高的玩家回到主城");
    SetPos(10,26);printf("    3龙息喷射   所有玩家承受1点伤害");
    SetPos(10,27);printf("    4火球连射   所有玩家投掷1枚骰子，点数最低的玩家承受2点伤害");
    SetPos(10,28);printf("    5火球散射   所有玩家投掷1枚骰子，点数最高的玩家承受2点伤害");
    SetPos(10,29);printf("    6威压咆哮   所有玩家投掷1枚骰子点数最低的玩家资源值耗尽(金币不受影响)");

    SetPos(10,32);printf("掷骰子成功与否的判定\t对于一个6面骰子(D6)，有成功、无果、失败3种情况");
    SetPos(10,33);printf("骰子判定表:(冒险骰:1&2失败3&4无果5&6成功  挑战骰:1失败2&3&4无果5&6成功)");
    SetPos(10,34);printf("    失败，相当于-1    无果，相当于0    成功，相当于1");

    SetPos(10,37);printf("冒险\t\t\t当玩家站在 平原 森林 板块上时，可以选择“冒险”，会根据玩家自己在该板块上");
    SetPos(10,38);printf("\t\t\t的冒险值进行判定，获得奖励……或者惩罚……");
    SetPos(10,39);printf("冒险表:");
    SetPos(10,40);printf("    -1以下 受到1点伤害  0 无事发生  1 获得1点经验但受到1点伤害  2以上 获得1点经验");
    SetPos(6,44);
}

void draw_help_page2()
{
    SetPos(10,4);printf("人物移动投骰\t\t投掷出不同的数值能够使玩家进入不同的板块(山 边界 焚毁的贝尔村都是不可逾越的)");
    SetPos(10,5);printf("移动表");
    SetPos(10,6);printf("    1 哪儿也去不了    2 可进入道路    3&4 可进入道路、平原");
    SetPos(10,7);printf("    5 可进入道路、平原、森林    6 除了可走任意板块外可以多投掷1次，但会触发龙怒");

    SetPos(10,10);printf("以下为板块图例");
    draw_help_block(8,14,13);SetPos(25,16);printf("<=道路");draw_help_block(2,42,13);SetPos(53,16);printf("<=森林");draw_help_block(15,70,13);SetPos(81,16);printf("<=城市/村庄/城镇");
    draw_help_block(6,14,22);SetPos(25,25);printf("<=平原");draw_help_block(5,42,22);SetPos(53,25);printf("<=山地");draw_help_block(4,70,22);SetPos(81,25);printf("<=烧毁的贝尔村");

    SetPos(10,31);printf("任务\t\t\t地图中的5座山藏着5个任务，需要玩家利用所需基础属性来投掷骰子进行完成");
    SetPos(10,32);printf("\t\t\t如果任务较难可以和队友一起完成，但是多人完成任务时需要队友站在任务板块周围");
    SetPos(10,33);printf("\t\t\t投掷出成功 完成度+1，投掷出无果 完成度不变，投掷出失败 完成度-1(最低为0)");
    SetPos(10,35);printf("奖励\t\t\t当任务完成时可以获得固定奖励，一共5张");
    SetPos(10,36);printf("奖励表");
    SetPos(10,37);printf("    匿龙地图\t当开始决战时先对龙造成1点伤害");
    SetPos(10,38);printf("    龙之秘宝\t\t获取者可以使用秘宝技能");
    SetPos(10,39);printf("    秘龙之书\t\t获取时所有玩家经验值+1");
    SetPos(10,40);printf("    屠龙武器\t\t获取时所有玩家战斗值+1");
    SetPos(10,41);printf("    古龙之血\t\t获取时所有玩家生命值回复到上限");

    SetPos(6,44);
}

void draw_help_page3()
{
    SetPos(10,4);printf("决战环节\t\t\t当玩家完成了5座山的任务或者通过移动投掷了15次6激怒龙时，开始决战！");
    SetPos(10,5);printf("\t\t\t通过移动投掷了15次6激怒龙开始决战，龙被激怒优先攻击，先进行两次龙怒攻击");
    SetPos(10,6);printf("\t\t\t通过完成任务开始决战时，英雄找到了龙开展了伏击，开场不会有两次龙怒");
    SetPos(10,9);printf("决战战斗环节\t\t\t玩家利用自己的战斗值和资源值与龙展开大战");
    SetPos(10,10);printf("决战表");
    SetPos(10,11);printf("    -1及以下\t被龙吞噬，不知所措，即死");
    SetPos(10,12);printf("    0\t\t龙的双爪连续猛攻，玩家承受4点伤害");
    SetPos(10,13);printf("    1\t\t龙息扫射，所有玩家承受1点伤害");
    SetPos(10,14);printf("    2\t\t连携攻击的机会，根据玩家人数再次投骰计入攻击，若仍为2则进行龙息扫射");
    SetPos(10,15);printf("    3\t\t两败俱伤，龙承受1点伤害，玩家承受2点伤害");
    SetPos(10,16);printf("    4\t\t背后突袭，龙承受1点伤害");
    SetPos(10,17);printf("    5及以上\t面对弱点的英勇一击，龙承受2点伤害");
    SetPos(10,20);printf("龙的生命值\t\t龙一共9血，除去最后1滴血必须单独攻击外，龙每回合最多承受2点伤害");
    SetPos(10,21);printf("龙怒攻击\t\t当龙的血量抵达8 6 4 2时，会触发龙怒攻击");
    SetPos(10,22);printf("龙怒攻击表");
    SetPos(10,23);printf("    1\t\t思考龙生，无事发生");
    SetPos(10,24);printf("    2&3\t龙息攻击，所有玩家承受1点伤害");
    SetPos(10,25);printf("    4&5&6\t鲁莽突进，所有玩家投掷1枚骰子，点数最低的玩家承受2点伤害");
    SetPos(10,29);printf("最后，制作者祝各位玩家屠(喂)龙愉快！");
}

void draw_help_block(int color,int x,int y)
{
    setColor(0,color);
    SetPos(x+4,y);printf("  ");
    SetPos(x+2,y+1);printf("      ");
    SetPos(x,y+2);printf("          ");
    SetPos(x,y+3);printf("          ");
    SetPos(x,y+4);printf("          ");
    SetPos(x+2,y+5);printf("      ");
    SetPos(x+4,y+6);printf("  ");
    setColor(7,0);
}
#endif // DRAW_HELP_H_INCLUDED
