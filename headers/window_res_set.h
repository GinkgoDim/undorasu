#ifndef WINDOW_RES_SET_H_INCLUDED
#define WINDOW_RES_SET_H_INCLUDED

void window_res_set()
{
    ///确定窗口大小，需要写在main最前面
    char str[20];
    sprintf(str, "mode con: cols=%d lines=%d",146,46);///修改屏幕显示框范围，前一个是横轴，后一个是纵轴
    system(str);
    ///禁用最大化按钮
    DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MAXIMIZE, MF_BYCOMMAND);///SC_MAXIMIZE 最大化，SC_CLOSE 关闭，SC_MINIMIZE 最小化
    DrawMenuBar(GetConsoleWindow());
    ///禁用自由分辨率
    HWND hWnd = GetConsoleWindow(); //获得cmd窗口句柄
    RECT rc;
    GetWindowRect(hWnd, &rc); //获得cmd窗口对应矩形
    //改变cmd窗口风格
    SetWindowLongPtr(hWnd,GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_THICKFRAME);
    // ~WS_THICKFRAME禁用自由分辨率 ~WS_MAXIMIZEBOX禁用最大化 & ~WS_MINIMIZEBOX禁用最小化
    //因为风格涉及到边框改变，必须调用SetWindowPos，否则无效果  最后一项为数字小数四舍五入
    //SetWindowPos(hWnd ,NULL ,rc.left ,rc.top ,rc.right - rc.left ,rc.bottom - rc.top ,NULL );
    SetWindowPos(hWnd ,NULL ,rc.left ,rc.top ,rc.right - rc.left ,rc.bottom - rc.top ,0);
}
#endif // WINDOW_RES_SET_H_INCLUDED
