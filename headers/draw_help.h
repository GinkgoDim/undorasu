#ifndef DRAW_HELP_H_INCLUDED
#define DRAW_HELP_H_INCLUDED
///1355531
void draw_help();
void draw_help_page1();
void draw_help_page2();
void draw_help_page3();
void draw_help_block(int color,int x,int y);

void draw_help()
{
    int page=1;
    int ch;
    draw_help_page1();
    SetPos(115,3);printf("���»س���ҳ");
    SetPos(115,4);printf("Press 'Enter' next page");
    SetPos(115,6);printf("����ESC����");
    SetPos(115,7);printf("Press 'ESC' back");
    SetPos(6,44);printf("Page 1");
    while(1)///����ESC�˳��޸Ľ��棬����ENTER��ʼ�����޸�
    {
        if (_kbhit())
        {///����а������£���_kbhit()����������
            ch = _getch();///ʹ��_getch()������ȡ���µļ�ֵ
            emergency_decoration(2);
            if(ch==13)
            {
                switch(page)
                {
                    case 1:
                        page++;
                        emergency_decoration(1);
                        draw_help_page2();
                        break;
                    case 2:
                        page++;
                        emergency_decoration(1);
                        draw_help_page3();
                        break;
                    case 3:
                        page=1;
                        emergency_decoration(1);
                        draw_help_page1();
                        break;
                    default:break;
                }
            }
            SetPos(6,44);printf("Page %d",page);
            if(ch==27)
                break;
        }
    }
}

void draw_help_page1()
{
    SetPos(10,4);printf("���������ߵİ���ҳ��");
    SetPos(10,6);printf("����ֵ(n/n)\t\t����ֵ����0��Ұ��ݵĽ�ɫ�ͻ�������ð�չ�����������Ϸ�ͻ����");
    SetPos(10,8);printf("����ֵ\t\t����ֵ��������������ɫ�ȼ��������");
    SetPos(10,10);printf("��Դֵ\t\tÿ����ɫ�����������Դֵ��ӵ������Ļظ��ֶ�");
    SetPos(10,11);printf("\t\t\t��Ϸ�������� ħ�� ���� ħ�� ���� ��� ������");
    SetPos(10,12);printf("\t\t\t���ǿ����������������߶�Ͷ�����������ɹ���");
    SetPos(10,14);printf("�����������\t\t�ƶ�(n) ð��(n/n) ս��(n) ̽��(n) ѧʶ(n)");
    SetPos(10,15);printf("\t\t\t����ð����ֵǰһ��Ϊƽԭð����ֵ����һ��Ϊɭ��ð����ֵ");
    SetPos(10,17);printf("�ر�\t\t\tÿ����ɫӵ��ǿ��Ч�������⼼�ܣ���Ҫ����[��֮�ر�]�ſ�ʹ��");

    SetPos(10,20);printf("��ŭ\t\t\t��ֵΪ15��ÿ����ҵ��ƶ���Ͷ����6��ʱ��ή1������0�ἤŭ��ǿ�ƽ����ս");
    SetPos(10,21);printf("����\t\t\t����ŭλ��14 11 8 5 2������ŭ����Ӧֵʱ������������ʱͶ�������Ӵ����¼�");
    SetPos(10,23);printf("������:");
    SetPos(10,24);printf("    1�ٻٱ����� �����屻�ջ٣������ڱ����������ܵ�2���˺�");
    SetPos(10,25);printf("    2��ץ��Ͷ   �������Ͷ��1ö���ӣ�������ߵ���һص�����");
    SetPos(10,26);printf("    3��Ϣ����   ������ҳ���1���˺�");
    SetPos(10,27);printf("    4��������   �������Ͷ��1ö���ӣ�������͵���ҳ���2���˺�");
    SetPos(10,28);printf("    5����ɢ��   �������Ͷ��1ö���ӣ�������ߵ���ҳ���2���˺�");
    SetPos(10,29);printf("    6��ѹ����   �������Ͷ��1ö���ӵ�����͵������Դֵ�ľ�(��Ҳ���Ӱ��)");

    SetPos(10,32);printf("�����ӳɹ������ж�\t����һ��6������(D6)���гɹ����޹���ʧ��3�����");
    SetPos(10,33);printf("�����ж���:(ð����:1&2ʧ��3&4�޹�5&6�ɹ�  ��ս��:1ʧ��2&3&4�޹�5&6�ɹ�)");
    SetPos(10,34);printf("    ʧ�ܣ��൱��-1    �޹����൱��0    �ɹ����൱��1");

    SetPos(10,37);printf("ð��\t\t\t�����վ�� ƽԭ ɭ�� �����ʱ������ѡ��ð�ա������������Լ��ڸð����");
    SetPos(10,38);printf("\t\t\t��ð��ֵ�����ж�����ý����������߳ͷ�����");
    SetPos(10,39);printf("ð�ձ�:");
    SetPos(10,40);printf("    -1���� �ܵ�1���˺�  0 ���·���  1 ���1�㾭�鵫�ܵ�1���˺�  2���� ���1�㾭��");
    SetPos(6,44);
}

