#ifndef MUSIC_ROOM_H_INCLUDED
#define MUSIC_ROOM_H_INCLUDED
void music_room();
void play_music(int);
extern char key_button[9];
void music_room()
{
    SetPos(20,9);
    printf("选择界面背景音乐");
    SetPos(26,11);
    printf("原曲：");

    SetPos(20,19);
    printf("游戏大地图背景音乐");
    SetPos(26,21);
    printf("原曲：");

    SetPos(20,29);
    printf("决战背景音乐");
    SetPos(26,31);
    printf("原曲：");

    SetPos(115,3);printf("按下ESC返回");
    SetPos(115,4);printf("Press 'ESC' back");
    SetPos(115,6);printf("按下 %c 上翻",key_button[7]);
    SetPos(115,7);printf("press %c to up",key_button[7]);
    SetPos(115,9);printf("按下 %c 下翻",key_button[8]);
    SetPos(115,10);printf("press %c to down",key_button[8]);

    int ch;
    int music_choice=1,music_x=22,music_y=11;
    SetPos(music_x,music_y);
    printf("=>");SetPos(6,44);
    while (1)
    {
        if (_kbhit())
        {//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
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
                break;///当按下ESC时循环，ESC键的键值时27.
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
