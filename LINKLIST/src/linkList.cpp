#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

lklst_ptr_node create_linklist(void)
{
    lklst_ptr_node L = (lklst_ptr_node)malloc(sizeof(lklst_node));
    if(NULL == L)
    {
        printf("malloc is default\n");
        return NULL;
    }
    //初始化指针，不然野指针必然段错误
    L->next = NULL;
    return L;
}

int insert_linklist(lklst_ptr_node L, int pos, linklist_data_t data)
{
    int len;// = get_len_linklist(L);
    //因为链表不会满，有一个来一个，所以不用判满
    //判断 pos 是否合法
    if(0 > pos || pos > len)
    {
        printf("position is default\n");
        return -1;
    }
    //找到插入位置的前一个node地址
    for(int i=0; i<pos; i++)//如果在第三个，L 就走到第二位
    {
        L = L->next;
    }

    //插入
    lklst_ptr_node p = create_linklist();   //创建新节点
    p->data = data;                         //初始化新节点

    p->next = L->next;
    L->next = p;
    return 0;
}