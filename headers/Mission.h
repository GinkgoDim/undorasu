///���Ǽ�������Ч����ͷ�ļ�
#ifndef MISSION_H_INCLUDED
#define MISSION_H_INCLUDED

DICE HeroCheck(DICE);

typedef int MISSION;
extern int map_mountain[6];
extern int count;
extern HERO py[3];
extern Dragonic dra;
extern int map_block[7][8];
extern int CP_2,CP_3,CP_4,CP_5,CP_6;

void mission_mountain(int mountain,int out);

void DraTreasure(HERO *,MISSION); ///����������֮�ر���5��
void DraBlood(HERO py[],int pynum,MISSION out); ///������������֮Ѫ��4��
void DraMapPlece(Dragonic *Dra,MISSION out); ///��������������ͼ��3��
void DraWeapon(HERO py[],int pynum,MISSION out); ///������������������2��
void DraBook(HERO py[],int pynum,MISSION out); ///������������֮�飨1��
void mission_reward(int n,int n_loop,int pynum,MISSION out);

MISSION HeroLastWords_2p(HERO *PY1, HERO *PY2);
MISSION HeroLastWords_3p(HERO *PY1, HERO *PY2, HERO *PY3);
MISSION Inscription_1p(HERO *PY);
MISSION Inscription_2p(HERO *PY, HERO *PY2);
MISSION Inscription_3p(HERO *PY, HERO *PY2, HERO *PY3);
MISSION MagicGuardian_1p(HERO *PY);
MISSION MagicGuardian_2p(HERO *PY, HERO *PY2);
MISSION MagicGuardian_3p(HERO *PY, HERO *PY2, HERO *PY3);
MISSION GoblinTeam_1p(HERO *PY);
MISSION GoblinTeam_2p(HERO *PY, HERO *PY2);
MISSION GoblinTeam_3p(HERO *PY, HERO *PY2, HERO *PY3);
MISSION Chimera_1p(HERO *PY);
MISSION Chimera_2p(HERO *PY, HERO *PY2);
MISSION Chimera_3p(HERO *PY, HERO *PY2, HERO *PY3);
MISSION SphinxMystery_1p(HERO *PY);

