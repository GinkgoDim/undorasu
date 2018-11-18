#ifndef CONTROL_BLOCK_CHOICE_H_INCLUDED
#define CONTROL_BLOCK_CHOICE_H_INCLUDED

extern int map_block[7][8];
extern char key_button[9];
extern int map_mountain[6];
extern HERO py[3];///��¼�˲μ���Ϸ�Ľ�ɫ

void control_block_choice(int,int,int);
void hero_action1(int,int*,int,int);
void hero_action2(int,int,int);
void block_choice_explore_p(int);
void block_choice_explore_f(int);
void mountain_spy(int);
void mountain_reward(int);
void mountain_mission(int);

void control_block_choice(int n,int a,int b)
{
    SetPos(113,33);printf(" >ѡ������ж�");
    if(map_block[a][b]%100>=10&&map_block[a][b]%100<20)
    {
        SetPos(113,34);printf("                ");
        SetPos(113,35);printf("                ");
        SetPos(113,34);printf("  (%c) ��Ϣ",key_button[7]);
    }
    if(map_block[a][b]%100>=20&&map_block[a][b]%100<30)
    {
        SetPos(113,34);printf("                ");
        SetPos(113,35);printf("                ");
        SetPos(113,34);printf("      ���¿���");
    }
    if(map_block[a][b]%100>=30&&map_block[a][b]%100<40)
    {
        SetPos(113,34);printf("                ");
        SetPos(113,35);printf("                ");
        SetPos(113,34);printf("  (%c) ð��",key_button[7]);
    }
    if(map_block[a][b]%100>=40&&map_block[a][b]%100<50)
    {
        SetPos(113,34);printf("                ");
        SetPos(113,35);printf("                ");
        SetPos(113,34);printf("  (%c) ð��",key_button[7]);
        Ninja_Res(&py[n]);
    }
    if(map_block[a][b]/100>0)
    {
        SetPos(113,35);printf("  (%c) ���/��ս",key_button[8]);
        int add_temp;///���ڼ�¼���θ�ɽ����Ӣ�۱���
        switch(map_block[a][b]/100)
        {
            case 1:
                add_temp=map_block[0][3]%10+map_block[1][4]%10+map_block[1][5]%10;
                map_mountain[1]+=add_temp;
                break;
            case 2:
                add_temp=map_block[1][0]%10+map_block[2][1]%10+map_block[3][1]%10+map_block[3][0]%10;
                map_mountain[2]+=add_temp;
                break;
            case 3:
                add_temp=map_block[1][2]%10+map_block[1][3]%10+map_block[2][2]%10+map_block[2][4]%10+map_block[3][3]%10+map_block[3][4]%10;
                map_mountain[3]+=add_temp;
                break;
            case 4:
                add_temp=map_block[2][6]%10+map_block[3][6]%10+map_block[4][7]%10;
                map_mountain[4]+=add_temp;
                break;
            case 5:
                add_temp=map_block[6][6]%10+map_block[5][6]%10+map_block[5][7]%10;
                map_mountain[5]+=add_temp;
                break;
            default:break;
        }
        hero_action1(n,&map_mountain[map_block[a][b]/100],a,b);
        map_mountain[map_block[a][b]/100]-=add_temp;///��ɽ�ϵ�Ӣ�۱���ȥ������֤�´�������ȷ
    }
    else
    {
        hero_action2(n,a,b);
    }
}

void hero_action1(int n,int *mountain_num,int a,int b)
{
    int ch;
    while (1)
    {
        if(map_block[a][b]%100>=30&&map_block[a][b]%100<40)///��ƽԭ��ð�� ɽ�ĸ��������/��ս
        {
            if (_kbhit())
            {//����а������£���_kbhit()����������
                ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
                if(ch==key_button[7])///ð��
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("ƽԭð��!");
                    block_choice_explore_p(n);
                    break;
                }
                if(ch==key_button[8])///���/��ս
                {
                    if((*mountain_num)%100<10)
                    {
                        emergency_decoration(2);
                        SetPos(6,44);printf("���!");
                        (*mountain_num)+=10;
                        mountain_spy(*mountain_num);
                    }
                    else
                    {
                        emergency_decoration(2);
                        SetPos(6,44);printf("��ս! ");
                        mission_choice(n,*mountain_num);///������ս�����뷢�������(0 1 2)��ɽ������ֵ
                    }
                    break;
                }
            }
        }
        if(map_block[a][b]%100>=40&&map_block[a][b]%100<50)///��ɭ�֣�ð�� ɽ�ĸ��������/��ս
        {
            if (_kbhit())
            {//����а������£���_kbhit()����������
                ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
                if(ch==key_button[7])///ð��
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("ɭ��ð��!");
                    block_choice_explore_f(n);
                    break;
                }
                if(ch==key_button[8])///���/��ս
                {
                    if((*mountain_num)%100<10)
                    {
                        emergency_decoration(2);
                        SetPos(6,44);printf("���!");
                        (*mountain_num)+=10;
                        mountain_spy(*mountain_num);
                    }
                    else
                    {
                        emergency_decoration(2);
                        SetPos(6,44);printf("��ս! ");
                        mission_choice(n,*mountain_num);///������ս�����뷢�������(0 1 2)��ɽ������ֵ
                    }
                    break;
                }
            }
        }
    }
}

