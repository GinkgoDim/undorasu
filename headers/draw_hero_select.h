#ifndef DRAW_HERO_SELECT_H
#define DRAW_HERO_SELECT_H
void draw_hero_select(int,int,int,int,int,int);
void draw_hero_select_word(int,int,int,int,int);
void draw_hero_select_draw_line1();
void draw_hero_select_draw_line2();
void draw_hero_select_draw_line3();
void draw_hero_select_draw_line4();
void draw_hero_select_draw_apart_y(int,int);///����ָ���
void draw_hero_select_draw_apart_x(int,int);///����ָ���
void draw_hero_select_draw_apart_a(int x,int y,int n);///б�Ϸָ���
void draw_hero_select_draw_apart_b(int x,int y,int n);///б�·ָ���
void draw_hero_select_draw_apart_c(int x,int y,int n);///������Ʒ�

void draw_hero_select_left_up(int x,int y);
void draw_hero_select_up(int x,int y);
void draw_hero_select_right_up(int x,int y);
void draw_hero_select_right_down(int x,int y);
void draw_hero_select_down(int x,int y);
void draw_hero_select_left_down(int x,int y);
void draw_hero_select_middle(int x,int y);

void draw_hero_select_flash_choice(int n,int a,int b,int x,int y);///���°�����ı߿��ɫ
void draw_hero_select_flash_left_up(int x,int y);
void draw_hero_select_flash_up(int x,int y);
void draw_hero_select_flash_right_up(int x,int y);
void draw_hero_select_flash_right_down(int x,int y);
void draw_hero_select_flash_down(int x,int y);
void draw_hero_select_flash_left_down(int x,int y);

void draw_hero_introduce_choice(int i,int x,int y);///���°�������ʾ��������
void draw_hero_introduce_HolySwordsman(int i);
void draw_hero_introduce_Ninja(int i);
void draw_hero_introduce_Hunter(int i);
void draw_hero_introduce_Gladiator(int i);
void draw_hero_introduce_setPrince(int i);
void draw_hero_introduce_Paladin(int i);

void draw_hero_select_empire_line();

void draw_hero_select(int ca,int cb,int cc,int cd,int x,int y)
{
    setColor(ca,cb);
    draw_hero_select_left_up(x,y);
    draw_hero_select_up(x,y);
    draw_hero_select_right_up(x,y);
    draw_hero_select_right_down(x,y);
    draw_hero_select_down(x,y);
    draw_hero_select_left_down(x,y);
    setColor(cc,cd);
    draw_hero_select_middle(x,y);
}

void draw_hero_select_word(int a,int b,int x,int y,int n)
{
    extern char key_button[9];
    if(n==1)
    {
        setColor(a,b);
        SetPos(x+38,y+14);printf("��  ʥ");SetPos(x+37,y+15);printf("(Press %c)",key_button[0]);
        SetPos(x+56,y+14);printf("��  ��");SetPos(x+55,y+15);printf("(Press %c)",key_button[1]);
        SetPos(x+32,y+20);printf("��  ��");SetPos(x+31,y+21);printf("(Press %c)",key_button[2]);
        SetPos(x+62,y+20);printf("�Ƕ�ʿ");SetPos(x+61,y+21);printf("(Press %c)",key_button[4]);
        SetPos(x+38,y+26);printf("��  ��");SetPos(x+37,y+27);printf("(Press %c)",key_button[5]);
        SetPos(x+56,y+26);printf("ʥ��ʿ");SetPos(x+55,y+27);printf("(Press %c)",key_button[6]);
        SetPos(x+45,y+18);printf("(%c)�� up",key_button[7]);
        SetPos(x+47,y+19);printf("�鿴����");
        SetPos(x+47,y+20);printf("��������");
        SetPos(x+47,y+21);printf("�� �� ��");
        SetPos(x+45,y+22);printf("(%c)��down",key_button[8]);
    }
    else
    {
        setColor(7,0);
        SetPos(x+38,y+14);printf("      ");SetPos(x+37,y+15);printf("          ");
        SetPos(x+56,y+14);printf("      ");SetPos(x+55,y+15);printf("          ");
        SetPos(x+32,y+20);printf("      ");SetPos(x+31,y+21);printf("          ");
        SetPos(x+62,y+20);printf("      ");SetPos(x+61,y+21);printf("          ");
        SetPos(x+38,y+26);printf("      ");SetPos(x+37,y+27);printf("          ");
        SetPos(x+56,y+26);printf("      ");SetPos(x+55,y+27);printf("          ");
        SetPos(x+47,y+19);printf("        ");
        SetPos(x+47,y+20);printf("        ");
        SetPos(x+47,y+21);printf("        ");
    }
}