///��ɫ������ǿ��
void Levelup(HERO *py)
{
    switch (py->timeP)
    {
    case 1: ///��ʥ
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setHolySwordsman();
        if (tempE >= 1) ///ս��+1
        {
            if (tempE >= 2) ///̽��+1
            {
                if (tempE >= 3) ///����ȫ��
                {
                    if (tempE >= 4) ///��Դ����+1
                    {
                        if (tempE >= 5) ///ս��+1
                        {
                            if (tempE >= 6) ///ս��+1
                            {
                                py->fightP++;
                                py->Level++;
                            }
                            py->fightP++;
                            py->Level++;
                        }
                        py->resourseMP++;
                        py->Level++;
                    }
                    tempL = py->lifeMP;
                    py->Level++;
                }
                py->exploreP++;
                py->Level++;
            }
            py->fightP++;
            py->Level++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 2: ///����
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setNinja();
        if (tempE >= 2) ///̽��+1
        {
            if (tempE >= 4) ///ս��+1
            {
                if (tempE >= 7) ///��Դ����+1
                {
                    py->resourseMP++;
                    py->Level++;
                }
                py->fightP++;
                py->Level++;
            }
            py->exploreP++;
            py->Level++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 3: ///����
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setHunter();
        if (tempE >= 2) ///ս��+1
        {
            if (tempE >= 4) ///̽��+1
            {
                if (tempE >= 7) ///ս��+1
                {
                    py->fightP++;
                    py->Level++;
                }
                py->exploreP++;
                py->Level++;
            }
            py->fightP++;
            py->Level++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 4: ///�Ƕ�ʿ
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setGladiator();
        if (tempE >= 2) ///ð��+1
        {
            if (tempE >= 4) ///ս��+1
            {
                if (tempE >= 7) ///����ȫ��
                {
                    tempL = py->lifeMP;
                    py->Level++;
                }
                py->fightP++;
                py->Level++;
            }
            py->exploreP++;
            py->Level++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 5: ///����
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setPrince();
        if (tempE >= 2) ///ս����̽������Դ����+1
        {
            if (tempE >= 4) ///ս����̽������Դ����+1
            {
                if (tempE >= 7) ///ս����̽������Դ����+1
                {
                    py->fightP++;
                    py->exploreP++;
                    py->resourseMP++;
                    py->Level++;
                }
                py->fightP++;
                py->exploreP++;
                py->resourseMP++;
                py->Level++;
            }
            py->fightP++;
            py->exploreP++;
            py->resourseMP++;
            py->Level++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    case 6: ///ʥ��ʿ
    {
        unsigned int tempE = py->Exp;
        unsigned int tempR = py->resourseP;
        int tempL = py->lifeP;
        *py = setPrince();
        if (tempE >= 2) ///��Դ����+1
        {
            if (tempE >= 4) ///����ȫ��
            {
                if (tempE >= 7) ///ս��+1
                {
                    py->fightP++;
                    py->Level++;
                }
                tempL = py->lifeMP;
                py->Level++;
            }
            py->resourseMP++;
            py->Level++;
        }
        py->Exp = tempE;
        py->resourseP = tempR;
        py->lifeP = tempL;
        break;
    }
    default:
        break;
    }
}

void mission_choice(int n,int mountain)///������ս�����뷢�������(0 1 2)��ɽ������ֵ
{
    int out;///�ж������Ƿ����
    int a[5];
    a[0]=mountain/10000;mountain-=10000*a[0];///ɽ��
    a[1]=mountain/1000;mountain-=1000*a[1];///������
    a[2]=mountain/100;mountain-=100*a[2];///�����
    a[3]=mountain/10;mountain-=10*a[3];///���ȱ�
    a[4]=mountain;///������
    switch(a[2])
    {
        case 0:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                printf("��������");break;
            }
            else
            {
                if(a[4]==4||a[4]==6||a[4]==8)
                {
                    out=HeroLastWords_2p(&py[n],&py[(a[4]-2*n-2)/2]);
                }
                if(a[4]==9)
                {
                    int n1,n2;
                    switch(a[4]-n)
                    {
                        case 4:n1=1;n2=2;break;
                        case 6:n1=1;n2=3;break;
                        case 8:n1=2;n2=3;break;
                    }
                    out=HeroLastWords_3p(&py[n],&py[n1],&py[n2]);
                }
                mission_reward(a[1],n,count,out);
                mission_mountain(a[0],out);
                break;
            }
            break;///����1
        case 1:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                out=Inscription_1p(&py[n]);
            }
            if(a[4]==4||a[4]==6||a[4]==8)
            {
                out=Inscription_2p(&py[n],&py[(a[4]-2*n-2)/2]);
            }
            if(a[4]==9)
            {
                int n1,n2;
                switch(a[4]-n)
                {
                    case 4:n1=1;n2=2;break;
                    case 6:n1=1;n2=3;break;
                    case 8:n1=2;n2=3;break;
                }
                out=Inscription_3p(&py[n],&py[n1],&py[n2]);
            }
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///����2
        case 2:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                out=MagicGuardian_1p(&py[n]);
            }
            if(a[4]==4||a[4]==6||a[4]==8)
            {
                out=MagicGuardian_2p(&py[n],&py[(a[4]-2*n-2)/2]);
            }
            if(a[4]==9)
            {
                int n1,n2;
                switch(a[4]-n)
                {
                    case 4:n1=1;n2=2;break;
                    case 6:n1=1;n2=3;break;
                    case 8:n1=2;n2=3;break;
                }
                out=MagicGuardian_3p(&py[n],&py[n1],&py[n2]);
            }
            ResGuard(&py[n],1);
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///����3
        case 3:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                out=GoblinTeam_1p(&py[n]);
            }
            if(a[4]==4||a[4]==6||a[4]==8)
            {
                out=GoblinTeam_2p(&py[n],&py[(a[4]-2*n-2)/2]);
            }
            if(a[4]==9)
            {
                int n1,n2;
                switch(a[4]-n)
                {
                    case 4:n1=1;n2=2;break;
                    case 6:n1=1;n2=3;break;
                    case 8:n1=2;n2=3;break;
                }
                out=GoblinTeam_3p(&py[n],&py[n1],&py[n2]);
            }
            if(out==0)
                ResGuard(&py[n],1);
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///����4
        case 4:
            if(a[4]==1||a[4]==3||a[4]==5)
            {
                out=Chimera_1p(&py[n]);
            }
            if(a[4]==4||a[4]==6||a[4]==8)
            {
                out=Chimera_2p(&py[n],&py[(a[4]-2*n-2)/2]);
            }
            if(a[4]==9)
            {
                int n1,n2;
                switch(a[4]-n)
                {
                    case 4:n1=1;n2=2;break;
                    case 6:n1=1;n2=3;break;
                    case 8:n1=2;n2=3;break;
                }
                out=Chimera_3p(&py[n],&py[n1],&py[n2]);
            }
            if(out==0)
                ResGuard(&py[n],2);
            else
                ResGuard(&py[n],1);
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///����5
        case 5:
            out=SphinxMystery_1p(&py[n]);
            if(out==0)
                ResGuard(&py[n],2);
            mission_reward(a[1],n,count,out);
            mission_mountain(a[0],out);
            break;///����6
        default:break;
    }
}

void mission_mountain(int mountain,int out)///���������ɣ��ؿ���ֵ��Ҫ�ı䣬���ٴ������ð���򲻷�����ս/����ж�
{
    if(out!=0)
    {
        switch(mountain)
        {
            case 1:
                map_block[0][3]-=100;map_block[1][4]-=100;map_block[1][5]-=100;
                break;
            case 2:
                map_block[1][0]-=200;map_block[2][1]-=200;map_block[3][1]-=200;map_block[3][0]-=200;
                break;
            case 3:
                map_block[1][2]-=300;map_block[1][3]-=300;map_block[2][2]-=300;map_block[2][4]-=300;map_block[3][3]-=300;map_block[3][4]-=300;
                break;
            case 4:
                map_block[2][6]-=400;map_block[3][6]-=400;map_block[4][7]-=400;
                break;
            case 5:
                map_block[6][6]-=500;map_block[5][6]-=500;map_block[5][7]-=500;
                break;
            default:break;
        }
    }
}

/**�����ʼ��**/
///****************����һ��Ӣ�۵�����״********************
MISSION HeroLastWords_2p(HERO *PY1, HERO *PY2)
{
    PY1->Exp++;
    PY2->Exp++;
    printf("����ɹ���������ÿ�˻��1��Exp ");
    Levelup(PY1);
    Levelup(PY2);
    return 1;
}
MISSION HeroLastWords_3p(HERO *PY1, HERO *PY2, HERO *PY3)
{
    PY1->Exp++;
    PY2->Exp++;
    PY3->Exp++;
    printf("����ɹ���������ÿ�˻��1��Exp ");
    Levelup(PY1);
    Levelup(PY2);
    Levelup(PY3);
    return 1;
}
///*******************���������֮����**********************
MISSION Inscription_1p(HERO *PY)
{
    int DP = HeroCheck(PY->knowledgeP+ResAdd(PY));Sleep(500);
    if (DP >= CP_2)
    {
        printf("����ɹ������2��Exp ");
        PY->Exp += 2;
        Levelup(PY);
        return 1;
    }
    else
    {
        CP_2 -= DP;
        if (CP_2 > 2)
            CP_2 = 2;
        printf("����ʧ�ܣ���ʣ%d����� ", CP_2);
        return 0;
    }
}
MISSION Inscription_2p(HERO *PY, HERO *PY2)
{
    int DP = HeroCheck(PY->knowledgeP + PY2->knowledgeP+ResAdd(PY));Sleep(500);
    if (DP >= CP_2)
    {
        printf("����ɹ���������ÿ�˻��1��Exp ");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
        return 1;
    }
    else
    {
        CP_2 -= DP;
        if (CP_2 > 2)
            CP_2 = 2;
        printf("����ʧ�ܣ���ʣ%d����� ", CP_2);
        return 0;
    }
}
MISSION Inscription_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    int DP = HeroCheck(PY->knowledgeP + PY2->knowledgeP + PY3->knowledgeP+ResAdd(PY));Sleep(500);
    if (DP >= CP_2)
    {
        printf("����ɹ���������ÿ�˻��1��Exp ");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
        return 1;
    }
    else
    {
        CP_2 -= DP;
        if (CP_2 > 2)
            CP_2 = 2;
        printf("����ʧ�ܣ���ʣ%d����� ", CP_2);
        return 0;
    }
}
///********************��������ħ���ػ���***********************
MISSION MagicGuardian_1p(HERO *PY)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("����ֵ���㣬���ܽ��д���ս�� ");
        exit(1);
    }
    int DP = HeroCheck(PY->exploreP+ResAdd(PY));Sleep(500);
    if (DP >= CP_3)
    {
        printf("����ɹ������2��Exp ");
        PY->Exp += 2;
        Levelup(PY);
        return 1;
    }
    else
    {
        CP_3 -= DP;
        if (CP_3 > 3)
            CP_3 = 3;
        printf("����ʧ�ܣ���ʣ%d����� ", CP_3);
        return 0;
    }
}
MISSION MagicGuardian_2p(HERO *PY, HERO *PY2)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("����ֵ���㣬���ܽ��д���ս�� ");
        exit(1);
    }
    int DP = HeroCheck(PY->exploreP + PY2->exploreP+ResAdd(PY));Sleep(500);
    if (DP >= CP_3)
    {
        printf("����ɹ���������ÿ�˻��1��Exp ");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
        return 1;
    }
    else
    {
        CP_3 -= DP;
        if (CP_3 > 3)
            CP_3 = 3;
        printf("����ʧ�ܣ���ʣ%d����� ", CP_3);
        return 0;
    }
}
MISSION MagicGuardian_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("����ֵ���㣬���ܽ��д���ս�� ");
        exit(1);
    }
    int DP = HeroCheck(PY->exploreP + PY2->exploreP + PY3->exploreP+ResAdd(PY));Sleep(500);
    if (DP >= CP_3)
    {
        printf("����ɹ���������ÿ�˻��1��Exp ");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
        return 1;
    }
    else
    {
        CP_3 -= DP;
        if (CP_3 > 3)
            CP_3 = 3;
        printf("����ʧ�ܣ���ʣ%d����� ", CP_3);
        return 0;
    }
}
///*************************�����ģ��粼��С��*************************
MISSION GoblinTeam_1p(HERO *PY)
{
    int DP = HeroCheck(PY->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_4)
    {
        printf("����ɹ������2��Exp ");
        PY->Exp += 3;
        Levelup(PY);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_4 -= DP;
        if (CP_4 > 3)
            CP_4 = 3;
        printf("����ʧ�ܣ���ս���ܵ�1���˺�����ʣ%d����� ", CP_4);
        return 0;
    }
}
MISSION GoblinTeam_2p(HERO *PY, HERO *PY2)
{
    int DP = HeroCheck(PY->fightP + PY2->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_4)
    {
        printf("����ɹ���������ÿ�˻��1��Exp ");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_4 -= DP;
        if (CP_4 > 3)
            CP_4 = 3;
        printf("����ʧ�ܣ���ս���ܵ�1���˺�����ʣ%d����� ", CP_4);
        return 0;
    }
}
MISSION GoblinTeam_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    int DP = HeroCheck(PY->fightP + PY2->fightP + PY3->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_4)
    {
        printf("����ɹ���������ÿ�˻��1��Exp ");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_4 -= DP;
        if (CP_4 > 3)
            CP_4 = 3;
        printf("����ʧ�ܣ���ս���ܵ�1���˺�����ʣ%d����� ", CP_4);
        return 0;
    }
}
///***************************�����壺ħ��������***************************
MISSION Chimera_1p(HERO *PY)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("����ֵ���㣬���ܽ��д���ս�� ");
        return 0;
    }
    int DP = HeroCheck(PY->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_5)
    {
        printf("����ɹ������2��Exp ");
        PY->Exp += 2;
        Levelup(PY);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_5 -= DP;
        if (CP_5 > 2)
            CP_5 = 2;
        printf("����ʧ�ܣ���ս���ܵ�1���˺�����ʣ%d����� ", CP_5);
        return 0;
    }
}
MISSION Chimera_2p(HERO *PY, HERO *PY2)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("����ֵ���㣬���ܽ��д���ս�� ");
        return 0;
    }
    int DP = HeroCheck(PY->fightP + PY2->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_5)
    {
        printf("����ɹ��� ������ÿ�˻��1��Exp ");
        PY->Exp++;
        PY2->Exp++;
        Levelup(PY);
        Levelup(PY2);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_5 -= DP;
        if (CP_5 > 2)
            CP_5 = 2;
        printf("����ʧ�ܣ���ս���ܵ�1���˺�����ʣ%d����� ", CP_5);
        return 0;
    }
}
MISSION Chimera_3p(HERO *PY, HERO *PY2, HERO *PY3)
{
    if (PY->lifeP > 1)
        PY->lifeP--;
    else
    {
        printf("����ֵ���㣬���ܽ��д���ս�� ");
        exit(1);
    }
    int DP = HeroCheck(PY->fightP + PY2->fightP + PY3->fightP+ResAdd(PY));Sleep(500);
    if (DP >= CP_5)
    {
        printf("����ɹ���������ÿ�˻��1��Exp ");
        PY->Exp++;
        PY2->Exp++;
        PY3->Exp++;
        Levelup(PY);
        Levelup(PY2);
        Levelup(PY3);
        return 1;
    }
    else
    {
        PY->lifeP--;
        CP_5 -= DP;
        if (CP_5 > 2)
            CP_5 = 2;
        printf("����ʧ�ܣ���ս���ܵ�1���˺�����ʣ%d����� ", CP_5);
        return 0;
    }
}
///*****************************��������˹�ҿ�˹֮��**********************
MISSION SphinxMystery_1p(HERO *PY)
{
    int DP = HeroCheck(PY->knowledgeP+ResAdd(PY));Sleep(500);
    if (DP >= CP_6)
    {
        printf("����ɹ������2��Exp ");
        PY->Exp += 2;
        Levelup(PY);
        return 1;
    }
    else
    {
        PY->lifeP -= 2;
        CP_6 -= DP;
        if (CP_6 > 1)
            CP_6 = 1;
        printf("����ʧ�ܣ���ս���ܵ�2���˺�����ʣ%d����� ", CP_6);
        return 0;
    }
}

