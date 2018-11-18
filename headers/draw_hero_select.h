#ifndef DRAW_HERO_SELECT_H
#define DRAW_HERO_SELECT_H
void draw_hero_select(int,int,int,int,int,int);
void draw_hero_select_word(int,int,int,int,int);
void draw_hero_select_draw_line1();
void draw_hero_select_draw_line2();
void draw_hero_select_draw_line3();
void draw_hero_select_draw_line4();
void draw_hero_select_draw_apart_y(int,int);///纵向分隔符
void draw_hero_select_draw_apart_x(int,int);///横向分隔符
void draw_hero_select_draw_apart_a(int x,int y,int n);///斜上分隔符
void draw_hero_select_draw_apart_b(int x,int y,int n);///斜下分隔符
void draw_hero_select_draw_apart_c(int x,int y,int n);///横向绘制符

void draw_hero_select_left_up(int x,int y);
void draw_hero_select_up(int x,int y);
void draw_hero_select_right_up(int x,int y);
void draw_hero_select_right_down(int x,int y);
void draw_hero_select_down(int x,int y);
void draw_hero_select_left_down(int x,int y);
void draw_hero_select_middle(int x,int y);

void draw_hero_select_flash_choice(int n,int a,int b,int x,int y);///按下按键后的边框变色
void draw_hero_select_flash_left_up(int x,int y);
void draw_hero_select_flash_up(int x,int y);
void draw_hero_select_flash_right_up(int x,int y);
void draw_hero_select_flash_right_down(int x,int y);
void draw_hero_select_flash_down(int x,int y);
void draw_hero_select_flash_left_down(int x,int y);

void draw_hero_introduce_choice(int i,int x,int y);///按下按键后显示人物属性
void draw_hero_introduce_HolySwordsman(int i);
void draw_hero_introduce_Ninja(int i);
void draw_hero_introduce_Hunter(int i);
void draw_hero_introduce_Gladiator(int i);
void draw_hero_introduce_setPrince(int i);
void draw_hero_introduce_Paladin(int i);

void draw_hero_select_empire_line();

void draw_hero_select(int ca,int cb,int cc,int cd,int x,int y)
{
    setColor(ca,cb);
    draw_hero_select_left_up(x,y);
    draw_hero_select_up(x,y);
    draw_hero_select_right_up(x,y);
    draw_hero_select_right_down(x,y);
    draw_hero_select_down(x,y);
    draw_hero_select_left_down(x,y);
    setColor(cc,cd);
    draw_hero_select_middle(x,y);
}

void draw_hero_select_word(int a,int b,int x,int y,int n)
{
    extern char key_button[9];
    if(n==1)
    {
        setColor(a,b);
        SetPos(x+38,y+14);printf("剑  圣");SetPos(x+37,y+15);printf("(Press %c)",key_button[0]);
        SetPos(x+56,y+14);printf("忍  者");SetPos(x+55,y+15);printf("(Press %c)",key_button[1]);
        SetPos(x+32,y+20);printf("猎  人");SetPos(x+31,y+21);printf("(Press %c)",key_button[2]);
        SetPos(x+62,y+20);printf("角斗士");SetPos(x+61,y+21);printf("(Press %c)",key_button[4]);
        SetPos(x+38,y+26);printf("王  子");SetPos(x+37,y+27);printf("(Press %c)",key_button[5]);
        SetPos(x+56,y+26);printf("圣骑士");SetPos(x+55,y+27);printf("(Press %c)",key_button[6]);
        SetPos(x+45,y+18);printf("(%c)上 up",key_button[7]);
        SetPos(x+47,y+19);printf("查看帮助");
        SetPos(x+47,y+20);printf("按键设置");
        SetPos(x+47,y+21);printf("音 乐 室");
        SetPos(x+45,y+22);printf("(%c)下down",key_button[8]);
    }
    else
    {
        setColor(7,0);
        SetPos(x+38,y+14);printf("      ");SetPos(x+37,y+15);printf("          ");
        SetPos(x+56,y+14);printf("      ");SetPos(x+55,y+15);printf("          ");
        SetPos(x+32,y+20);printf("      ");SetPos(x+31,y+21);printf("          ");
        SetPos(x+62,y+20);printf("      ");SetPos(x+61,y+21);printf("          ");
        SetPos(x+38,y+26);printf("      ");SetPos(x+37,y+27);printf("          ");
        SetPos(x+56,y+26);printf("      ");SetPos(x+55,y+27);printf("          ");
        SetPos(x+47,y+19);printf("        ");
        SetPos(x+47,y+20);printf("        ");
        SetPos(x+47,y+21);printf("        ");
    }
}

