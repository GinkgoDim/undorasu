#ifndef BACKGROUNDSTORY_H_INCLUDED
#define BACKGROUNDSTORY_H_INCLUDED

void background_story(int,int);

void background_story(int x,int y)
{
    FILE *fp;
    char ch;
    SetPos(42,44);printf("==================== ������������� ====================");
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
            {//����а������£���_kbhit()����������
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
    printf("   ");///��ֹ������Ӱ����һ��������ʾ
    system("cls");
}
#endif // BACKGROUNDSTORY_H_INCLUDED
