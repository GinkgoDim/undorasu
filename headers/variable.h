#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED

char key_button[9]={'w','e','a','s','d','z','x','y','n'};///�趨��9����Ҫ�Ŀ��޸İ���(weasdzxrv)���������ȼ�ESC

int map_block[7][8]=
{
{30,    10,     30,     140,    -1,     0,      0,      0   },
{240,   30,     330,    340,    140,    140,    0,      0   },
{-2,    230,    340,    -3,     330,    30,     440,    0   },
{240,   240,    30,     340,    340,    10,     440,    -4  },
{0,     30,     30,     30,     20,     20,     30,     430 },
{0,     0,      10,     10,     20,     30,     540,    540 },
{0,     0,      0,      10,     30,     30,     540,    -5  }
};///��ͼ�������

///Ӣ����ʾ������
int hero_moving_x[4]={0,    31,     27,     41};
int hero_moving_y[4]={0,    38,     33,     33};
///Ӣ�������������
int hero_moving_a[4]={0,    6,      5,      5};
int hero_moving_b[4]={0,    3,      2,      3};
///ɽ������ʶ
int map_mountain[6]={0,     10000,   20000,   30000,   40000,   50000};

int count;///��¼�˲μӱ�����Ϸ������

int dragon_anger;

HERO py[3];///��¼�˲μ���Ϸ�Ľ�ɫ

Dragonic dra;///������

int CP_2=2,CP_3=3,CP_4=3,CP_5=2,CP_6=1;///������ɵĵ���

#endif // VARIABLE_H_INCLUDED
