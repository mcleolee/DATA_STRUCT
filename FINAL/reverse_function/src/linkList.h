//链表
#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef char linklist_data_t;

typedef struct linklist
{
    linklist_data_t data;
    struct linklist *next; 
}lklst_node, *lklst_ptr_node;

lklst_ptr_node create_linklist(void);

int insert_linklist(lklst_ptr_node L, int pos, linklist_data_t data);
int get_length_linklist(lklst_ptr_node L);
int empty_linklist(lklst_ptr_node L);
int show_linklist(lklst_ptr_node L);
int reversed_order_linklist(lklst_ptr_node L);

#endif