void draw_hero_select_empire_line()
{
    ///绘制分隔符
    draw_hero_select_draw_apart_x(146,0);
    draw_hero_select_draw_apart_x(146,1);
    draw_hero_select_draw_apart_x(146,42);
    draw_hero_select_draw_apart_x(146,43);
    draw_hero_select_draw_apart_y(110,46);
    draw_hero_select_draw_apart_y(140,46);
    draw_hero_select_draw_apart_y(3,46);
}

void draw_hero_select_draw_line1()
{
    printf("| |");
}
void draw_hero_select_draw_line2()
{
    //printf("_");
    printf(" ");
}
void draw_hero_select_draw_line3()
{
    //printf("/");
    printf(" ");
}
void draw_hero_select_draw_line4()
{
    //printf("\\");
    printf(" ");
}
void draw_hero_select_draw_apart_y(int x,int y)///纵向分隔符
{
    int i;
    for(i=0;i<y;i++)
    {
        SetPos(x,i);draw_hero_select_draw_line1();
    }
}
void draw_hero_select_draw_apart_x(int x,int y)///横向分隔符
{
    int i;
    SetPos(0,y);
    for(i=0;i<x;i++)
        draw_hero_select_draw_line2();
}

void draw_hero_select_draw_apart_a(int x,int y,int n)///斜上绘制符 x,y为左上角坐标
{
    int i;
    for(i=0;i<n;i++)
    {
        SetPos(x+i,y-i);
        draw_hero_select_draw_line3();
    }
}
void draw_hero_select_draw_apart_b(int x,int y,int n)///斜下绘制符 x,y为左下角坐标
{
    int i;
    for(i=0;i<n;i++)
    {
        SetPos(x+i,y+i);
        draw_hero_select_draw_line4();
    }
}
void draw_hero_select_draw_apart_c(int x,int y,int n)///横向绘制符 x,y为左坐标
{
    int i;
    SetPos(x,y);
    for(i=0;i<n;i++)
        draw_hero_select_draw_line2();
}