void draw_hero_select_empire_line()
{
    ///���Ʒָ���
    draw_hero_select_draw_apart_x(146,0);
    draw_hero_select_draw_apart_x(146,1);
    draw_hero_select_draw_apart_x(146,42);
    draw_hero_select_draw_apart_x(146,43);
    draw_hero_select_draw_apart_y(110,46);
    draw_hero_select_draw_apart_y(140,46);
    draw_hero_select_draw_apart_y(3,46);
}

void draw_hero_select_draw_line1()
{
    printf("| |");
}
void draw_hero_select_draw_line2()
{
    //printf("_");
    printf(" ");
}
void draw_hero_select_draw_line3()
{
    //printf("/");
    printf(" ");
}
void draw_hero_select_draw_line4()
{
    //printf("\\");
    printf(" ");
}
void draw_hero_select_draw_apart_y(int x,int y)///����ָ���
{
    int i;
    for(i=0;i<y;i++)
    {
        SetPos(x,i);draw_hero_select_draw_line1();
    }
}
void draw_hero_select_draw_apart_x(int x,int y)///����ָ���
{
    int i;
    SetPos(0,y);
    for(i=0;i<x;i++)
        draw_hero_select_draw_line2();
}

void draw_hero_select_draw_apart_a(int x,int y,int n)///б�ϻ��Ʒ� x,yΪ���Ͻ�����
{
    int i;
    for(i=0;i<n;i++)
    {
        SetPos(x+i,y-i);
        draw_hero_select_draw_line3();
    }
}
void draw_hero_select_draw_apart_b(int x,int y,int n)///б�»��Ʒ� x,yΪ���½�����
{
    int i;
    for(i=0;i<n;i++)
    {
        SetPos(x+i,y+i);
        draw_hero_select_draw_line4();
    }
}
void draw_hero_select_draw_apart_c(int x,int y,int n)///������Ʒ� x,yΪ������
{
    int i;
    SetPos(x,y);
    for(i=0;i<n;i++)
        draw_hero_select_draw_line2();
}

void draw_hero_select_left_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+25,y+18,8);
    draw_hero_select_draw_apart_b(x+24,y+1,10);
    draw_hero_select_draw_apart_c(x+3,y+19,22);
}
void draw_hero_select_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+63,y+9,9);
    draw_hero_select_draw_apart_b(x+28,y+1,9);
    draw_hero_select_draw_apart_c(x+37,y+9,26);
}
void draw_hero_select_right_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+66,y+10,10);
    draw_hero_select_draw_apart_b(x+67,y+11,8);
    draw_hero_select_draw_apart_c(x+75,y+19,22);
}
void draw_hero_select_right_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+66,y+30,9);
    draw_hero_select_draw_apart_b(x+67,y+31,9);
    draw_hero_select_draw_apart_c(x+75,y+21,22);
}
void draw_hero_select_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+28,y+39,8);
    draw_hero_select_draw_apart_b(x+64,y+32,8);
    draw_hero_select_draw_apart_c(x+36,y+31,28);
}
void draw_hero_select_left_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+24,y+39,9);
    draw_hero_select_draw_apart_b(x+25,y+22,9);
    draw_hero_select_draw_apart_c(x+3,y+21,22);

}
void draw_hero_select_middle(int x,int y)
{
    ///����б��
    draw_hero_select_draw_apart_a(x+64,y+10,10);
    draw_hero_select_draw_apart_a(x+26,y+39,9);
    draw_hero_select_draw_apart_b(x+26,y+1,10);
    draw_hero_select_draw_apart_b(x+65,y+31,9);
    draw_hero_select_draw_apart_c(x+3,y+20,23);
    draw_hero_select_draw_apart_c(x+74,y+20,23);
    ///�в���������
    draw_hero_select_draw_apart_a(x+25,y+20,10);
    draw_hero_select_draw_apart_a(x+64,y+30,10);
    draw_hero_select_draw_apart_b(x+65,y+11,10);
    draw_hero_select_draw_apart_b(x+26,y+21,10);
    draw_hero_select_draw_apart_c(x+36,y+10,28);
    draw_hero_select_draw_apart_c(x+36,y+30,28);
    ///�в�С������
    draw_hero_select_draw_apart_a(x+42,y+20,3);
    draw_hero_select_draw_apart_a(x+55,y+22,2);
    draw_hero_select_draw_apart_b(x+43,y+21,2);
    draw_hero_select_draw_apart_b(x+55,y+18,3);
    draw_hero_select_draw_apart_c(x+45,y+17,10);
    draw_hero_select_draw_apart_c(x+45,y+23,10);
}