void draw_help_page2()
{
    SetPos(10,4);printf("�����ƶ�Ͷ��\t\tͶ������ͬ����ֵ�ܹ�ʹ��ҽ��벻ͬ�İ��(ɽ �߽� �ٻٵı����嶼�ǲ�����Խ��)");
    SetPos(10,5);printf("�ƶ���");
    SetPos(10,6);printf("    1 �Ķ�Ҳȥ����    2 �ɽ����·    3&4 �ɽ����·��ƽԭ");
    SetPos(10,7);printf("    5 �ɽ����·��ƽԭ��ɭ��    6 ���˿�������������Զ�Ͷ��1�Σ����ᴥ����ŭ");

    SetPos(10,10);printf("����Ϊ���ͼ��");
    draw_help_block(8,14,13);SetPos(25,16);printf("<=��·");draw_help_block(2,42,13);SetPos(53,16);printf("<=ɭ��");draw_help_block(15,70,13);SetPos(81,16);printf("<=����/��ׯ/����");
    draw_help_block(6,14,22);SetPos(25,25);printf("<=ƽԭ");draw_help_block(5,42,22);SetPos(53,25);printf("<=ɽ��");draw_help_block(4,70,22);SetPos(81,25);printf("<=�ջٵı�����");

    SetPos(10,31);printf("����\t\t\t��ͼ�е�5��ɽ����5��������Ҫ��������������������Ͷ�����ӽ������");
    SetPos(10,32);printf("\t\t\t���������ѿ��ԺͶ���һ����ɣ����Ƕ����������ʱ��Ҫ����վ����������Χ");
    SetPos(10,33);printf("\t\t\tͶ�����ɹ� ��ɶ�+1��Ͷ�����޹� ��ɶȲ��䣬Ͷ����ʧ�� ��ɶ�-1(���Ϊ0)");
    SetPos(10,35);printf("����\t\t\t���������ʱ���Ի�ù̶�������һ��5��");
    SetPos(10,36);printf("������");
    SetPos(10,37);printf("    ������ͼ\t����ʼ��սʱ�ȶ������1���˺�");
    SetPos(10,38);printf("    ��֮�ر�\t\t��ȡ�߿���ʹ���ر�����");
    SetPos(10,39);printf("    ����֮��\t\t��ȡʱ������Ҿ���ֵ+1");
    SetPos(10,40);printf("    ��������\t\t��ȡʱ�������ս��ֵ+1");
    SetPos(10,41);printf("    ����֮Ѫ\t\t��ȡʱ�����������ֵ�ظ�������");

    SetPos(6,44);
}

void draw_help_page3()
{
    SetPos(10,4);printf("��ս����\t\t\t����������5��ɽ���������ͨ���ƶ�Ͷ����15��6��ŭ��ʱ����ʼ��ս��");
    SetPos(10,5);printf("\t\t\tͨ���ƶ�Ͷ����15��6��ŭ����ʼ��ս��������ŭ���ȹ������Ƚ���������ŭ����");
    SetPos(10,6);printf("\t\t\tͨ���������ʼ��սʱ��Ӣ���ҵ�������չ�˷���������������������ŭ");
    SetPos(10,9);printf("��սս������\t\t\t��������Լ���ս��ֵ����Դֵ����չ����ս");
    SetPos(10,10);printf("��ս��");
    SetPos(10,11);printf("    -1������\t�������ɣ���֪���룬����");
    SetPos(10,12);printf("    0\t\t����˫צ�����͹�����ҳ���4���˺�");
    SetPos(10,13);printf("    1\t\t��Ϣɨ�䣬������ҳ���1���˺�");
    SetPos(10,14);printf("    2\t\t��Я�����Ļ��ᣬ������������ٴ�Ͷ�����빥��������Ϊ2�������Ϣɨ��");
    SetPos(10,15);printf("    3\t\t���ܾ��ˣ�������1���˺�����ҳ���2���˺�");
    SetPos(10,16);printf("    4\t\t����ͻϮ��������1���˺�");
    SetPos(10,17);printf("    5������\t��������Ӣ��һ����������2���˺�");
    SetPos(10,20);printf("��������ֵ\t\t��һ��9Ѫ����ȥ���1��Ѫ���뵥�������⣬��ÿ�غ�������2���˺�");
    SetPos(10,21);printf("��ŭ����\t\t������Ѫ���ִ�8 6 4 2ʱ���ᴥ����ŭ����");
    SetPos(10,22);printf("��ŭ������");
    SetPos(10,23);printf("    1\t\t˼�����������·���");
    SetPos(10,24);printf("    2&3\t��Ϣ������������ҳ���1���˺�");
    SetPos(10,25);printf("    4&5&6\t³çͻ�����������Ͷ��1ö���ӣ�������͵���ҳ���2���˺�");
    SetPos(10,29);printf("���������ף��λ�����(ι)����죡");
}

void draw_help_block(int color,int x,int y)
{
    setColor(0,color);
    SetPos(x+4,y);printf("  ");
    SetPos(x+2,y+1);printf("      ");
    SetPos(x,y+2);printf("          ");
    SetPos(x,y+3);printf("          ");
    SetPos(x,y+4);printf("          ");
    SetPos(x+2,y+5);printf("      ");
    SetPos(x+4,y+6);printf("  ");
    setColor(7,0);
}
#endif // DRAW_HELP_H_INCLUDED
