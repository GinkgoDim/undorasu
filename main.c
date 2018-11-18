#define _WIN32_WINNT 0x0500///�������ý�����󻯺ͽ������ɷֱ���

#include"headers/head.h"            ///�����������ͷ�ļ�
#include"headers/SetPos.h"          ///�����תģ��
#include"headers/setColor.h"        ///���弰������ɫ����ģ��
#include"headers/number_ARAB.h"     ///���������ʾ ����������
#include"headers/number_ROME.h"     ///���������ʾ ��������
#include"headers/emergency_decoration.h"///Ӧ��װ��ģ��
#include"headers/dice.h"            ///���Ӻ���
#include"headers/characters.h"
#include"headers/HeroMod.h"
#include"headers/Mission.h"         ///������������
#include"headers/music_room.h"      ///������ģ��

#include"headers/map.h"             ///��Ϸ��ͼ����ģ��
#include"headers/backgroundstory.h" ///��������ģ��
#include"headers/draw_title.h"      ///������ʾģ��
#include"headers/draw_key_config.h" ///�������û���ģ��
#include"headers/draw_hero_select.h"///Ӣ��ѡ�����ģ��
#include"headers/draw_empire_line.h"///�ָ��߻���ģ��
#include"headers/draw_help.h"       ///����ҳ��
#include"headers/random_mission.h"  ///�������ģ��
#include"headers/preparation.h"     ///һ�������ݳ�ʼ��ģ��
#include"headers/DragonicMod.h"     ///��ŭ ���� ������
#include"headers/control_key_config.h"  ///�����޸Ŀ���ģ��
#include"headers/control_hero_select.h" ///Ӣ��ѡ�����ģ��
#include"headers/control_map_moving.h"  ///̽�չ�����Ӣ�۵��ƶ�ģ��
#include"headers/control_block_choice.h"///���Ӣ�����������ܽ��еĻ
#include"headers/conrtol_heros_loop.h"  ///̽�չ�����Ӣ�۵��ֻ�ģ��
#include"headers/final_battle.h"        ///��ս�����ļ�

#include"headers/window_res_set.h"      ///���ڴ�С����ģ��

#include"headers/variable.h"            ///���������еĹ��б���

//a=97 s=115 d=100 w=119 h=104 q=113 e=101 z=122 x=120 enter=13
//6,2  6,41  109,2  109,41���������
//113,2  113,41  139,2  139,41�Ҳ�������
//6,44  109,44�·��������

int main()
{
    ///������󻯽��� ���ɷֱ��ʹ̶� �ֱ����趨
    window_res_set();

    ///����ģ��
    draw_title(6,2);

    ///��������ģ��,�������������
    background_story(20,21);

    ///��ⰴ���浵�����������д�������������������
    control_key_config_check(key_button);

    ///���Ʒָ���
    draw_empire_line();

    ///���Ծֲ���� Ӣ��ѡ�����
    draw_hero_select(0,7,0,8,8,2);
    draw_hero_select_word(7,0,8,2,1);
    setColor(7,0);
    control_hero_select();///����Ӣ��ѡ�����ģ��
    emergency_decoration(1);

    ///���Ի�����Ϸ����ͼ
    draw_map();
    ///Ӣ��ѭ��ģ��
    conrtol_heros_loop(count);

    ///��ս����
    final_battle_loop(count);

    SetPos(0,0);
    printf("system end!!!\n");
    return 0;
}