void draw_hero_select_flash_choice(int n,int a,int b,int x,int y)///���ư��¶�Ӧ����ʾ��������
{
    setColor(a,b);
    switch(n)
    {
        case 0:draw_hero_select_flash_left_up(x,y);break;
        case 1:draw_hero_select_flash_up(x,y);break;
        case 2:draw_hero_select_flash_left_down(x,y);break;
        case 4:draw_hero_select_flash_right_up(x,y);break;
        case 5:draw_hero_select_flash_down(x,y);break;
        case 6:draw_hero_select_flash_right_down(x,y);break;
        default:break;
    }
}

void draw_hero_select_flash_left_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+24,y+18,8);
    draw_hero_select_draw_apart_b(x+23,y+1,10);
    draw_hero_select_draw_apart_c(x+3,y+18,22);
}
void draw_hero_select_flash_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+63,y+8,8);
    draw_hero_select_draw_apart_b(x+29,y+1,8);
    draw_hero_select_draw_apart_c(x+37,y+8,26);
}
void draw_hero_select_flash_right_up(int x,int y)
{
    draw_hero_select_draw_apart_a(x+67,y+10,10);
    draw_hero_select_draw_apart_b(x+68,y+11,8);
    draw_hero_select_draw_apart_c(x+76,y+18,21);
}
void draw_hero_select_flash_right_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+67,y+30,9);
    draw_hero_select_draw_apart_b(x+68,y+31,9);
    draw_hero_select_draw_apart_c(x+76,y+22,21);
}
void draw_hero_select_flash_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+29,y+39,8);
    draw_hero_select_draw_apart_b(x+63,y+32,8);
    draw_hero_select_draw_apart_c(x+36,y+32,28);
}
void draw_hero_select_flash_left_down(int x,int y)
{
    draw_hero_select_draw_apart_a(x+23,y+39,9);
    draw_hero_select_draw_apart_b(x+24,y+22,9);
    draw_hero_select_draw_apart_c(x+3,y+22,21);
}

void draw_hero_introduce_choice(int i,int x,int y)
{
    setColor(x,y);
    switch(i)
    {
        case 1:draw_hero_introduce_HolySwordsman(1);break;
        case 2:draw_hero_introduce_HolySwordsman(0);break;
        case 3:draw_hero_introduce_Ninja(1);break;
        case 4:draw_hero_introduce_Ninja(0);break;
        case 5:draw_hero_introduce_Hunter(1);break;
        case 6:draw_hero_introduce_Hunter(0);break;
        case 7:draw_hero_introduce_Gladiator(1);break;
        case 8:draw_hero_introduce_Gladiator(0);break;
        case 9:draw_hero_introduce_setPrince(1);break;
        case 10:draw_hero_introduce_setPrince(0);break;
        case 11:draw_hero_introduce_Paladin(1);break;
        case 12:draw_hero_introduce_Paladin(0);break;
        default:break;
    }
}

