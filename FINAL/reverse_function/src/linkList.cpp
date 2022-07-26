#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

lklst_ptr_node create_linklist(void)
{
    lklst_ptr_node L = (lklst_ptr_node)malloc(sizeof(lklst_node));
    if(NULL == L)
    {
        printf("apply for malloc failed\n");
        return NULL;
    }
    //初始化指针，不然野指针必然段错误
    L->next = NULL;
    return L;
}

int insert_linklist(lklst_ptr_node L,int pos,linklist_data_t ISTdata)
{
    int len = get_length_linklist(L);
    //因为链表不会满，有一个来一个，所以不用判满
    //判断 pos 是否合法
    if(0 > pos || pos > len)
    {
        printf("the position you ask is fatal\n");
        return -1;
    }
    //让L到pos前，这样新节点就在L和L->next之间
    for(int i=0;i<pos;i++)
    {
        L = L->next;
    }
    //创建新节点
    lklst_ptr_node ptr_new_node = create_linklist();

    //把插入的数据给新节点
    ptr_new_node->data = ISTdata;

    //把新node和前后节点连接起来
    ptr_new_node->next = L->next;
    L->next = ptr_new_node;

    return 0;

}

int get_length_linklist(lklst_ptr_node L)
{
    int len = 0;
    while(L->next) 
    {
        L = L->next;
        len++;
    }
    return len;
}

int empty_linklist(lklst_ptr_node L)
{
    if(NULL == L->next)
    {
        printf("L is on the end of the list\n");
        return 0;
    }
    else
    {
        return -2;
    }
}


int show_linklist(lklst_ptr_node L)
{
    if(0 == empty_linklist(L))
    {
        printf("L is on the end of the list\n");
        return -2;
    }
    
    while(L->next) 
    {
        printf("%c",L->next->data);
        L = L->next;
    }
    printf("\n");
    return 0;
}


int reversed_order_linklist(lklst_ptr_node L)
{
    if(0 == empty_linklist(L))
    {
        printf("the linkedlist is empty\n");
        return -1;
    }

    lklst_ptr_node p = L->next;
    lklst_ptr_node ap = p;
    L->next = NULL;

    while(p)
    {
        ap = p;
        p = p->next;
        
        ap->next = L->next;
        L->next = ap;
    }
}

