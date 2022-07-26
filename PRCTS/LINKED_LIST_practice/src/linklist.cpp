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
}

int insert_linklist(lklst_ptr_node L,int pos,linklist_data_t ISTdata);

int get_length_linklist(lklst_ptr_node L);

int delete_based_value_linklist(lklst_ptr_node L,linklist_data_t DLTdata);

int delete_based_address_linklistt(lklst_ptr_node L,int pos);

int empty_linklist(lklst_ptr_node L);

int show_linklist(lklst_ptr_node L);


//根据值修改
//摧毁
//清空
//逆序
//排序


