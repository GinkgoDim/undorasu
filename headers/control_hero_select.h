#ifndef CONTROL_HERO_SELECT_INCLUDED
#define CONTROL_HERO_SELECT_INCLUDED
///������ע�ǰ�������Ӧ�ļ���
// w=119 e=101
//a=97 s=115 d=100
// z=122 x=120
//1=49 2=50 3=51 4=52 5=53 6=54 0=48
extern char key_button[9];
extern int count;
void control_hero_select()
{
    //HERO py[3];
    extern HERO py[3];
    int ch;///��������ַ�
    int i;///ѭ������i,���ü���ֵ
    int room_choice=1,room_x=53,room_y=21;

    while(1)
    {///�ڿ�ʼ��Ϸ֮ǰ���� ��Ϣ��ʼ�� ����ѡ�� �鿴���� �޸ļ�λ �鿴���� ��ѭ��
        play_music(1);
        int select_HEROS[6]={0,0,0,0,0,0};                                      ///�жϳ�����Ӣ��              �����仹���𱣳ֳ�ʼ��
        int select_count=0;                                                     ///�жϵ�ǰ����������
        count=0;                                                            ///countΪ�Ѳ�ս��Ӣ�۱��

        SetPos(room_x,room_y);printf("=>");
        SetPos(6,44);printf("ѡ��Ӣ�۳���!");
        while (1)
        {///����������ѭ��
            if (_kbhit())
            {///����а������£���_kbhit()����������
                ch = _getch();                                                  ///ʹ��_getch()������ȡ���µļ�ֵ
                emergency_decoration(2);                                        ///������������ղ��ص����������ʼλ��
                if(key_button[0]==ch)                                           ///��ʥ
                    switch(select_HEROS[0])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[0]=1;select_count++;printf("��ʥ��Ҫ����");
                                draw_hero_select_flash_choice(0,0,9,8,2);///����ɫ
                                draw_hero_introduce_choice(1,7,0);
                            }
                            else if(select_count==3)
                                printf("����������");
                            break;
                        case 1:
                            select_HEROS[0]=0;select_count--;
                            draw_hero_select_flash_choice(0,7,0,8,2);
                            draw_hero_introduce_choice(2,7,0);
                            break;
                        default:break;
                    }
                if(key_button[1]==ch)                                           ///����
                    switch(select_HEROS[1])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[1]=1;select_count++;printf("������Ҫ����");
                                draw_hero_select_flash_choice(1,0,10,8,2);///����ɫ
                                draw_hero_introduce_choice(3,7,0);
                            }
                            else if(select_count==3)
                                printf("����������");
                            break;
                        case 1:
                            select_HEROS[1]=0;select_count--;
                            draw_hero_select_flash_choice(1,7,0,8,2);
                            draw_hero_introduce_choice(4,7,0);
                            break;
                        default:break;
                    }
                if(key_button[2]==ch)                                           ///����
                    switch(select_HEROS[2])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[2]=1;select_count++;printf("������Ҫ����");
                                draw_hero_select_flash_choice(2,0,14,8,2);///����ɫ
                                draw_hero_introduce_choice(5,7,0);
                            }
                            else if(select_count==3)
                                printf("����������");
                            break;
                        case 1:
                            select_HEROS[2]=0;select_count--;
                            draw_hero_select_flash_choice(2,7,0,8,2);
                            draw_hero_introduce_choice(6,7,0);
                            break;
                        default:break;
                    }
                if(key_button[4]==ch)                                           ///�Ƕ�ʿ
                    switch(select_HEROS[3])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[3]=1;select_count++;printf("�Ƕ�ʿ��Ҫ����");
                                draw_hero_select_flash_choice(4,0,12,8,2);///����ɫ
                                draw_hero_introduce_choice(7,7,0);
                            }
                            else if(select_count==3)
                                printf("����������");
                            break;
                        case 1:
                            select_HEROS[3]=0;select_count--;
                            draw_hero_select_flash_choice(4,7,0,8,2);
                            draw_hero_introduce_choice(8,7,0);
                            break;
                        default:break;
                    }
                if(key_button[5]==ch)                                           ///����
                    switch(select_HEROS[4])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[4]=1;select_count++;printf("������Ҫ����");
                                draw_hero_select_flash_choice(5,0,13,8,2);///����ɫ
                                draw_hero_introduce_choice(9,7,0);
                            }
                            else if(select_count==3)
                                printf("����������");
                            break;
                        case 1:
                            select_HEROS[4]=0;select_count--;
                            draw_hero_select_flash_choice(5,7,0,8,2);
                            draw_hero_introduce_choice(10,7,0);
                            break;
                        default:break;
                    }
                if(key_button[6]==ch)                                           ///ʥ��ʿ
                    switch(select_HEROS[5])
                    {
                        case 0:
                            if(select_count<3)
                            {
                                select_HEROS[5]=1;select_count++;printf("ʥ��ʿ��Ҫ����");
                                draw_hero_select_flash_choice(6,0,11,8,2);///ǳ��ɫ
                                draw_hero_introduce_choice(11,7,0);
                            }
                            else if(select_count==3)
                                printf("����������");
                            break;
                        case 1:
                            select_HEROS[5]=0;select_count--;
                            draw_hero_select_flash_choice(6,7,0,8,2);
                            draw_hero_introduce_choice(12,7,0);
                            break;
                        default:break;
                    }
                if(key_button[3]==ch)                                           ///���¿�ʼ��ť ������� ���ɽ�ɫ
                {
                    switch(select_count)
                    {
                        case 0:printf("Ŀǰû��Ӣ�۳�����");break;
                        default:                                                ///ΪӢ�۳�ʼ������Ӣ�۽ṹ��
                        {
                            i=0;                                                ///iΪ��׼ѭ������������������
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setHolySwordsman();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setNinja();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setHunter();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setGladiator();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setPrince();printf("%d",py[count].timeP);
                                count++;
                            }
                            i++;
                            if(select_HEROS[i]==1)
                            {
                                py[count]=setPaladin();printf("%d",py[count].timeP);
                                count++;
                            }
                            emergency_decoration(2);
                            preparation();///��ʼ��һ��������
                            printf(" ׼����! ");
                            Sleep(1000);printf("3 ");
                            Sleep(1000);printf("2 ");
                            Sleep(1000);printf("1 ");
                            Sleep(1000);
                        }
                        break;
                    }
                    if(select_count!=0)
                        break;
                }
                setColor(7,0);
                if(ch==27)                                                      ///ESC�ȼ��˳� ESC���ļ�ֵʱ27
                {
                    printf("Ӣ����������");
                    exit(0);
                }
                if(ch==13)                                                      ///���ɽ��뵱ǰ��ָ����
                {
                    room_choice+=10;
                    break;///������ESCʱ����ѭ����ESC���ļ�ֵʱ27.
                }
                if(key_button[7]==ch)                                           ///ѡ����������
                {
                    if(room_choice>1)
                    {
                        SetPos(room_x,room_y);
                        printf("  ");
                        room_y--;
                        SetPos(room_x,room_y);
                        printf("=>");
                        room_choice--;
                    }
                }
                if(key_button[8]==ch)                                           ///ѡ����������
                {
                    if(room_choice<3)
                    {
                        SetPos(room_x,room_y);
                        printf("  ");
                        room_y++;
                        SetPos(room_x,room_y);
                        printf("=>");
                        room_choice++;
                    }
                }
                SetPos(6,44);
            }
        }
        if(room_choice>10)                                                      ///�����ж�ѡ����뷿������˳�����
        {
            switch(room_choice)
            {
                case 11:
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_help();
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_hero_select(0,7,0,8,8,2);                              ///����Ӣ��ѡ��ģ���ͼ��
                    draw_hero_select_word(7,0,8,2,1);                           ///����Ӣ��ѡ��ģ�������
                    break;
                case 12:
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_key_config_help();
                    setColor(0,7);                                              ///���ð����޸�ģ����ɫΪ���ְ׵�
                    draw_key_config(32,2);                                      ///���ư����޸�ģ���ͼ��
                    draw_key_config_word(32,2,1);                               ///���ư����޸�ģ�������
                    control_key_config(0,14);                                   ///�����޸�ģ��
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_hero_select(0,7,0,8,8,2);                              ///����Ӣ��ѡ��ģ���ͼ��
                    draw_hero_select_word(7,0,8,2,1);                           ///����Ӣ��ѡ��ģ�������
                    break;
                case 13:
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    music_room();                                               ///������ģ��
                    emergency_decoration(1);
                    emergency_decoration(2);
                    emergency_decoration(3);
                    draw_hero_select(0,7,0,8,8,2);                              ///����Ӣ��ѡ��ģ���ͼ��
                    draw_hero_select_word(7,0,8,2,1);                           ///����Ӣ��ѡ��ģ�������
                    break;
                default:break;
            }
            room_choice-=10;
        }
        else
        {
            emergency_decoration(1);
            emergency_decoration(2);
            emergency_decoration(3);
            break;
        }
    }
}

#endif // CONTROL_HERO_SELECT_INCLUDED
///ͨ�ú�����
//HERO setHolySwordsman(void) ///�趨��ʥĬ������
//HERO setNinja(void) ///�趨����Ĭ������
//HERO setHunter(void) ///�趨����Ĭ������
//HERO setGladiator(void) ///�趨�Ƕ�ʿĬ������
//HERO setPrince(void) ///�趨����Ĭ������
//HERO setPaladin(void) ///�趨ʥ��ʿĬ������

///����Ӣ�۵ķ���
/*
HERO py[3];
py[0]=setPaladin();
py[1]=setHolySwordsman();
py[2]=setHunter();
*/
