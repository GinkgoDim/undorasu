#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <mmsystem.h>
#include <io.h>
#include <string.h>
#include <malloc.h>

///用于引用winmm库文件，cb好像手动加库
//#pragma comment(lib, "WINMM.LIB")

#ifndef FALSE
#define FALSE 0
#endif//FALSE

#ifndef ERROR
#define ERROR -1
#endif//ERROR

#ifndef TRUE
#define TRUE 1
#endif//TRUE

#endif // HEAD_H
