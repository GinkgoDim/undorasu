#ifndef WINDOW_RES_SET_H_INCLUDED
#define WINDOW_RES_SET_H_INCLUDED

void window_res_set()
{
    ///ȷ�����ڴ�С����Ҫд��main��ǰ��
    char str[20];
    sprintf(str, "mode con: cols=%d lines=%d",146,46);///�޸���Ļ��ʾ��Χ��ǰһ���Ǻ��ᣬ��һ��������
    system(str);
    ///������󻯰�ť
    DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MAXIMIZE, MF_BYCOMMAND);///SC_MAXIMIZE ��󻯣�SC_CLOSE �رգ�SC_MINIMIZE ��С��
    DrawMenuBar(GetConsoleWindow());
    ///�������ɷֱ���
    HWND hWnd = GetConsoleWindow(); //���cmd���ھ��
    RECT rc;
    GetWindowRect(hWnd, &rc); //���cmd���ڶ�Ӧ����
    //�ı�cmd���ڷ��
    SetWindowLongPtr(hWnd,GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_THICKFRAME);
    // ~WS_THICKFRAME�������ɷֱ��� ~WS_MAXIMIZEBOX������� & ~WS_MINIMIZEBOX������С��
    //��Ϊ����漰���߿�ı䣬�������SetWindowPos��������Ч��  ���һ��Ϊ����С����������
    //SetWindowPos(hWnd ,NULL ,rc.left ,rc.top ,rc.right - rc.left ,rc.bottom - rc.top ,NULL );
    SetWindowPos(hWnd ,NULL ,rc.left ,rc.top ,rc.right - rc.left ,rc.bottom - rc.top ,0);
}
#endif // WINDOW_RES_SET_H_INCLUDED
