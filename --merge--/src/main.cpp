#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "link.h"
// 用这个头文件会报错: 多个定义
// #include "general.h"

int main()
{
    system("cls");
    // linkedList();
    linkedQueue();
    return 0;
}