void hero_action2(int n,int a,int b)
{
    int ch;
    while (1)
    {
        if(map_block[a][b]%100>=20&&map_block[a][b]%100<30)///�ڵ�·�ϣ����¿���
        {
            break;
        }
        if(map_block[a][b]%100>=10&&map_block[a][b]%100<20)///�ڳ���壬��Ϣ
        {
            if (_kbhit())
            {//����а������£���_kbhit()����������
                ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
                if(ch==key_button[7])
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("��Ϣ!");
                    HeroSleep(&py[n]); ///Ӣ����Ϣ����
                    showPlayer(py[n]);
                    break;
                }
            }
        }
        if(map_block[a][b]%100>=30&&map_block[a][b]%100<40)///��ƽԭ��ð��
        {
            if (_kbhit())
            {//����а������£���_kbhit()����������
                ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
                if(ch==key_button[7])
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("ƽԭð��!");
                    block_choice_explore_p(n);///Ӣ��ð�������ж�����
                    break;
                }
            }
        }
        if(map_block[a][b]%100>=40&&map_block[a][b]%100<50)///��ɭ�֣�ð��
        {
            if (_kbhit())
            {//����а������£���_kbhit()����������
                ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
                if(ch==key_button[7])
                {
                    emergency_decoration(2);
                    SetPos(6,44);printf("ɭ��ð��!");
                    block_choice_explore_f(n);
                    break;
                }
            }
        }
    }
}

void block_choice_explore_p(int n)
{
    int temp;
    temp=HeroExplore(py[n].advP_P+ResAdd(&py[n]));Sleep(500);
    if(temp==1)
    {
        py[n].Exp++;py[n].lifeP--;
        ResGuard(&py[n],1); ///ʹ����Դֵ���з����ĺ���
        Levelup(&py[n]);
    }
    if(temp>=2)
    {
        py[n].Exp++;
        Levelup(&py[n]);
    }
    if(temp<=-1)
    {
        py[n].lifeP--;
        ResGuard(&py[n],1); ///ʹ����Դֵ���з����ĺ���
    }
    if(py[n].timeP==4&&py[n].lifeP<py[n].lifeMP)///�Ƕ�ʿƽԭð������ֵ�ظ�
        py[n].lifeP++;
}

void block_choice_explore_f(int n)
{
    int temp;
    temp=HeroExplore(py[n].advP_F+ResAdd(&py[n]));Sleep(500);
    if(temp==1)
    {
        py[n].Exp++;py[n].lifeP--;
        ResGuard(&py[n],1); ///ʹ����Դֵ���з����ĺ���
        Levelup(&py[n]);
    }
    if(temp>=2)
    {
        py[n].Exp++;
        Levelup(&py[n]);
    }
    if(temp<=-1)
    {
        py[n].lifeP--;
        ResGuard(&py[n],1); ///ʹ����Դֵ���з����ĺ���
    }
}

void mountain_spy(int mountain)
{
    setColor(12,5);///����ɫ����������ɫ�ַ�
    switch(mountain/10000)
    {
        case 1:
            SetPos(77,6);mountain_mission((mountain%1000)/100);
            SetPos(78,7);mountain_reward((mountain%10000)/1000);
            break;
        case 2:
            SetPos(17,16);mountain_mission((mountain%1000)/100);
            SetPos(18,17);mountain_reward((mountain%10000)/1000);
            break;
        case 3:
            SetPos(53,16);mountain_mission((mountain%1000)/100);
            SetPos(54,17);mountain_reward((mountain%10000)/1000);
            break;
        case 4:
            SetPos(95,21);mountain_mission((mountain%1000)/100);
            SetPos(96,22);mountain_reward((mountain%10000)/1000);
            break;
        case 5:
            SetPos(77,36);mountain_mission((mountain%1000)/100);
            SetPos(78,37);mountain_reward((mountain%10000)/1000);
            break;
    }
    setColor(7,0);///��ɫ��������ɫ�ַ�
}

void mountain_reward(int n)
{
    switch(n)
    {
        case 0:printf("����֮��");break;
        case 1:printf("��������");break;
        case 2:printf("������ͼ");break;
        case 3:printf("����֮Ѫ");break;
        case 4:printf("��֮�ر�");break;
    }

}

void mountain_mission(int n)
{
    switch(n)
    {
        case 0:printf("Ӣ������״");break;
        case 1:printf(" ��֮����");break;
        case 2:printf("ħ���ػ���");break;
        case 3:printf("�粼��С��");break;
        case 4:printf("ħ��������");break;
        case 5:printf(" ˹�ҿ�˹");break;
    }
}

#endif // CONTROL_BLOCK_CHOICE_H_INCLUDED
