#include "linkList.h"
#include <stdio.h>
#include <stdlib.h>

lklst_ptr_node create_linklist(void)
{
    lklst_ptr_node L = (lklst_ptr_node)malloc(sizeof(lklst_node));
    if(NULL == L)
    {
        printf("memory allocate failed\n");
        return NULL;
    }
    L->next = NULL;
    return L;
}

int insert_linklist(lklst_ptr_node L,int pos,linklist_data_t ISTdata)
{
    int len = get_length_linklist(L);
    if(pos < 0 || pos > len)
    {
        printf("Fatal:bad position!\n");
        return -1;
    }

    for(int i=0;i<pos;i++) // why not pos-1
    {
        L = L->next;
    }

    lklst_ptr_node newPtrNode = create_linklist();
    newPtrNode->data = ISTdata;

    newPtrNode->next = L->next;
    L->next = newPtrNode;

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

// int delete_based_value_linklist(lklst_ptr_node L,linklist_data_t DLTdata);

int delete_based_address_linklist(lklst_ptr_node L,int pos)
{
    if(0 == empty_linklist(L))
    {
        printf("一眼顶针，鉴定为空\n");
        return -1;
    }
    if(pos<0 || pos>=get_length_linklist(L)) 
    {
        printf("Fatal:bad position!\n");
        return -1;
    }

    for(int i=0;i<pos;i++)
    {
        L = L->next;
    }

    lklst_ptr_node temp = L->next;
    L->next = temp->next;

    free(temp);
    return 0;
}

int empty_linklist(lklst_ptr_node L)
{
    if(NULL == L->next)
    {
        printf("一眼顶针，鉴定为空\n");
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
        printf("一眼顶针，鉴定为空\n");
        return -1;
    }

    while(L->next)
    {
        printf("%c",L->next->data);
        L = L->next;
    }
    printf("\n");
    return 0;
}


//根据值修改
//摧毁
//清空
//逆序
//排序


