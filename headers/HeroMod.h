///���Ǽ���Ӣ�۶�����ͷ�ļ�
#ifndef HEROMOD_H_INCLUDED
#define HEROMOD_H_INCLUDED

extern char key_button[9];
extern HERO py[3];

//113,2  113,41  139,2  139,41�Ҳ�������
void showPlayer(HERO PY) ///չʾ�������
{
    SetPos(115,3);
    switch(PY.timeP)
    {
        case 1:printf("  <<��ʥ>>");break;
        case 2:printf("  <<����>>");break;
        case 3:printf("  <<����>>");break;
        case 4:printf("  <<�Ƕ�ʿ>>");break;
        case 5:printf("  <<����>>");break;
        case 6:printf("  <<ʥ��ʿ>>");break;
        default:break;
    }
    SetPos(115,4);printf(">>  ����ֵ��%d|%d\n",PY.lifeP,PY.lifeMP);
    SetPos(115,5);printf(">>  ����ֵ��%d\n",PY.Exp);
    SetPos(115,6);printf(">>  �ȼ���%d\n",PY.Level);
    SetPos(115,7);printf(">>  �ж�����%d\n",PY.actionP);
    SetPos(115,8);printf(">>  ð��ֵ��%d|%d\n",PY.advP_P,PY.advP_F);
    SetPos(115,9);printf(">>  ս������%d\n",PY.fightP);
    SetPos(115,10);printf(">>  ̽������%d\n",PY.exploreP);
    SetPos(115,11);printf(">>  ֪ʶ����%d\n",PY.knowledgeP);
    SetPos(115,12);printf(">>  ��Դֵ��%d|%d\n",PY.resourseP,PY.resourseMP);
    SetPos(115,13);printf(">>  ���ر���%d\n",PY.Treasure);
    SetPos(6,44);
}

DICE HeroAction(DICE num) ///Ӣ���ж������ж�����
{
    int actP=0,i;
    int ActDP[15]={0};
    D6(ActDP,num);
    for(i=0;i<num;i++)
    {
        printf("%d ",ActDP[i]);
        switch(ActDP[i])
        {
            default:break;
            case 2:actP++;break; ///Dice2���Ͽ��Խ����·
            case 3:actP+=10;break; ///Dice3���Ͽ��Խ���ƽԭ
            case 4:actP+=10;break;
            case 5:actP+=100;break; ///Dice5���Ͽ��Խ���ɭ��
            case 6:actP+=1000;break; ///Dice6��ը���ۼӱ�ը������D6
        }
    }
    if(actP>=1000) ///��������������Dice6�����ۼ��ж�
    {
        int temp=HeroAction((unsigned)actP/1000);
        return actP+temp;
    }
    else
        return actP;
}

DICE HeroCheck(DICE num) ///Ӣ�ۼ�������ж�����
{
    int DP=0,i;
    int DiceP[30]={0};
    D6(DiceP,num);
    for(i=0;i<num;i++)
    {
        printf("%d ",DiceP[i]);
        switch(DiceP[i])
        {
            default:break;
            case 1:DP++;break; ///Dice1ʱ�ɹ�ֵΪ-1
            case 4:DP+=10;break; ///Dice4���ϳɹ�ֵΪ+1
            case 5:DP+=10;break;
            case 6:DP+=100;break; ///Dice6��ը���ۼӱ�ը������D6
        }
    }
    if(DP>=100) ///��������������Dice6�����ۼ��ж�
    {
        int temp=HeroCheck((unsigned)DP/100);
        return DP/100+(DP%100-DP%10)/10-DP%10+temp;
    }
    else
        return DP/100+(DP%100-DP%10)/10-DP%10;
}

void HeroSleep(HERO *PY) ///Ӣ����Ϣ����
{
    if((PY->lifeMP-PY->lifeP)>=2)
        PY->lifeP+=2;
    else
        PY->lifeP=PY->lifeMP;
    if(PY->timeP==3)
        PY->resourseP=PY->resourseMP;
}

DICE HeroExplore(DICE num) ///Ӣ��ð�������ж�����
{
    int DP=0,i;
    int DiceP[30]={0};
    D6(DiceP,num);
    for(i=0;i<num;i++)
    {
        printf("%d ",DiceP[i]);
        switch(DiceP[i])
        {
            default:break;
            case 1:DP++;break; ///Dice1-2ʱ�ɹ�ֵΪ-1
            case 2:DP++;break;
            case 5:DP+=10;break; ///Dice5���ϳɹ�ֵΪ+1
            case 6:DP+=100;break; ///Dice6��ը���ۼӱ�ը������D6
        }
    }
    if(DP>=100) ///��������������Dice6�����ۼ��ж�
    {
        int temp1=HeroExplore((unsigned)DP/100);
        int temp2=DP%10;
        return DP/100+(DP%100-DP%10)/10-temp2+temp1;
    }
    else
        return DP/100+(DP%100-DP%10)/10-DP%10;
}

void ResGuard(HERO *PY,int damage) ///ʹ����Դֵ���з����ĺ���
{
    Sleep(1000);emergency_decoration(2);
    printf("��Ҫ����%d���˺� ������ʹ�ü�����Դֵ���з���?(������ʹ��������0):",damage);
    int useR=0;
    scanf("%d",&useR);
    if(damage>=PY->resourseP)
    {
        if(useR>=PY->resourseP)
             useR=PY->resourseP;
        SetPos(6,44);emergency_decoration(2);
        printf("�����(%d)���˺� ",useR);
        PY->lifeP+=useR;
        PY->resourseP-=useR;
    }
    else
    {
        if(useR>=PY->resourseP)
             useR=PY->resourseP;
        if(useR>=damage)
             useR=damage;
        SetPos(6,44);emergency_decoration(2);
        printf("�����(%d)���˺� ",useR);
        PY->resourseP-=useR;
        PY->lifeP+=useR;
    }
}

