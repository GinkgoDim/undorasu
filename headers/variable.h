#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED

char key_button[9]={'w','e','a','s','d','z','x','y','n'};///设定的9个必要的可修改按键(weasdzxrv)，额外有热键ESC

int map_block[7][8]=
{
{30,    10,     30,     140,    -1,     0,      0,      0   },
{240,   30,     330,    340,    140,    140,    0,      0   },
{-2,    230,    340,    -3,     330,    30,     440,    0   },
{240,   240,    30,     340,    340,    10,     440,    -4  },
{0,     30,     30,     30,     20,     20,     30,     430 },
{0,     0,      10,     10,     20,     30,     540,    540 },
{0,     0,      0,      10,     30,     30,     540,    -5  }
};///地图区块编码

///英雄显示的坐标
int hero_moving_x[4]={0,    31,     27,     41};
int hero_moving_y[4]={0,    38,     33,     33};
///英雄在区块的坐标
int hero_moving_a[4]={0,    6,      5,      5};
int hero_moving_b[4]={0,    3,      2,      3};
///山特征标识
int map_mountain[6]={0,     10000,   20000,   30000,   40000,   50000};

int count;///记录了参加本次游戏的人数

int dragon_anger;

HERO py[3];///记录了参加游戏的角色

Dragonic dra;///建立龙

int CP_2=2,CP_3=3,CP_4=3,CP_5=2,CP_6=1;///任务完成的点数

#endif // VARIABLE_H_INCLUDED