/********************������************************/
void mission_reward(int n,int n_loop,int pynum,MISSION out)
{
    switch(n)
    {
        case 0:DraBook(py,pynum,out);break;
        case 1:DraWeapon(py,pynum,out);break;
        case 2:DraMapPlece(&dra,out);break;
        case 3:DraBlood(py,pynum,out);break;
        case 4:DraTreasure(&py[n_loop],out);break;
    }
}

void DraBook(HERO py[],int pynum,MISSION out) ///������������֮�飨1��
{
    if(out!=0)
    {
        int i;
        printf("�������֮�飡�����˾���ֵ+1 ");
        for(i=0;i<pynum;i++)
            py[i].Exp++;
    }
}

void DraWeapon(HERO py[],int pynum,MISSION out) ///������������������2��
{
    if(out!=0)
    {
        int i;
        printf("�������������������ս����+1 ");
        for(i=0;i<pynum;i++)
            py[i].fightP++;
    }
}

void DraMapPlece(Dragonic *Dra,MISSION out) ///��������������ͼ��3��
{
    if(out!=0)
    {
        printf("���������ͼ��������һ��ͻϮ���ܵ�1���˺� ");
        Dra->lifeD--;
    }
}

void DraBlood(HERO py[],int pynum,MISSION out) ///������������֮Ѫ��4��
{
    if(out!=0)
    {
        int i;
        printf("��ù���֮Ѫ������������ֵȫ�ظ� ");
        for(i=0;i<pynum;i++)
            py[i].lifeP=py[i].lifeMP;
    }
}

void DraTreasure(HERO *py,MISSION out) ///����������֮�ر���5��
{
    if(out!=0)
    {
        printf("�����֮�ر��������ر�Ч�� ");
        py->Treasure = TRUE;
    }
}

#endif
