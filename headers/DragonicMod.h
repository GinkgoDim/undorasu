///���Ǽ��������ж���ͷ�ļ�
#ifndef DRAGONICMOD_H_INCLUDED
#define DRAGONICMOD_H_INCLUDED

extern HERO py[3];
///Ӣ����ʾ������
extern int hero_moving_x[4];
extern int hero_moving_y[4];
///Ӣ�������������
extern int hero_moving_a[4];
extern int hero_moving_b[4];
extern int map_block[7][8];

void dragon_attack(int life,int pynum);

void showDragonAnger(Dragonic dra) ///չʾ��ŭ��ֵ�ĺ���
{
    int i,num_c;
    i=dra.angerD;
    if(i>=12&&i<16)
        num_c=7;
    if(i>=8&&i<12)
        num_c=9;
    if(i>=3&&i<8)
        num_c=13;
    if(i>0&&i<3)
        num_c=12;
    number_ROME(93,2,0,num_c,i);///��ͼ���Ͻǿ�λ����(93,2)
    setColor(7,0);
}

 void showDragonLife(Dragonic dra) ///չʾ������ֵ�ĺ���
 {
     int i;
     printf("������");
     for(i=dra.lifeD-1;i>=0;i--)
     {
         if(i%2==0)
             putchar('O');
         else
            putchar('X');
     }
     ///putchar('\n');
 }

 void DragonDisaster(int pynum) ///�����ж�����
{
    int i;///ѭ������
    int DD = DraD6(); ///����DD
    int *DiceD=(int*)malloc(pynum*sizeof(int));
    int maxPY, minPY;
    emergency_decoration(2);
    printf("�����ɳ��˳�Ѩ������");
    printf("�����ж���(%d) !!!", DD);
    Sleep(1000);
    emergency_decoration(2);
    switch (DD)
    {
    case 1: ///�ջٴ�ׯ
        number_ARAB(7,34,0,7,1);
        printf("�������������Ϊ���棬�Ӵ˱������޷����룡");
        printf("�ڱ��������ҽ��ܵ�2���˺���");
        draw_map_block(4,41,4);SetPos(43,5);setColor(0,4);printf("������");SetPos(44,6);printf("�ٻ�");
        switch(map_block[0][1]%10)
        {
            case 1:
                py[0].lifeP--;
                hero_moving_x[1]=19;
                hero_moving_y[1]=8;
                hero_moving_a[1]=1;
                hero_moving_b[1]=2;
                SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
                break;
            case 3:
                py[1].lifeP--;
                hero_moving_x[2]=21;
                hero_moving_y[2]=8;
                hero_moving_a[2]=1;
                hero_moving_b[2]=2;
                SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
                break;
            case 5:
                py[2].lifeP--;
                hero_moving_x[3]=23;
                hero_moving_y[3]=8;
                hero_moving_a[3]=1;
                hero_moving_b[3]=2;
                SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
                break;
            case 4:
                py[0].lifeP--;py[2].lifeP--;
                hero_moving_x[1]=19;
                hero_moving_y[1]=8;
                hero_moving_a[1]=1;
                hero_moving_b[1]=2;
                SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
                hero_moving_x[2]=21;
                hero_moving_y[2]=8;
                hero_moving_a[2]=1;
                hero_moving_b[2]=2;
                SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
                break;
            case 6:
                py[0].lifeP--;py[3].lifeP--;
                hero_moving_x[1]=19;
                hero_moving_y[1]=8;
                hero_moving_a[1]=1;
                hero_moving_b[1]=2;
                SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
                hero_moving_x[3]=23;
                hero_moving_y[3]=8;
                hero_moving_a[3]=1;
                hero_moving_b[3]=2;
                SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
                break;
            case 8:
                py[2].lifeP--;py[3].lifeP--;
                hero_moving_x[2]=21;
                hero_moving_y[2]=8;
                hero_moving_a[2]=1;
                hero_moving_b[2]=2;
                SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
                hero_moving_x[3]=23;
                hero_moving_y[3]=8;
                hero_moving_a[3]=1;
                hero_moving_b[3]=2;
                SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
                break;
            case 9:
                py[0].lifeP--;py[1].lifeP--;py[2].lifeP--;
                hero_moving_x[1]=19;
                hero_moving_y[1]=8;
                hero_moving_a[1]=1;
                hero_moving_b[1]=2;
                SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
                hero_moving_x[2]=21;
                hero_moving_y[2]=8;
                hero_moving_a[2]=1;
                hero_moving_b[2]=2;
                SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
                hero_moving_x[3]=23;
                hero_moving_y[3]=8;
                hero_moving_a[3]=1;
                hero_moving_b[3]=2;
                SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
                break;
            default:break;
        }
        map_block[0][1]=-6;
        setColor(7,0);
        break;
    case 2: ///������Żس�
        number_ARAB(7,34,0,7,2);
        printf("���Զ�����ͻϮ���������Ͷһ����");
        printf("������ߵ���ҽ����ұ�������������");
        HeroD6(DiceD, pynum);
        maxPY = getMAX(DiceD, pynum);
        switch (maxPY)
        {
        case 1:
            printf(" (P1)");
            SetPos(hero_moving_x[1],hero_moving_y[1]);printf("  ");
            hero_moving_x[1]=31;
            hero_moving_y[1]=38;
            hero_moving_a[1]=6;
            hero_moving_b[1]=3;
            SetPos(hero_moving_x[1],hero_moving_y[1]);printf("P1");
            break;
        case 2:
            printf(" (P2)");
            SetPos(hero_moving_x[2],hero_moving_y[2]);printf("  ");
            hero_moving_x[2]=27;
            hero_moving_y[2]=33;
            hero_moving_a[2]=5;
            hero_moving_b[2]=2;
            SetPos(hero_moving_x[2],hero_moving_y[2]);printf("P2");
            break;
        case 3:
            printf(" (P3)");
            SetPos(hero_moving_x[3],hero_moving_y[3]);printf("  ");
            hero_moving_x[3]=41;
            hero_moving_y[3]=33;
            hero_moving_a[3]=5;
            hero_moving_b[3]=3;
            SetPos(hero_moving_x[3],hero_moving_y[3]);printf("P3");
            break;
        default:
            break;
        }
        break;
    case 3: ///ȫ��-1HP
        number_ARAB(7,34,0,7,3);
        printf("����������������ʹ���˰�β��");
        printf("�����ڳ�������ܵ�1���˺���");
        for(i=0;i<pynum;i++)
            py[i].lifeP--;
        break;
    case 4: ///�����-2HP
        number_ARAB(7,34,0,7,4);
        printf("������ŭ�ļ�̤���������Ͷһ���ӣ�");
        printf("������͵�����ܵ�2���˺���");
        HeroD6(DiceD, pynum);
        minPY = getMIN(DiceD, pynum);
        switch (minPY)
        {
        case 1:
            printf(" (P1)");
            py[0].lifeP -= 2;
            break;
        case 2:
            printf(" (P2)");
            py[1].lifeP -= 2;
            break;
        case 3:
            printf(" (P3)");
            py[2].lifeP -= 2;
            break;
        default:
            break;
        }
        break;
    case 5: ///�����-2HP
        number_ARAB(7,34,0,7,5);
        printf("�����³��˻����������Ͷһ���ӣ�");
        printf("������ߵ�����ܵ�2���˺���");
        HeroD6(DiceD, pynum);
        maxPY = getMAX(DiceD, pynum);
        switch (maxPY)
        {
        case 1:
            printf(" (P1)");
            py[0].lifeP -= 2;
            break;
        case 2:
            printf(" (P2)");
            py[1].lifeP -= 2;
            break;
        case 3:
            printf(" (P3)");
            py[2].lifeP -= 2;
            break;
        default:
            break;
        }
        break;
    case 6: ///�������Դ���
        number_ARAB(7,34,0,7,6);
        printf("�����ֲ�����Ϣ���������Ͷһ���ӣ�");
        printf("������͵�����ܵ����ˣ���Դ��գ�");
        HeroD6(DiceD, pynum);
        minPY = getMIN(DiceD, pynum);
        switch (minPY)
        {
        case 1:
            printf(" (P1)");
            py[0].resourseP = 0;
            break;
        case 2:
            printf(" (P2)");
            py[1].resourseP = 0;
            break;
        case 3:
            printf(" (P3)");
            py[2].resourseP = 0;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

int DragonAnger(int num, Dragonic *dra) ///��ŭ��ֵ�仯����
{
    unsigned int angerN=num/1000;
    int DD=0;
    int temp;temp=dra->angerD;
    if(temp-angerN>=0)
    {
        while(angerN>0)
        {
            dra->angerD--;
            angerN--;
            if(dra->angerD==13||dra->angerD==10||dra->angerD==7||dra->angerD==4||dra->angerD==1)
            {
                DD++;
            }
        }
    }
    else
    {
        if(((temp+1)%3)!=0)
        {
            DD+=(temp+1)/3;
        }
        dra->angerD=0;
    }
    return DD;
}

void FinalBattle(HERO *PY,int pynum,Dragonic *dra) ///��ս����
{
    int num=HeroCheck(PY->fightP+ResAdd(py));
    int i,secnum=0;
    if(PY->timeP==2)
        num=Ninja_Tre(py,num);
    if(PY->timeP==3)
        num=Hunter_Tre(py,num);
    if(PY->timeP==6)
        Paladin_Tre(PY,pynum);
    recheck:
    {
        if(num<=-1) ///Dice<0:����
        {
            PY->lifeP=0;
        }
        else if(num==0) ///Dice=0:���-4LP
        {
            PY->lifeP-=4;
        }
        else if(num==1) ///Dice=1:ȫ��-1LP
        {
            for(i=0;i<pynum;i++)
                py[i].lifeP--;
        }
        else if(num==2) ///Dice=2:��Я������ȫ��-1��
        {
            num+=HeroCheck(pynum);
            if(secnum==0)
                goto recheck;
            else
                for(i=0;i<pynum;i++)
                    py[i].lifeP--;
            secnum++;
        }
        else if(num==3) ///Dice=3:���-2��-1
        {
            PY->lifeP-=2;
            dra->lifeD--;
            dragon_attack(dra->lifeD,pynum);
        }
        else if(num==4) ///Dice=4����-1
        {
            dra->lifeD--;
            dragon_attack(dra->lifeD,pynum);
        }
        else ///Dice>4: ��-2
        {
            dra->lifeD--;
            dragon_attack(dra->lifeD,pynum);
            dra->lifeD--;
            dragon_attack(dra->lifeD,pynum);
        }
    }
}

void dragon_attack(int life,int pynum)
{
    if(life==8||life==6||life==4||life==2)
    {
        int *DiceD=(int*)malloc(pynum*sizeof(int));
        int DD=DraD6();///����DD
        if(DD==1)
        {
            emergency_decoration(2);
            printf("˼�����������·���");
        }
        if(DD==2||DD==3)
        {
            emergency_decoration(2);
            printf("��Ϣ������������ҳ���1���˺�");
            int i;
            for(i=0;i<pynum;i++)
            {
                py[i].lifeP--;
            }
        }
        if(DD==4||DD==5||DD==6)
        {
            emergency_decoration(2);
            printf("³çͻ�����������Ͷ��1ö���ӣ�������͵���ҳ���2���˺�");
            py[getMIN(DiceD,pynum)].lifeP-=2;
        }
    }
}

#endif // DRAGONICMOD_H_INCLUDED
