#define _WIN32_WINNT 0x0500///用于设置禁用最大化和禁用自由分辨率

#include"headers/head.h"            ///包含所需基本头文件
#include"headers/SetPos.h"          ///光标跳转模组
#include"headers/setColor.h"        ///字体及背景颜色设置模组
#include"headers/number_ARAB.h"     ///大块数字显示 阿拉伯数字
#include"headers/number_ROME.h"     ///大块数字显示 罗马数字
#include"headers/emergency_decoration.h"///应急装饰模组
#include"headers/dice.h"            ///骰子函数
#include"headers/characters.h"
#include"headers/HeroMod.h"
#include"headers/Mission.h"         ///任务和升级相关
#include"headers/music_room.h"      ///音乐室模组

#include"headers/map.h"             ///游戏地图绘制模组
#include"headers/backgroundstory.h" ///背景故事模组
#include"headers/draw_title.h"      ///标题显示模组
#include"headers/draw_key_config.h" ///按键设置绘制模组
#include"headers/draw_hero_select.h"///英雄选择绘制模组
#include"headers/draw_empire_line.h"///分割线绘制模组
#include"headers/draw_help.h"       ///帮助页面
#include"headers/random_mission.h"  ///随机任务模组
#include"headers/preparation.h"     ///一部分数据初始化模组
#include"headers/DragonicMod.h"     ///龙怒 龙祸 龙生命
#include"headers/control_key_config.h"  ///按键修改控制模组
#include"headers/control_hero_select.h" ///英雄选择控制模组
#include"headers/control_map_moving.h"  ///探险过程中英雄的移动模组
#include"headers/control_block_choice.h"///检测英雄所在区域能进行的活动
#include"headers/conrtol_heros_loop.h"  ///探险过程中英雄的轮换模组
#include"headers/final_battle.h"        ///决战环节文件

#include"headers/window_res_set.h"      ///窗口大小控制模组

#include"headers/variable.h"            ///程序中所有的公有变量

//a=97 s=115 d=100 w=119 h=104 q=113 e=101 z=122 x=120 enter=13
//6,2  6,41  109,2  109,41主界面参数
//113,2  113,41  139,2  139,41右侧界面参数
//6,44  109,44下方界面参数

int main()
{
    ///窗口最大化禁用 自由分辨率固定 分辨率设定
    window_res_set();

    ///标题模组
    draw_title(6,2);

    ///背景故事模组,按下任意键继续
    background_story(20,21);

    ///检测按键存档，如果存在则复写按键，如果不存在则建立
    control_key_config_check(key_button);

    ///绘制分割线
    draw_empire_line();

    ///测试局部清除 英雄选择界面
    draw_hero_select(0,7,0,8,8,2);
    draw_hero_select_word(7,0,8,2,1);
    setColor(7,0);
    control_hero_select();///测试英雄选择控制模组
    emergency_decoration(1);

    ///测试绘制游戏主地图
    draw_map();
    ///英雄循环模组
    conrtol_heros_loop(count);

    ///决战环节
    final_battle_loop(count);

    SetPos(0,0);
    printf("system end!!!\n");
    return 0;
}