int ResAdd(HERO *PY) ///ʹ����Դֵ�������Ӽӳɵĺ���
{
    if(PY->resourseP==0)
        return 0;
    Sleep(1000);emergency_decoration(2);
    printf("��������Ҫʹ�ö�����Դֵ?(���ܳ���%d)��",PY->resourseP);
    int costP=0;
    scanf("%d",&costP);
    if(costP>PY->resourseP||costP<0)
    {
        SetPos(6,44);emergency_decoration(2);
        printf("Error�����������룡");
        costP=ResAdd(PY);
    }
    else
    {
        SetPos(6,44);emergency_decoration(2);
        printf("��ʹ����%d�����Դ ",costP);
        PY->resourseP-=costP;
    }
    return costP;
}

///==========Ӣ�۵��ر�Ч��==========
void HolySwordsman_Tre(HERO *PY) ///��ʥ�ر���Զ����ҩ��
{
    if(PY->Treasure&&PY->timeP==1)
    {
        printf("��ʥ�ر���Զ����ҩ��������");
        printf("��Դֵ����+1��ȫ�ظ�");
        PY->resourseMP++;
        PY->resourseP=PY->resourseMP;
    }
}

int Ninja_Tre(HERO *PY,DICE num)  ///�����ر�����ϼ��
{
    printf("�Ƿ�ʹ���ر�����ϼ������Y/N��");
    printf("��һ�غ�һ�Σ���ս�׶α����ж�ǰ������Ͷһ���������ӣ���");
    int ch;
    int temp;
    while (1)
    {
        if (_kbhit())
        {//����а������£���_kbhit()����������
            ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            if(ch==key_button[7])
            {
                temp=PY->fightP+ResAdd(PY);
                return HeroCheck(temp);
            }
            if(ch==key_button[8])
            {
                return num;
            }
        }
    }
}

int Hunter_Tre(HERO *PY,DICE num) ///�����ر��������ӵ���
{
    static int canbeUse=3;
    if(canbeUse<=0)
        return num;
    if(PY->Treasure)
    {
        printf("�Ƿ�ʹ���ر��������ӵ�������Y/N��");
        printf("����ս�׶�����3�Σ����غ�ս��+1����");
        int ch;
        while (1)
        {
            if (_kbhit())
            {//����а������£���_kbhit()����������
                ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
                if(ch==key_button[7])
                {
                    num+=HeroCheck(1);
                    PY->fightP--;
                    canbeUse--;
                    return num;
                }
                if(ch==key_button[8])
                {
                    return num;
                }
            }
        }
    }
    else
        return num;
}

void Gladiator_Tre(HERO *PY) ///�Ƕ�ʿ�ر��������⡹
{
    if(PY->Treasure&&PY->timeP==4)
    {
        printf("�Ƕ�ʿ�ر��������⡹������");
        printf("����ֵȫ���ָ���");
        PY->lifeP=PY->lifeMP;
    }
}

void Prince_Tre(HERO *PY) ///�����ر������ء�
{
    if(PY->Treasure&&PY->timeP==5)
    {
        printf("�����ر������ء�������");
        printf("��ս�׶λ��4�������Դ");
        PY->resourseP+=4;
    }
}

void Paladin_Tre(HERO *PY,int pynum) ///ʥ��ʿ�ر�������֮�ܡ�
{
    static int canbeUse=1;
    if(canbeUse==1)
    {
        if(PY->Treasure)
        {
            printf("ʥ��ʿ�ر�������֮�ܡ�������");
            printf("����ս�׶���һ�Σ�Ⱥ������+1��������+2��");
            int num,i;
            printf("�����������ߵ���ţ�ȫ������������0����");
            scanf("%d",&num);
            if(num==0)
                for(i=0;i<pynum;i++)
                    py[i].lifeP++;
            else if(num>0 && num<=pynum)
                py[num-1].lifeP+=2;
            canbeUse--;
        }
    }

}

///==========Ӣ�۵���Դ�ظ�==========
void HolySwordsman_Res(HERO *PY)
{
    if(PY->resourseP<PY->resourseMP&&PY->timeP==1)
        PY->resourseP++;
}

void Ninja_Res(HERO *PY)
{
    if(PY->resourseP<PY->resourseMP&&PY->timeP==2)
        PY->resourseP++;
}

void Prince_Res(HERO *PY)
{
    if(PY->resourseP<=PY->resourseMP&&PY->timeP==5)
        PY->resourseP=PY->resourseMP;
}

int Paladin_Res(HERO *PY,int num)
{
    printf("�Ƿ�ʹ��ʥ��ʿ��Ч��?(%c/%c)",key_button[7],key_button[8]);
    printf("(���������ж������ظ�1����Դֵ):");
    int ch;
    while(1)///����ESC�˳��޸Ľ��棬����ENTER��ʼ�����޸�
    {
        if (_kbhit())
        {///����а������£���_kbhit()����������
            ch = _getch();///ʹ��_getch()������ȡ���µļ�ֵ
            if(ch==key_button[7]&&(PY->resourseP<PY->resourseMP))
            {
                if(num>=1000)
                    num-=1000;
                else if(num>=100)
                    num-=100;
                else if(num>=10)
                    num-=10;
                else
                    num--;
                PY->resourseP++;
                break;
            }
            if(ch==key_button[7]&&(PY->resourseP==PY->resourseMP))
            {
                printf("��Դֵȫ��");
                break;
            }
            if(ch==key_button[8])
                break;
        }
    }
    return num;
}
#endif // HEROMOD_H_INCLUDED
