///���Ǽ������ӹ��ܵ�ͷ�ļ�
#ifndef DICE_H_INCLUDED
#define DICE_H_INCLUDED

typedef int DICE;

///���ӿ��ƺ���
void D6(int *p,int frequency)
{
    int i;
    srand((unsigned)(time(NULL)));
    Sleep(1000);
    for(i=0;i<frequency;i++)
        *(p+i)=rand()%6+1;
}  ///1sˢ��һ��
DICE DraD6() ///�������ӷ���ֵ����
{
    srand((unsigned)(time(NULL)));
    Sleep(1000);
    return rand()%6+1;
}
void HeroD6(int *p,int num) ///����ÿ����Ͷ�����ӵ������ж�
{
    int i;
    srand((unsigned)(time(NULL)));
    for(i=0;i<num;i++)
    {
        printf("%d�������Ͷ����",i+1);
        printf("���Ľ���ǣ�");
        Sleep(1000);
        *(p+i)=rand()%6+1;
        printf("%d",*(p+i));
    }
}

#endif // DICE_H_INCLUDED