void draw_hero_select_left_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+25,y+18,8);
    draw_hero_select_draw_apart_b(x+24,y+1,10);
    draw_hero_select_draw_apart_c(x+3,y+19,22);
}
void draw_hero_select_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+63,y+9,9);
    draw_hero_select_draw_apart_b(x+28,y+1,9);
    draw_hero_select_draw_apart_c(x+37,y+9,26);
}
void draw_hero_select_right_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+66,y+10,10);
    draw_hero_select_draw_apart_b(x+67,y+11,8);
    draw_hero_select_draw_apart_c(x+75,y+19,22);
}
void draw_hero_select_right_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+66,y+30,9);
    draw_hero_select_draw_apart_b(x+67,y+31,9);
    draw_hero_select_draw_apart_c(x+75,y+21,22);
}
void draw_hero_select_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+28,y+39,8);
    draw_hero_select_draw_apart_b(x+64,y+32,8);
    draw_hero_select_draw_apart_c(x+36,y+31,28);
}
void draw_hero_select_left_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+24,y+39,9);
    draw_hero_select_draw_apart_b(x+25,y+22,9);
    draw_hero_select_draw_apart_c(x+3,y+21,22);

}
void draw_hero_select_middle(int x,int y)
{
    ///六向斜线
    draw_hero_select_draw_apart_a(x+64,y+10,10);
    draw_hero_select_draw_apart_a(x+26,y+39,9);
    draw_hero_select_draw_apart_b(x+26,y+1,10);
    draw_hero_select_draw_apart_b(x+65,y+31,9);
    draw_hero_select_draw_apart_c(x+3,y+20,23);
    draw_hero_select_draw_apart_c(x+74,y+20,23);
    ///中部大六边形
    draw_hero_select_draw_apart_a(x+25,y+20,10);
    draw_hero_select_draw_apart_a(x+64,y+30,10);
    draw_hero_select_draw_apart_b(x+65,y+11,10);
    draw_hero_select_draw_apart_b(x+26,y+21,10);
    draw_hero_select_draw_apart_c(x+36,y+10,28);
    draw_hero_select_draw_apart_c(x+36,y+30,28);
    ///中部小六边形
    draw_hero_select_draw_apart_a(x+42,y+20,3);
    draw_hero_select_draw_apart_a(x+55,y+22,2);
    draw_hero_select_draw_apart_b(x+43,y+21,2);
    draw_hero_select_draw_apart_b(x+55,y+18,3);
    draw_hero_select_draw_apart_c(x+45,y+17,10);
    draw_hero_select_draw_apart_c(x+45,y+23,10);
}

void draw_hero_select_flash_choice(int n,int a,int b,int x,int y)///绘制按下对应后显示亮光区域
{
    setColor(a,b);
    switch(n)
    {
        case 0:draw_hero_select_flash_left_up(x,y);break;
        case 1:draw_hero_select_flash_up(x,y);break;
        case 2:draw_hero_select_flash_left_down(x,y);break;
        case 4:draw_hero_select_flash_right_up(x,y);break;
        case 5:draw_hero_select_flash_down(x,y);break;
        case 6:draw_hero_select_flash_right_down(x,y);break;
        default:break;
    }
}

void draw_hero_select_flash_left_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+24,y+18,8);
    draw_hero_select_draw_apart_b(x+23,y+1,10);
    draw_hero_select_draw_apart_c(x+3,y+18,22);
}
void draw_hero_select_flash_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+63,y+8,8);
    draw_hero_select_draw_apart_b(x+29,y+1,8);
    draw_hero_select_draw_apart_c(x+37,y+8,26);
}
void draw_hero_select_flash_right_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+67,y+10,10);
    draw_hero_select_draw_apart_b(x+68,y+11,8);
    draw_hero_select_draw_apart_c(x+76,y+18,21);
}
void draw_hero_select_flash_right_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+67,y+30,9);
    draw_hero_select_draw_apart_b(x+68,y+31,9);
    draw_hero_select_draw_apart_c(x+76,y+22,21);
}
void draw_hero_select_flash_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+29,y+39,8);
    draw_hero_select_draw_apart_b(x+63,y+32,8);
    draw_hero_select_draw_apart_c(x+36,y+32,28);
}
void draw_hero_select_flash_left_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+23,y+39,9);
    draw_hero_select_draw_apart_b(x+24,y+22,9);
    draw_hero_select_draw_apart_c(x+3,y+22,21);
}

void draw_hero_introduce_choice(int i,int x,int y)
{
    setColor(x,y);
    switch(i)
    {
        case 1:draw_hero_introduce_HolySwordsman(1);break;
        case 2:draw_hero_introduce_HolySwordsman(0);break;
        case 3:draw_hero_introduce_Ninja(1);break;
        case 4:draw_hero_introduce_Ninja(0);break;
        case 5:draw_hero_introduce_Hunter(1);break;
        case 6:draw_hero_introduce_Hunter(0);break;
        case 7:draw_hero_introduce_Gladiator(1);break;
        case 8:draw_hero_introduce_Gladiator(0);break;
        case 9:draw_hero_introduce_setPrince(1);break;
        case 10:draw_hero_introduce_setPrince(0);break;
        case 11:draw_hero_introduce_Paladin(1);break;
        case 12:draw_hero_introduce_Paladin(0);break;
        default:break;
    }
}

