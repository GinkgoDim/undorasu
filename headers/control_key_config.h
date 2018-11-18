#ifndef CONRTOL_KEY_CONFIG_H_INCLUDED
#define CONRTOL_KEY_CONFIG_H_INCLUDED
void show_message(int);
void control_key_config(int,int);
void control_key_config_check(char *);
int key_button_check(char *);
extern char key_button[9];

void control_key_config(int x,int y)
{
    setColor(x,y);
    int key_button_count=0;

	int  i,modify=1,ch;///ѭ������i�����ڼ���޸ĵ�modify�����ڼ�ⰴ����ch
	while(modify!=0)
    {
        for(i=0;i<9;i++)
        {
            show_message(i);
            printf("=%c",key_button[i]);
        }
        SetPos(6,44);
        while(1)///����ESC�˳��޸Ľ��棬����ENTER��ʼ�����޸�
        {
            if (_kbhit())
            {///����а������£���_kbhit()����������
                ch = _getch();///ʹ��_getch()������ȡ���µļ�ֵ
                if(ch==27)
                {
                    SetPos(6,44);setColor(7,0);printf("              ");SetPos(6,44);printf("�˳��޸ģ�");setColor(x,y);
                    modify=0;
                    break;
                }
                if(ch==13)
                {
                    SetPos(6,44);setColor(7,0);printf("              ");SetPos(6,44);printf("��ʼ�޸ģ�");setColor(x,y);
                    modify=1;
                    break;
                }///������ENTERʱѭ��������ENTER���ļ�ֵ13.
            }
        }
        if(modify==1)
        {
            FILE *fp;
            fp=fopen(".\\text\\config_KB","r+");
            while (1)
            {
                if (_kbhit())
                {///����а������£���_kbhit()����������
                    ch = _getch();///ʹ��_getch()������ȡ���µļ�ֵ
                    switch(ch)
                    {
                        case 13:///�����һ��ʼ�Ͱ���ENTER��ָ�Ĭ��ֵ����;�������ж��޸�
                            if(key_button_count==0)
                            {
                                sprintf(key_button,"weasdzxrv");
                            }
                            break;
                        case 27:///���κ�����°���ESC�����ж��޸�
                            break;
                        default:
                            setColor(15,9);
                            show_message(key_button_count);
                            printf("=%c",ch);
                            key_button[key_button_count]=ch;
                            key_button_count++;
                            if(key_button_count==9)
                            {
                                key_button_count=0;
                                ch=13;
                                Sleep(1000);
                            }
                            setColor(x,y);
                            break;
                    }
                    if((ch==27||ch==13))
                    {
                        if(key_button_check(key_button)!=1)
                        {
                            key_button_count=0;
                            SetPos(6,44);setColor(7,0);printf("              ");SetPos(6,44);printf("���óɹ�!");setColor(x,y);
                            break;

                        }
                        else
                        {
                            key_button_count=0;
                            sprintf(key_button,"weasdzxrv");
                            for(i=0;i<9;i++)
                            {
                                show_message(i);
                                printf("=%c",key_button[i]);
                            }
                            SetPos(6,44);setColor(7,0);printf("              ");SetPos(6,44);printf("�����ظ�!");setColor(x,y);
                        }
                    }///������ESCʱѭ��������ESC���ļ�ֵʱ27.
                }
            }
            fp=fopen(".\\text\\config_KB", "r+");
            fprintf(fp,key_button);
            fclose(fp);
        }
    }
    for(i=0;i<9;i++)
    {
        setColor(7,0);show_message(i);///�������������ʾ
    }
}

void control_key_config_check(char *key_button)
{
    FILE *fp;
    int i;
    if((fp=fopen(".\\text\\config_KB", "r+"))== NULL)
	{
		fp=fopen(".\\text\\config_KB", "w+");
		fprintf(fp,key_button);
	    SetPos(6,44);printf("              ");SetPos(6,44);printf("�����ָ���ʼ��");
	}
	else
    {
        fp=fopen(".\\text\\config_KB","r+");
        for(i=0;i<9;i++)
        {
            fseek(fp,i,SEEK_SET);///i=0ʱ����λ���ַ�����ͷ
            key_button[i]=fgetc(fp);
        }
    }
}

void show_message(int num)
{
    switch(num)
    {
        case 0:SetPos(34,10);printf("    \b\b\b");break;
        case 1:SetPos(56,10);printf("    \b\b\b");break;
        case 2:SetPos(23,22);printf("    \b\b\b");break;
        case 3:SetPos(45,22);printf("    \b\b\b");break;
        case 4:SetPos(67,22);printf("    \b\b\b");break;
        case 5:SetPos(34,34);printf("    \b\b\b");break;
        case 6:SetPos(56,34);printf("    \b\b\b");break;
        case 7:SetPos(88,13);printf("    \b\b\b");break;
        case 8:SetPos(88,33);printf("    \b\b\b");break;
        default:break;
    }
}

int key_button_check(char *key_button)
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=i+1;j<9;j++)
        {
            if(key_button[i]==key_button[j])
            return 1;
        }
    return 0;
}
#endif // CONRTOL_KEY_CONFIG_H_INCLUDED
