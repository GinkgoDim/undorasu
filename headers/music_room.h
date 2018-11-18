#ifndef MUSIC_ROOM_H_INCLUDED
#define MUSIC_ROOM_H_INCLUDED
void music_room();
void play_music(int);
extern char key_button[9];
void music_room()
{
    SetPos(20,9);
    printf("ѡ����汳������");
    SetPos(26,11);
    printf("ԭ����");

    SetPos(20,19);
    printf("��Ϸ���ͼ��������");
    SetPos(26,21);
    printf("ԭ����");

    SetPos(20,29);
    printf("��ս��������");
    SetPos(26,31);
    printf("ԭ����");

    SetPos(115,3);printf("����ESC����");
    SetPos(115,4);printf("Press 'ESC' back");
    SetPos(115,6);printf("���� %c �Ϸ�",key_button[7]);
    SetPos(115,7);printf("press %c to up",key_button[7]);
    SetPos(115,9);printf("���� %c �·�",key_button[8]);
    SetPos(115,10);printf("press %c to down",key_button[8]);

    int ch;
    int music_choice=1,music_x=22,music_y=11;
    SetPos(music_x,music_y);
    printf("=>");SetPos(6,44);
    while (1)
    {
        if (_kbhit())
        {//����а������£���_kbhit()����������
            ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            if(key_button[7]==ch)
            {
                if(music_choice>1)
                {
                    SetPos(music_x,music_y);
                    printf("  ");
                    music_y-=10;
                    SetPos(music_x,music_y);
                    printf("=>");
                    music_choice--;
                }
            }
            if(key_button[8]==ch)
            {
                if(music_choice<3)
                {
                    SetPos(music_x,music_y);
                    printf("  ");
                    music_y+=10;
                    SetPos(music_x,music_y);
                    printf("=>");
                    music_choice++;
                }
            }
            SetPos(6,44);
            if(ch==13)
            {
                switch(music_choice)
                {
                    case 1:
                        if(_access("./music/01.wav",0)!=-1)
                            PlaySound(TEXT("./music/01.wav"),0,SND_FILENAME|SND_ASYNC|SND_LOOP);
                        break;
                    case 2:
                        if(_access("./music/02.wav",0)!=-1)
                            PlaySound(TEXT("./music/02.wav"),0,SND_FILENAME|SND_ASYNC|SND_LOOP);
                        break;
                    case 3:
                        if(_access("./music/03.wav",0)!=-1)
                            PlaySound(TEXT("./music/03.wav"),0,SND_FILENAME|SND_ASYNC|SND_LOOP);
                        break;
                    default:break;
                }
            }

            if(ch==27)
                break;///������ESCʱѭ����ESC���ļ�ֵʱ27.
        }
    }
}

void play_music(int n)
{
    switch(n)
    {
        case 1:
            if(_access("./music/01.wav",0)!=-1)
                PlaySound(TEXT("./music/01.wav"),0,SND_FILENAME|SND_ASYNC|SND_LOOP);
            break;
        case 2:
            if(_access("./music/02.wav",0)!=-1)
                PlaySound(TEXT("./music/02.wav"),0,SND_FILENAME|SND_ASYNC|SND_LOOP);
            break;
        case 3:
            if(_access("./music/03.wav",0)!=-1)
                PlaySound(TEXT("./music/03.wav"),0,SND_FILENAME|SND_ASYNC|SND_LOOP);
            break;
    }
}

#endif // MUSIC_ROOM_H_INCLUDED