void draw_hero_introduce_HolySwordsman(int i)
{
    switch(i)
    {
        case 1:
            SetPos(13,6);printf("��ʥ");
            SetPos(13,8);printf("����ֵ:6/6");
            SetPos(13,10);printf("�ƶ�4 ð��2/2 ս��2");
            SetPos(13,11);printf("̽��2 ѧʶ2");
            SetPos(13,13);printf("ħ��:3/3(4)");
            SetPos(13,14);printf("�غϿ�ʼʱ���ָ�1��");
            fn_clear_right();

            SetPos(113,2);printf("����ֵ:");
            SetPos(113,3);printf("lv0(0)\t��");
            SetPos(113,4);printf("lv1(1)\tս��+1");
            SetPos(113,5);printf("lv2(2)\t̽��+1");
            SetPos(113,6);printf("lv3(3)\t����ȫ��");
            SetPos(113,7);printf("lv4(4)\tħ������+1 ");
            SetPos(113,8);printf("lv5(5)\tս��+1");
            SetPos(113,9);printf("lv6(6)\tս��+1");

            SetPos(113,12);printf("�ر�:");
            SetPos(113,13);printf("Զ����ҩ");
            SetPos(113,14);printf("[��ս�׶�]��ʼʱʹ�ã���");
            SetPos(113,15);printf("��ħ�����ޣ��ָ�ȫ��ħ��");

            SetPos(113,28);printf("��ʥ");
            SetPos(113,30);printf("��������");
            SetPos(113,31);printf("��������[��˵�е�Ӣ��]");
            SetPos(113,32);printf("�ƺŵĵ۹���ʿ�ų�����");
            SetPos(113,33);printf("�ʵ�֮��ֻ��һ�����ַ�");
            SetPos(113,34);printf("������ʧ���˵ĹŴ�ħ��");
            SetPos(113,35);printf("�Ĵ����ߣ������ǵ۹���");
            SetPos(113,36);printf("��һָ�Ľ�����ʦ��");
            break;
        case 0:
            SetPos(13,6);printf("    ");
            SetPos(13,8);printf("          ");
            SetPos(13,10);printf("                   ");
            SetPos(13,11);printf("           ");
            SetPos(13,13);printf("            ");
            SetPos(13,14);printf("                   ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_Ninja(int i)
{
    switch(i)
    {
        case 1:
            SetPos(44,4);printf("����  ����ֵ:4/4");
            SetPos(43,5);printf("�ƶ�4 ð��1/3 ս��2 ̽��3 ѧʶ1");
            SetPos(44,6);printf("����:2/3(4)");
            SetPos(45,7);printf("�ظ��ֶ�:ͣ����ɭ��ʱ");
            SetPos(47,8);printf("�ظ�1��");
            fn_clear_right();

            SetPos(113,2);printf("����ֵ:");
            SetPos(113,3);printf("lv0(0)\t��");
            SetPos(113,4);printf("lv1(2)\t̽��+1");
            SetPos(113,5);printf("lv2(4)\tս��+1");
            SetPos(113,6);printf("lv3(7)\t��������+1");
            SetPos(113,7);printf("\t�ظ�1������");

            SetPos(113,10);printf("�ر�:");
            SetPos(113,11);printf("��ϼ");
            SetPos(113,12);printf("[��ս�׶�]�У�ս��Ͷ����");
            SetPos(113,13);printf("[����]�ж�ǰ�����Խ�������");
            SetPos(113,14);printf("����Ͷ1��(ÿ�غ�1��)");

            SetPos(113,28);printf("����");
            SetPos(113,30);printf("��������");
            SetPos(113,31);printf("���ź�ɫ���£���������");
            SetPos(113,32);printf("Ŀ����֮���ˡ�Ϊ������");
            SetPos(113,33);printf("������ҩԭ�ϵ����Σ�̤");
            SetPos(113,34);printf("��������֮�á�������Ȼ");
            SetPos(113,35);printf("֮������[����]�Ĵ�����");
            break;
        case 0:
            SetPos(44,4);printf("                ");
            SetPos(43,5);printf("                               ");
            SetPos(44,6);printf("           ");
            SetPos(45,7);printf("                       ");
            SetPos(47,8);printf("        ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_Hunter(int i)
{
    switch(i)
    {
        case 1:
            SetPos(13,27);printf("����");
            SetPos(13,28);printf("����ֵ:5/5");
            SetPos(13,30);printf("�ƶ�3 ð��2/2 ս��2");
            SetPos(13,31);printf("̽��2 ѧʶ2");
            SetPos(13,33);printf("ħ��:3/3");
            SetPos(13,34);printf("�ظ��ֶΣ�[��Ϣ]ʱ��");
            SetPos(13,35);printf("�ظ������ޡ�");
            fn_clear_right();

            SetPos(113,2);printf("����ֵ:");
            SetPos(113,3);printf("lv0(0)\t��");
            SetPos(113,4);printf("lv1(2)\tս��+1");
            SetPos(113,5);printf("lv2(4)\t̽��+1");
            SetPos(113,6);printf("lv3(7)\tս��+1");

            SetPos(113,9);printf("�ر�:");
            SetPos(113,10);printf("�����ӵ�");
            SetPos(113,11);printf("[��ս�׶�]�У�ս��Ͷ����");
            SetPos(113,12);printf("[����]�ж�ǰ������һ��ɹ�");
            SetPos(113,13);printf("ֵ(ÿ����Ϸ��3�Σ�ÿ�غ���");
            SetPos(113,14);printf("һ��)");

            SetPos(113,28);printf("����");
            SetPos(113,30);printf("��������");
            SetPos(113,31);printf("������ħ��Ϊ�������ˡ�");
            SetPos(113,32);printf("�����ƽ�������ԣ���Ҫ");
            SetPos(113,33);printf("ͨ�����Զ�����һҹ����");
            SetPos(113,34);printf("ʹ�ù�ע��ħ����[ħ�]");
            SetPos(113,35);printf("����ս����");
            break;
        case 0:
            SetPos(13,27);printf("    ");
            SetPos(13,28);printf("          ");
            SetPos(13,30);printf("                   ");
            SetPos(13,31);printf("            ");
            SetPos(13,33);printf("        ");
            SetPos(13,34);printf("                    ");
            SetPos(13,35);printf("            ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_Gladiator(int i)
{
    switch(i)
    {
        case 1:
            SetPos(85,6);printf("�Ƕ�ʿ");
            SetPos(85,7);printf("����ֵ:5/6");
            SetPos(85,9);printf("�ƶ�3 ð��2/1 ս��4");
            SetPos(85,10);printf("̽��1 ѧʶ1");
            SetPos(85,12);printf("�Ƕ�ʿ����Ҫ��Դ");
            SetPos(85,14);printf("��[ƽԭ]����[ð��]");
            SetPos(85,15);printf("��ظ�1����ֵ");
            fn_clear_right();

            SetPos(113,2);printf("����ֵ:");
            SetPos(113,3);printf("lv0(0)\t��");
            SetPos(113,4);printf("lv1(2)\t̽��+1");
            SetPos(113,5);printf("lv2(4)\tս��+1");
            SetPos(113,6);printf("lv3(7)\t����ֵȫ��");

            SetPos(113,9);printf("�ر�:");
            SetPos(113,10);printf("������");
            SetPos(113,11);printf("�ڽ���[��ս�׶�]ʱ�����̽�");
            SetPos(113,12);printf("����ֵ�ָ������ֵ");

            SetPos(113,28);printf("�Ƕ�ʿ");
            SetPos(113,30);printf("��������");
            SetPos(113,31);printf("�ӵ۶���һ������ս��ʤ");
            SetPos(113,32);printf("����ԭ�����ھ���Ϊ�˸�");
            SetPos(113,33);printf("�������Ե���ʦ������");
            SetPos(113,34);printf("����ʰ�����������ó�˫");
            SetPos(113,35);printf("���������������������");
            SetPos(113,36);printf("�����");
            break;
        case 0:
            SetPos(85,6);printf("      ");
            SetPos(85,7);printf("           ");
            SetPos(85,9);printf("                   ");
            SetPos(85,10);printf("           ");
            SetPos(85,12);printf("                ");
            SetPos(85,14);printf("                  ");
            SetPos(85,15);printf("             ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_setPrince(int i)
{
    switch(i)
    {
        case 1:
            SetPos(46,36);printf("����  ����ֵ:4/4");
            SetPos(45,37);printf("�ƶ�3 ð��2/1 ս��1 ̽��1");
            SetPos(44,38);printf("ѧʶ3");
            SetPos(43,39);printf("����:0/lv��");
            SetPos(42,40);printf("�Լ��غϿ�ʼʱ���ظ�������");
            SetPos(41,41);printf("([��ս�׶�]�޷��ָ�)");
            fn_clear_right();

            SetPos(113,2);printf("����ֵ:");
            SetPos(113,3);printf("lv0(0)\t��");
            SetPos(113,4);printf("lv1(2)\tս��+1̽��+1");
            SetPos(113,5);printf("lv2(4)\tս��+1̽��+1");
            SetPos(113,6);printf("lv3(7)\tս��+1̽��+1");

            SetPos(113,9);printf("�ر�:");
            SetPos(113,10);printf("���:1/3");
            SetPos(113,11);printf("[��֮�ر�]����ʱ�ظ�3��");
            SetPos(113,12);printf("��ҿ��Ե�����Դʹ��");

            SetPos(113,28);printf("����");
            SetPos(113,30);printf("��������");
            SetPos(113,31);printf("��Ϊ����ʧ�ܶ���������");
            SetPos(113,32);printf("�ӡ���Ҫ�ڹʹ����𡣼�");
            SetPos(113,33);printf("��ͨ����ս�����������");
            SetPos(113,34);printf("���̤��������֮�á���");
            SetPos(113,35);printf("�ڱ����ó�ս����ͨ��");
            SetPos(113,36);printf("��Ӷ�������½���ս����");
            break;
        case 0:
            SetPos(46,36);printf("                ");
            SetPos(45,37);printf("                         ");
            SetPos(44,38);printf("     ");
            SetPos(43,39);printf("           ");
            SetPos(42,40);printf("                          ");
            SetPos(41,41);printf("                    ");
            fn_clear_right();
            break;
        default:break;
    }
}
void draw_hero_introduce_Paladin(int i)
{
    switch(i)
    {
        case 1:
            SetPos(85,27);printf("ʥ��ʿ");
            SetPos(85,28);printf("����ֵ:5/6");
            SetPos(85,30);printf("�ƶ�3 ð��2/1 ս��3");
            SetPos(85,31);printf("̽��1 ѧʶ2");
            SetPos(85,33);printf("������:2/2");
            SetPos(85,34);printf("�ƶ�ʱ����Ͷ���������");
            SetPos(85,35);printf("��1�������Ƴ����ظ�1��");
            SetPos(85,36);printf("(ÿ�غ�1��)");
            fn_clear_right();

            SetPos(113,2);printf("����ֵ:");
            SetPos(113,3);printf("lv0(0)\t��");
            SetPos(113,4);printf("lv1(2)\t������+1");
            SetPos(113,5);printf("lv2(4)\t����ȫ��");
            SetPos(113,6);printf("lv3(7)\tս��+1");

            SetPos(113,9);printf("�ر�:");
            SetPos(113,10);printf("����֮��");
            SetPos(113,11);printf("��һ��Ӣ�ۻظ�2����������");
            SetPos(113,12);printf("Ϊ����Ӣ�ۻظ�1������");
            SetPos(113,13);printf("(ÿ����Ϸ��1��)");

            SetPos(113,28);printf("ʥ��ʿ");
            SetPos(113,30);printf("��������");
            SetPos(113,31);printf("ȫ�����ؼ׵�ʥ����ʿ");
            SetPos(113,32);printf("�ܴ�̻���ǲ����������");
            SetPos(113,33);printf("�������ܹ�ʹ���ɶ����");
            SetPos(113,34);printf("����֮��ת�����ɵ���ʥ");
            SetPos(113,35);printf("ħ����");
            break;
        case 0:
            SetPos(85,27);printf("      ");
            SetPos(85,28);printf("          ");
            SetPos(85,30);printf("                   ");
            SetPos(85,31);printf("           ");
            SetPos(85,33);printf("          ");
            SetPos(85,34);printf("                      ");
            SetPos(85,35);printf("                      ");
            SetPos(85,36);printf("           ");
            fn_clear_right();
            break;
        default:break;
    }
}
#endif // DRAW_HERO_SELECT_H
