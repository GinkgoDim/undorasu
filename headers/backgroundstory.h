#ifndef BACKGROUNDSTORY_H_INCLUDED
#define BACKGROUNDSTORY_H_INCLUDED

void background_story(int,int);

void background_story(int x,int y)
{
    FILE *fp;
    char ch;
    SetPos(42,44);printf("==================== 按下任意键跳过 ====================");
    if((fp=fopen(".\\text\\backgroundstory","rt+"))==NULL)
    {
        printf("\nbackground story is missing!");
    }
    else
    {
        ch=fgetc(fp);
        SetPos(x,y);
        while(ch!=EOF)
        {
            if (_kbhit())
            {//如果有按键按下，则_kbhit()函数返回真
                break;
            }
            else
            {
                if(ch=='\n')
                {
                    y=y+2;
                    SetPos(x,y);
                    ch=fgetc(fp);
                }
                else
                {
                    putchar(ch);
                    ch=fgetc(fp);
                }
                Sleep(25);
            }
        }
        if(ch==EOF)
            Sleep(4000);
    }
    fclose(fp);
    printf("   ");///防止中文字影响下一步绘制显示
    system("cls");
}
#endif // BACKGROUNDSTORY_H_INCLUDED