void draw_hero_introduce_HolySwordsman(int i)
{
    switch(i)
    {
        case 1:
            SetPos(13,6);printf("剑圣");
            SetPos(13,8);printf("生命值:6/6");
            SetPos(13,10);printf("移动4 冒险2/2 战斗2");
            SetPos(13,11);printf("探索2 学识2");
            SetPos(13,13);printf("魔力:3/3(4)");
            SetPos(13,14);printf("回合开始时，恢复1点");
            fn_clear_right();

            SetPos(113,2);printf("经验值:");
            SetPos(113,3);printf("lv0(0)\t无");
            SetPos(113,4);printf("lv1(1)\t战斗+1");
            SetPos(113,5);printf("lv2(2)\t探索+1");
            SetPos(113,6);printf("lv3(3)\t生命全满");
            SetPos(113,7);printf("lv4(4)\t魔力上限+1 ");
            SetPos(113,8);printf("lv5(5)\t战斗+1");
            SetPos(113,9);printf("lv6(6)\t战斗+1");

            SetPos(113,12);printf("秘宝:");
            SetPos(113,13);printf("远古秘药");
            SetPos(113,14);printf("[决战阶段]开始时使用，提");
            SetPos(113,15);printf("升魔力上限，恢复全部魔力");

            SetPos(113,28);printf("剑圣");
            SetPos(113,30);printf("人物描述");
            SetPos(113,31);printf("被授予了[传说中的英雄]");
            SetPos(113,32);printf("称号的帝国骑士团长。受");
            SetPos(113,33);printf("皇帝之命只身一人来讨伐");
            SetPos(113,34);printf("恶龙。失传了的古代魔法");
            SetPos(113,35);printf("的传承者，并且是帝国首");
            SetPos(113,36);printf("屈一指的剑术大师。");
            break;
        case 0:
            SetPos(13,6);printf("    ");
            SetPos(13,8);printf("          ");
            SetPos(13,10);printf("                   ");
            SetPos(13,11);printf("           ");
            SetPos(13,13);printf("            ");
            SetPos(13,14);printf("                   ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_Ninja(int i)
{
    switch(i)
    {
        case 1:
            SetPos(44,4);printf("忍者  生命值:4/4");
            SetPos(43,5);printf("移动4 冒险1/3 战斗2 探索3 学识1");
            SetPos(44,6);printf("忍术:2/3(4)");
            SetPos(45,7);printf("回复手段:停留在森林时");
            SetPos(47,8);printf("回复1点");
            fn_clear_right();

            SetPos(113,2);printf("经验值:");
            SetPos(113,3);printf("lv0(0)\t无");
            SetPos(113,4);printf("lv1(2)\t探索+1");
            SetPos(113,5);printf("lv2(4)\t战斗+1");
            SetPos(113,6);printf("lv3(7)\t忍术上限+1");
            SetPos(113,7);printf("\t回复1点忍术");

            SetPos(113,10);printf("秘宝:");
            SetPos(113,11);printf("胧霞");
            SetPos(113,12);printf("[决战阶段]中，战斗投骰后，");
            SetPos(113,13);printf("[暴击]判定前，可以将所有骰");
            SetPos(113,14);printf("子重投1次(每回合1次)");

            SetPos(113,28);printf("忍者");
            SetPos(113,30);printf("人物描述");
            SetPos(113,31);printf("身着黑色外衣，隐藏真面");
            SetPos(113,32);printf("目的谜之旅人。为了入手");
            SetPos(113,33);printf("不死秘药原料的龙肝，踏");
            SetPos(113,34);printf("上了屠龙之旅。利用自然");
            SetPos(113,35);printf("之力秘书[忍术]的传承人");
            break;
        case 0:
            SetPos(44,4);printf("                ");
            SetPos(43,5);printf("                               ");
            SetPos(44,6);printf("           ");
            SetPos(45,7);printf("                       ");
            SetPos(47,8);printf("        ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_Hunter(int i)
{
    switch(i)
    {
        case 1:
            SetPos(13,27);printf("猎人");
            SetPos(13,28);printf("生命值:5/5");
            SetPos(13,30);printf("移动3 冒险2/2 战斗2");
            SetPos(13,31);printf("探索2 学识2");
            SetPos(13,33);printf("魔弹:3/3");
            SetPos(13,34);printf("回复手段：[休息]时，");
            SetPos(13,35);printf("回复到上限。");
            fn_clear_right();

            SetPos(113,2);printf("经验值:");
            SetPos(113,3);printf("lv0(0)\t无");
            SetPos(113,4);printf("lv1(2)\t战斗+1");
            SetPos(113,5);printf("lv2(4)\t探索+1");
            SetPos(113,6);printf("lv3(7)\t战斗+1");

            SetPos(113,9);printf("秘宝:");
            SetPos(113,10);printf("致命子弹");
            SetPos(113,11);printf("[决战阶段]中，战斗投骰后，");
            SetPos(113,12);printf("[暴击]判定前，增加一点成功");
            SetPos(113,13);printf("值(每局游戏限3次，每回合限");
            SetPos(113,14);printf("一次)");

            SetPos(113,28);printf("猎人");
            SetPos(113,30);printf("人物描述");
            SetPos(113,31);printf("以狩猎魔兽为生的猎人。");
            SetPos(113,32);printf("厌倦了平常的狩猎，想要");
            SetPos(113,33);printf("通过狩猎恶龙，一夜暴富");
            SetPos(113,34);printf("使用灌注了魔力的[魔铳]");
            SetPos(113,35);printf("进行战斗。");
            break;
        case 0:
            SetPos(13,27);printf("    ");
            SetPos(13,28);printf("          ");
            SetPos(13,30);printf("                   ");
            SetPos(13,31);printf("            ");
            SetPos(13,33);printf("        ");
            SetPos(13,34);printf("                    ");
            SetPos(13,35);printf("            ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_Gladiator(int i)
{
    switch(i)
    {
        case 1:
            SetPos(85,6);printf("角斗士");
            SetPos(85,7);printf("生命值:5/6");
            SetPos(85,9);printf("移动3 冒险2/1 战斗4");
            SetPos(85,10);printf("探索1 学识1");
            SetPos(85,12);printf("角斗士不需要资源");
            SetPos(85,14);printf("在[平原]进行[冒险]");
            SetPos(85,15);printf("后回复1生命值");
            fn_clear_right();

            SetPos(113,2);printf("经验值:");
            SetPos(113,3);printf("lv0(0)\t无");
            SetPos(113,4);printf("lv1(2)\t探索+1");
            SetPos(113,5);printf("lv2(4)\t战斗+1");
            SetPos(113,6);printf("lv3(7)\t生命值全满");

            SetPos(113,9);printf("秘宝:");
            SetPos(113,10);printf("猛犸肉");
            SetPos(113,11);printf("在进入[决战阶段]时，立刻将");
            SetPos(113,12);printf("生命值恢复至最大值");

            SetPos(113,28);printf("角斗士");
            SetPos(113,30);printf("人物描述");
            SetPos(113,31);printf("从帝都第一斗技场战斗胜");
            SetPos(113,32);printf("出的原斗技冠军。为了给");
            SetPos(113,33);printf("被恶龙吃掉的师傅报仇，");
            SetPos(113,34);printf("重新拾起了武器。擅长双");
            SetPos(113,35);printf("持武器的连续攻击与大力");
            SetPos(113,36);printf("打击。");
            break;
        case 0:
            SetPos(85,6);printf("      ");
            SetPos(85,7);printf("           ");
            SetPos(85,9);printf("                   ");
            SetPos(85,10);printf("           ");
            SetPos(85,12);printf("                ");
            SetPos(85,14);printf("                  ");
            SetPos(85,15);printf("             ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_setPrince(int i)
{
    switch(i)
    {
        case 1:
            SetPos(46,36);printf("王子  生命值:4/4");
            SetPos(45,37);printf("移动3 冒险2/1 战斗1 探索1");
            SetPos(44,38);printf("学识3");
            SetPos(43,39);printf("部下:0/lv数");
            SetPos(42,40);printf("自己回合开始时，回复到上限");
            SetPos(41,41);printf("([决战阶段]无法恢复)");
            fn_clear_right();

            SetPos(113,2);printf("经验值:");
            SetPos(113,3);printf("lv0(0)\t无");
            SetPos(113,4);printf("lv1(2)\t战斗+1探索+1");
            SetPos(113,5);printf("lv2(4)\t战斗+1探索+1");
            SetPos(113,6);printf("lv3(7)\t战斗+1探索+1");

            SetPos(113,9);printf("秘宝:");
            SetPos(113,10);printf("金币:1/3");
            SetPos(113,11);printf("[龙之秘宝]入手时回复3点");
            SetPos(113,12);printf("金币可以当作资源使用");

            SetPos(113,28);printf("王子");
            SetPos(113,30);printf("人物描述");
            SetPos(113,31);printf("因为政争失败而流亡的王");
            SetPos(113,32);printf("子。想要在故国复起。计");
            SetPos(113,33);printf("划通过挑战巨龙获得声望");
            SetPos(113,34);printf("因此踏上了屠龙之旅。由");
            SetPos(113,35);printf("于本身不擅长战斗，通过");
            SetPos(113,36);printf("雇佣大量部下进行战斗。");
            break;
        case 0:
            SetPos(46,36);printf("                ");
            SetPos(45,37);printf("                         ");
            SetPos(44,38);printf("     ");
            SetPos(43,39);printf("           ");
            SetPos(42,40);printf("                          ");
            SetPos(41,41);printf("                    ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_Paladin(int i)
{
    switch(i)
    {
        case 1:
            SetPos(85,27);printf("圣骑士");
            SetPos(85,28);printf("生命值:5/6");
            SetPos(85,30);printf("移动3 冒险2/1 战斗3");
            SetPos(85,31);printf("探索1 学识2");
            SetPos(85,33);printf("信仰心:2/2");
            SetPos(85,34);printf("移动时，将投掷点数最高");
            SetPos(85,35);printf("的1颗骰子移除，回复1点");
            SetPos(85,36);printf("(每回合1次)");
            fn_clear_right();

            SetPos(113,2);printf("经验值:");
            SetPos(113,3);printf("lv0(0)\t无");
            SetPos(113,4);printf("lv1(2)\t信仰心+1");
            SetPos(113,5);printf("lv2(4)\t生命全满");
            SetPos(113,6);printf("lv3(7)\t战斗+1");

            SetPos(113,9);printf("秘宝:");
            SetPos(113,10);printf("白银之盾");
            SetPos(113,11);printf("给一个英雄回复2点生命或者");
            SetPos(113,12);printf("为所有英雄回复1点生命");
            SetPos(113,13);printf("(每局游戏限1次)");

            SetPos(113,28);printf("圣骑士");
            SetPos(113,30);printf("人物描述");
            SetPos(113,31);printf("全身覆盖重甲的圣堂骑士");
            SetPos(113,32);printf("受大教会派遣而来，退治");
            SetPos(113,33);printf("恶龙。能够使用由对神的");
            SetPos(113,34);printf("信仰之力转化而成的神圣");
            SetPos(113,35);printf("魔法。");
            break;
        case 0:
            SetPos(85,27);printf("      ");
            SetPos(85,28);printf("          ");
            SetPos(85,30);printf("                   ");
            SetPos(85,31);printf("           ");
            SetPos(85,33);printf("          ");
            SetPos(85,34);printf("                      ");
            SetPos(85,35);printf("                      ");
            SetPos(85,36);printf("           ");
            fn_clear_right();
            break;
        default:break;
    }
}
#endif // DRAW_HERO_SELECT_H
