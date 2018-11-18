#ifndef PREPARATION_H_INCLUDED
#define PREPARATION_H_INCLUDED

extern int map_mountain[6];
extern int dragon_anger;
extern Dragonic dra;

void preparation()
{
    int a[5],i,b[6];
    SetPos(6,44);printf("�ȴ���������ͽ���");
    random_mission(a,5);///����5/5
    for(i=1;i<6;i++)
    {
        map_mountain[i]+=1000*a[i-1];///������ǧλ��
    }
    Sleep(1000);
    random_mission(b,6);///����5/6
    for(i=1;i<6;i++)
    {
        map_mountain[i]+=100*b[i-1];///�����ڰ�λ��
    }
    dra=setSingleDarkDragon(dra);
}

int getMAX(int *dice, int num) ///��ȡ���ֵ
{
    int i, maxD, maxI;
    maxD = dice[0];
    maxI = 0;
    for (i = 0; i < num; i++)
    {
        if (dice[i] > maxD)
        {
            maxD = dice[i];
            maxI = i;
        }
    }
    return maxI + 1;
}

int getMIN(int *dice, int num) ///��ȡ��Сֵ
{
    int i, minD, minI;
    minD = dice[0];
    minI = 0;
    for (i = 0; i < num; i++)
    {
        if (dice[i] < minD)
        {
            minD = dice[i];
            minI = i;
        }
    }
    return minI + 1;
}


#endif // PREPARATION_H_INCLUDED

///��ʾ������ظ���ȡ����
    /*
    int a[5],i;
    random_mission(a,5);
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
    SetPos(6,44);printf("the end!");system("pause");
    */
