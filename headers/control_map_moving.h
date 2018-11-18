#ifndef CONTROL_MAP_MOVING_H_INCLUDED
#define CONTROL_MAP_MOVING_H_INCLUDED

int moving_block_check_all(int);
int block_check_6();
int block_check_forest();
int block_check_plain();
int block_check_road();

extern int map_block[7][8];
int step_show[4]={0,0,0,0};

void map_moving(int,int,int*,int*,int*,int*);
///������6ȫ���ַ� ������5�ַ�
//a=97 s=115 d=100 w=119 h=104 q=113 e=101 z=122 x=120

void map_moving(int step,int n,int *hero_moving_x,int *hero_moving_y,int *hero_moving_a,int *hero_moving_b)
{
    int step_copy1;                 ///�����������ݱ��ݵĳ�Ա
    int x,y,a,b;
    x=*hero_moving_x;y=*hero_moving_y;a=*hero_moving_a;b=*hero_moving_b;///���������ƶ������ĸ���������ȡ���ָ���ʼ��
    SetPos(x,y);printf("P%d",n);    ///��ʼ��������ʾ

    step_copy1=step;                ///�����������
    if(step_copy1/1000>=1)          ///����
    {
        step_show[3]=step_copy1/1000;
        step_copy1-=1000*step_show[3];
    }
    if(step_copy1/100>=1)           ///ɭ��
    {
        step_show[2]=step_copy1/100;
        step_copy1-=100*step_show[2];
    }
    if(step_copy1/10>=1)            ///ƽԭ
    {
        step_show[1]=step_copy1/10;
        step_copy1-=10*step_show[1];
    }
    if(step_copy1>=1)               ///��·
    {
        step_show[0]=step_copy1;
    }
    SetPos(113,37);printf(" �ƶ���  ");
    SetPos(113,38);printf(" ���⣺  %d",step_show[3]);
    SetPos(113,39);printf(" ɭ�֣�  %d",step_show[2]);
    SetPos(113,40);printf(" ƽԭ��  %d",step_show[1]);
    SetPos(113,41);printf(" ��·��  %d",step_show[0]);

    int ch,ch_again;
    while (1)
    {
        if (_kbhit())
        {//����а������£���_kbhit()����������
            emergency_decoration(2);
            ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            if(key_button[0]==ch)                                               ///�����ƶ�
                if(a>0&&b>0)                                                    ///�߽��ж�
                {
                    if(moving_block_check_all(map_block[a-1][b-1])==1)          ///�ؿ��ж� �۳���Ӧ����
                    {
                        SetPos(x,y);printf("  ");SetPos(x-6,y-5);
                        map_block[a][b]-=2*n-1;                                 ///�����µ����������ʶȥ��
                        x-=6;y-=5;a--;b--;
                        map_block[a][b]+=2*n-1;                                 ///���µ�������������ʶ
                        printf("P%d",n);
                    }
                }
            if(key_button[1]==ch)                                               ///�����ƶ�
                if(a>0&&b-4<a)
                {
                    if(moving_block_check_all(map_block[a-1][b])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x+6,y-5);
                        map_block[a][b]-=2*n-1;
                        x+=6;y-=5;a--;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[2]==ch)                                               ///���ƶ�
                if(b>0&&b+3>a)
                {
                    if(moving_block_check_all(map_block[a][b-1])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x-12,y);
                        map_block[a][b]-=2*n-1;
                        x-=12;b--;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[3]==ch||key_button[7]==ch)                            ///���������ƶ�
            {
                SetPos(6,44);
                emergency_decoration(2);
                printf("���������ƶ���");
                if(key_button[3]==ch_again)
                {
                    emergency_decoration(2);
                    printf("���������ƶ���");
                    break;
                }
            }
            if(key_button[4]==ch)                                               ///���ƶ�
                if(b<7&&b-4<a)
                {
                    if(moving_block_check_all(map_block[a][b+1])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x+12,y);
                        map_block[a][b]-=2*n-1;
                        x+=12;b++;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[5]==ch)                                               ///�����ƶ�
                if(b+3>a&&a<6)
                {
                    if(moving_block_check_all(map_block[a+1][b])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x-6,y+5);
                        map_block[a][b]-=2*n-1;
                        x-=6;y+=5;a++;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[6]==ch)                                               ///�����ƶ�
                if(a<6&&b<7)
                {
                    if(moving_block_check_all(map_block[a+1][b+1])==1)
                    {
                        SetPos(x,y);printf("  ");SetPos(x+6,y+5);x+=6;y+=5;
                        map_block[a][b]-=2*n-1;
                        a++;b++;
                        map_block[a][b]+=2*n-1;
                        printf("P%d",n);
                    }
                }
            if(key_button[8]==ch)                                               ///ȡ���ƶ����� �ָ�����εĳ�ʼ��
            {
                SetPos(x,y);printf("  ");
                map_block[a][b]-=2*n-1;
                x=*hero_moving_x;y=*hero_moving_y;a=*hero_moving_a;b=*hero_moving_b;
                map_block[a][b]+=2*n-1;
                SetPos(x,y);printf("P%d",n);

                step_copy1=step;                ///�����������
                if(step_copy1/1000>=1)          ///����
                {
                    step_show[3]=step_copy1/1000;
                    step_copy1-=1000*step_show[3];
                }
                if(step_copy1/100>=1)           ///ɭ��
                {
                    step_show[2]=step_copy1/100;
                    step_copy1-=100*step_show[2];
                }
                if(step_copy1/10>=1)            ///ƽԭ
                {
                    step_show[1]=step_copy1/10;
                    step_copy1-=10*step_show[1];
                }
                if(step_copy1>=1)               ///��·
                {
                    step_show[0]=step_copy1;
                }
                SetPos(121,38);printf(" %d",step_show[3]);
                SetPos(121,39);printf(" %d",step_show[2]);
                SetPos(121,40);printf(" %d",step_show[1]);
                SetPos(121,41);printf(" %d",step_show[0]);
            }
            if (ch==27)                                                         ///�ȼ�ESC�˳�
            {
                SetPos(6,44);
                emergency_decoration(2);
                printf("�˳���Ϸ��");
                if(ch_again==27)
                {
                    emergency_decoration(2);
                    printf("�˳���Ϸ��");
                    exit(0);
                }
            }//������ESCʱѭ����ESC���ļ�ֵʱ27.
            ch_again=ch;///�������һ�ΰ�����ֵ �ж�ǰ�����ΰ����Ƿ���ͬ
            SetPos(6,44);
        }
    }
    *hero_moving_x=x;*hero_moving_y=y;*hero_moving_a=a;*hero_moving_b=b;///�����ƶ��������޸ģ�����ʵ���޸�
}

int moving_block_check_all(int block)
{
    if(block%100>=10&&block%100<30)
        return block_check_road();
    if(block%100>=30&&block%100<40)
        return block_check_plain();
    if(block%100>=40&&block%100<50)
        return block_check_forest();
    return 0;
}

int block_check_6()
{
    if(step_show[3]>0)
    {
        step_show[3]--;
        SetPos(121,38);printf(" %d",step_show[3]);
        return 1;
    }
    else
        return 0;
}

int block_check_forest()
{
    if(step_show[2]>0)
    {
        step_show[2]--;
        SetPos(121,39);printf(" %d",step_show[2]);
        return 1;
    }
    else
        return block_check_6();
}

int block_check_plain()
{
    if(step_show[1]>0)
    {
        step_show[1]--;
        SetPos(121,40);printf(" %d",step_show[1]);
        return 1;
    }
    else
        return block_check_forest();
}

int block_check_road()
{
    if(step_show[0]>0)
    {
        step_show[0]--;
        SetPos(121,41);printf(" %d",step_show[0]);
        return 1;
    }
    else
        return block_check_plain();
}

#endif // CONTROL_MAP_MOVING_H_INCLUDED
